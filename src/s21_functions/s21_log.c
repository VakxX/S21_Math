#include "../s21_math.h"

long double s21_log(double x) {
  long double rez = 0.0;
  int epow = 0;
  long double buffer;

  if (x == S21_INF) {
    rez = x;
  } else if (x == 0) {
    rez = S21_NEGZERO;
  } else if (x < 0) {
    rez = S21_NAN;
  } else {
    for (; x >= S21_E; x = x / S21_E, epow++) {
      continue;
    }
    for (int i = 0; i < 100; i++) {
      buffer = rez;
      long double error = (2 * (x - s21_exp(buffer))) / (x + s21_exp(buffer));
      rez += error;
      if (error < 0) {
        error *= -1;
      }
      if (error < 1e-10) {
        break;
      }
    }
  }
  return rez + epow;
}
