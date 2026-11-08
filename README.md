# Lumppari Logger

A battery-powered environmental data logger built with Zephyr RTOS.

The project aims to provide a simple, low-power platform for collecting and storing environmental measurements over extended periods without requiring a continuous network connection.

Initial use case will be outdoor temperature monitoring all-year around in Finland (temperatures ranging -40 to +30). The project also serves as a platform for experimenting with embedded software, sensor interfaces, power management, and persistent storage.

## Hardware

- **MCU:** Seeed Studio XIAO nRF52840
- **RTOS:** Zephyr 4.5.0
- **Temperature sensor (planned):** DS18B20 (1-Wire)
- **Storage (planned):** Onboard flash memory
- **Power:** Battery-powered operation (AA-batteries)

Additional sensors and connectivity options may be introduced later.

## Project Status

Early development. The basic Zephyr application builds successfully, but sensor acquisition and data logging have not yet been implemented.

### Planned Features

- [ ] DS18B20 temperature measurements
- [ ] Periodic sensor sampling
- [ ] Timestamped data logging
- [ ] Persistent flash storage
- [ ] Very low-power operation
- [ ] Data retrieval over BLE
- [ ] Battery voltage monitoring (possibly)

## Building

The project uses Zephyr's west build system and maintains its own west manifest (`west.yml`) to manage the Zephyr version and dependencies.

### Prerequisites

- Python and west
- Zephyr SDK with ARM toolchain
- CMake and Ninja

Refer to the [Zephyr Getting Started Guide](https://docs.zephyrproject.org/latest/develop/getting_started/) for installation instructions.

### Clone and initialize

```bash
west init -m https://github.com/<username>/lumppari-logger.git lumppari-workspace
cd lumppari-workspace
west update
```

Replace `<username>` with the repository owner. A private repository requires GitHub authentication.

### Build

From the workspace root:

```bash
west build -b xiao_ble/nrf52840 lumppari-logger
```

The resulting UF2 firmware can be found at:

```text
build/zephyr/zephyr.uf2
```

### Flash

1. Connect the XIAO nRF52840 via USB.
2. Double-click the reset button to enter the UF2 bootloader.
3. Copy `zephyr.uf2` to the USB mass-storage device.
4. The board will reboot into the application.

## License

License to be determined.