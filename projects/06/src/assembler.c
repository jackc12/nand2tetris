#include "code.h"
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
    int instruction_count, line_number = 0, instruction_number = 0;
    char **lines = constructor(argv[1], &instruction_count);
    char *instruction = NULL, *dest, *comp, *jump;

    FILE *file = fopen("Prog.hack", "w");
    if (!file)
      return 1;
    char **hack = malloc(instruction_count * sizeof(char *));

    while (has_more_lines(line_number, instruction_count)) {
      printf("ln: %d\n", line_number);
      instruction = advance(lines, &line_number, instruction_count);
      printf("i: %s\n", instruction);
      switch (instruction_type(instruction)) {
      case A_INSTRUCTION:
        // TODO
        printf("%s\n", instruction);
        break;

      case C_INSTRUCTION:
        printf("%s\n", instruction);
        dest = parser_dest(instruction);
        dest = code_dest(dest);
        comp = parser_comp(instruction);
        comp = code_comp(comp);
        jump = parser_jump(instruction);
        jump = code_jump(jump);
        sprintf(hack[instruction_number], "111%s%s%s", dest, comp, jump);
        printf("%s\n", hack[instruction_number]);
        instruction_number++;
        break;

      case L_INSTRUCTION:
        printf("%s\n", instruction);
        // TODO
        break;
      }
      line_number++;
    }
    free_line_array(lines, instruction_count);
    free_line_array(hack, instruction_count);
  }
  return 0;
}
