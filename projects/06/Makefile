CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude

SRC_DIR = src
OBJ_DIR = obj

SRC = $(wildcard $(SRC_DIR)/*.c)
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

assembler: $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

parser_test: tests/parser_test.c $(SRC_DIR)/parser.c
	$(CC) $(CFLAGS) -o test_runner $^
	./test_runner

code_test: tests/code_test.c $(SRC_DIR)/code.c
	$(CC) $(CFLAGS) -o test_runner $^
	./test_runner

assembler_test: tests/assembler_test.c $(SRC_DIR)/assembler.c
	$(CC) $(CFLAGS) -o test_runner $^
	./test_runner

format:
	clang-format -i $(SRC_DIR)/*.c include/*.h tests/*.c tests/*.h

clean:
	rm -f assembler test_runner
	rm -rf $(OBJ_DIR)

.PHONY: test clean format
