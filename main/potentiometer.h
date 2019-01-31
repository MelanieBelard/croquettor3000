#include <stdio.h>

#include "esp_system.h"
#include "driver/gpio.h"
#include "config.h"
#include "driver/adc.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"


int getDurationFromPotentiometer();
