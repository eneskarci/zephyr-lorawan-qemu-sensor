cmake_minimum_required(VERSION 3.20.0)
find_package(Zephyr REQUIRED HINTS $ENV{ZEPHYR_BASE})
project(app_lorawan_stub)

target_sources(app PRIVATE
  src/main.c
  src/lorawan_config.c
  src/payload_crypto.c
)
