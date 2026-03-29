#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * Returns the binary code of the comp mnemonic
 */
char *comp(char *comp) {
  switch (comp) {
  case "null":
    return "000";
  case "M":
    return "001";
  case "D":
    return "010";
  case "DM":
    return "011";
  case "A":
    return "100";
  case "AM":
    return "101";
  case "AD":
    return "110";
  case "ADM":
    return "111";
  }
}

/**
 * Returns the binary code of the dest mnemonic
 */
char *dest(char *dest) {}

/**
 * Returns the binary code of the jump mnemonic
 */
char *jump(char *dest) {}
