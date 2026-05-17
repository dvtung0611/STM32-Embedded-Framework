MCU = stm32f407
CPU = cortex-m4

LINKER_SCRIPT = core/stm32f407/linker/stm32f407vgtx.ld
STARTUP_FILE = core/stm32f407/startup/startup-stm32f407vgtx.c

OPENOCD_TARGET = target/stm32f4x.cfg
OPENOCD_INTERFACE = interface/stlink.cfg

CPU_FLAGS = \
    -mcpu=$(CPU) \
