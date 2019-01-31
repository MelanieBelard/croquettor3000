#include <stdio.h>

#include "potentiometer.h"

int getDurationFromPotentiometer(){
    uint16_t potentiometerValue = adc_read(nPotentiometer);
	int potentiometerToMs = (unsigned int) potentiometerValue * 100;
	int duration = pdMS_TO_TICKS(potentiometerToMs);
	printf(duration);
	return duration;
}
