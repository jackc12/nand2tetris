#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2)
    printf("WRONG!\n");
  else {
    // -1 because advance increments first
    // fix later
    int instruction_count, line_number = -1;
    char **lines = constructor(argv[1], &instruction_count);
    char *instruction = NULL;
    while (has_more_lines(line_number, instruction_count)) {
      instruction = advance(lines, line_number, instruction_count);
      switch (instruction_type(instruction)) {
      case A_INSTRUCTION:
        // TODO
        printf("A_INSTRUCTION\n");
        break;

      case C_INSTRUCTION:
        // TODO
        printf("C_INSTRUCTION\n");
        break;

      case L_INSTRUCTION:
        // TODO
        printf("L_INSTRUCTION\n");
        break;
      }
      printf("ln: %d\n", line_number);
      printf("i: %s\n", instruction);
      line_number++;
    }
    free_line_array(lines, instruction_count);
  }
  return 0;
}
