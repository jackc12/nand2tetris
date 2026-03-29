#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
  if (argc != 2)
    return 0;
  else {
    printf("\n\n%s\n\n", argv[1]);
    return 0;
  }
}
