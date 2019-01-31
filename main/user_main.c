/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include <unistd.h>

#include "config.h"
#include "led.h"
#include "button.h"
#include "potentiometer.h"
#include "esp_system.h"
#include "driver/gpio.h"


/******************************************************************************
 * FunctionName : app_main
 * Description  : entry of user application, init user function here
 * Parameters   : none
 * Returns      : none
*******************************************************************************/
void app_main(void)
{
    // printf("SDK version:%s\n", esp_get_idf_version());

    config();

    int red    = GPIO_NUM_4;
    int yellow = GPIO_NUM_5;
    int green  = GPIO_NUM_16;

    int btn    = GPIO_NUM_2;

    int infrared = GPIO_NUM_14;
    int motor = GPIO_NUM_12;

    // if (!read_btn(btn)) {
    //   switch_on(red);
    // }
    //
    // if (read_btn(btn)) {
    //   switch_off(red);
    // }

    switch_on(red);
    switch_off(red);

    switch_on(yellow);
    switch_off(yellow);

    switch_on(green);
    switch_off(green);

    getDurationFromPotentiometer();
}
