# Zephyr LoRaWAN Sensor (QEMU Stub)

This project is a QEMU-based, RF-less LoRaWAN sensor application skeleton
developed using Zephyr RTOS.

## Project Scope
- Target: LoRaWAN Class A sensor node
- Region: EU868
- LoRaWAN Version: 1.0.3
- Environment: QEMU (no RF hardware)

## Implemented Features
- LoRaWAN configuration abstraction
- Periodic sensor data generation (temperature & humidity - mock)
- Payload formatting
- HMAC-SHA256 payload signing
- RF-less send stub for testing

## Payload Format
T:<temperature>,H:<humidity>#<HMAC_SHA256>

## Build & Run
west build -b qemu_x86 app_lorawan_stub -p always
west build -t run

## Notes
This project does not perform real RF transmission.
