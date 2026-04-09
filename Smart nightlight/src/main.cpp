#include <ESP32Servo.h>
#include <esp_adc_cal.h>



#define LED_PIN 6
#define LIGHT_SENSOR_PIN 5
#define READ_RESOLUTION 12
#define READ_FREQUENCY 20




ESP32PWM pwm;
int freq = 5000;
void setup() {
	// Allow allocation of all timers
	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);
	Serial.begin(115200);
	pwm.attachPin(LED_PIN, freq, 12); // 1KHz 10 bits

}
void loop() {

	// fade the LED on thisPin from off to brightest:
	for (float brightness = 0; brightness <= 0.5; brightness += 0.0001) {
		// Write a unit vector value from 0.0 to 1.0
		pwm.writeScaled(brightness);
		delay(2);
	}
	//delay(1000);
	// fade the LED on thisPin from brithstest to off:
	for (float brightness = 0.5; brightness >= 0; brightness -= 0.0001) {
		
		// Adjust the frequency on the fly with a specific brightness
		// Frequency is in herts and duty cycle is a unit vector 0.0 to 1.0
		pwm.adjustFrequency(freq, brightness); // update the time base of the PWM
		delay(2);
	}
	// pause between LEDs:
	delay(1000);
	freq = 5000;
	pwm.adjustFrequency(freq, 0.0);    // reset the time base
}