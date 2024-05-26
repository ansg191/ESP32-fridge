//
// Created by Anshul Gupta on 5/25/24.
//

#ifndef ESP32_FRIDGE_TIMESERVICE_H
#define ESP32_FRIDGE_TIMESERVICE_H

#include "../BluetoothService.h"

namespace ble_services {

class TimeService : public BluetoothService {
public:
	TimeService() = default;

	void setup(BLEServer *server) override;
	BLEUUID getUUID() override;

private:
	BLECharacteristic *getTime = nullptr;
	BLECharacteristic *setTime = nullptr;

	static BLEUUID SERVICE_UUID;
	static BLEUUID GET_TIME_UUID;
	static BLEUUID SET_TIME_UUID;
};

}// namespace ble_services

#endif//ESP32_FRIDGE_TIMESERVICE_H
