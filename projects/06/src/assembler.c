#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "assembler.h"
#include "code.h"
#include "parser.h"
#include "symbol_table.h"

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

    // first pass
    SymbolTable *symbol_table = new_symbol_table();
    first_pass(&symbol_table, lines, instruction_count);

    // should prob be in own module
    int address, free_address = 16;
    // second pass
    char **hack = malloc(instruction_count * sizeof(char *));

    while (has_more_lines(line_number, instruction_count)) {
      instruction = advance(lines, &line_number, instruction_count);
      hack[instruction_number] = malloc(30);
      switch (instruction_type(instruction)) {
      case A_INSTRUCTION:
        // TODO
        a_instruction = symbol(instruction);
        if (a_instruction[0] >= '0' && a_instruction[0] <= '9') {
          int_to_bin(a_instruction, hack[instruction_number], 30);
        } else {
          address = get_address(symbol_table, a_instruction);

          if (address == -1) {
            add_entry(&symbol_table, a_instruction, free_address);
            snprintf(a_instruction, 16, "%d", free_address);
            int_to_bin(a_instruction, hack[instruction_number], 30);
            free_address++;
          } else {
            snprintf(a_instruction, 16, "%d", address);
            int_to_bin(a_instruction, hack[instruction_number], 30);
          }
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
      case NOT_INSTRUCTION:
        break;
      }
      line_number++;
    }
    destroy_symbol_table(&symbol_table);
    free_line_array(lines, instruction_count);
    free_line_array(hack, instruction_number);
    fclose(file);
  }
  return 0;
}
