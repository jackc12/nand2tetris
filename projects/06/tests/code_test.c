#include "code.h"
#include "minunit.h"

MU_TEST(dest_test) {
  char *hack = dest("null");
  mu_assert_string_eq("000", hack);
  hack = dest("M");
  mu_assert_string_eq("001", hack);
  hack = dest("D");
  mu_assert_string_eq("010", hack);
  hack = dest("DM");
  mu_assert_string_eq("011", hack);
  hack = dest("A");
  mu_assert_string_eq("100", hack);
  hack = dest("AM");
  mu_assert_string_eq("101", hack);
  hack = dest("AD");
  mu_assert_string_eq("110", hack);
  hack = dest("ADM");
  mu_assert_string_eq("111", hack);
}
MU_TEST(comp_test) {
  char *hack = dest("null");
  mu_assert_string_eq("000", hack);
}
MU_TEST(jump_test) {
  char *hack = jump("null");
  mu_assert_string_eq("000", hack);
  hack = jump("JGT");
  mu_assert_string_eq("001", hack);
  hack = jump("JEQ");
  mu_assert_string_eq("010", hack);
  hack = jump("JGE");
  mu_assert_string_eq("011", hack);
  hack = jump("JLT");
  mu_assert_string_eq("100", hack);
  hack = jump("JNE");
  mu_assert_string_eq("101", hack);
  hack = jump("JLE");
  mu_assert_string_eq("110", hack);
  hack = jump("JMP");
  mu_assert_string_eq("111", hack);
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
