//
// Created by Anshul Gupta on 5/25/24.
//

#ifndef ESP32_FRIDGE_DEVICEINFOSERVICE_H
#define ESP32_FRIDGE_DEVICEINFOSERVICE_H

#include "../BluetoothService.h"

namespace ble_services {

class DeviceInfoService : public BluetoothService {
public:
	DeviceInfoService() = default;

	void setup(BLEServer *server) override;
	BLEUUID getUUID() override;

private:
	BLECharacteristic *name = nullptr;
	BLECharacteristic *version = nullptr;

	static BLEUUID SERVICE_UUID;
	static BLEUUID NAME_UUID;
	static BLEUUID VERSION_UUID;
};

}// namespace ble_services

#endif//ESP32_FRIDGE_DEVICEINFOSERVICE_H
