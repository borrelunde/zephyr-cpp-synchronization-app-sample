#pragma once

#include <zephyr/kernel.h>

class Semaphore {
   private:
    struct k_sem internal_semaphore;

   public:
    Semaphore();
    ~Semaphore();
    const int wait();
    void give();
};