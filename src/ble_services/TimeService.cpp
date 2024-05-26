//
// Created by Anshul Gupta on 5/25/24.
//

#include <ESP32Time.h>

#include "TimeService.h"

namespace ble_services {

static ESP32Time rtc;

uint64_t from_bytes(const uint8_t *data, size_t len);

//BLEUUID TimeService::SERVICE_UUID = BLEUUID((uint16_t) 0x1847);
BLEUUID TimeService::SERVICE_UUID = BLEUUID("db7b23f7-9cb9-4411-b7c0-73105fe56919");
//BLEUUID TimeService::GET_TIME_UUID = BLEUUID((uint16_t) 0x2A2B);
BLEUUID TimeService::GET_TIME_UUID = BLEUUID("8b7bfc03-2a3e-44d7-833a-17917eb180f2");
BLEUUID TimeService::SET_TIME_UUID = BLEUUID("65625049-d533-4c6c-9c2b-b2a1291d146f");

class GetTimeCallbacks : public BLECharacteristicCallbacks {
public:
	void onRead(BLECharacteristic *pCharacteristic) override
	{
		uint32_t current_time = rtc.getEpoch();
		pCharacteristic->setValue(current_time);
	}
};

class SetTimeCallbacks : public BLECharacteristicCallbacks {
public:
	void onWrite(BLECharacteristic *pCharacteristic) override
	{
		uint8_t *data = pCharacteristic->getData();
		size_t len = pCharacteristic->getLength();

		rtc.setTime(from_bytes(data, len));
	}
};

void TimeService::setup(BLEServer *server)
{
	service = server->createService(TimeService::SERVICE_UUID);

	getTime = service->createCharacteristic(
	        GET_TIME_UUID,
	        BLECharacteristic::PROPERTY_READ);
	getTime->setCallbacks(new GetTimeCallbacks());

	setTime = service->createCharacteristic(
	        SET_TIME_UUID,
	        BLECharacteristic::PROPERTY_WRITE);
	setTime->setCallbacks(new SetTimeCallbacks());

	service->start();
}

BLEUUID TimeService::getUUID()
{
	return TimeService::SERVICE_UUID;
}

uint64_t from_bytes(const uint8_t *data, size_t len)
{
	uint64_t value = 0;
	for (size_t i = 0; i < len; i++) {
		uint64_t tmp = data[i];
		value |= tmp << (i * 8);
	}
	return value;
}


}// namespace ble_services