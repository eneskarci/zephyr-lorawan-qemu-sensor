#include <string.h>
#include <stdio.h>

#include <zephyr/logging/log.h>
#include <mbedtls/md.h>

#include "payload_crypto.h"

/* Payload signing secret (NOT LoRaWAN AppKey) */
static const unsigned char PAYLOAD_SECRET[] = "PAYLOAD_HMAC_SECRET_123";

LOG_MODULE_REGISTER(payload_crypto, LOG_LEVEL_INF);

void payload_hmac_sha256_hex(const char *input, char *out_hex, size_t out_size)
{
    unsigned char hmac[32];
    const mbedtls_md_info_t *md_info;

    if (!input || !out_hex || out_size < 65) {
        return;
    }

    md_info = mbedtls_md_info_from_type(MBEDTLS_MD_SHA256);
    if (md_info == NULL) {
        return;
    }

    /* HMAC-SHA256 */
    if (mbedtls_md_hmac(md_info,
                        PAYLOAD_SECRET, strlen((const char *)PAYLOAD_SECRET),
                        (const unsigned char *)input, strlen(input),
                        hmac) != 0) {
        return;
    }

    /* to hex (64 chars) */
    for (int i = 0; i < 32; i++) {
        snprintf(&out_hex[i * 2], out_size - (i * 2), "%02x", hmac[i]);
    }
    out_hex[64] = '\0';
}
