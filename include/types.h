#pragma once

#include <cstdint>
#include <iostream>
#include <iomanip>

#define PROGMEM

static constexpr uint8_t UNUSED_PIN = UINT8_MAX;

#define DEC 10
#define HEX 16
#define OCT 8

#define LSBFIRST 0
#define MSBFIRST 1

#ifndef _NOP
#define _NOP() do { __asm__ volatile ("nop"); } while (0)
#endif

#define bit(b) (1UL << (b))

typedef unsigned int word;
typedef bool boolean;
typedef uint8_t byte;
typedef char __FlashStringHelper;

#define F


inline void yield(void) {}


extern void delay(uint16_t ms);
extern uint32_t millis();
extern void digitalWrite(uint16_t pin, uint16_t level);

class Serial {
public:
    template<typename T>
    static void print(T data, int16_t base=DEC) {
        std::cout << std::setbase(base) << data;
        std::cout.flush();
    }

    template<typename T>
    static void println(T&& data, int16_t base=DEC) {
        print(std::forward<T&&>(data), base);
        println();
    }

    static void println() {
        std::cout << "\n";
    }
};