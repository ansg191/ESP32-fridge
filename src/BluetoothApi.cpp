//
// Created by Anshul Gupta on 5/25/24.
//

#include <Arduino.h>

#include "BluetoothApi.h"

class ServerCallbacks : public BLEServerCallbacks {
public:
	void onConnect(BLEServer *pServer) override
	{
		Serial.println("Connected");
		pServer->startAdvertising();
	}
	void onDisconnect(BLEServer *pServer) override
	{
		Serial.println("Disconnected");
		pServer->startAdvertising();
	}
};

void BluetoothApi::setup()
{
	BLEDevice::init("ESP32 Fridge");

	server = BLEDevice::createServer();
	server->setCallbacks(new ServerCallbacks());

	gapService.setup(server);
	tempService.setup(server);
	timeService.setup(server);

	advertising = BLEDevice::getAdvertising();
	advertising->addServiceUUID(gapService.getUUID());
	advertising->addServiceUUID(tempService.getUUID());
	advertising->addServiceUUID(timeService.getUUID());
	advertising->setScanResponse(true);
	advertising->setMinPreferred(0x06);
	advertising->setMinPreferred(0x12);

	BLEDevice::startAdvertising();
}

void BluetoothApi::setCoolerTemp(float value)
{
	tempService.setCooler(value);
}

void BluetoothApi::setAmbientTemp(float value)
{
	tempService.setAmbient(value);
}

void BluetoothApi::setWaterTemp(float value)
{
	tempService.setWater(value);
}
