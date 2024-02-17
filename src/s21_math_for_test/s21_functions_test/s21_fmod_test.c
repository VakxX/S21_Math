#include "../s21_tests.h"

START_TEST(s21_fmod_test_1) {
  double x = 1.232323;
  ck_assert_ldouble_nan(fmodl(x, S21_NAN));
  ck_assert_ldouble_nan(s21_fmod(x, S21_NAN));
}
END_TEST
START_TEST(s21_fmod_test_2) {
  double x = 1.232323;
  ck_assert_ldouble_nan(fmodl(S21_NAN, x));
  ck_assert_ldouble_nan(s21_fmod(S21_NAN, x));
}
END_TEST
START_TEST(s21_fmod_test_3) {
  double x = 1.232323;
  ck_assert_ldouble_nan(fmodl(S21_INF, x));
  ck_assert_ldouble_nan(s21_fmod(S21_INF, x));
}
END_TEST
START_TEST(s21_fmod_test_4) {
  double x = 1.232323;
  ck_assert_ldouble_eq_tol(fmodl(x, INFINITY), s21_fmod(x, INFINITY), S21_EPS);
}
END_TEST
START_TEST(s21_fmod_test_5) {
  double x = 100;
  for (double y = -24.240233; y < 28; y = y + 1.012321) {
    ck_assert_ldouble_eq_tol(fmodl(x, y), s21_fmod(x, y), S21_EPS);
  }
}
END_TEST
START_TEST(s21_fmod_test_6) {
  double x = -100;
  for (double y = -24.240233; y < 28; y = y + 1.012321) {
    ck_assert_ldouble_eq_tol(fmodl(x, y), s21_fmod(x, y), S21_EPS);
  }
}
START_TEST(s21_fmod_test_7) {
  double x = 10.950001;
  double y = 2.323543;
  ck_assert_ldouble_eq_tol(fmodl(x, y), s21_fmod(x, y), S21_EPS);
}
END_TEST
START_TEST(s21_fmod_test_8) {
  double x = 100;
  for (double y = -24.240233; y < 28; y = y + 1.012321) {
    ck_assert_ldouble_eq_tol(fmodl(y, x), s21_fmod(y, x), S21_EPS);
  }
}
END_TEST
START_TEST(s21_fmod_test_9) {
  double x = -100;
  for (double y = -24.240233; y < 28; y = y + 1.012321) {
    ck_assert_ldouble_eq_tol(fmodl(y, x), s21_fmod(y, x), S21_EPS);
  }
}

Suite *s21_fmod_test() {
  Suite *s;
  TCase *t;
  s = suite_create("\033[45m| s21_fmod_test |\033[0m");
  t = tcase_create("s21_fmod_test");
  tcase_set_timeout(t, 1000);
  tcase_add_test(t, s21_fmod_test_1);
  tcase_add_test(t, s21_fmod_test_2);
  tcase_add_test(t, s21_fmod_test_3);
  tcase_add_test(t, s21_fmod_test_4);
  tcase_add_test(t, s21_fmod_test_5);
  tcase_add_test(t, s21_fmod_test_6);
  tcase_add_test(t, s21_fmod_test_7);
  tcase_add_test(t, s21_fmod_test_8);
  tcase_add_test(t, s21_fmod_test_9);
  suite_add_tcase(s, t);
  return s;
}