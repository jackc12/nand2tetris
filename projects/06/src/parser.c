#include "parser.h"
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

/**
 * If the current instruction is (xxx), returns the symbol xxx
 * If the current instruction is @xxx, returns the symbol or decimal xxx
 * Only called if instructionType is A_INSTRUCTION or L_INSTRUCTION
 */
instruction_t instruction_type(char *instruction) {
  instruction_t type;
  int i;
  // brittle
  // should check that i in @i is 0..32767
  if (instruction[0] == '@') {
    type = A_INSTRUCTION;
  } else if (instruction[0] == '(') {
    i = 1;
    while (instruction[i] != '\0') {
      if (instruction[i] != ')') {
        type = L_INSTRUCTION;
      }
      i++;
    }
  } else {
    // brittle but valid assembly is an invariant
    type = C_INSTRUCTION;
  }
  return type;
}

/**
 * If the current instruction is (xxx), returns the symbol xxx
 * If the current instruction is @xxx, returns the symbol or decimal xxx
 * Only called if instructionType is A_INSTRUCTION or L_INSTRUCTION
 */
char *symbol(char *instruction) {
  char *buffer = malloc(11 * sizeof(char));
  if (buffer == NULL)
    return NULL;
  if (instruction[0] == '@') {
    strncpy(buffer, &instruction[1], 10);
    buffer[strcspn(buffer, "\n")] = '\0';
    return buffer;
  } else {
    strncpy(buffer, &instruction[1], 10);
    buffer[strcspn(buffer, ")")] = '\0';
    return buffer;
  }
}

char *dest(char *instruction) {
  char *buffer = malloc(3 * sizeof(char)), *end = strchr(instruction, '=');
  if (buffer == NULL || end == NULL)
    return NULL;

  int index = (int)(end - instruction);
  char *dest = strncpy(buffer, instruction, index);
  if (dest == NULL)
    return NULL;
  return dest;
}

char *comp(char *instruction) {
  char *buffer = malloc(3 * sizeof(char)), *start = strchr(instruction, '='),
       *end = strchr(instruction, ';');
  if (buffer == NULL || start == NULL || end == NULL)
    return NULL;

  int start_i = start - instruction + 1, end_i = end - start - 1;
  char *dest = strncpy(buffer, instruction + start_i, end_i);
  if (dest == NULL)
    return NULL;
  return dest;
}
