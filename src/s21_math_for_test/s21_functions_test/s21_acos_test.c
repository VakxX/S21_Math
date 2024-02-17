#include "../s21_tests.h"

START_TEST(s21_acos_test_1) {
  double x = 453.0000001;
  ck_assert_ldouble_nan(s21_acos(x));
  ck_assert_ldouble_nan(acosl(x));
}
END_TEST
START_TEST(s21_acos_test_2) {
  double x = -1.0000001;
  ck_assert_ldouble_nan(s21_acos(x));
  ck_assert_ldouble_nan(acosl(x));
}
END_TEST
START_TEST(s21_acos_test_3) {
  double x = -0.0;
  ck_assert_ldouble_eq_tol(acosl(x), s21_acos(x), S21_EPS);
}
END_TEST
START_TEST(s21_acos_test_4) {
  double x = +0.0;
  ck_assert_ldouble_eq_tol(acosl(x), s21_acos(x), S21_EPS);
}
END_TEST
START_TEST(s21_acos_test_5) {
  double x = 1e-9;
  ck_assert_ldouble_eq_tol(acosl(x), s21_acos(x), S21_EPS);
}
END_TEST
START_TEST(s21_acos_test_6) {
  double x = -1.0;
  ck_assert_ldouble_eq_tol(acosl(x), s21_acos(x), S21_EPS);
}
END_TEST
START_TEST(s21_acos_test_7) {
  double x = 1.0;
  ck_assert_ldouble_eq_tol(acosl(x), s21_acos(x), S21_EPS);
}
END_TEST
START_TEST(s21_acos_test_8) {
  ck_assert_ldouble_nan(acosl(NAN));
  ck_assert_ldouble_nan(s21_acos(NAN));
}
END_TEST
START_TEST(s21_acos_test_9) {
  ck_assert_ldouble_nan(acosl(INFINITY));
  ck_assert_ldouble_nan(s21_acos(INFINITY));
}
END_TEST
START_TEST(s21_acos_test_10) {
  ck_assert_ldouble_nan(acosl(-INFINITY));
  ck_assert_ldouble_nan(s21_acos(-INFINITY));
}
END_TEST
START_TEST(s21_acos_test_11) {
  for (double x = -1; x < 1; x += 0.0456654)
    ck_assert_double_eq_tol(s21_acos(x), acos(x), S21_EPS);
}
END_TEST

Suite *s21_acos_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_acos_test |\033[0m");
  t = tcase_create("s21_acos_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_acos_test_1);
  tcase_add_test(t, s21_acos_test_2);
  tcase_add_test(t, s21_acos_test_3);
  tcase_add_test(t, s21_acos_test_4);
  tcase_add_test(t, s21_acos_test_5);
  tcase_add_test(t, s21_acos_test_6);
  tcase_add_test(t, s21_acos_test_7);
  tcase_add_test(t, s21_acos_test_8);
  tcase_add_test(t, s21_acos_test_9);
  tcase_add_test(t, s21_acos_test_10);
  tcase_add_test(t, s21_acos_test_11);
  suite_add_tcase(s, t);
  return s;
}