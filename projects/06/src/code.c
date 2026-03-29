#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Returns the binary code of the dest mnemonic
 */
char *code_dest(char *dest) {
  if (strcmp(dest, "null") == 0)
    return "000";
  else if (strcmp(dest, "M") == 0)
    return "001";
  else if (strcmp(dest, "D") == 0)
    return "010";
  else if (strcmp(dest, "DM") == 0)
    return "011";
  else if (strcmp(dest, "A") == 0)
    return "100";
  else if (strcmp(dest, "AM") == 0)
    return "101";
  else if (strcmp(dest, "AD") == 0)
    return "110";
  else if (strcmp(dest, "ADM") == 0)
    return "111";
  else
    return "INVALID_INSTRUCTION";
}

/**
 * Returns the binary code of the comp mnemonic
 */
char *code_comp(char *comp) { return comp; }

/**
 * Returns the binary code of the jump mnemonic
 */
char *code_jump(char *dest) { 
  if (strcmp(dest, "null") == 0)
    return "000";
  else if (strcmp(dest, "JGT") == 0)
    return "001";
  else if (strcmp(dest, "JEQ") == 0)
    return "010";
  else if (strcmp(dest, "JGE") == 0)
    return "011";
  else if (strcmp(dest, "JLT") == 0)
    return "100";
  else if (strcmp(dest, "JNE") == 0)
    return "101";
  else if (strcmp(dest, "JLE") == 0)
    return "110";
  else if (strcmp(dest, "JMP") == 0)
    return "111";
  else
    return "INVALID_INSTRUCTION";
 }
