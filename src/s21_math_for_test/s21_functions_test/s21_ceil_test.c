#include "../s21_tests.h"

START_TEST(s21_ceil_test_1) {
  ck_assert_ldouble_nan(ceill(S21_NAN));
  ck_assert_ldouble_nan(s21_ceil(S21_NAN));
}
END_TEST
START_TEST(s21_ceil_test_2) {
  ck_assert_ldouble_infinite(ceill(S21_INF));
  ck_assert_ldouble_infinite(s21_ceil(-S21_INF));
}
END_TEST
START_TEST(s21_ceil_test_3) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), S21_EPS);
}
END_TEST
START_TEST(s21_ceil_test_4) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), S21_EPS);
}
END_TEST
START_TEST(s21_ceil_test_5) {
  for (long double x = -1341.324; x < 1000.000000; x += 125.213) {
    ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), S21_EPS);
  }
}
END_TEST
START_TEST(s21_ceil_test_6) {
  double x = -0.5;
  ck_assert_ldouble_eq_tol(ceil(x), s21_ceil(x), S21_EPS);
}
END_TEST
Suite *s21_ceil_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_ceil_test |\033[0m");
  t = tcase_create("s21_ceil_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_ceil_test_1);
  tcase_add_test(t, s21_ceil_test_2);
  tcase_add_test(t, s21_ceil_test_3);
  tcase_add_test(t, s21_ceil_test_4);
  tcase_add_test(t, s21_ceil_test_5);
  tcase_add_test(t, s21_ceil_test_6);
  suite_add_tcase(s, t);
  return s;
}