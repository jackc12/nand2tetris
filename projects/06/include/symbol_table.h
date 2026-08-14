#ifndef SYMBOL_TABLE_H
#define SYMBOL_TABLE_H
#include "uthash.h"

typedef struct {
  char key[26];
  int value;
  UT_hash_handle hh;
} SymbolTable;

SymbolTable *new_symbol_table();
void destroy_symbol_table(SymbolTable **symbol_table);
int contains(SymbolTable *symbol_table, char *key);
void add_entry(SymbolTable **symbol_table, char *symbol, int address);
int get_address(SymbolTable *symbol_table, char *symbol);
void print_symbol_table(SymbolTable **symbol_table);

#endif
