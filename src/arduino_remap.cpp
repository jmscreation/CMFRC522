#include "types.h"
#include "pigpio.h"

#include <iostream>
#include <stdexcept>
#include <thread>
#include <chrono>


void delay(uint16_t ms) {
    std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}

uint32_t millis() {
    static auto time_point = std::chrono::steady_clock::now();
    return static_cast<uint32_t>(std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - time_point).count());
}

void digitalWrite(uint16_t pin, uint16_t level) {
    if(pin != UNUSED_PIN){
        gpioWrite(pin, level);
    }
}