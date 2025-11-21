#include "spi_helper.h"

#include <bitset>

bool SPI::init(uint64_t clk_spd, uint32_t channel) {
    uint32_t flags = 0x0;

    // flags |= PI_SPI_FLAGS_AUX_SPI(1); // USE SPI 1

    spi_handle = spiOpen(channel, clk_spd, flags);

    return (spi_handle >= 0);
}

uint8_t SPI::transfer(uint8_t data) {
    if(spi_handle < 0) return 0;

    uint8_t rval;
	spiXfer(spi_handle, (char *)&data, (char *)&rval, 1);
    return rval;
}

void SPI::transfer(void* buf, uint32_t count) {
    if(spi_handle < 0) return;

    uint8_t cache[1024 * 16]; // temporary cache buffer
    spiXfer(spi_handle, (char *)buf, (char *)cache, count);
    for(uint32_t i=0; i < count; ++i){
        *((uint8_t*)buf + i) = cache[i]; // cpy
    }
}