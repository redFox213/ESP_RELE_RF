#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "RAK3172.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"
#include "driver/uart.h"
#include "esp_log.h"

//конфигурция UART >
#define UART_RX_PIN GPIO_NUM_14
#define UART_TX_PIN GPIO_NUM_15
static const char *tag = "UART EVENET";

#define BUF_SIZE 1024
#define BUF_SIZE_TX 1024
#define TASK_MEMORY 1024
QueueHandle_t QueueHandle;

typedef struct 
{
    int Baud_Rate;
    uint8_t Stop_Bits;
} RAK3172_Param_Config_t;



void uart_task(void *Parametr)
{
    uart_event_t event;
    uint8_t *data = (uint8_t*)malloc(BUF_SIZE);
    char value[50];
    while(1)
    {
        if(xQueueReceive(QueueHandle, (void*)&event, portMAX_DELAY))
        {
            bzero(data, BUF_SIZE);
            switch (event.type)
            {
            case UART_DATA:
                uart_read_bytes(UART_NUM_0, data, event.size, 1000);
                uart_write_bytes(UART_NUM_0, (const char*)data, event.size);
                uart_flush(UART_NUM_0);
                ESP_LOGI(tag, "Data resive: %s", data);
                break;
            
            default:
                break;
            }
        }
    }
}
//кофигуркция UART <
void RAK3172_UART_INIT()
{
    uart_config_t uart0_config = {
        .baud_rate = 115200,
        .data_bits = UART_DATA_8_BITS,
        .parity = UART_PARITY_DISABLE,
        .stop_bits = UART_STOP_BITS_1,
        .flow_ctrl = UART_HW_FLOWCTRL_DISABLE,
        .source_clk = UART_SCLK_APB,
    };
    uart_param_config(UART_NUM_0, &uart0_config);
    uart_set_pin(UART_NUM_0, UART_TX_PIN, UART_RX_PIN, 
                UART_PIN_NO_CHANGE, UART_PIN_NO_CHANGE);
    uart_driver_install(UART_NUM_0, BUF_SIZE, BUF_SIZE,
                        3, &QueueHandle, 0);
    xTaskCreate(uart_task, "uart task", TASK_MEMORY,
                NULL, 5, NULL);
}
//

void Sennd_AT_Command(char AT_Command[])
{   
    uint8_t leight = strlen(AT_Command);
    uart_write_bytes(UART_NUM_0, "AT?", sizeof("AT?"));
}

void AT_HWMODEL(void)
{
    Sennd_AT_Command("AT+HWMODEL+");
}

void RAK3172_Init(void)
{
    RAK3172_UART_INIT();
    Sennd_AT_Command("ATE");
    
}
