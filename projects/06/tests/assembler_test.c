#include "assembler.h"
#include "minunit.h"
#include <stddef.h>

MU_TEST(int_to_bin_test) {
  char binary[17] = "";
  size_t binary_size = sizeof(binary);
  char nine[16] = "9", twelve[16] = "12", twelve_k[16] = "12000";
  int_to_bin(nine, binary, binary_size);
  mu_assert_string_eq("0000000000001001", binary);
}
MU_TEST_SUITE(test_suite) { MU_RUN_TEST(int_to_bin_test); }

int main() {
  MU_RUN_SUITE(test_suite);
  MU_REPORT();
  return MU_EXIT_CODE;
}
