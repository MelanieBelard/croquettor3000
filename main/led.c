#include <stdio.h>

#include "esp_system.h"
#include "driver/gpio.h"
#include "config.h"

void switch_on(int nLed){
    gpio_set_level(nLed, 1) ;
}

void switch_off(int nLed){
    gpio_set_level(nLed, 0) ;
}
