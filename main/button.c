#include <stdio.h>

#include "esp_system.h"
#include "driver/gpio.h"

bool read_btn(int btn){

    int n = gpio_get_level(btn) ;

    return n;

    // printf("Etat bouton : \n");
    //
    // char str[10] = "";
    // sprintf(str, "%d \n", n);
    // printf("%d \n", n);
    //
    // if(n == 0){
    //
    //     printf("n = 0 ");
    //
    // } else {
    //
    //     printf("n = autre chose ");
    //
    // }
    //
    // return true;
}
