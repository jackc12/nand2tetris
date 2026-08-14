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

assembler_test: tests/assembler_test.c $(SRC_DIR)/int_to_bin.c
	$(CC) $(CFLAGS) -o test_runner $^
	./test_runner

first_pass_test: tests/first_pass_test.c $(SRC_DIR)/first_pass.c $(SRC_DIR)/parser.c $(SRC_DIR)/symbol_table.c
	$(CC) $(CFLAGS) -o test_runner $^
	./test_runner

symbol_table_test: tests/symbol_table_test.c $(SRC_DIR)/symbol_table.c
	$(CC) $(CFLAGS) -o test_runner $^
	./test_runner

format:
	clang-format -i $(SRC_DIR)/*.c include/*.h tests/*.c tests/*.h

clean:
	rm -f assembler test_runner
	rm -rf $(OBJ_DIR)

.PHONY: test clean format
