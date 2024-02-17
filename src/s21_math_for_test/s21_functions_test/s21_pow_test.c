#include "../../s21_math.h"
#include "../s21_tests.h"

START_TEST(s21_pow_test_1) {
  double base = 0.0 / 0.0;
  double exp = 2.0;

  ck_assert_ldouble_nan(s21_pow(base, exp));
  ck_assert_ldouble_nan(pow(base, exp));
}
END_TEST
START_TEST(s21_pow_test_2) {
  double base = 1.0;
  double exp = 3.0;

  long double result = s21_pow(base, exp);
  ck_assert(result == 1.0);
}
END_TEST

START_TEST(s21_pow_test_3) {
  double base = 0.0;
  double exp = 0.0;

  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_double_eq(result, expected);
}
END_TEST
START_TEST(s21_pow_test_4) {
  double base = 0.0;
  double exp = 3.0;

  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_double_eq(result, expected);
}
END_TEST
START_TEST(s21_pow_test_5) {
  double base = 3.0;
  double exp = -INFINITY;

  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_double_eq(result, expected);
}
END_TEST
START_TEST(s21_pow_test_6) {
  double base = -INFINITY;
  double exp = INFINITY;

  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_double_eq(result, expected);
}
END_TEST
START_TEST(s21_pow_test_7) {
  double base = 31251234125143.0;
  double exp = 31251234125143.0;

  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_double_infinite(result);
  ck_assert_double_infinite(expected);
}
END_TEST
START_TEST(s21_pow_test_8) {
  double base = -412975982379182;
  double exp = -412975982379182;
  ck_assert_ldouble_eq_tol(s21_pow(base, exp), pow(base, exp), S21_EPS);
}
END_TEST
START_TEST(s21_pow_test_9) {
  double base = 2.0;
  double exp = -3.0;

  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_double_eq(result, expected);
}
END_TEST
START_TEST(s21_pow_test_10) {
  double base = 2.0;
  double exp = 1.5;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert((result - expected) < 0.0001);
}
END_TEST
START_TEST(s21_pow_test_11) {
  double base = 2.0;
  double exp = -0.52;
  long double result = s21_pow(base, exp);
  long double expected = pow(base, exp);
  ck_assert_double_eq(result, expected);
}
END_TEST
Suite *s21_pow_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_pow_test |\033[0m");
  t = tcase_create("s21_pow_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_pow_test_1);
  tcase_add_test(t, s21_pow_test_2);
  tcase_add_test(t, s21_pow_test_3);
  tcase_add_test(t, s21_pow_test_4);
  tcase_add_test(t, s21_pow_test_5);
  tcase_add_test(t, s21_pow_test_6);
  tcase_add_test(t, s21_pow_test_7);
  tcase_add_test(t, s21_pow_test_8);
  tcase_add_test(t, s21_pow_test_9);
  tcase_add_test(t, s21_pow_test_10);
  tcase_add_test(t, s21_pow_test_11);
  suite_add_tcase(s, t);
  return s;
}