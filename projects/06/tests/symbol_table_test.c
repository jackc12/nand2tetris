#include "minunit.h"
#include "symbol_table.h"

MU_TEST(constructor_test) {
  SymbolTable *symbol_table = constructor(), *result = NULL;
  HASH_FIND_STR(symbol_table, "R0", result);
  mu_assert_int_eq(0, result->value);
  HASH_FIND_STR(symbol_table, "SCREEN", result);
  mu_assert_int_eq(16384, result->value);
}
MU_TEST(add_entry_test) {
  SymbolTable *symbol_table = constructor(), *result = NULL;
  add_entry(symbol_table, "VON", 64);
  HASH_FIND_STR(symbol_table, "VON", result);
  mu_assert_int_eq(64, resumt);
}
MU_TEST(contains_test) {
  SymbolTable *symbol_table = constructor();
  int contains_ = contains(symbol_table, "R0");
  mu_assert_int_eq(1, contains_);
  contains_ = contains(symbol_table, "SMURK");
  mu_assert_int_eq(0, contains_);
}
MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(constructor_test);
  MU_RUN_TEST(add_entry_test);
  MU_RUN_TEST(contains_test);
}

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
