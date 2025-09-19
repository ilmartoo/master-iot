#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "driver/adc_types_legacy.h"
#include "driver/adc.h"

#define msToTicks(ms) (ms / portTICK_PERIOD_MS)

#define LDR_CHANNEL ADC_CHANNEL_7 // LDR analog channel (pin)

#define ANALOG_ATTENUATION ADC_ATTEN_DB_12 // Atenuation for the analog value
#define ANALOG_RESOLUTION 12               // Resolution for the analog value

#define LOOP_WAIT_TIME 2000 // Wait time in milliseconds

void config_ldr(adc1_channel_t channel);         // Config channel as LDR input
void execute_task_2(adc1_channel_t ldr_channel); // Execute the desired task

void app_main(void)
{
    config_ldr(LDR_CHANNEL);

    while (1)
    {
        execute_task_2(LDR_CHANNEL);
        vTaskDelay(msToTicks(LOOP_WAIT_TIME));
    }
}

void config_ldr(adc1_channel_t channel)
{
    adc1_config_channel_atten(channel, ANALOG_ATTENUATION);
    adc1_config_width(ANALOG_RESOLUTION);
}

void execute_task_2(adc1_channel_t ldr_channel)
{
    int ldr_value = adc1_get_raw(ldr_channel);
    printf("LDR value = %d\n", ldr_value);
}
