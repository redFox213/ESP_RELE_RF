#include <stdio.h>
#include "RELE.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "esp_log.h"

void Rele_init(void)
{
    gpio_reset_pin(RELE_1);
    gpio_reset_pin(RELE_2);
    gpio_reset_pin(RELE_3);
    gpio_reset_pin(RELE_4);

    gpio_set_direction(RELE_1, GPIO_MODE_OUTPUT);
    gpio_set_direction(RELE_2, GPIO_MODE_OUTPUT);
    gpio_set_direction(RELE_3, GPIO_MODE_OUTPUT);
    gpio_set_direction(RELE_4, GPIO_MODE_OUTPUT);

    gpio_set_level(RELE_1, LOW);
    gpio_set_level(RELE_2, LOW);
    gpio_set_level(RELE_3, LOW);
    gpio_set_level(RELE_4, LOW);
}

void Test_Rele(uint8_t number_rele)
{
    switch (number_rele)
    {
    case 1:
        gpio_set_level(RELE_1, HIGH);
        vTaskDelay(1000);
        gpio_set_level(RELE_1, LOW);
        break;
    case 2:
        gpio_set_level(RELE_1, HIGH);
        vTaskDelay(1000);
        gpio_set_level(RELE_1, LOW);
        break;
    case 3:
        gpio_set_level(RELE_1, HIGH);
        vTaskDelay(1000);
        gpio_set_level(RELE_1, LOW);
        break;
    case 4:
        gpio_set_level(RELE_1, HIGH);
        vTaskDelay(1000);
        gpio_set_level(RELE_1, LOW);
        break;
    default:
        break;
    }
}

void On_Off_Rele(uint8_t number_rele, uint8_t status_rele) //введите номер реле и потом его состояние 0 выключить, 1 включить
{
    if(status_rele < 2)
    {
        switch (number_rele)
        {
            case 1:
                if(status_rele == 0)
                    {
                        gpio_set_level(RELE_1, LOW);
                    }
                else if(status_rele == 1)
                    {
                        gpio_set_level(RELE_1, HIGH);
                    }
                break;
            case 2:
                if(status_rele == 0)
                    {
                        gpio_set_level(RELE_2, LOW);
                    }
                else if(status_rele == 1)
                    {
                        gpio_set_level(RELE_2, HIGH);
                    }
                break;
            case 3:
                if(status_rele == 0)
                    {
                        gpio_set_level(RELE_3, LOW);
                    }
                else if(status_rele == 1)
                    {
                        gpio_set_level(RELE_3, HIGH);
                    }
                break;
            case 4:
                if(status_rele == 0)
                    {
                        gpio_set_level(RELE_4, LOW);
                    }
                else if(status_rele == 1)
                    {
                        gpio_set_level(RELE_4, HIGH);
                    }
                break;
            default:
                break;
        }
    }
    
}
