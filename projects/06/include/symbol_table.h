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

#endif
