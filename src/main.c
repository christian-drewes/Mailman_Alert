#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"

#define BLINK_GPIO 2 //Built in led

void app_main() {
    gpio_pad_select_gpio(BLINK_GPIO); // Select PIN
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);

    while(1){
        gpio_set_level(BLINK_GPIO, 0); // Turn off led
        vTaskDelay(1000 / portTICK_PERIOD_MS); // delay 1s
        gpio_set_level(BLINK_GPIO, 1); // Turn on led
        vTaskDelay(1000 / portTICK_PERIOD_MS); // delay 1s
    }
}