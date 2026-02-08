#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Reads a file and returns an array of strings.
 * Updates 'line_count' so the caller knows the array size.
 */
char **constructor(char *file_name, int *line_count) {
  FILE *file = fopen(file_name, "r");
  if (!file)
    return NULL;

  int capacity = 10; // Start with space for 10 lines
  *line_count = 0;

  // Allocate memory for an array of string pointers
  char **lines = malloc(capacity * sizeof(char *));
  char buffer[1024];

  while (fgets(buffer, sizeof(buffer), file)) {
    // If array is full, double its size
    if (*line_count >= capacity) {
      capacity *= 2;
      lines = realloc(lines, capacity * sizeof(char *));
    }

    // Clean newline and copy to heap
    buffer[strcspn(buffer, "\n")] = '\0';
    lines[*line_count] = strdup(buffer);
    (*line_count)++;
  }

  // 5. Cleanup
  fclose(file);
  return lines;
}

/**
 * Helper to clean up the allocated memory
 */
void free_line_array(char **lines, int count) {
  for (int i = 0; i < count; i++) {
    free(lines[i]);
  }
  free(lines);
}

/**
 * Are there more lines in the input
 */
int has_more_lines(int line_count, int line_number) {
  return line_count - 1 > line_number;
}

/**
 * Skips over white space and comments.
 * Reads the next instruction from input and makes it the current instruction
 * Only called if has_more_lines is true
 * Initially no current instruction
 */
int advance(char **lines, int current_instruction) {
  char *current_line = lines[current_instruction];
  printf("current_line: %s\n", current_line);
  return 0;
}
