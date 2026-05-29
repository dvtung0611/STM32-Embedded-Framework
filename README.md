# STM32 Embedded Framework
STM32 Embedded Framework is a modular bare-metal firmware framework for STM32 microcontrollers using direct register-level programming without vendor HAL libraries.

The project focuses on learning and understanding STM32 peripherals, ARM Cortex-M architecture, interrupt handling, and reusable embedded driver design.


**Note:** This repository is intended for learning and discovery of STM32 MCU peripherals and ARM Cortex-M architecture. It is not suitable for commercial use. The firmware may contain errors or bugs, so please contact me via email at dvtung0611@gmail.com.

**Author:** Van Tung Dinh

Thank you!

---

## Supported MCU

Currently tested on:

| Board                 | MCU               |
| ------                | ------            |
| STM32F407VG-DISC1     | STM32F407VG       |

---

## Architecture

```
STM32-Embedded-Framework/
│
├── core/                           # Core initialization and system configuration (assert, compiler, platform, ...)
│   ├── inc/
│   ├── src/
│   ├── *mcu_family                 # (eg. stm32f407, stm32f767)
│       ├── linker/
│       ├── startup_code/
│
├── boards/                         # Board-specific configurations
│   ├── *board_name                 # (eg. stm32f407vg-disc1, nucleo-f767zi)
│       ├── inc/
│       ├── src/
│       ├── board.json
│       ├── board.mk
│       ├── openocd.cfg
│
├── config/
│
├── docs/                           # Documents (ARM Cortex-M, STM32 MCUs, STM32 boards, ...)
│   ├── boards
│   ├── cpus
│   ├── mcus
│
├── drivers/                        # Peripheral drivers
│   ├── *mcu_family                 # (eg. stm32f407, stm32f767)
│       ├── cpu/                    # NVIC, SysTick, HardFault, ...
│       ├── mcu/                    # GPIO, EXTI, SPI, I2C, ...
│
├── libc/                           # Tiny libraries
│   ├── inc/
│   ├── src/
│
├── platform/                       # Support build and debug firmware
│   ├── debug/
│       ├── inc/
│       ├── src/
│   ├── ringbuffer/
│       ├── inc/
│       ├── src/
│   utils/
│       ├── inc/
│
├── svd/                            # svd files for debug with VSCode extension Cortex-Debug
│
├── tools/                          # Generate .json files
│
├── .gitignore
├── Makefile
├── README.md
```

---

## Tools and apps

### Software
- VSCode
- VSCode Extensions:
  - Cortex-Debug
  - C/C++
- GNU ARM Toolchain (arm-none-eabi-gcc/gdb/ojdump/...)
- GNU Make
- OpenOCD
- Python

### Hardware
- STM32 Boards (STM32F407VG-DISC1)
- ST-LINK

---

## Build

Step 1: Clone repo

```bash
git clone https://github.com/dvtung0611/STM32-Embedded-Framework.git
```

Step 2: Download full `tools and apps`

Step 3: Open repo with VSCode

Step 4: Open terminal in VSCode, generate launch.json and task.json with tools

``` bash
python tools/generate_launch.py
```

Step 5: Press `F5`. VSCode will automatically build and flash the firmware to the target board.

---

## Drivers
<!-- To understand how to use the APIs, please check the **test/** folder and read function comments in the *.h files inside the **drivers/** folder. -->

To understand how to use the APIs, please read function comments in the *.h files inside the **drivers/** folder.

**Note:** These APIs are designed for the **STM32F407VG MCU**, **ARM Cortex-M4 architecture**. Other STM32 MCUs may provide more or fewer features, and some APIs (such as DMA) depend on the specific MCU, ARM Cortex-M architecture. However, most STM32 MCUs support the following APIs.

### GPIO
The current APIs support the following features:
- Enable/Disable clock for a GPIO port
- Initialize/De-initialize a GPIO port
- Read from an input pin/port
- Write to an output pin/port
- Toggle an output pin
- Lock a GPIO pin
- Get GPIO port code

### EXTI
The current APIs support the following features:
- Initialize/De-initialize EXTI
- Get pending flag
- Clear pending flag (write `1` to clear)

### NVIC
The current APIs support the following features:
- Enable/Disable interrupt request lines
- Configure interrupt request priority

### SPI
The current APIs support the following features:
- Enable/Disable clock for SPI
- Initialize/De-initialize SPI
- Get SPI flag status (BSY, TXE, RXNE, OVR, ...)
- Enable/Disable SPI
- Enable/Disable SSI bit (Internal Slave Select)
- Enable/Disable SSOE bit (SS output enable)
- Handle SPI interrupt requests
- Application event callback (end of interrupt)
- Transmit, Receive, and Full-duplex (Transmit + Receive) blocking APIs
- Transmit, Receive, and Full-duplex (Transmit + Receive) non-blocking APIs

---

## License

MIT License