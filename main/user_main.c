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
#include "servo.h"


/******************************************************************************
 * FunctionName : app_main
 * Description  : entry of user application, init user function here
 * Parameters   : none
 * Returns      : none
*******************************************************************************/
void app_main(void)
{

    config();

    int red    = GPIO_NUM_4;
    int yellow = GPIO_NUM_5;
    int green  = GPIO_NUM_16;

    int btn    = GPIO_NUM_2;


    int infrared = GPIO_NUM_14;
    int servo = GPIO_NUM_12;

    while (true) {
        bool btnState = read_btn(btn);
        printf("Bouton (bool) : %d \n", btnState);
        sleep(1);

        switch_on(red);
        sleep(1);
        switch_off(red);

        sleep(1);
        switch_on(yellow);
        sleep(1);
        switch_off(yellow);

        sleep(1);
        switch_on(green);
        sleep(1);
        switch_off(green);

        sleep(1);
        switch_on(yellow);
        sleep(1);
        switch_off(yellow);
    }

    // int duration = getDurationFromPotentiometer();
    // motorAction(duration);


}
