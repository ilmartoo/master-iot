#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"

#define msToTicks(ms) (ms / portTICK_PERIOD_MS)

#define BUTTON_PIN 47 // Button pin number
#define LED_PIN 21    // LED pin number

#define LOOP_WAIT_TIME 2000 // Wait time in milliseconds

void config_button(gpio_num_t pin);                             // Config pin as button input
void config_led(gpio_num_t pin);                                // Config pin as LED output
void execute_task_1(gpio_num_t button_pin, gpio_num_t led_pin); // Execute the desired task

void app_main(void)
{
    config_button(BUTTON_PIN);
    config_led(LED_PIN);

    while (1)
    {
        execute_task_1(BUTTON_PIN, LED_PIN);
        vTaskDelay(msToTicks(LOOP_WAIT_TIME));
    }
}

void config_button(gpio_num_t pin)
{
    gpio_reset_pin(pin);
    gpio_set_direction(pin, GPIO_MODE_INPUT);
}

void config_led(gpio_num_t pin)
{
    gpio_reset_pin(pin);
    gpio_set_direction(pin, GPIO_MODE_OUTPUT);
}

void execute_task_1(gpio_num_t button_pin, gpio_num_t led_pin)
{
    int button_value = gpio_get_level(button_pin); // 0 on button press, 1 on released
    if (button_value)
    {
        gpio_set_level(led_pin, false);
        printf("LED apagado\n");
    }
    else
    {
        gpio_set_level(led_pin, true);
        printf("LED encendido\n");
    }
}
