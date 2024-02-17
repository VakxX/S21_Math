#include "../s21_math.h"

long double s21_sqrt(double x) {
  long double rez = 0;
  if (S21_IS_NAN(x) || x < 0)
    rez = S21_NAN;
  else if (x == 0.0) {
    char buf_str[4000];
    sprintf(buf_str, "%lf", x);
    if (buf_str[0] == '-') {
      rez = -0.0;
    } else {
      rez = 0.0;
    }
  } else {
    long double start = 0;
    long double fin = 0;
    if (x >= 1) {
      fin = x;
    } else if (x < 1 && x >= 0) {
      fin = 1;
    }
    long double mid = 0.5 * fin;
    int i = 0;
    while ((((mid - start)) > S21_EPS) && (i < 100)) {
      if (((mid * mid)) > x) {
        fin = mid;
      }
      if ((mid * mid) < x) {
        start = mid;
      }
      mid = (start + fin) * 0.5;
      i++;
    }
    rez = mid;
  }
  return rez;
}
