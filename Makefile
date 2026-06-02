# Compiler
CC = arm-none-eabi-gcc


# Select board
BOARD ?= stm32f407vg-disc1
include boards/$(BOARD)/board.mk


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
    -ffreestanding

CFLAGS += $(CPU_FLAGS)
CFLAGS += -Idrivers/$(MCU_FAMILY)/cpu/inc
CFLAGS += -Idrivers/$(MCU_FAMILY)/mcu/inc
CFLAGS += -Ilibc/inc
CFLAGS += -Iplatform/debug/inc


# Linker Flags
LDFLAGS = \
    -mthumb \
    -mfloat-abi=soft \
    -specs=nosys.specs \
	-specs=nano.specs \
    -Wl,--gc-sections \
    -Wl,-Map=Build/$(BOARD)/firmware.map \
    -Wl,--print-memory-usage
# 	-Wl,--print-gc-sections

LDFLAGS += $(CPU_FLAGS)
LDFLAGS += -T $(LINKER_SCRIPT)


.PHONY: \
    all \
	clean \
	flash-code \
	openocd \
	gdb \
	elf-sections \
	print-obj


# .c files
SRC = \
    $(wildcard core/src/*.c) \
	$(STARTUP_FILE) \
	$(wildcard drivers/$(MCU_FAMILY)/cpu/src/*.c) \
	$(wildcard drivers/$(MCU_FAMILY)/mcu/src/*.c) \
	$(wildcard libc/src/*.c) \
	$(wildcard platform/debug/src/*.c) \
	$(wildcard tests/main.c)


# .o files
OBJ_DIR = build/$(BOARD)/obj
OBJ = $(patsubst %.c, $(OBJ_DIR)/%.o, $(SRC))


# .elf file
ELF_FILE = build/$(BOARD)/firmware.elf


# Build final ELF firmware binary
all: $(ELF_FILE)


# Compile each .c source file into .o object file
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


# Link all object files into final ELF executable file
$(ELF_FILE): $(OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $^ -o $@


# Remove all generated build artifacts for selected board
clean:
	rm -rf build/$(BOARD)/*


# Flash firmware to target MCU using OpenOCD
flash-code:
	openocd \
	-f $(OPENOCD_FILE)
	-c "program $(ELF_FILE) verify reset exit"


# Start OpenOCD GDB server for debugging
openocd:
	openocd -f $(OPENOCD_FILE)


# Launch ARM GDB debugger with current ELF file
gdb:
	arm-none-eabi-gdb $(ELF_FILE)


# Display ELF memory sections and sizes
elf-sections:
	arm-none-eabi-objdump -h $(ELF_FILE)


# Print all generated object file paths
print-obj:
	@echo $(OBJ)