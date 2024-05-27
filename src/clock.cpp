//
// Created by Anshul Gupta on 5/26/24.
//

#include <Arduino.h>

#include "clock.h"

/// TIM0 flag
volatile bool timeFlag;

/// TIM0 instance
static hw_timer_t *timer = nullptr;

/// TIM0 ISR routine. Stored in IRAM.
void IRAM_ATTR Timer0_ISR()
{
	timeFlag = true;
}

void enableTimer(uint64_t interval_ms)
{
	// Tim0 is a 80MHz clock with a 16-bit prescaler and a 64-bit counter.
	// Prescaler is hard-coded to 80. This gives us a 1MHz clock.
	// 80MHz / 80 = 1MHz. 1Mhz = 1us.
	uint16_t prescaler = 80;

	// Calculate the counter value.
	uint64_t counter = interval_ms * 1000;

	// Provision the timer. Timer0 counting-up with a prescaler of 80.
	timer = timerBegin(0, prescaler, true);

	// Attach the ISR to the timer.
	timerAttachInterrupt(timer, &Timer0_ISR, true);

	// Set the alarm value and enable auto-reload.
	timerAlarmWrite(timer, counter, true);

	// Set flag to false.
	timeFlag = false;

	// Enable the timer.
	timerAlarmEnable(timer);
}
