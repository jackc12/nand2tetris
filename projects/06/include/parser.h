#ifndef PARSER_H
#define PARSER_H

char **constructor(char *file_name, int *instruction_count);
void free_line_array(char **lines, int instruction_count);
int has_more_lines(int line_number, int instruction_count);
char *advance(char **lines, int current_instruction, int instruction_count);

#endif
