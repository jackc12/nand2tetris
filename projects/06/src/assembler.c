#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2)
    printf("WRONG!\n");
  else {
    int instruction_count;
    char **file = constructor(argv[1], &instruction_count);
    for (int i = 0; i < instruction_count; i++) {
      printf("%s\n", file[i]);
    }
  }
  return 0;
}
