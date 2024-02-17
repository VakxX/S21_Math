#include "../s21_math.h"

long double s21_atan(double x) {
  long double result = 0.0;
  register int n = 1500;
  if (x != x)
    result = S21_NAN;
  else if (x == S21_INF_MIN)
    result = -S21_PI_2;
  else if (x == S21_INF)
    result = S21_PI_2;
  else if (x == 1)
    result = S21_PI_2 / 2;
  else if (x == -1)
    result = -S21_PI_2 / 2;
  else {
    if (x > -1.0 && x < 1.0) {
      for (register int i = 0; i < n; i++) {
        result += s21_pow(-1, i) * s21_pow(x, 1 + (2 * i)) / (1 + (2 * i));
      }
    } else {
      for (register int i = 0; i < n; i++) {
        result += s21_pow(-1, i) * s21_pow(x, -1 - (2 * i)) / (1 + (2 * i));
      }
      result = (x > 0) ? S21_PI_2 - result : -S21_PI_2 - result;
    }
  }
  return result;
}
