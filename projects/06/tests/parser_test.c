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
  mu_assert_int_eq(1, third_line);
}
MU_TEST(advance_test) {
  char *lines[] = {"@i", "M=1", "// comment", "     ", "@sum"};
  int instruction_count = 5;
  int line_number = 0;
  char *next_line = advance(lines, &line_number, instruction_count);
  mu_assert_string_eq("@i", next_line);
  line_number++;
  next_line = advance(lines, &line_number, instruction_count);
  mu_assert_string_eq("M=1", next_line);
  line_number++;
  next_line = advance(lines, &line_number, instruction_count);
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
  symbol1 = symbol("(xxx)");
  mu_assert_string_eq("xxx", symbol1);
}
MU_TEST(dest_test) {
  char *dest0 = parser_dest("null=D+1;JLE");
  mu_assert_string_eq("null", dest0);
  dest0 = parser_dest("M=D+1;JLE");
  mu_assert_string_eq("M", dest0);
  dest0 = parser_dest("D=D+1;JLE");
  mu_assert_string_eq("D", dest0);
  dest0 = parser_dest("DM=D+1;JLE");
  mu_assert_string_eq("DM", dest0);
  dest0 = parser_dest("A=D+1;JLE");
  mu_assert_string_eq("A", dest0);
  dest0 = parser_dest("AM=D+1;JLE");
  mu_assert_string_eq("AM", dest0);
  dest0 = parser_dest("AD=D+1;JLE");
  mu_assert_string_eq("AD", dest0);
  dest0 = parser_dest("ADM=D+1;JLE");
  mu_assert_string_eq("ADM", dest0);
  dest0 = parser_dest("M=0");
  mu_assert_string_eq("M", dest0);
  dest0 = parser_dest("D;JGT");
  mu_assert_string_eq("null", dest0);
}
MU_TEST(comp_test) {
  char *comp0 = parser_comp("D=0;JLE");
  mu_assert_string_eq("0", comp0);
  comp0 = parser_comp("M=1;JLE");
  mu_assert_string_eq("1", comp0);
  comp0 = parser_comp("D=-1;JLE");
  mu_assert_string_eq("-1", comp0);
  comp0 = parser_comp("DM=D;JLE");
  mu_assert_string_eq("D", comp0);
  comp0 = parser_comp("A=!D;JLE");
  mu_assert_string_eq("!D", comp0);
  comp0 = parser_comp("AM=-D;JLE");
  mu_assert_string_eq("-D", comp0);
  comp0 = parser_comp("AD=D+1;JLE");
  mu_assert_string_eq("D+1", comp0);
  comp0 = parser_comp("ADM=D|A;JLE");
  mu_assert_string_eq("D|A", comp0);
  comp0 = parser_comp("M=0");
  mu_assert_string_eq("0", comp0);
  comp0 = parser_comp("D;JGT");
  mu_assert_string_eq("D", comp0);
}
MU_TEST(jump_test) {
  char *jump0 = parser_jump("D=D+1;null");
  mu_assert_string_eq("null", jump0);
  jump0 = parser_jump("D=D+1;JGT");
  mu_assert_string_eq("JGT", jump0);
  jump0 = parser_jump("D=D+1;JEQ");
  mu_assert_string_eq("JEQ", jump0);
  jump0 = parser_jump("D=D+1;JGE");
  mu_assert_string_eq("JGE", jump0);
  jump0 = parser_jump("D=D+1;JLT");
  mu_assert_string_eq("JLT", jump0);
  jump0 = parser_jump("D=D+1;JNE");
  mu_assert_string_eq("JNE", jump0);
  jump0 = parser_jump("D=D+1;JLE");
  mu_assert_string_eq("JLE", jump0);
  jump0 = parser_jump("D=D+1;JMP");
  mu_assert_string_eq("JMP", jump0);
  jump0 = parser_jump("M=0");
  mu_assert_string_eq("null", jump0);
  jump0 = parser_jump("D;JGT");
  mu_assert_string_eq("JGT", jump0);
}
MU_TEST_SUITE(test_suite) {
  MU_RUN_TEST(constructor_test);
  MU_RUN_TEST(has_more_lines_test);
  MU_RUN_TEST(advance_test);
  MU_RUN_TEST(instruction_type_test);
  MU_RUN_TEST(symbol_test);
  MU_RUN_TEST(dest_test);
  MU_RUN_TEST(comp_test);
  MU_RUN_TEST(jump_test);
}

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
