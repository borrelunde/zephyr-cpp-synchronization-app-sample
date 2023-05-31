#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>

#include "Semaphore.hpp"

LOG_MODULE_REGISTER(main, LOG_LEVEL_DBG);

// Delay between greetings in milliseconds.
#define SLEEPTIME 1000
#define STACKSIZE 2000

struct k_thread coop_thread;
struct k_thread main_thread;

K_THREAD_STACK_DEFINE(coop_stack, STACKSIZE);
K_THREAD_STACK_DEFINE(main_stack, STACKSIZE);

Semaphore coop_semaphore;
Semaphore main_semaphore;

void coop_thread_loop() {
    struct k_timer timer;
    k_timer_init(&timer, NULL, NULL);

    while (true) {
        // Wait for main thread to let us have a turn.
        coop_semaphore.wait();

        LOG_INF("%s", __FUNCTION__);

        // Wait a while, then let main thread have a turn.
        k_timer_start(&timer, K_MSEC(SLEEPTIME), K_NO_WAIT);
        k_timer_status_sync(&timer);
        main_semaphore.give();
    }
}

void main_thread_loop() {
    struct k_timer timer;
    k_timer_init(&timer, NULL, NULL);

    while (true) {
        LOG_INF("%s", __FUNCTION__);

        // Wait a while, then let main thread have a turn.
        k_timer_start(&timer, K_MSEC(SLEEPTIME), K_NO_WAIT);
        k_timer_status_sync(&timer);
        coop_semaphore.give();

        // Wait for coop thread to let us have a turn.
        main_semaphore.wait();
    }
}

int main() {
    k_thread_create(&coop_thread, coop_stack, STACKSIZE,
                    (k_thread_entry_t)coop_thread_loop,
                    NULL, NULL, NULL, K_PRIO_COOP(7), 0, K_NO_WAIT);
    k_thread_create(&main_thread, main_stack, STACKSIZE,
                    (k_thread_entry_t)main_thread_loop,
                    NULL, NULL, NULL, K_PRIO_COOP(7), 0, K_NO_WAIT);
    return 0;
}