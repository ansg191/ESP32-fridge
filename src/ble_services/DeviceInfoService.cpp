//
// Created by Anshul Gupta on 5/25/24.
//

#include "DeviceInfoService.h"

namespace ble_services {

//BLEUUID DeviceInfoService::SERVICE_UUID = BLEUUID((uint16_t) 0x180A);
BLEUUID DeviceInfoService::SERVICE_UUID = BLEUUID("926c28b7-78e4-4702-a61f-6d59a3d92ef5");
//BLEUUID DeviceInfoService::NAME_UUID = BLEUUID((uint16_t) 0x2A00);
BLEUUID DeviceInfoService::NAME_UUID = BLEUUID("a39f17f5-04d1-4b92-9463-f929207076b4");
BLEUUID DeviceInfoService::VERSION_UUID = BLEUUID((uint16_t) 0x2A28);

const char *NAME = "ESP32 Fridge";
const int VERSION = 1;

void DeviceInfoService::setup(BLEServer *server)
{
	service = server->createService(SERVICE_UUID);

	name = service->createCharacteristic(
	        NAME_UUID,
	        BLECharacteristic::PROPERTY_READ);
	name->setValue(NAME);

	version = service->createCharacteristic(
	        VERSION_UUID,
	        BLECharacteristic::PROPERTY_READ);
	int v = VERSION;
	version->setValue(v);

	service->start();
}

BLEUUID DeviceInfoService::getUUID()
{
	return SERVICE_UUID;
}
}// namespace ble_services