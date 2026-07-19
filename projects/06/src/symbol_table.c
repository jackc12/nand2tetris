#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "symbol_table.h"

/**
 * Creates a new empty symbol table
 */
SymbolTable *constructor() {
  SymbolTable *symbol_table = NULL;
  char *keys[] = {"foenem", "twin"};
  int values[] = {0, 1};

  for (int i = 0; i < 2; i++) {
    SymbolTable *item = (SymbolTable *)malloc(sizeof(SymbolTable));
    if (item == NULL) {
      perror("Failed to allocate memory");
      exit(EXIT_FAILURE);
    }
    strcpy(item->key, keys[i]);
    item->value = values[i];

    HASH_ADD_STR(symbol_table, key, item);
  }

  return symbol_table;
}

int main() {
  SymbolTable *my_table = constructor();

  // Look up a value
  SymbolTable *result = NULL;
  HASH_FIND_STR(my_table, "foenem", result);

  if (result) {
    printf("Found 'b': %d\n", result->value);
  }

  return 0;
}
