#include <Arduino.h>



#define LED (5)
#define LED2 (6)
#define BLINK_DELAY_MS (125)
#define BAUDRATE (115200)
#define SPEEDCHANGE (17)
bool switchState = false;
uint32_t startTime = 0;
uint32_t lastTime = 0;
uint32_t interval = 0;
void setup() {
  
  pinMode(LED,OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(SPEEDCHANGE,INPUT_PULLDOWN);
  // put your setup code here, to run once:
 Serial.begin(BAUDRATE);
 Serial.println("Start");
 startTime = millis();
 
}



void loop() {
  
  int speedChange=analogRead(SPEEDCHANGE);
  interval = BLINK_DELAY_MS+map(speedChange,20,64,0,1000);
  if (!switchState&& (millis() - lastTime) >= interval)
  {
    digitalWrite(LED,LOW);
    digitalWrite(LED2,HIGH);
    switchState = true;
    Serial.print("Interval1: ");
    Serial.println(interval);
    lastTime = millis();
  }
  if (switchState && (millis() - lastTime) >= interval)
  {
    digitalWrite(LED,HIGH);
    digitalWrite(LED2,LOW);
    switchState = false;
    Serial.print("Interval2: ");
    Serial.println(interval);
    lastTime = millis();
  }
  
}

