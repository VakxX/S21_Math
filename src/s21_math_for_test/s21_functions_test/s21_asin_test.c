#include "../s21_tests.h"

START_TEST(s21_asin_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(asinl(x), s21_asin(x), S21_EPS);
}
END_TEST
START_TEST(s21_asin_test_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(asinl(x), s21_asin(x), S21_EPS);
}
END_TEST
START_TEST(s21_asin_test_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(asinl(x), s21_asin(x), S21_EPS);
}
END_TEST
START_TEST(s21_asin_test_4) {
  ck_assert_ldouble_nan(asinl(NAN));
  ck_assert_ldouble_nan(s21_asin(NAN));
}
END_TEST
START_TEST(s21_asin_test_5) {
  ck_assert_ldouble_nan(asinl(INFINITY));
  ck_assert_ldouble_nan(s21_asin(INFINITY));
}
END_TEST
START_TEST(s21_asin_test_6) {
  for (double x = -0.910001; x < 1; x = x + 0.012321) {
    ck_assert_ldouble_eq_tol(asinl(x), s21_asin(x), S21_EPS);
  }
}
END_TEST
START_TEST(s21_asin_test_7) {
  double x = -0.950001;
  ck_assert_ldouble_eq_tol(asinl(x), s21_asin(x), S21_EPS);
}
END_TEST

Suite *s21_asin_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_asin_test |\033[0m");
  t = tcase_create("s21_asin_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_asin_test_1);
  tcase_add_test(t, s21_asin_test_2);
  tcase_add_test(t, s21_asin_test_3);
  tcase_add_test(t, s21_asin_test_4);
  tcase_add_test(t, s21_asin_test_5);
  tcase_add_test(t, s21_asin_test_6);
  tcase_add_test(t, s21_asin_test_7);
  suite_add_tcase(s, t);
  return s;
}