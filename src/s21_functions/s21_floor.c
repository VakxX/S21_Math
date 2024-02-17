#include "../s21_math.h"

long double s21_floor(double x) {
  if (S21_IS_NAN(x) || S21_IS_INF(x) || x == S21_NEGZERO) {
    return x;
  } else {
    long double y = x;
    if (y >= 0 || y == (long long int)y) {
      y = (long long int)y;
    } else {
      y = (long long int)(y - 1);
    }
    return y;
  }
}