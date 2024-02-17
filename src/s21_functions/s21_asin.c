#include "../s21_math.h"

long double s21_asin(double x) {
  long double res = 0.0;
  if (x == S21_ZERO) res = S21_ZERO;
  if (x >= -1 && x <= 1) {
    x = x / s21_sqrt(1 - x * x);
    res = s21_atan(x);
  } else {
    res = S21_NAN;
  }
  return res;
}