#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Reads a file and returns an array of strings.
 * Updates 'lineCount' so the caller knows the array size.
 */
char **constructor(char *file_name) {
  FILE *file = fopen(filename, "r");
  if (!file)
    return NULL;

  int capacity = 10; // Start with space for 10 lines
  *lineCount = 0;

  // Allocate memory for an array of string pointers
  char **lines = malloc(capacity * sizeof(char *));
  char buffer[1024];

  while (fgets(buffer, sizeof(buffer), file)) {
    // If array is full, double its size
    if (*lineCount >= capacity) {
      capacity *= 2;
      lines = realloc(lines, capacity * sizeof(char *));
    }

    // Clean newline and copy to heap
    buffer[strcspn(buffer, "\n")] = '\0';
    lines[*lineCount] = strdup(buffer);
    (*lineCount)++;
  }

  // 5. Cleanup
  fclose(fptr);
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
