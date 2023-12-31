
#include <stdio.h>
#include "sdkconfig.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "esp_system.h"
#include "esp_spi_flash.h"
#include "input_iot.h"
#include "output_iot.h"
#include "freertos/timers.h"
#include "freertos/event_groups.h"
// void hello_task(void *pvParameter)
// {
//     printf("Hello world!\n");
//     for (int i = 10; i >= 0; i--) {
//         printf("Restarting in %d seconds...\n", i);
//         vTaskDelay(1000 / portTICK_RATE_MS);
//     }
//     printf("Restarting now.\n");
//      fflush(stdout);
//     esp_restart();
// }
TimerHandle_t xTimers[2];
EventGroupHandle_t xEventGroup;
#define BIT_EVENT_BUTTON_PRESS	( 1 << 0 )
#define BIT_EVENT_UART_RECV	( 1 << 1 )

void vTask1( void * pvParameters )
{
    for( ;; )
    {  
   EventBits_t uxBits = xEventGroupWaitBits( //function blocked
            xEventGroup,   /* The event group being tested. */
            BIT_EVENT_UART_RECV | BIT_EVENT_BUTTON_PRESS, /* The bits within the event group to wait for. */
            pdTRUE,        /* BIT_0 & BIT_4 should be cleared before returning. */
            pdFALSE,       /* Don't wait for both bits, either bit will do. */
            portMAX_DELAY );/* Wait a maximum of 100ms for either bit to be set. */

   if(uxBits && BIT_EVENT_BUTTON_PRESS) {
       printf("BUTTON PRESS\n");
       output_io_toggle(2);
   }
   if(uxBits && BIT_EVENT_UART_RECV){
      printf("UART DATA\n");
   }
}
}
// void vTask2( void * pvParameters )
// {
//     for( ;; )
//     {
//         printf("Task2\n");
//         vTaskDelay(1000 / portTICK_RATE_MS);// 1s
//     }
// }
// void vTask3( void * pvParameters )
// {
//     for( ;; )
//     {
//         printf("Task3\n");
//         vTaskDelay(1000 / portTICK_RATE_MS);// 1s
//     }
// }

void vTimerCallback( TimerHandle_t xTimer )
 {
     
      uint32_t ulCount;
    /* Optionally do something if the pxTimer parameter is NULL. */
    configASSERT( xTimer );

    /* The number of times this timer has expired is saved as the
    timer's ID.  Obtain the count. */
    ulCount = ( uint32_t ) pvTimerGetTimerID( xTimer );
    if(ulCount == 0 ){ //blink LED
       output_io_toggle(2);
    }else if(ulCount ==1){//print UART
       printf("Hello World\n");
    }
 }

void button_callback(int pin){
   if(pin == GPIO_NUM_0){
      BaseType_t xHigherPriorityTaskWoken;
         xEventGroupSetBitsFromISR(xEventGroup,    /* The event group being updated. */
                              BIT_EVENT_BUTTON_PRESS,&xHigherPriorityTaskWoken);/* The bits being set. */
   }
}

void app_main(void)//priority = 1 
{
     xTimers[0] = xTimerCreate("Timer_Blink",pdMS_TO_TICKS(500),pdTRUE,(void *) 0,vTimerCallback);
     xTimers[1] = xTimerCreate("Timer_Print",pdMS_TO_TICKS(1000),pdTRUE,(void *) 1,vTimerCallback);
     output_io_create(2);
     input_io_create(GPIO_NUM_0,HI_TO_LO);
     input_set_callback(button_callback);
   //   xTimerStart(xTimers[0],0);
   //   xTimerStart(xTimers[1],0);
     xEventGroup = xEventGroupCreate();
     //When call vTaskDelay then task will be blocked state 
    //Task3(call vTaskDelay --> blocked) --> Task2 --> Task1 
    /* Create the task, storing the handle. */
      xTaskCreate(  vTask1,       /* Function that implements the task. */
                    "vTask1",          /* Text name for the task. */
                     2048,      /* Stack size in words, not bytes. */
                    NULL,    /* Parameter passed into the task. */
                    4,/* Priority at which the task is created. */
                    NULL);      /* Used to pass out the created task's handle. */
    //   xTaskCreate(  vTask2,       /* Function that implements the task. */
    //                 "vTask2",          /* Text name for the task. */
    //                  1024,      /* Stack size in words, not bytes. */
    //                 NULL,    /* Parameter passed into the task. */
    //                 4,/* Priority at which the task is created. */
    //                 NULL);      /* Used to pass out the created task's handle. */
    //  xTaskCreate(  vTask3,       /* Function that implements the task. */
    //                 "vTask3",          /* Text name for the task. */
    //                  1024,      /* Stack size in words, not bytes. */
    //                 NULL,    /* Parameter passed into the task. */
    //                 4/* Priority at which the task is created. */
    //                 NULL);      /* Used to pass out the created task's handle. */
 
   //xTaskCreate(&hello_task, "hello_task", 2048, NULL, 5, NULL);
   
}
