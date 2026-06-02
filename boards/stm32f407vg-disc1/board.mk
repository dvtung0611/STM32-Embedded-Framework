MCU_FAMILY = stm32f407
MCU_DEVICE = STM32F407VG
MCU = stm32f407vg
CPU = cortex-m4

OPENOCD_FILE = boards/$(BOARD)/openocd.cfg
LINKER_SCRIPT = core/$(MCU_FAMILY)/linker/$(MCU).ld
STARTUP_FILE = core/$(MCU_FAMILY)/startup/startup-$(MCU).c

CPU_FLAGS = \
    -mcpu=$(CPU)