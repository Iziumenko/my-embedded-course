#include <Arduino.h>
#include <stdlib.h>



#define BOOT_BUTTON GPIO_NUM_0
#define LED GPIO_NUM_6
#define BUTTON GPIO_NUM_35
#define CONST_PERIOD 250





uint32_t last_time;
uint32_t current_time;
uint32_t boot_button_time;
bool bt_boot = false ;
bool led_on = false;
int period = 125;

int speedchange(bool button_state);

void setup() {

Serial.begin(115200);
Serial.println("Setup is done");
int variing_period = period;
pinMode(BUTTON, INPUT_PULLDOWN);
pinMode(LED, OUTPUT);
}

void loop() {
  current_time = millis();
   
  if (digitalRead(GPIO_NUM_0) == 0  && (current_time - boot_button_time) > CONST_PERIOD) {
   boot_button_time = current_time;
    bt_boot= true;
    period*=2;
    Serial.println("Speed is lower 2x than before");
  }

  if (digitalRead(GPIO_NUM_35) == HIGH  && (current_time - last_time) > CONST_PERIOD) {
   last_time = current_time;
    bt_boot= false;
    period/=2;
    Serial.println("Speed is higher 2x than before");
  }

digitalWrite(GPIO_NUM_6, HIGH);
delay(period);
digitalWrite(GPIO_NUM_6, LOW);
delay(period);


}



 