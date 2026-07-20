#ifndef PARSER_H
#define PARSER_H
#include "uthash.h"

typedef struct {
  char key[16];
  int value;
  UT_hash_handle hh;
} SymbolTable;

SymbolTable *constructor();
void destructor(SymbolTable *symbol_table);
/*
void free_line_array(char **lines, int instruction_count);
int has_more_lines(int line_number, int instruction_count);
char *advance(char **lines, int *current_instruction, int instruction_count);
instruction_t instruction_type(char *instruction);
char *symbol(char *instruction);
char *parser_dest(char *instruction);
char *parser_comp(char *instruction);
char *parser_jump(char *instruction);
*/

#endif
