#include "../s21_tests.h"

START_TEST(s21_atan_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), S21_EPS);
}
END_TEST
START_TEST(s21_atan_test_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), S21_EPS);
}
END_TEST
START_TEST(s21_atan_test_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), S21_EPS);
}
END_TEST
START_TEST(s21_atan_test_4) {
  ck_assert_ldouble_eq_tol(atan(INFINITY), s21_atan(INFINITY), S21_EPS);
}
END_TEST
START_TEST(s21_atan_test_5) {
  ck_assert_ldouble_nan(atan(NAN));
  ck_assert_ldouble_nan(s21_atan(NAN));
}
END_TEST
START_TEST(s21_atan_test_6) {
  for (double x = -123422; x < 123442; x += 13204.523)
    ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), S21_EPS);
}
END_TEST
START_TEST(s21_atan_test_7) {
  for (double x = -1; x < 1; x += 0.0157)
    ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), S21_EPS);
}
END_TEST
START_TEST(s21_atan_test_8) {
  ck_assert_ldouble_eq_tol(atan(-INFINITY), s21_atan(-INFINITY), S21_EPS);
}
END_TEST
START_TEST(s21_atan_test_9) {
  double x = 99999;
  ck_assert_ldouble_eq_tol(atan(x), s21_atan(x), S21_EPS);
}
END_TEST

Suite *s21_atan_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_atan_test |\033[0m");
  t = tcase_create("s21_atan_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_atan_test_1);
  tcase_add_test(t, s21_atan_test_2);
  tcase_add_test(t, s21_atan_test_3);
  tcase_add_test(t, s21_atan_test_4);
  tcase_add_test(t, s21_atan_test_5);
  tcase_add_test(t, s21_atan_test_6);
  tcase_add_test(t, s21_atan_test_7);
  tcase_add_test(t, s21_atan_test_8);
  tcase_add_test(t, s21_atan_test_9);
  suite_add_tcase(s, t);
  return s;
}