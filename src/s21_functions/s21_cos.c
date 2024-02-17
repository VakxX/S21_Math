#include "../s21_math.h"

long double s21_cos(double x) {
  long double result = 1.0;
  if (S21_IS_NAN(x)) {
    result = S21_NAN;
  } else if (S21_IS_INF(x)) {
    result = -S21_NAN;
  } else {
    long double curr = 1.0;
    long double accuracy = 1e-10;
    int n = 1;
    double check;
    check = x / (2 * S21_PI);
    x -= (long int)check * (2 * S21_PI);
    while (s21_fabs(curr) > accuracy) {
      curr *= -x * x / ((2 * n) * (2 * n - 1));
      result += curr;
      n++;
    }
  }
  return result;
}
