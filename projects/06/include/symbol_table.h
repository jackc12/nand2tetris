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
int contains(SymbolTable *symbol_table, char *key);
void add_entry(SymbolTable *symbol_table, char *symbol, int address);

#endif
