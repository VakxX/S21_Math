#include "../s21_tests.h"

START_TEST(s21_floor_test_1) {
  double x = 453.0000001;
  ck_assert_ldouble_eq_tol(floorl(x), s21_floor(x), S21_EPS);
}
END_TEST
START_TEST(s21_floor_test_2) {
  double x = -1.0000001;
  ck_assert_ldouble_eq_tol(floorl(x), s21_floor(x), S21_EPS);
}
END_TEST
START_TEST(s21_floor_test_3) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(floorl(x), s21_floor(x), S21_EPS);
}
END_TEST
START_TEST(s21_floor_test_4) {
  double x = +0.0;
  ck_assert_ldouble_eq_tol(floorl(x), s21_floor(x), S21_EPS);
}
END_TEST
START_TEST(s21_floor_test_5) {
  double x = 0.0;
  ck_assert_ldouble_eq_tol(floorl(x), s21_floor(x), S21_EPS);
}
END_TEST
START_TEST(s21_floor_test_6) {
  double x = -1.0;
  ck_assert_ldouble_eq_tol(floorl(x), s21_floor(x), S21_EPS);
}
END_TEST
START_TEST(s21_floor_test_7) {
  double x = +4.0;
  ck_assert_ldouble_eq_tol(floorl(x), s21_floor(x), S21_EPS);
}
END_TEST
START_TEST(s21_floor_test_8) {
  ck_assert_ldouble_nan(floorl(NAN));
  ck_assert_ldouble_nan(s21_floor(NAN));
}
END_TEST
START_TEST(s21_floor_test_9) {
  ck_assert_ldouble_infinite(floorl(INFINITY));
  ck_assert_ldouble_infinite(s21_floor(INFINITY));
}
END_TEST
START_TEST(s21_floor_test_10) {
  ck_assert_ldouble_infinite(floorl(S21_INF_MIN));
  ck_assert_ldouble_infinite(s21_floor(S21_INF_MIN));
}
END_TEST
START_TEST(s21_floor_test_11) {
  for (double x = -2.312422e-15; x < 1e7; x += 349.3367)
    ck_assert_double_eq_tol(s21_floor(x), floor(x), S21_EPS);
}
END_TEST

Suite *s21_floor_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_floor_test |\033[0m");
  t = tcase_create("s21_floor_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_floor_test_1);
  tcase_add_test(t, s21_floor_test_2);
  tcase_add_test(t, s21_floor_test_3);
  tcase_add_test(t, s21_floor_test_4);
  tcase_add_test(t, s21_floor_test_5);
  tcase_add_test(t, s21_floor_test_6);
  tcase_add_test(t, s21_floor_test_7);
  tcase_add_test(t, s21_floor_test_8);
  tcase_add_test(t, s21_floor_test_9);
  tcase_add_test(t, s21_floor_test_10);
  tcase_add_test(t, s21_floor_test_11);
  suite_add_tcase(s, t);
  return s;
}