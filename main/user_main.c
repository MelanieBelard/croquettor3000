/*
   This example code is in the Public Domain (or CC0 licensed, at your option.)

   Unless required by applicable law or agreed to in writing, this
   software is distributed on an "AS IS" BASIS, WITHOUT WARRANTIES OR
   CONDITIONS OF ANY KIND, either express or implied.
*/

#include <stdio.h>
#include <unistd.h>

#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"

#include "esp_log.h"
#include "esp_system.h"
#include "esp_err.h"

#include "esp8266/gpio_register.h"
#include "esp8266/pin_mux_register.h"

#include "driver/pwm.h"


#include "config.h"
#include "led.h"
#include "button.h"
#include "potentiometer.h"
#include "esp_system.h"
#include "driver/gpio.h"

#define PWM_0_OUT_IO_NUM   12
#define PWM_1_OUT_IO_NUM   13
#define PWM_2_OUT_IO_NUM   14
#define PWM_3_OUT_IO_NUM   15

// PWM period 500us(2Khz), same as depth
#define PWM_PERIOD    (500)

static const char *TAG = "pwm_example";

// pwm pin number
const uint32_t pin_num[4] = {
    PWM_0_OUT_IO_NUM,
    PWM_1_OUT_IO_NUM,
    PWM_2_OUT_IO_NUM,
    PWM_3_OUT_IO_NUM
};

// dutys table, (duty/PERIOD)*depth
uint32_t duties[4] = {
    250, 250, 250, 250,
};

// phase table, (phase/180)*depth
int16_t phase[4] = {
    0, 0, 50, -50,
};

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
    int servo = GPIO_NUM_12;

    bool btnState = read_btn(btn);

    printf("%d \n", btnState);


    int duration = getDurationFromPotentiometer();

    pwm_init(PWM_PERIOD, duties, 4, pin_num);
    pwm_set_channel_invert(0x1 << 0);

    pwm_set_phases(phase);
    pwm_start();
    int16_t count = 0;

    while (1) {
        if (count == 20) {
            //channel0, 1 output hight level.
            //channel2, 3 output low level.
            pwm_stop(0x3);
            ESP_LOGI(TAG, "PWM stop\n");
        } else if (count == 30) {
            pwm_start();
            ESP_LOGI(TAG, "PWM re-start\n");
            count = 0;
        }

        count++;
        vTaskDelay(1000 / portTICK_RATE_MS);
    }



    //
    // switch_on(red);
    // switch_off(red);
    //
    // switch_on(green);
    // switch_off(green);
    //
    // switch_on(yellow);
    // switch_off(yellow);


}
