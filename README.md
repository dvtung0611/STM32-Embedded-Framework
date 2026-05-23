# STM32 Embedded Framework

A modular bare-metal framework for STM32 microcontrollers focused on low-level embedded systems development using direct register manipulation without vendor HAL libraries.

---

## Architecture

```
STM32-Embedded-Framework/
│
├── core/              # Core initialization and system configuration
├── boards/            # Board-specific configurations
├── drivers/           # Peripheral drivers
│   ├── gpio/
│   ├── exti/
│   ├── nvic/
│   └── spi/
│
├── libc/              # Shared utility libraries
├── platform/          # Example applications
└── Makefile
```

---

## Features

- Bare-metal STM32 development
- Direct register-level peripheral programming
- Modular and portable driver architecture
- Custom linker scripts and startup code
- Makefile-based build system
- GDB/OpenOCD debugging support
- ITM/SWD real-time debugging

---

## Implemented Drivers
### GPIO
- Pin mode configuration
- Input/Output handling
- Alternate function configuration

### EXTI
- External interrupt configuration
- Rising/Falling edge trigger support

### NVIC
- Interrupt enable/disable
- Interrupt priority configuration

### SPI
- Full-duplex communication
- Blocking APIs
- Interrupt-driven APIs

### Toolchain
- ARM GNU Toolchain
- GNU Make
- OpenOCD
- GDB

---

## Build

Build project:

```
make
```

Clean build artifacts:

```
make clean
```

Flash firmware:

```
make flash
```

Start debugging session:

```
make openocd
make gdb
```

---

## Development Objectives

This project is intended to improve understanding of:
- ARM Cortex-M architecture
- Interrupt handling
- Peripheral register programming
- Embedded memory layout
- Real-time debugging
- Portable driver abstraction

---

## Future Improvements
- UART driver
- I2C driver
- DMA support
- SysTick timer
- RTOS integration
- CMake migration