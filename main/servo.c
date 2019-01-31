#include <stdio.h>

#include "esp_system.h"
#include "driver/gpio.h"
#include "potentiometer.h"

void motorAction(duration){
  servo.write(90);
  delay(duration);
  servo.write(0);

}
