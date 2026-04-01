#include <Arduino.h>
#include <driver/gpio.h>
#include <stdlib.h>


#define period 250




gpio_config_t io_conf{},led_conf{};
uint32_t last_time;
uint32_t current_time;
uint32_t boot_button_time;
bool any_button_pressed ;
bool led_on = false;

void setup() {
io_conf.pin_bit_mask = (1ULL<<GPIO_NUM_0) | (1ULL<<GPIO_NUM_35);
io_conf.mode = GPIO_MODE_INPUT;
io_conf.pull_up_en = GPIO_PULLUP_ENABLE;
io_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;
io_conf.intr_type = GPIO_INTR_DISABLE;
led_conf.pin_bit_mask = (1ULL<<GPIO_NUM_6);
led_conf.mode = GPIO_MODE_OUTPUT;
led_conf.pull_up_en = GPIO_PULLUP_DISABLE;
led_conf.pull_down_en = GPIO_PULLDOWN_DISABLE;  
led_conf.intr_type = GPIO_INTR_DISABLE;

  gpio_config(&io_conf);
  gpio_config(&led_conf);
Serial.begin(115200);
Serial.println("Setup is done");
}

void loop() {
  current_time = millis();
  any_button_pressed = false;
  if (gpio_get_level(GPIO_NUM_0) == 0  && (current_time - boot_button_time) > period) {
    Serial.println("Boot button is pressed");
    
    boot_button_time = current_time;
    any_button_pressed = true;
    led_on = !led_on;
  }

  if (gpio_get_level(GPIO_NUM_35) == 1  && (current_time - last_time) > period) {
    Serial.println("Button is pressed");
    last_time = current_time;
    any_button_pressed = true;
    gpio_set_level(GPIO_NUM_6, 1);
    led_on = !led_on;
  }
  if(led_on ){
    gpio_set_level(GPIO_NUM_6, 1);
  }
 else{
    gpio_set_level(GPIO_NUM_6, 0);
  }
}