#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2)
    printf("WRONG!\n");
  else {
    int instruction_count, current_instruction = 0, line_number = 0;
    char **lines = constructor(argv[1], &instruction_count);
    while(has_more_lines(line_number, instruction_count) {
		    printf("%s", current_instruction)
		    advance(&lines, &current_instruction, &instruction_count)
		    printf("%s", current_instruction)

		    }
    free_line_array(lines, instruction_count)
  }
  return 0;
}
