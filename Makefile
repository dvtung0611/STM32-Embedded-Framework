# Compiler
CC = arm-none-eabi-gcc


# Compiler Flags
CFLAGS = \
-mthumb \
-mcpu=cortex-m4 \
-mfloat-abi=soft \
-std=gnu11 \
-Wall \
-O0 \
-IDrivers/Inc


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
