#pragma once
#include <stdint.h>
#include <stdbool.h>

#ifdef __cplusplus
extern "C" {
#endif

/* ========== LoRaWAN Configuration (from specification) ========== */

/* General */
#define LORAWAN_REGION_STR          "EU868"
#define LORAWAN_CLASS_STR           "A"
#define LORAWAN_VERSION_STR         "1.0.3"

/* Uplink settings */
#define LORAWAN_FPORT               1
#define LORAWAN_CONFIRMED_UPLINK    1
#define LORAWAN_ADR_ENABLED         1

/* Transmission interval
 * QEMU test value: 10 seconds
 * Real device value: 600 seconds
 */
#define TX_INTERVAL_SECONDS         10

/* OTAA credentials (PLACEHOLDER)
 * Fill real values when moving to real hardware
 */
static const uint8_t DEV_EUI[8]  = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

static const uint8_t JOIN_EUI[8] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

static const uint8_t APP_KEY[16] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00
};

/* Print configuration to log */
void lorawan_config_dump(void);

#ifdef __cplusplus
}
#endif
