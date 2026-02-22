#include "minunit.h"
#include "parser.h"

MU_TEST(constructor_test) {
  int instruction_count;
  char **lines = constructor("tests/files/crazy_story.txt", &instruction_count);
  mu_assert_string_eq(
      "He got bricks, plus his neck is icy and it match his wrist", lines[0]);
  mu_assert_string_eq(
      "Now it’s like six, told her hit his phone, meet her in the WIIIC",
      lines[1]);
  mu_assert_string_eq("But he ain't go, buddy ain’t that slow, say meet him at "
                      "the store (That's cool)",
                      lines[2]);
  mu_assert_int_eq(3, instruction_count);
}
MU_TEST(has_more_lines_test) {
  int instruction_count = 3;
  // index starts at 0
  int second_line = has_more_lines(1, instruction_count);
  int third_line = has_more_lines(2, instruction_count);
  mu_assert_int_eq(1, second_line);
  mu_assert_int_eq(0, third_line);
}
MU_TEST(advance_test) {
  char *lines[] = {"@i", "M=1", "// comment", "     ", "@sum"};
  int instruction_count = 5;
  char *next_line = advance(lines, 0, instruction_count);
  mu_assert_string_eq("M=1", next_line);
  next_line = advance(lines, 1, instruction_count);
  mu_assert_string_eq("@sum", next_line);
}
MU_TEST(instruction_type_test) {
  instruction_t type = instruction_type("@i");
  mu_check(A_INSTRUCTION == type);
  type = instruction_type("(xxx)");
  mu_check(L_INSTRUCTION == type);
  type = instruction_type("D=D+1;JLE");
  mu_check(C_INSTRUCTION == type);
}
MU_TEST(symbol_test) {
  char *symbol1 = symbol("@xxx");
  mu_assert_string_eq("xxx", symbol1);
  // *symbol = instruction_type("(xxx)");
  // mu_assert_string_eq("xxx", symbol);
}
MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(constructor_test);
  MU_RUN_TEST(has_more_lines_test);
  MU_RUN_TEST(advance_test);
  MU_RUN_TEST(instruction_type_test);
  MU_RUN_TEST(symbol_test);
}

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
