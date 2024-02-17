#include "../s21_math.h"

long double s21_fmod(double x, double y) {
  long double res = 0;
  if (y == 0 || x == S21_INF || x == S21_INF_MIN) {
    return S21_NAN;
  }
  if (y == S21_INF || y == S21_INF_MIN) {
    return x;
  }
  long long int mod = 0;
  mod = x / y;
  res = (long double)x - mod * (long double)y;
  if (x < 0 && res == 0.0) res = -0.0;
  return res;
}