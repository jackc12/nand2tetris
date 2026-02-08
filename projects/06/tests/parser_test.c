#include "minunit.h"
#include "parser.h"

MU_TEST(constructor_test) {
  char **lines = constructor("tests/files/hello_world.txt");
  mu_assert_string_eq("hello world", lines[0]);
}
MU_TEST_SUITE(test_suite) { MU_RUN_TEST(constructor_test); }

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
