#include "../s21_math.h"

long double s21_fabs(double x) {
  if (x == S21_NEGZERO || x == S21_ZERO)
    x = S21_ZERO;
  else if (x < 0)
    x = -x;
  else if (S21_IS_NAN(x))
    x = S21_NAN;
  return x;
}