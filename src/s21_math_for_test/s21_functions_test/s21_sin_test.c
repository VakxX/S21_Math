#include "../s21_tests.h"

START_TEST(s21_sin_test_1) {
  ck_assert_ldouble_nan(sinl(S21_NAN));
  ck_assert_ldouble_nan(s21_sin(S21_NAN));
}
END_TEST

START_TEST(s21_sin_test_2) {
  ck_assert_ldouble_nan(sinl(S21_INF));
  ck_assert_ldouble_nan(s21_sin(-S21_INF));
}
END_TEST
START_TEST(s21_sin_test_3) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(sinl(x), s21_sin(x), S21_EPS);
}
END_TEST
START_TEST(s21_sin_test_4) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(sinl(x), s21_sin(x), S21_EPS);
}
END_TEST
START_TEST(s21_sin_test_5) {
  for (double x = -1341.324; x < 1000.000000; x += 75.213) {
    ck_assert_ldouble_eq_tol(sin(x), s21_sin(x), S21_EPS);
  }
}
END_TEST

Suite *s21_sin_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_sin_test |\033[0m");
  t = tcase_create("s21_sin_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_sin_test_1);
  tcase_add_test(t, s21_sin_test_2);
  tcase_add_test(t, s21_sin_test_3);
  tcase_add_test(t, s21_sin_test_4);
  tcase_add_test(t, s21_sin_test_5);
  suite_add_tcase(s, t);
  return s;
}