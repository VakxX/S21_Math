#include "../s21_math.h"

long double s21_sin(double x) {
  long double rez = 0;
  char buf_str[4000];
  sprintf(buf_str, "%lf", x);
  if ((S21_IS_NAN(x)) || (S21_IS_INF(x))) {
    rez = S21_NAN;
  } else if (x == -0.0) {
    if (buf_str[0] == '-') {
      rez = -0.0;
    }
  } else {
    x = s21_fmod(x, 2 * S21_PI);
    long double term = x;
    long double sum = 0;
    int i = 1;
    while ((s21_fabs(term) > 1e-10) && i < 10000) {
      sum = sum + term;
      term = term * (-1) * (x * x) / ((2 * i + 1) * (i * 2));
      i = i + 1;
    }
    rez = sum;
  }
  return rez;
}
