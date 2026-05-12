# Compiler
CC = arm-none-eabi-gcc


# Compiler Flags
CFLAGS = \
    -mcpu=cortex-m4 \
    -mthumb \
    -mfloat-abi=soft \
    -std=gnu11 \
    -O0 \
    -Wall \
    -Wextra \
    -Wshadow \
    -Wundef \
    -g3 \
    -ffunction-sections \
    -fdata-sections \
    -ffreestanding \
    -IDrivers/Inc \
	-ILibC/Inc


# Linker Flags
LDFLAGS = \
    -mcpu=cortex-m4 \
    -mthumb \
    -mfloat-abi=soft \
    -nostdlib \
    -T Linker/stm32f407vgtx.ld \
    -Wl,--gc-sections \
    -Wl,-Map=Debug/stm32f407vgtx.map \
    -Wl,--print-memory-usage \
    -Wl,--print-gc-sections


# Source Files
SRC = \
Startup/startup_stm32f407vgtx.c \
$(wildcard Src/*.c) \
$(wildcard Drivers/Src/*.c) \
$(wildcard LibC/Src/*.c)


# Object Files
OBJ = $(SRC:.c=.o)


# PHONY
.PHONY: all clean flash debug gdb


# Default Target
all: stm32f407vgtx.elf


# Pattern Rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# ELF file
ELF = stm32f407vgtx.elf


# stm32f407vgtx.elf
$(ELF): $(OBJ)
	$(CC) $(LDFLAGS) $^ -o $@


# Clean
clean:
	rm -f \
	$(OBJ) \
	*.map \
	*.elf


# Flash code
flash:
	openocd \
	-f board/stm32f4discovery.cfg \
	-c "program $(ELF) verify reset exit"


# Debug server
debug:
	openocd \
	-f board/stm32f4discovery.cfg


# GDB target
gdb:
	arm-none-eabi-gdb $(ELF)
