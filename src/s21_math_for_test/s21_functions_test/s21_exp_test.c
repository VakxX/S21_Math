#include "../s21_tests.h"

START_TEST(s21_exp_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(expl(x), s21_exp(x), S21_EPS);
}
END_TEST
START_TEST(s21_exp_test_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(expl(x), s21_exp(x), S21_EPS);
}
END_TEST
START_TEST(s21_exp_test_3) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(expl(x), s21_exp(x), S21_EPS);
}
END_TEST
START_TEST(s21_exp_test_4) {
  ck_assert_ldouble_nan(expl(NAN));
  ck_assert_ldouble_nan(s21_exp(NAN));
}
END_TEST
START_TEST(s21_exp_test_5) {
  ck_assert_ldouble_infinite(expl(INFINITY));
  ck_assert_ldouble_infinite(s21_exp(INFINITY));
}
END_TEST
START_TEST(s21_exp_test_6) {
  double x = -INFINITY;
  ck_assert_ldouble_eq_tol(expl(x), s21_exp(x), S21_EPS);
}
END_TEST
START_TEST(s21_exp_test_7) {
  for (double x = -24.240233; x < 28; x = x + 1.012321) {
    ck_assert_ldouble_eq_tol(expl(x), s21_exp(x), S21_EPS);
  }
}
END_TEST
START_TEST(s21_exp_test_8) {
  double x = -10.25;
  ck_assert_ldouble_eq_tol(expl(x), s21_exp(x), S21_EPS);
}
END_TEST

Suite *s21_exp_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_exp_test |\033[0m");
  t = tcase_create("s21_exp_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_exp_test_1);
  tcase_add_test(t, s21_exp_test_2);
  tcase_add_test(t, s21_exp_test_3);
  tcase_add_test(t, s21_exp_test_4);
  tcase_add_test(t, s21_exp_test_5);
  tcase_add_test(t, s21_exp_test_6);
  tcase_add_test(t, s21_exp_test_7);
  tcase_add_test(t, s21_exp_test_8);
  suite_add_tcase(s, t);
  return s;
}