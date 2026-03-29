#include "code.h"
#include "minunit.h"

MU_TEST(code_dest_test) {
  char *hack = code_dest("null");
  mu_assert_string_eq("000", hack);
  hack = code_dest("M");
  mu_assert_string_eq("001", hack);
  hack = code_dest("D");
  mu_assert_string_eq("010", hack);
  hack = code_dest("DM");
  mu_assert_string_eq("011", hack);
  hack = code_dest("A");
  mu_assert_string_eq("100", hack);
  hack = code_dest("AM");
  mu_assert_string_eq("101", hack);
  hack = code_dest("AD");
  mu_assert_string_eq("110", hack);
  hack = code_dest("ADM");
  mu_assert_string_eq("111", hack);
}
MU_TEST(code_comp_test) {
  char *hack = code_comp("0");
  mu_assert_string_eq("0101010", hack);
  hack = code_comp("1");
  mu_assert_string_eq("0111111", hack);
  hack = code_comp("-1");
  mu_assert_string_eq("0111010", hack);
  hack = code_comp("D");
  mu_assert_string_eq("0001100", hack);
  hack = code_comp("A");
  mu_assert_string_eq("0110000", hack);
  hack = code_comp("!D");
  mu_assert_string_eq("0001101", hack);
  hack = code_comp("!A");
  mu_assert_string_eq("0110001", hack);
  hack = code_comp("-D");
  mu_assert_string_eq("0001111", hack);
  hack = code_comp("-A");
  mu_assert_string_eq("0110011", hack);
  hack = code_comp("D+1");
  mu_assert_string_eq("0111111", hack);
  hack = code_comp("A+1");
  mu_assert_string_eq("0110111", hack);
  hack = code_comp("D-1");
  mu_assert_string_eq("0001110", hack);
  hack = code_comp("A-1");
  mu_assert_string_eq("0110010", hack);
  hack = code_comp("D+A");
  mu_assert_string_eq("0000010", hack);
  hack = code_comp("D-A");
  mu_assert_string_eq("0010011", hack);
  hack = code_comp("A-D");
  mu_assert_string_eq("0000111", hack);
  hack = code_comp("D&A");
  mu_assert_string_eq("0000000", hack);
  hack = code_comp("D|A");
  mu_assert_string_eq("0010101", hack);
  hack = code_comp("M");
  mu_assert_string_eq("1110000", hack);
  hack = code_comp("!M");
  mu_assert_string_eq("1110001", hack);
  hack = code_comp("-M");
  mu_assert_string_eq("1110011", hack);
  hack = code_comp("M+1");
  mu_assert_string_eq("1110111", hack);
  hack = code_comp("M-1");
  mu_assert_string_eq("1110010", hack);
  hack = code_comp("D+M");
  mu_assert_string_eq("1000010", hack);
  hack = code_comp("D-M");
  mu_assert_string_eq("1010011", hack);
  hack = code_comp("M-D");
  mu_assert_string_eq("1000111", hack);
  hack = code_comp("D&M");
  mu_assert_string_eq("1000000", hack);
  hack = code_comp("D|M");
  mu_assert_string_eq("1010101", hack);
}
MU_TEST(code_jump_test) {
  char *hack = code_jump("null");
  mu_assert_string_eq("000", hack);
  hack = code_jump("JGT");
  mu_assert_string_eq("001", hack);
  hack = code_jump("JEQ");
  mu_assert_string_eq("010", hack);
  hack = code_jump("JGE");
  mu_assert_string_eq("011", hack);
  hack = code_jump("JLT");
  mu_assert_string_eq("100", hack);
  hack = code_jump("JNE");
  mu_assert_string_eq("101", hack);
  hack = code_jump("JLE");
  mu_assert_string_eq("110", hack);
  hack = code_jump("JMP");
  mu_assert_string_eq("111", hack);
}
MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(code_dest_test);
  // MU_RUN_TEST(code_comp_test);
  MU_RUN_TEST(code_jump_test);
}

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
