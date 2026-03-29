#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Returns the binary code of the comp mnemonic
 */
char *code_comp(char *comp) {
  if (strcmp(comp, "null") == 0)
    return "000";
  else if (strcmp(comp, "M") == 0)
    return "001";
  else if (strcmp(comp, "D") == 0)
    return "010";
  else if (strcmp(comp, "DM") == 0)
    return "011";
  else if (strcmp(comp, "A") == 0)
    return "100";
  else if (strcmp(comp, "AM") == 0)
    return "101";
  else if (strcmp(comp, "AD") == 0)
    return "110";
  else if (strcmp(comp, "ADM") == 0)
    return "111";
}

/**
 * Returns the binary code of the dest mnemonic
 */
char *code_dest(char *dest) { return dest; }

/**
 * Returns the binary code of the jump mnemonic
 */
char *code_jump(char *dest) { return dest; }
