#pragma once
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Compute HMAC-SHA256 of input string and return hex string (64 chars) */
void payload_hmac_sha256_hex(const char *input, char *out_hex, size_t out_size);

#ifdef __cplusplus
}
#endif
