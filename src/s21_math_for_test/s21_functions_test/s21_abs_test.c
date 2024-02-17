#include "../s21_tests.h"

START_TEST(s21_abs_test_1) {
  int num = 5;
  ck_assert_int_eq(abs(num), s21_abs(num));
}
END_TEST

START_TEST(s21_abs_test_2) {
  int num = -7;
  ck_assert_int_eq(abs(num), s21_abs(num));
}
END_TEST

START_TEST(s21_abs_test_3) {
  double num = 1.323;
  ck_assert_int_eq(abs((int)num), s21_abs((int)num));
}
END_TEST
START_TEST(s21_abs_test_4) {
  double num = 1e-9;
  ck_assert_int_eq(abs((int)num), s21_abs((int)num));
}
END_TEST
START_TEST(s21_abs_test_5) {
  int num = S21_NEGZERO;
  ck_assert_int_eq(abs(num), s21_abs(num));
}
END_TEST

Suite *s21_abs_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_abs_test |\033[0m");
  t = tcase_create("s21_abs_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_abs_test_1);
  tcase_add_test(t, s21_abs_test_2);
  tcase_add_test(t, s21_abs_test_3);
  tcase_add_test(t, s21_abs_test_4);
  tcase_add_test(t, s21_abs_test_5);
  suite_add_tcase(s, t);
  return s;
}