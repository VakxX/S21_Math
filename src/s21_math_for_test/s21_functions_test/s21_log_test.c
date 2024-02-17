#include "../s21_tests.h"

START_TEST(s21_log_test_1) {
  ck_assert_ldouble_infinite(log(INFINITY));
  ck_assert_ldouble_infinite(s21_log(S21_INF));
}
END_TEST
START_TEST(s21_log_test_2) {
  double x = 0.0;
  ck_assert_ldouble_infinite(log(x));
  ck_assert_ldouble_infinite(s21_log(x));
}
END_TEST
START_TEST(s21_log_test_3) {
  double x = 14;
  ck_assert_ldouble_eq_tol(log(x), s21_log(x), S21_EPS);
}
END_TEST
START_TEST(s21_log_test_4) {
  double x = -1.0;
  ck_assert_ldouble_nan(log(x));
  ck_assert_ldouble_nan(s21_log(x));
}
END_TEST
START_TEST(s21_log_test_5) {
  for (double x = 1.41423; x < 1e7; x += 1234.512)
    ck_assert_double_eq_tol(s21_log(x), log(x), S21_EPS);
}
END_TEST

Suite *s21_log_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_log_test |\033[0m");
  t = tcase_create("s21_log_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_log_test_1);
  tcase_add_test(t, s21_log_test_2);
  tcase_add_test(t, s21_log_test_3);
  tcase_add_test(t, s21_log_test_4);
  tcase_add_test(t, s21_log_test_5);
  suite_add_tcase(s, t);
  return s;
}