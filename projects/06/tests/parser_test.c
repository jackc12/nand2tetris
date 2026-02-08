#include "minunit.h"
#include "parser.h"

MU_TEST(constructor_test) {
  int count;
  char **lines = constructor("tests/files/hello_world.txt", &count);
  for (int i = 0; i < 1; i++)
    printf("%s\n", lines[i]);
  mu_assert_string_eq("hello world", lines[0]);
}
MU_TEST(hasMoreLines_test) {
  const char *lines[] = {"pooh shiesty", "king von", "lil durk"};
  int three_lines = hasMoreLines(lines, 2);
  int four_lines = hasMoreLines(lines, 3);
  mu_assert_int_eq(1, three_lines);
  mu_assert_int_eq(0, four_lines);
}
MU_TEST_SUITE(test_suite) {
  // MU_RUN_TEST(constructor_test);
  MU_RUN_TEST(hasMoreLines_test);
}

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
