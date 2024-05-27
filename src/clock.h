//
// Created by Anshul Gupta on 5/26/24.
//

#ifndef ESP32_FRIDGE_CLOCK_H
#define ESP32_FRIDGE_CLOCK_H

/**
 * @brief Flag to indicate that the timer has triggered.
 *
 * Set back to false when the timer is handled.
 */
extern volatile bool timeFlag;

/**
 * @brief Enable the timer with the given interval.
 *
 * The timer will trigger the timeFlag when the interval has passed.
 *
 * @param interval_ms The interval in milliseconds.
 */
void enableTimer(uint64_t interval_ms);

#endif//ESP32_FRIDGE_CLOCK_H
