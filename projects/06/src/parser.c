#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc < 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }
  FILE *fptr = fopen(argv[1], "r");

  // 3. Error handling if file doesn't exist
  if (fptr == NULL) {
    perror("Error opening file"); // Prints a descriptive error message
    return 1;
  }

  char ch;
  // 4. Read and print character by character until End Of File (EOF)
  while ((ch = fgetc(fptr)) != EOF) {
    printf("%c", ch);
  }

  // 5. Cleanup
  fclose(fptr);
  return 0;
}
