#include <Arduino.h>

#include "BluetoothApi.h"
#include "clock.h"

#define LED_PIN 2

static BluetoothApi bApi;

void setup()
{
	Serial.begin(9600);

	pinMode(LED_PIN, OUTPUT);
	digitalWrite(LED_PIN, LOW);

	enableTimer(1000);

	bApi.setup();

	Serial.println("Ready!");
}

void loop()
{
	if (timeFlag) {
		digitalWrite(LED_PIN, !digitalRead(LED_PIN));
		timeFlag = false;
	}
}
