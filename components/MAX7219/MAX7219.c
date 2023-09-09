#include <stdio.h>
#include "MAX7219.h"
#include <string.h>
#include <stdlib.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/spi_master.h"
#include "esp_log.h"

spi_device_handle_t spi_device_handle;

void MAX7219_SPI_Init(void)
{
    spi_bus_config_t spi1_bus_config = {
        .mosi_io_num = GPIO_MOSI,
        .miso_io_num = GPIO_MISO,
        .sclk_io_num = GPIO_SCLK,
        .quadhd_io_num = -1,
        .quadwp_io_num = -1,
        .max_transfer_sz = 1024,
    };

    spi_device_interface_config_t spi_device_config = {
                                    .mode = 0,
                                    .duty_cycle_pos = 128,
                                    .clock_speed_hz = 100000,
                                    .spics_io_num = GPIO_CS,
                                    .flags = SPI_DEVICE_HALFDUPLEX,
                                    .queue_size = 1,
                                    .pre_cb = NULL,
                                    .post_cb = NULL,
                                    };
    spi_bus_initialize(SPI1_HOST, &spi1_bus_config, SPI_DMA_CH_AUTO);

    spi_bus_add_device(SPI1_HOST, &spi_device_config, &spi_device_handle);
}

void MAX7219_SPI_Write(uint8_t reg, uint8_t value)
{
    uint8_t data[2] = {reg, value};
    spi_transaction_t spi_transaction = {
        .tx_buffer = data,
        .length = 16,
    };
    spi_device_transmit(spi_device_handle, &spi_transaction);
}

void MAX7219_INIT(void)
{
    MAX7219_SPI_Write(REG_DECODE_MODE, 0);
    MAX7219_SPI_Write(REG_INTENSITY, 7);
    MAX7219_SPI_Write(REG_SCNA_LIMIT, 7);
    MAX7219_SPI_Write(REG_SHUTDOWN, 1);
    MAX7219_SPI_Write(REG_DISPLAY_TEST, 0);
}

void MAX7219_Clear(void)
{
    for (size_t i = 0; i < 8; i++)
    {
        MAX7219_SPI_Write(i, 0);
    }
}

void MAX7219_Red_Led(void)
{
    MAX7219_SPI_Write(REG_DIGIT_0, 0x00);
}

void MAX7219_Blue_Led(void)
{
    MAX7219_SPI_Write(REG_DIGIT_0, 0x01);
}

void MAX7219_Green_Led(void)
{
    MAX7219_SPI_Write(REG_DIGIT_0, 0x03);
}


void MAX7219_Init(void)
{
    MAX7219_SPI_Init();
    MAX7219_INIT();
    MAX7219_Clear();
}

