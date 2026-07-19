#include "uthash.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char key[16];
  int value;
  UT_HASH_HANDLE hh;
} SymbolTable;

/**
 * Creates a new empty symbol table
 */
SymbolTable *constructor() {
  SymbolTable *symbol_table = NULL;
  char *keys[] = {};
  char values[] = {};

  for (int i = 0; i < 16; i++) {
    SymbolTable *symbol = (SymbolTable *)malloc(sizeof(SymbolTable));
    if (item == NULL) {
      perror("Failed to allocate memory");
      exit(EXIT_FAILURE);
    }
    strcpy(item->key, keys[i]);
    item->value = values[i];

    HASH_ADD_STR(table, key, item)
  }
}
