#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbol_table.h"

/**
 * Creates a new empty symbol table
 */
SymbolTable *new_symbol_table() {
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
    add_entry(&symbol_table, predefined_symbols[i].key,
              predefined_symbols[i].value);
  }
  return symbol_table;
}

/**
 * Frees all entries in the symbol table and clears the caller's handle
 */
void destroy_symbol_table(SymbolTable **symbol_table) {
  SymbolTable *current, *tmp;
  HASH_ITER(hh, *symbol_table, current, tmp) {
    HASH_DEL(*symbol_table, current);
    free(current);
  }
  *symbol_table = NULL;
}

/**
 * Adds symbol -> address. Takes the table by address because uthash
 * reassigns the head pointer when it grows.
 */
void add_entry(SymbolTable **symbol_table, char *symbol, int address) {

  SymbolTable *item = (SymbolTable *)malloc(sizeof(SymbolTable));
  if (item == NULL)
    return;

  strncpy(item->key, symbol, sizeof(item->key) - 1);
  item->key[sizeof(item->key) - 1] = '\0';

  item->value = address;
  HASH_ADD_STR(*symbol_table, key, item);
}

int contains(SymbolTable *symbol_table, char *key) {
  SymbolTable *result = NULL;
  HASH_FIND_STR(symbol_table, key, result);
  return result != NULL;
}

/**
 * Returns the address bound to symbol, or -1 if it is not in the table
 */
int get_address(SymbolTable *symbol_table, char *symbol) {
  SymbolTable *result = NULL;
  HASH_FIND_STR(symbol_table, symbol, result);
  if (result == NULL)
    return -1;
  return result->value;
}
