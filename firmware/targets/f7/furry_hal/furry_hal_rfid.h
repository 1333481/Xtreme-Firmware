/**
 * @file furry_hal_rfid.h
 * RFID HAL API
 */

#pragma once

#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/** Initialize RFID subsystem
 */
void furry_hal_rfid_init();

/** Config rfid pins to reset state
 */
void furry_hal_rfid_pins_reset();

/** Config rfid pins to emulate state
 */
void furry_hal_rfid_pins_emulate();

/** Config rfid pins to read state
 */
void furry_hal_rfid_pins_read();

/** Release rfid pull pin
 */
void furry_hal_rfid_pin_pull_release();

/** Pulldown rfid pull pin
 */
void furry_hal_rfid_pin_pull_pulldown();

/** Config rfid timer to read state
 *
 * @param      freq        timer frequency
 * @param      duty_cycle  timer duty cycle, 0.0-1.0
 */
void furry_hal_rfid_tim_read(float freq, float duty_cycle);

/** Start read timer
 */
void furry_hal_rfid_tim_read_start();

/** Stop read timer
 */
void furry_hal_rfid_tim_read_stop();

/** Config rfid timer to emulate state
 *
 * @param      freq  timer frequency
 */
void furry_hal_rfid_tim_emulate(float freq);

typedef void (*FurryHalRfidEmulateCallback)(void* context);

/** Start emulation timer
 */
void furry_hal_rfid_tim_emulate_start(FurryHalRfidEmulateCallback callback, void* context);

typedef void (*FurryHalRfidReadCaptureCallback)(bool level, uint32_t duration, void* context);

void furry_hal_rfid_tim_read_capture_start(FurryHalRfidReadCaptureCallback callback, void* context);

void furry_hal_rfid_tim_read_capture_stop();

typedef void (*FurryHalRfidDMACallback)(bool half, void* context);

void furry_hal_rfid_tim_emulate_dma_start(
    uint32_t* duration,
    uint32_t* pulse,
    size_t length,
    FurryHalRfidDMACallback callback,
    void* context);

void furry_hal_rfid_tim_emulate_dma_stop();

/** Stop emulation timer
 */
void furry_hal_rfid_tim_emulate_stop();

/** Config rfid timers to reset state
 */
void furry_hal_rfid_tim_reset();

/** Set emulation timer period
 *
 * @param      period  overall duration
 */
void furry_hal_rfid_set_emulate_period(uint32_t period);

/** Set emulation timer pulse
 *
 * @param      pulse  duration of high level
 */
void furry_hal_rfid_set_emulate_pulse(uint32_t pulse);

/** Set read timer period
 *
 * @param      period  overall duration
 */
void furry_hal_rfid_set_read_period(uint32_t period);

/** Set read timer pulse
 *
 * @param      pulse  duration of high level
 */
void furry_hal_rfid_set_read_pulse(uint32_t pulse);

/** Сhanges the configuration of the RFID timer "on a fly"
 *
 * @param      freq        new frequency
 * @param      duty_cycle  new duty cycle
 */
void furry_hal_rfid_change_read_config(float freq, float duty_cycle);

/** Start/Enable comparator */
void furry_hal_rfid_comp_start();

/** Stop/Disable comparator */
void furry_hal_rfid_comp_stop();

typedef void (*FurryHalRfidCompCallback)(bool level, void* context);

/** Set comparator callback */
void furry_hal_rfid_comp_set_callback(FurryHalRfidCompCallback callback, void* context);

#ifdef __cplusplus
}
#endif
