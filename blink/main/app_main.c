/* Blink Example

   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/
#include <stdio.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "driver/gpio.h"
#include "sdkconfig.h"
#include "input_iot.h"
#include "output_iot.h"
#define BLINK_GPIO 2

//output_iot:
// void input_event_callback(int pin){
//     if(pin == GPIO_NUM_0){
//         output_io_toggle(BLINK_GPIO);
//     }
// }

//input_iot:
void input_event_callback(int pin){
    if(pin==GPIO_NUM_0){
        static int x = 0;
        gpio_set_level(BLINK_GPIO,x);
        x = 1 - x;
    }
}
void app_main(void)
{

    //input_iot:
    gpio_pad_select_gpio(BLINK_GPIO);
    gpio_set_direction(BLINK_GPIO, GPIO_MODE_OUTPUT);
    input_io_create(GPIO_NUM_0,HI_TO_LO);
    input_set_callback(input_event_callback);

    //output_iot:
    // output_io_create(BLINK_GPIO);
    // input_io_create(GPIO_NUM_0,HI_TO_LO);
    // input_set_callback(input_event_callback);


    // while(1) {
    //     /* Blink off (output low) */
	// printf("Turning off the LED\n");
    //     gpio_set_level(BLINK_GPIO, 0);
    //     vTaskDelay(1000 / portTICK_PERIOD_MS);
    //     /* Blink on (output high) */
	// printf("Turning on the LED\n");
    //     gpio_set_level(BLINK_GPIO, 1);
    //     vTaskDelay(1000 / portTICK_PERIOD_MS);
    // }
}
