#include <stdio.h>

#include "esp_system.h"
#include "driver/gpio.h"
#include "freertos/task.h"
#include "config.h"


int getDurationFromPotentiometer(int nPotentiometer);
