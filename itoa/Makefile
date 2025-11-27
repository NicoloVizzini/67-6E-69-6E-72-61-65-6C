# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -Wextra -g -fsanitize=address

# Target executable
TARGET = test

# Source files
SRC = itoa.c

# Default target
all: $(TARGET)

# Build the target
$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

# Clean up compiled files
clean:
	rm -f $(TARGET)

