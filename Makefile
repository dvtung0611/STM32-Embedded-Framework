# Compiler
CC = arm-none-eabi-gcc


# Select board
BOARD ?= STM32F4-DISC1
include Boards/$(BOARD)/board.mk


# Compiler Flags
CFLAGS = \
    -mthumb \
    -mfloat-abi=soft \
    -std=gnu11 \
	-specs=nano.specs \
	-u _printf_float \
    -O0 \
    -Wall \
    -Wextra \
    -Wshadow \
    -Wundef \
    -g3 \
    -ffunction-sections \
    -fdata-sections \
    -ffreestanding \

CFLAGS += $(CPU_FLAGS)
CFLAGS += -D$(MCU)
CFLAGS += -IDrivers/Cortex/Common/Inc
CFLAGS += -IDrivers/Cortex/$(CPU)/Inc
CFLAGS += -IDrivers/MCU/Common/Inc
CFLAGS += -IDrivers/MCU/$(MCU)/Inc
CFLAGS += -ILibc/Inc


# Linker Flags
LDFLAGS = \
    -mthumb \
    -mfloat-abi=soft \
    -specs=nosys.specs \
	-specs=nano.specs \
    -Wl,--gc-sections \
    -Wl,-Map=Build/$(BOARD)/firmware_map.map \
    -Wl,--print-memory-usage
# 	-Wl,--print-gc-sections

LDFLAGS += $(CPU_FLAGS)
LDFLAGS += -T $(LINKER_SCRIPT)


# Source Files
SRC = \
    $(wildcard Applications/main.c) \
    $(wildcard Core/Src/*.c) \
	$(STARTUP_FILE) \
	$(wildcard Drivers/Cortex/Common/Src/*.c) \
	$(wildcard Drivers/Cortex/$(CPU)/Src/*.c) \
	$(wildcard Drivers/MCU/Common/Src/*.c) \
	$(wildcard Drivers/MCU/$(MCU)/Src/*.c) \
	$(wildcard Libc/Src/*.c) \


# PHONY
.PHONY: \
    all \
	clean \
	flash-code \
	openocd \
	gdb \
	elf-sections


# Default Target
all: ELF


# Object Files
OBJ = $(SRC:.c=.o)


# Pattern Rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# ELF file
ELF = Build/$(BOARD)/firmware.elf


# stm32f407vgtx.elf
$(ELF): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@


# Clean
clean:
	rm -f \
	$(OBJ) \
	$(ELF) \
	*.map \
	*.i \
	*.s \
	*.o \
	*.elf


# Flash code
flash-code:
	openocd \
	-f $(OPENOCD_INTERFACE) \
	-f $(OPENOCD_TARGET) \
	-c "program $(ELF) verify reset exit"


# Debug server
openocd:
	openocd \
	-f $(OPENOCD_INTERFACE) \
	-f $(OPENOCD_TARGET)


# GDB target
gdb:
	arm-none-eabi-gdb $(ELF)


elf-sections:
	arm-none-eabi-objdump -h $(ELF)
