//
// Created by Anshul Gupta on 5/25/24.
//

#ifndef ESP32_FRIDGE_TEMPSERVICE_H
#define ESP32_FRIDGE_TEMPSERVICE_H

#include "../BluetoothService.h"

namespace ble_services {

class TempService : public BluetoothService {
public:
	TempService() = default;

	void setup(BLEServer *server) override;
	BLEUUID getUUID() override;

	void setCooler(float value);
	void setAmbient(float value);
	void setWater(float value);

private:
	BLECharacteristic *cooler = nullptr;
	BLECharacteristic *ambient = nullptr;
	BLECharacteristic *water = nullptr;

	static BLEUUID SERVICE_UUID;
	static BLEUUID COOLER_UUID;
	static BLEUUID AMBIENT_UUID;
	static BLEUUID WATER_UUID;
};

}// namespace ble_services

#endif//ESP32_FRIDGE_TEMPSERVICE_H
