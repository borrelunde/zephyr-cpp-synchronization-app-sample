#pragma once

#include <zephyr/kernel.h>

class Semaphore {
   protected:
    struct k_sem internal_semaphore;

   public:
    Semaphore();
    ~Semaphore();
    const int wait();
    const int wait(int timeout);
    void give();
};