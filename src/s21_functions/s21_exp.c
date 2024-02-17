#include "../s21_math.h"

long double s21_factorial(int x);

long double s21_exp(double x) {
  long double res = 1.0;
  if (x == -0.0)
    res = 1.0;
  else if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (S21_IS_INF(x))
    res = S21_INF;
  else {
    for (double i = 1; i < 128; i++) {
      res += s21_pow(x, i) / s21_factorial(i);
    }
    if (x <= -25) res = 0.0;
  }
  if (x == S21_INF_MIN) {
    res = 0.0;
  }
  return res;
}

long double s21_factorial(int x) {
  if (x == 0) return 1.0;
  long double rez = 1.0;
  for (int i = 1; i <= x; i++) {
    rez *= i;
  }
  return rez;
}