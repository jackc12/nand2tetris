#ifndef ASSEMBLER_H
#define ASSEMBLER_H
#include <stddef.h>
void int_to_bin(char *a_instruction, char *binary, size_t binary_size);
void first_pass(char *symbol_table, char **lines, int line_number,
                int instruction_count);

#endif
