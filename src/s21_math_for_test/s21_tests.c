#include "s21_tests.h"

int main(void) {
  int test_fail = 0;
  int test_successed = 0;
  int gg = 0;
  Suite *s[] = {s21_tan_test(),   s21_cos_test(),  s21_acos_test(),
                s21_fabs_test(),  s21_abs_test(),  s21_pow_test(),
                s21_floor_test(), s21_sin_test(),  s21_atan_test(),
                s21_ceil_test(),  s21_asin_test(), s21_exp_test(),
                s21_fmod_test(),  s21_log_test(),  s21_sqrt_test()};
  for (Suite **cur = s; gg < 15; cur++) {
    SRunner *sr;
    sr = srunner_create(*cur);
    srunner_run_all(sr, CK_VERBOSE);
    test_fail += srunner_ntests_failed(sr);
    if (test_fail == 0) test_successed += 1;
    srunner_free(sr);
    gg++;
  }
  printf("\033[43m Tests => \033[42m Success: %d  \033[41m Fail: %d  \033[0m\n",
         test_successed, test_fail);
  return (test_fail == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
