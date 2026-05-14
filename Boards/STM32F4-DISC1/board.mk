MCU = STM32F407xx
CPU = Cortex-M4

LINKER_SCRIPT = Core/STM32F407xx/Linker/stm32f407vgtx.ld
STARTUP_FILE = Core/STM32F407xx/Startup/startup_stm32f407vgtx.c

OPENOCD_TARGET = target/stm32f4x.cfg
OPENOCD_INTERFACE = interface/stlink.cfg

CPU_FLAGS = \
    -mcpu=cortex-m4 \
