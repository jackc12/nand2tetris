#include "minunit.h"
#include "code.h"

MU_TEST(dest_test) {
  char *hack = dest("null")
  mu_assert_string_eq("000", next_line);
  hack = dest("M")
  mu_assert_string_eq("001", next_line);
  hack = dest("D")
  mu_assert_string_eq("010", next_line);
  hack = dest("DM")
  mu_assert_string_eq("011", next_line);
  hack = dest("A")
  mu_assert_string_eq("100", next_line);
  hack = dest("AM")
  mu_assert_string_eq("101", next_line);
  hack = dest("AD")
  mu_assert_string_eq("110", next_line);
  hack = dest("ADM")
  mu_assert_string_eq("111", next_line);
}
MU_TEST(comp_test) {
}
MU_TEST(jump_test) {
}
MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(comp_test);
  MU_RUN_TEST(dest_test);
  MU_RUN_TEST(jump_test);
}

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
