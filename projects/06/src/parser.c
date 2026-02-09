#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Reads a file and returns an array of strings.
 * Updates 'instruction_count' so the caller knows the array size.
 */
char **constructor(char *file_name, int *instruction_count) {
  FILE *file = fopen(file_name, "r");
  if (!file)
    return NULL;

  int capacity = 10; // Start with space for 10 lines
  *instruction_count = 0;

  // Allocate memory for an array of string pointers
  char **lines = malloc(capacity * sizeof(char *));
  char buffer[1024];

  while (fgets(buffer, sizeof(buffer), file)) {
    // If array is full, double its size
    if (*instruction_count >= capacity) {
      capacity *= 2;
      lines = realloc(lines, capacity * sizeof(char *));
    }

    // Clean newline and copy to heap
    buffer[strcspn(buffer, "\n")] = '\0';
    lines[*instruction_count] = strdup(buffer);
    (*instruction_count)++;
  }

  // 5. Cleanup
  fclose(file);
  return lines;
}

/**
 * Helper to clean up the allocated memory
 */
void free_line_array(char **lines, int instruction_count) {
  for (int i = 0; i < instruction_count; i++) {
    free(lines[i]);
  }
  free(lines);
}

/**
 * Are there more lines in the input
 */
int has_more_lines(int line_number, int instruction_count) {
  return instruction_count - 1 > line_number;
}

/**
 * Skips over white space and comments.
 * Reads the next instruction from input and makes it the current instruction
 * Only called if has_more_lines is true
 * Initially no current instruction
 */
char *advance(char **lines, int current_instruction, int instruction_count) {
  current_instruction++;
  char *next_instruction;
  int i, white_space;
  while (current_instruction < instruction_count) {
    char *p = lines[current_instruction];

    // We check *p and *(p+1) to ensure we don't read past a null terminator
    if (*p == '/' && *(p + 1) == '/') {
      // comment
      current_instruction++;
    } else {
      i = 0, white_space = 1;
      // iterate through instruction until terminator
      while (p[i] != '\0' && white_space) {
        if (p[i] != ' ') {
          // not all white space so instruction
          white_space = 0;
        } else {
          // all white space so far...
          i++;
        }
      }
      if (white_space) {
        // white space
        current_instruction++;
      } else {
        // instruction
        next_instruction = lines[current_instruction];
        current_instruction += instruction_count;
      }
    }
  }
  return next_instruction;
}

int get_instruction_type(char *instruction) {
  printf("%s\n", instruction);
  return 0;
}
