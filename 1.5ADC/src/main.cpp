#include <Arduino.h>
#include <stdlib.h>

#define BUTTON_LEFT 5
#define BUTTON_RIGHT 6
#define DEBOUNCE_TIME 250

int16_t counter_left = 0;
int16_t counter_right = 0;
uint32_t current_time = 0;
int16_t loop_counter_left = 0;
int16_t loop_counter_right = 0;
uint32_t last_time=0;
bool button_left_state = false;
bool button_right_state = false;


/*  void IRAM_ATTR handleButtonLeft() {
  counter_left++;
  Serial.print("Counter left: ");
  Serial.println(counter_left);
}
void IRAM_ATTR handleButtonRight() {
  counter_right++;
  Serial.print("Counter right: ");
  Serial.println(counter_right);
}  */



void setup() {
  Serial.begin(115200);
  pinMode(BUTTON_LEFT,INPUT_PULLDOWN);
  pinMode(BUTTON_RIGHT,INPUT_PULLDOWN);
  /* attachInterrupt(BUTTON_LEFT, handleButtonLeft, FALLING);
  attachInterrupt(BUTTON_RIGHT, handleButtonRight, FALLING); */
  
  Serial.println("Setup complete");
}

void loop() {
  current_time = millis();
  if(digitalRead(BUTTON_LEFT) == HIGH && (current_time - last_time) >= DEBOUNCE_TIME&& button_left_state == false){
    loop_counter_left++;
    Serial.print("Loop counter left is: ");
    Serial.println(loop_counter_left);
    last_time = current_time;
    button_left_state = true;
  }
  if(digitalRead(BUTTON_RIGHT) == HIGH && (current_time - last_time) >= DEBOUNCE_TIME&& button_right_state == false){
    loop_counter_right++;
    Serial.print("Loop counter right is: ");
    Serial.println(loop_counter_right);
    last_time = current_time;
    button_right_state = true;
  }
  if(digitalRead(BUTTON_LEFT) == LOW){
    button_left_state = false;
  }
  if(digitalRead(BUTTON_RIGHT) == LOW){
    button_right_state = false;
  }
  // put your main code here, to run repeatedly:
}

