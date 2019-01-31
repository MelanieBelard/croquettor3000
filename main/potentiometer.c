#include <stdio.h>

#include "esp_system.h"
#include "driver/gpio.h"
#include "config.h"

int getDurationFromPotentiometer(int nPotentiometer){
	potentiometerToMs = nPotentiometer * 100;
	duration = pdMS_TO_TICKS(potentiometerToMs);
	printf(duration);
	return duration
};
