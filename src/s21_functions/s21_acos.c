#include "../s21_math.h"

long double s21_acos(double x) {
  if (x >= -1 || x <= 1) {
    return (S21_PI_2 - s21_asin(x));
  } else {
    return S21_NAN;
  }
}