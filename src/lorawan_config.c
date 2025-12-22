#include <zephyr/logging/log.h>
#include <zephyr/sys/util.h>
#include <stdio.h>

#include "lorawan_config.h"

LOG_MODULE_REGISTER(lora_cfg, LOG_LEVEL_INF);

static void print_hex(const char *label, const uint8_t *buf, size_t len)
{
    char out[128];
    size_t pos = 0;

    for (size_t i = 0; i < len; i++) {
        if (pos + 2 >= sizeof(out)) {
            break;
        }
        pos += snprintk(&out[pos], sizeof(out) - pos, "%02X", buf[i]);
    }

    out[MIN(pos, sizeof(out) - 1)] = 0;
    LOG_INF("%s: %s", label, out);
}

void lorawan_config_dump(void)
{
    LOG_INF("========== LoRaWAN CONFIG ==========");
    LOG_INF("Region           : %s", LORAWAN_REGION_STR);
    LOG_INF("Class            : %s", LORAWAN_CLASS_STR);
    LOG_INF("LoRaWAN Version  : %s", LORAWAN_VERSION_STR);

    LOG_INF("FPort            : %d", LORAWAN_FPORT);
    LOG_INF("Confirmed Uplink : %d", LORAWAN_CONFIRMED_UPLINK);
    LOG_INF("ADR Enabled      : %d", LORAWAN_ADR_ENABLED);

    LOG_INF("TX Interval (s)  : %d", TX_INTERVAL_SECONDS);

    print_hex("DevEUI",  DEV_EUI,  sizeof(DEV_EUI));
    print_hex("JoinEUI", JOIN_EUI, sizeof(JOIN_EUI));
    print_hex("AppKey",  APP_KEY,  sizeof(APP_KEY));

    LOG_INF("===================================");
}
