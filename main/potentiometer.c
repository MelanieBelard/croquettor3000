#include <stdio.h>

#include "esp_system.h"
#include "driver/gpio.h"
#include "config.h"

int getDurationFromPotentiometer(int nPotentiometer){
    int potentiometerValue = GetADC(nPotentiometer)
	potentiometerToMs = potentiometerValue * 100;
	duration = pdMS_TO_TICKS(potentiometerToMs);
	printf(duration);
	return duration;
}
