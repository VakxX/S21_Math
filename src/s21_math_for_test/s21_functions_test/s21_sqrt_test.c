#include "../s21_tests.h"

START_TEST(s21_sqrt_test_1) {
  ck_assert_ldouble_nan(sqrtl(S21_NAN));
  ck_assert_ldouble_nan(s21_sqrt(S21_NAN));
}
END_TEST

START_TEST(s21_sqrt_test_2) {
  ck_assert_ldouble_infinite(sqrtl(S21_INF));
  ck_assert_ldouble_nan(s21_sqrt(-S21_INF));
}
END_TEST
START_TEST(s21_sqrt_test_3) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(sqrtl(x), s21_sqrt(x), S21_EPS);
}
END_TEST
START_TEST(s21_sqrt_test_4) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(sqrtl(x), s21_sqrt(x), S21_EPS);
}
END_TEST
START_TEST(s21_sqrt_test_5) {
  for (double x = -1324.24; x < 0; x += 75.213) {
    ck_assert_ldouble_nan(s21_sqrt(x));
  }
}
END_TEST
START_TEST(s21_sqrt_test_6) {
  for (double x = 0.0; x < 2134.2134; x += 75.213) {
    ck_assert_ldouble_eq_tol(sqrtl(x), s21_sqrt(x), S21_EPS);
  }
}
END_TEST

Suite *s21_sqrt_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_sqrt_test |\033[0m");
  t = tcase_create("s21_sqrt_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_sqrt_test_1);
  tcase_add_test(t, s21_sqrt_test_2);
  tcase_add_test(t, s21_sqrt_test_3);
  tcase_add_test(t, s21_sqrt_test_4);
  tcase_add_test(t, s21_sqrt_test_5);
  tcase_add_test(t, s21_sqrt_test_6);
  suite_add_tcase(s, t);
  return s;
}