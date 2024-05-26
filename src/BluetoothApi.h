//
// Created by Anshul Gupta on 5/25/24.
//

#ifndef ESP32_FRIDGE_BLUETOOTHAPI_H
#define ESP32_FRIDGE_BLUETOOTHAPI_H

#include "BLEService.h"
#include "ble_services/DeviceInfoService.h"
#include "ble_services/TempService.h"
#include "ble_services/TimeService.h"

class BluetoothApi {
public:
	BluetoothApi() = default;

	void setup();

	void setCoolerTemp(float value);
	void setAmbientTemp(float value);
	void setWaterTemp(float value);

private:
	BLEServer *server = nullptr;
	BLEAdvertising *advertising = nullptr;

	ble_services::DeviceInfoService gapService;
	ble_services::TempService tempService;
	ble_services::TimeService timeService;
	//	BLEService *storageService = nullptr;
};


#endif//ESP32_FRIDGE_BLUETOOTHAPI_H
