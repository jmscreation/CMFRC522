#pragma once

#include "types.h"
#include "pigpio.h"

class SPI {
    inline static int32_t spi_handle = -1;
public:
    static bool init(uint64_t baud, uint32_t channel = 0);

    static uint8_t transfer(uint8_t data);
    static void transfer(void* buf, uint32_t count);
};