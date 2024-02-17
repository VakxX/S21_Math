#include "../s21_tests.h"

START_TEST(s21_tan_test_1) {
  double x = 1;
  ck_assert_ldouble_eq_tol(tanl(x), s21_tan(x), S21_EPS);
}
END_TEST
START_TEST(s21_tan_test_2) {
  double x = -1;
  ck_assert_ldouble_eq_tol(tanl(x), s21_tan(x), S21_EPS);
}
END_TEST
START_TEST(s21_tan_test_3) {
  double x = 0;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS);
}
END_TEST
START_TEST(s21_tan_test_4) {
  ck_assert_ldouble_nan(tan(NAN));
  ck_assert_ldouble_nan(s21_tan(NAN));
}
END_TEST
START_TEST(s21_tan_test_5) {
  ck_assert_ldouble_nan(tan(INFINITY));
  ck_assert_ldouble_nan(s21_tan(INFINITY));
}
END_TEST
START_TEST(s21_tan_test_6) {
  for (double x = -123422; x < 123442; x += 1324.523)
    ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS);
}
END_TEST
START_TEST(s21_tan_test_7) {
  double x = 15220.1234;
  ck_assert_ldouble_eq_tol(tan(x), s21_tan(x), S21_EPS);
}
END_TEST

Suite *s21_tan_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_tan_test |\033[0m");
  t = tcase_create("s21_tan_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_tan_test_1);
  tcase_add_test(t, s21_tan_test_2);
  tcase_add_test(t, s21_tan_test_3);
  tcase_add_test(t, s21_tan_test_4);
  tcase_add_test(t, s21_tan_test_5);
  tcase_add_test(t, s21_tan_test_6);
  tcase_add_test(t, s21_tan_test_7);
  suite_add_tcase(s, t);
  return s;
}