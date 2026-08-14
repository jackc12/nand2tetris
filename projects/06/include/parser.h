#ifndef PARSER_H
#define PARSER_H
typedef enum {
  A_INSTRUCTION,
  C_INSTRUCTION,
  L_INSTRUCTION,
  NOT_INSTRUCTION
} instruction_t;
char **constructor(char *file_name, int *instruction_count);
void free_line_array(char **lines, int instruction_count);
int has_more_lines(int line_number, int instruction_count);
char *advance(char **lines, int *current_instruction, int instruction_count);
instruction_t instruction_type(char *instruction);
char *symbol(char *instruction);
char *parser_dest(char *instruction);
char *parser_comp(char *instruction);
char *parser_jump(char *instruction);

#endif
