#include "minunit.h"
#include "symbol_table.h"

MU_TEST(contains_test) {
  SymbolTable *symbol_table = constructor();
  int contains_ = contains(symbol_table, "R0");
  assert_int_eq(contains_, "0");
}
MU_TEST_SUITE(test_suite) { MU_RUN_TEST(constructor_test); }

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
