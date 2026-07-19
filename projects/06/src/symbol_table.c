#include "symbol_table.h"
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
  char *keys[] = {"foenem", "twin"};
  char values[] = {0, 1};

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

int main() {
  SymbolTable *my_table = constructor();

  // Look up a value
  SymbolTable *result = NULL;
  HASH_FIND_STR(my_table, "b", result);

  if (result) {
    printf("Found 'b': %d\n", result->value);
  }

  return 0;
}
