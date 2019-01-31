#include <stdio.h>

#include "esp_system.h"
#include "driver/gpio.h"

bool read_btn(int btn){
    int n = gpio_get_level(btn) ;
    return n;
}
