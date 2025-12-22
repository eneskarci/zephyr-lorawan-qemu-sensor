#include <zephyr/kernel.h>
#include <zephyr/logging/log.h>
#include <zephyr/random/random.h>
#include <stdio.h>

#include "lorawan_config.h"
#include "payload_crypto.h"

LOG_MODULE_REGISTER(app, LOG_LEVEL_INF);

static float rand_float_1dp(float min_v, float max_v)
{
    uint32_t r = sys_rand32_get();
    float t = (float)r / (float)UINT32_MAX;
    float v = min_v + t * (max_v - min_v);

    int32_t scaled = (int32_t)(v * 10.0f + (v >= 0 ? 0.5f : -0.5f));
    return (float)scaled / 10.0f;
}

static void lorawan_send_stub(uint8_t fport, const char *payload, bool confirmed)
{
    LOG_INF("SEND (stub): fport=%d confirmed=%d payload=\"%s\"",
            fport, confirmed ? 1 : 0, payload);
}

int main(void)
{
    LOG_INF("App started (QEMU).");
    lorawan_config_dump();

    const uint8_t fport = LORAWAN_FPORT;
    const bool confirmed = (LORAWAN_CONFIRMED_UPLINK != 0);

    while (1) {
        float temp = rand_float_1dp(-10.0f, 40.0f);
        float hum  = rand_float_1dp(20.0f, 90.0f);

        char payload_plain[64];
        char hmac_hex[65];
        char payload_signed[140];

        snprintf(payload_plain, sizeof(payload_plain),
                 "T:%.1f,H:%.1f", (double)temp, (double)hum);

        payload_hmac_sha256_hex(payload_plain, hmac_hex, sizeof(hmac_hex));

        snprintf(payload_signed, sizeof(payload_signed),
                 "%s#%s", payload_plain, hmac_hex);

        LOG_INF("Sensor mock: T=%.1f C, H=%.1f %%", (double)temp, (double)hum);
        LOG_INF("Payload plain : %s", payload_plain);
        LOG_INF("Payload signed: %s", payload_signed);

        lorawan_send_stub(fport, payload_signed, confirmed);

        k_sleep(K_SECONDS(TX_INTERVAL_SECONDS));
    }

    return 0;
}
