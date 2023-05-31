#include "Semaphore.hpp"

#include <zephyr/logging/log.h>

LOG_MODULE_REGISTER(Semaphore, LOG_LEVEL_DBG);

Semaphore::Semaphore() {
    LOG_DBG("Constructing Semaphore (%p)", (void *)this);
    k_sem_init(&internal_semaphore, 0, K_SEM_MAX_LIMIT);
}

Semaphore::~Semaphore() {
    LOG_DBG("Deconstructing Semaphore (%p)", (void *)this);
}

const int Semaphore::wait() {
    LOG_DBG("%s", __FUNCTION__);
    k_sem_take(&internal_semaphore, K_FOREVER);
    return 1;
}

void Semaphore::give() {
    LOG_DBG("%s", __FUNCTION__);
    k_sem_give(&internal_semaphore);
}