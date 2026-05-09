# Compiler
CC = arm-none-eabi-gcc


# Compiler Flags
CFLAGS = \
-mcpu=cortex-m4 \
-mthumb \
-mfloat-abi=soft \
-std=gnu11 \
-Og \
-Wall \
-Wextra \
-Wshadow \
-Wundef \
-g3 \
-ffunction-sections \
-fdata-sections \
-ffreestanding \
-IDrivers/Inc


# Linker Flags
LDFLAGS = \



# Source Files
SRC = \
Src/main.c \
Startup/startup_stm32f407vgtx.c \
$(wildcard Drivers/Src/*.c)


# Object Files
OBJ = $(SRC:.c=.o)


# Default Target
all: $(OBJ)


# Pattern Rule
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# Clean
clean:
	rm -f $(OBJ)
