#include "assembler.h"
#include "minunit.h"
#include "parser.h"
#include "symbol_table.h"
#include <stddef.h>

MU_TEST(int_to_bin_test) {
  char binary[17] = "";
  size_t binary_size = sizeof(binary);
  char nine[16] = "9", twelve[16] = "12", twelve_k[16] = "12000";
  int_to_bin(nine, binary, binary_size);
  mu_assert_string_eq("0000000000001001", binary);
  int_to_bin(twelve, binary, binary_size);
  mu_assert_string_eq("0000000000001100", binary);
  int_to_bin(twelve_k, binary, binary_size);
  mu_assert_string_eq("0010111011100000", binary);
}
MU_TEST(first_pass_test) {
  int instruction_count, line_number;
  char **lines =
      constructor("tests/asm/first_pass_test.asm", &instruction_count);
  SymbolTable *symbol_table = new_symbol_table();
  first_pass(&symbol_table, lines, instruction_count);
  line_number = get_address(symbol_table, "LOOP");
  mu_assert_int_eq(4, line_number);
  line_number = get_address(symbol_table, "STOP");
  mu_assert_int_eq(18, line_number);
}
MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(int_to_bin_test);
  MU_RUN_TEST(first_pass_test);
}

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
