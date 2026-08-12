#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "code.h"
#include "parser.h"

void int_to_bin(char *a_instruction, char *binary, size_t binary_size);

int main(int argc, char *argv[]) {
  if (argc != 2)
    printf("WRONG!\n");
  else {
    int instruction_count, line_number = 0, instruction_number = 0;
    char **lines = constructor(argv[1], &instruction_count);
    char *instruction = NULL, *dest, *comp, *jump, *a_instruction;

    FILE *file = fopen("Prog.hack", "w");
    if (!file)
      return 1;

    while(has_more_lines(line_number, instruction_count)) {
    }
    char **hack = malloc(instruction_count * sizeof(char *));

    while (has_more_lines(line_number, instruction_count)) {
      instruction = advance(lines, &line_number, instruction_count);
      hack[instruction_number] = malloc(17);
      switch (instruction_type(instruction)) {
      case A_INSTRUCTION:
        // TODO
        a_instruction = symbol(instruction);
        if (a_instruction[0] >= '0' && a_instruction[0] <= '9') {
          int_to_bin(a_instruction, hack[instruction_number], 17);
        }
        fprintf(file, "%s\n", hack[instruction_number]);
        instruction_number++;
        break;

      case C_INSTRUCTION:
        dest = parser_dest(instruction);
        dest = code_dest(dest);
        comp = parser_comp(instruction);
        comp = code_comp(comp);
        jump = parser_jump(instruction);
        jump = code_jump(jump);
        sprintf(hack[instruction_number], "111%s%s%s", comp, dest, jump);
        fprintf(file, "%s\n", hack[instruction_number]);
        instruction_number++;
        break;

      case L_INSTRUCTION:
        // TODO
        break;
      }
      line_number++;
    }
    free_line_array(lines, instruction_count);
    free_line_array(hack, instruction_number);
    fclose(file);
  }
  return 0;
}
