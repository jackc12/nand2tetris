#ifndef PARSER_H
#define PARSER_H

char **constructor(char *file_name, int *lineCount);
void free_line_array(char **lines, int count);
int has_more_lines(int line_count, int line_number);

#endif
