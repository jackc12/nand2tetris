#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbol_table.h"

/**
 * Creates a new empty symbol table
 */
SymbolTable *constructor() {
  SymbolTable *symbol_table = NULL;
  struct {
    char *key;
    int value;
  } predefined_symbols[] = {
      {"R0", 0},   {"R1", 1},         {"R2", 2},     {"R3", 3},   {"R4", 4},
      {"R5", 5},   {"R6", 6},         {"R7", 7},     {"R8", 8},   {"R9", 9},
      {"R10", 10}, {"R11", 11},       {"R12", 12},   {"R13", 13}, {"R14", 14},
      {"R15", 15}, {"SP", 0},         {"LCL", 1},    {"ARG", 2},  {"THIS", 3},
      {"THAT", 4}, {"SCREEN", 16384}, {"KBD", 24576}};

  int element_count =
      sizeof(predefined_symbols) / sizeof(predefined_symbols[0]);
  for (int i = 0; i < element_count; i++) {
    SymbolTable *item = (SymbolTable *)malloc(sizeof(SymbolTable));
    if (item == NULL)
      return NULL;

    strncpy(item->key, predefined_symbols[i].key, sizeof(item->key) - 1);
    item->key[sizeof(item->key) - 1] = '\0';

    item->value = predefined_symbols[i].value;

    HASH_ADD_STR(symbol_table, key, item);
  }
  return symbol_table;
}

/**
 * Frees all entries in the symbol table
 */
void destructor(SymbolTable *symbol_table) {
  SymbolTable *current, *tmp;
  HASH_ITER(hh, symbol_table, current, tmp) {
    HASH_DEL(symbol_table, current);
    free(current);
  }
}

void add_entry(char *symbol, int address) {}

int contains(SymbolTable *symbol_table, char *key) {
  SymbolTable *result = NULL;
  HASH_FIND_STR(symbol_table, key, result);
  return result != NULL;
}

int get_address(char *symbol) { return 0; }

/*
int main() {
  SymbolTable *my_table = constructor();

  // Look up a value
  SymbolTable *result = NULL;
  HASH_FIND_STR(my_table, "SCREEN", result);

  if (result) {
    printf("Found 'SCREEN': %d\n", result->value);
  }

  destructor(my_table);

  return 0;
}
*/
