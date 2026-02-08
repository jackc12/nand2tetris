#include "minunit.h"
#include "parser.h"

MU_TEST(constructor_test) {
  int count;
  char **lines = constructor("tests/files/hello_world.txt", &count);
  mu_assert_string_eq("hello world", lines[0]);
  mu_assert_int_eq(1, count);
}
MU_TEST(has_more_lines_test) {
  int line_count = 3;
  // index starts at 0
  int second_line = has_more_lines(line_count, 1);
  int third_line = has_more_lines(line_count, 2);
  mu_assert_int_eq(1, second_line);
  mu_assert_int_eq(0, third_line);
}
MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(constructor_test);
  MU_RUN_TEST(has_more_lines_test);
}

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
