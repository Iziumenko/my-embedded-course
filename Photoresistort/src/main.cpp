#include <Arduino.h>
#include <driver/gpio.h>
#include <stdlib.h>

#define INPUT_PIN 5
#define LED_PIN 6
// put function declarations here:


void setup() {
  // put your setup code here, to run once:
  pinMode(INPUT_PIN,INPUT);
  pinMode(LED_PIN,OUTPUT);
 
  Serial.begin(115200);

}

void loop() {
   int photo_resistor_value = analogRead(INPUT_PIN);
  if(photo_resistor_value < 3000){
    digitalWrite(LED_PIN,HIGH);
    Serial.println("LED is ON");
  }
  else{
    digitalWrite(LED_PIN,LOW);
    ;
  }
  Serial.println(photo_resistor_value);
  delay(1000);
  // put your main code here, to run repeatedly:
}

// put function definitions here:
