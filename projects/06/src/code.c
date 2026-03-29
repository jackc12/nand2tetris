#include "parser.h"
#include <stdio.h>
#include <string.h>

/**
 * Returns the binary code of the dest mnemonic
 */
char *code_dest(char *dest) {
  printf("%s\n", dest);
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
char *code_comp(char *comp) {
  if (strcmp(comp, "0") == 0)
    return "0101010";
  else if (strcmp(comp, "1") == 0)
    return "0111111";
  else if (strcmp(comp, "-1") == 0)
    return "0111010";
  else if (strcmp(comp, "D") == 0)
    return "0001100";
  else if (strcmp(comp, "A") == 0)
    return "0110000";
  else if (strcmp(comp, "!D") == 0)
    return "0001101";
  else if (strcmp(comp, "!A") == 0)
    return "0110001";
  else if (strcmp(comp, "-D") == 0)
    return "0001111";
  else if (strcmp(comp, "-A") == 0)
    return "0110011";
  else if (strcmp(comp, "D+1") == 0)
    return "0111111";
  else if (strcmp(comp, "A+1") == 0)
    return "0110111";
  else if (strcmp(comp, "D-1") == 0)
    return "0001110";
  else if (strcmp(comp, "A-1") == 0)
    return "0110010";
  else if (strcmp(comp, "D+A") == 0)
    return "0000010";
  else if (strcmp(comp, "D-A") == 0)
    return "0010011";
  else if (strcmp(comp, "A-D") == 0)
    return "0000111";
  else if (strcmp(comp, "D&A") == 0)
    return "0000000";
  else if (strcmp(comp, "D|A") == 0)
    return "0010101";
  else if (strcmp(comp, "M") == 0)
    return "1110000";
  else if (strcmp(comp, "!M") == 0)
    return "1110001";
  else if (strcmp(comp, "-M") == 0)
    return "1110011";
  else if (strcmp(comp, "M+1") == 0)
    return "1110111";
  else if (strcmp(comp, "M-1") == 0)
    return "1110010";
  else if (strcmp(comp, "D+M") == 0)
    return "1000010";
  else if (strcmp(comp, "D-M") == 0)
    return "1010011";
  else if (strcmp(comp, "M-D") == 0)
    return "1000111";
  else if (strcmp(comp, "D&M") == 0)
    return "1000000";
  else if (strcmp(comp, "D|M") == 0)
    return "1010101";
  else
    return "INVALID_INSTRUCTION";
}

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
