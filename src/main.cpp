#include <Arduino.h>

#include "BluetoothApi.h"

#define LED_PIN 2

static BluetoothApi bApi;
static int i = 0;

void setup()
{
	Serial.begin(9600);
	Serial.println("Hello World!");
	pinMode(LED_PIN, OUTPUT);
	digitalWrite(LED_PIN, LOW);

	bApi.setup();

	Serial.println("Ready!");
}

void loop()
{
//	bApi.set_current_temperature((float) i);
//	i++;
//	delay(1000);
}