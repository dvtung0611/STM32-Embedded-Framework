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
    -ffreestanding

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


# Source .c files
SRC = \
    $(wildcard Applications/main.c) \
    $(wildcard Core/Src/syscalls.c) \
	$(STARTUP_FILE) \
	$(wildcard Drivers/Cortex/Common/Src/*.c) \
	$(wildcard Drivers/Cortex/$(CPU)/Src/*.c) \
	$(wildcard Drivers/MCU/Common/Src/*.c) \
	$(wildcard Drivers/MCU/$(MCU)/Src/*.c) \
	$(wildcard Libc/Src/*.c)


.PHONY: \
    all \
	clean \
	flash-code \
	openocd \
	gdb \
	elf-sections


ELF = Build/$(BOARD)/firmware.elf


# Build final ELF firmware binary
all: $(ELF)


# Compile each .c source file into .o object file
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@


# Link all object files into final ELF executable
$(ELF): $(OBJ)
	@mkdir -p $(dir $@)
	$(CC) $(LDFLAGS) $^ -o $@


# Remove all generated build artifacts for selected board
clean:
	rm -rf Build/$(BOARD)/*


# Flash firmware to target MCU using OpenOCD
flash-code:
	openocd \
	-f $(OPENOCD_INTERFACE) \
	-f $(OPENOCD_TARGET) \
	-c "program $(ELF) verify reset exit"


# Start OpenOCD GDB server for debugging
openocd:
	openocd \
	-f $(OPENOCD_INTERFACE) \
	-f $(OPENOCD_TARGET)


# Launch ARM GDB debugger with current ELF file
gdb:
	arm-none-eabi-gdb $(ELF)


# Display ELF memory sections and sizes
elf-sections:
	arm-none-eabi-objdump -h $(ELF)


# Print all generated object file paths
print-obj:
	@echo $(OBJ)