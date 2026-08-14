#include <stdlib.h>

#include "assembler.h"
#include "parser.h"
#include "symbol_table.h"

/**
 * Records every (LABEL) in the symbol table, bound to the address of the
 * instruction that follows it. Labels generate no code, so only real
 * instructions advance the address.
 */
void first_pass(SymbolTable **symbol_table, char **lines,
                int instruction_count) {
  int line_number = 0;

  while (has_more_lines(line_number, instruction_count)) {
    // advance stops on the instruction without consuming it
    char *instruction = advance(lines, &line_number, instruction_count);
    if (instruction == NULL)
      return;

    if (instruction_type(instruction) == L_INSTRUCTION) {
      char *label = symbol(instruction);
      if (label != NULL) {
        add_entry(symbol_table, label, line_number);
        free(label);
      }
    } else if (instruction_type(instruction) == A_INSTRUCTION ||
               instruction_type(instruction) == C_INSTRUCTION) {
      line_number++;
    }
  }
}
