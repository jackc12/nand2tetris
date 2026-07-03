#include "assembler.h"
#include <stdio.h>
#include <stdlib.h>

void int_to_bin(char *a_instruction, char *binary, size_t binary_size) {
  int integer = atoi(a_instruction);
  int current_len = 0;
  for (int i = 15; i >= 0; i--) {
    int remaining_space = binary_size - current_len;
    int written = snprintf(binary + current_len, remaining_space, "%d",
                           (integer >> i) & 1);
    current_len += written;
    if (current_len >= (int)binary_size) {
      break;
    }
  }
}
