#include <stdio.h>                      /* standard io library*/
#include "driver/gpio.h"               /* gpio driver code  header file */
#include "freertos/FreeRTOS.h"        /* freertos header file */
#include "freertos/task.h"           /* task header file in freertos */

/*  marco for buzzer_pin */
#define BUZZER_PIN 23         

void app_main(void)
{
  esp_rom_gpio_pad_select_gpio(BUZZER_PIN);             /*selecting the buzzer_pin in the gpio_pins */  
  gpio_set_direction(BUZZER_PIN, GPIO_MODE_OUTPUT);   /* setting the Buzzer_pin in output direction*/
  int flag = 0;                                     /* flag to  toggle the state of the buzzer_pin */
  
while(true)          /*infinite while loop*/
{
   flag = !flag;
   gpio_set_level(BUZZER_PIN, flag);   /* setting the buzzer pin with flag */
   vTaskDelay(10);                    /* delay function with 10ms delay*/
}
}
