CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = hack

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# The final executable path
TARGET = $(BIN_DIR)/assembler

# Default target
all: $(TARGET)

# Link the objects into the hack folder
$(TARGET): $(OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) -o $@ $^

# Rule for object files
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Create directories if they don't exist
$(OBJ_DIR) $(BIN_DIR):
	mkdir -p $@

# --- Test Rules ---

parser_test: tests/parser_test.c $(SRC_DIR)/parser.c
	$(CC) $(CFLAGS) -o test_runner $^
	./test_runner

code_test: tests/code_test.c $(SRC_DIR)/code.c
	$(CC) $(CFLAGS) -o test_runner $^
	./test_runner

test_assembler: tests/assembler_test.c $(SRC_DIR)/assembler.c
	$(CC) $(CFLAGS) -o test_runner $^
	./test_runner

# --- Utility Rules ---

format:
	clang-format -i $(SRC_DIR)/*.c include/*.h tests/*.c tests/*.h

clean:
	rm -f test_runner
	rm -rf $(OBJ_DIR) $(BIN_DIR)

.PHONY: all test clean format
