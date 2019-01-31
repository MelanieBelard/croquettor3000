#include <stdio.h>

#include "button.h"
#include "esp_system.h"
#include "driver/gpio.h"



void nyehehe() {
  // printf("NYEHEHE HEHEHEHEH HEHEHE!!!\n");
  gpio_set_level(GPIO_NUM_4, 0);
}

void config(){

  gpio_install_isr_service(0);

  printf("Configuration pin D2 (led rouge) \n");
      gpio_config_t red;
      red.mode = GPIO_MODE_OUTPUT ;
      red.pin_bit_mask = GPIO_Pin_4;
      red.intr_type = GPIO_INTR_DISABLE;
      red.pull_down_en = 0;
      red.pull_up_en = 0;
      gpio_config(&red);

  printf("Configuration pin D0 (led verte) \n");
      gpio_config_t green;
      green.mode = GPIO_MODE_OUTPUT ;
      green.pin_bit_mask = GPIO_Pin_16;
      green.intr_type = GPIO_INTR_DISABLE;
      green.pull_down_en = 0;
      green.pull_up_en = 0;
      gpio_config(&green);

  printf("Configuration pin D1 (led jaune) \n");
      gpio_config_t yellow;
      yellow.mode = GPIO_MODE_OUTPUT ;
      yellow.pin_bit_mask = GPIO_Pin_5;
      yellow.intr_type = GPIO_INTR_DISABLE;
      yellow.pull_down_en = 0;
      yellow.pull_up_en = 0;
      gpio_config(&yellow);

  printf("Configuration pin D4 \n");
      gpio_config_t btn;
      btn.mode = GPIO_MODE_INPUT;
      btn.pin_bit_mask = GPIO_Pin_2;
      btn.intr_type = GPIO_INTR_NEGEDGE;
      btn.pull_down_en = 0;
      btn.pull_up_en = 0;
      gpio_config(&btn);
      gpio_isr_handler_add(GPIO_NUM_2, nyehehe, NULL);



}
