#include <stdio.h>

#include "potentiometer.h"

int getDurationFromPotentiometer(int nPotentiometer){
    int potentiometerValue = GetADC(nPotentiometer);
	int potentiometerToMs = potentiometerValue * 100;
	int duration = pdMS_TO_TICKS(potentiometerToMs);
	printf(duration);
	return duration;
}
