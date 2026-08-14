#include "assembler.h"
#include "minunit.h"
#include "parser.h"
#include "symbol_table.h"

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
MU_TEST_SUITE(test_suite) { MU_RUN_TEST(first_pass_test); }

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
