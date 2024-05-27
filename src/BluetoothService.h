//
// Created by Anshul Gupta on 5/25/24.
//

#ifndef ESP32_FRIDGE_BLESERVICE_H
#define ESP32_FRIDGE_BLESERVICE_H

#include <BLEDevice.h>
#include <BLEServer.h>
#include <BLEUtils.h>

class BluetoothService {
public:
	virtual ~BluetoothService() = default;

	virtual void setup(BLEServer *server) = 0;
	virtual BLEUUID getUUID() = 0;

protected:
	BLEService *service = nullptr;
};


#endif//ESP32_FRIDGE_BLESERVICE_H
