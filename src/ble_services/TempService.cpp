//
// Created by Anshul Gupta on 5/25/24.
//

#include "TempService.h"

namespace ble_services {

BLEUUID TempService::SERVICE_UUID = BLEUUID("3cfc3156-2944-489c-b82d-554c3c422281");
BLEUUID TempService::COOLER_UUID = BLEUUID("dd45aa1d-a42d-4ada-8cc6-6bbb87b681b0");
BLEUUID TempService::AMBIENT_UUID = BLEUUID("ecbc2ad7-c41b-4b67-95b6-865255a8cb59");
BLEUUID TempService::WATER_UUID = BLEUUID("fee1b7f3-5e0f-47eb-964d-8d5913e0ca86");

void TempService::setup(BLEServer *server)
{
	float initial_temp = 0.0;
	service = server->createService(TempService::SERVICE_UUID);

	cooler = service->createCharacteristic(
	        COOLER_UUID,
	        BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
	cooler->setValue(initial_temp);

	ambient = service->createCharacteristic(
	        AMBIENT_UUID,
	        BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
	ambient->setValue(initial_temp);

	water = service->createCharacteristic(
	        WATER_UUID,
	        BLECharacteristic::PROPERTY_READ | BLECharacteristic::PROPERTY_NOTIFY);
	water->setValue(initial_temp);

	service->start();
}

BLEUUID TempService::getUUID()
{
	return TempService::SERVICE_UUID;
}

void TempService::setCooler(float value)
{
	cooler->setValue(value);
	cooler->notify();
}

void TempService::setAmbient(float value)
{
	ambient->setValue(value);
	ambient->notify();
}

void TempService::setWater(float value)
{
	water->setValue(value);
	water->notify();
}

}// namespace ble_services
