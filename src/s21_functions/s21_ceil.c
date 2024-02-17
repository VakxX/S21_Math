#include "../s21_math.h"

long double s21_ceil(double x) {
  char buf[4000] = {'\0'};
  long double y = x;
  long double result = 0;
  if (x == 0.0) {
    sprintf(buf, "%lf", x);
    if (buf[0] == '-') {
      result = -0.0;
    } else {
      result = 0.0;
    }
  } else {
    if ((!S21_IS_NAN(x)) && (!S21_IS_INF(x)) && (x != 0)) {
      y = (long long int)y;
      if ((y == x) || (y <= -1 && x != 0)) {
        result = y;
      } else if ((x < 0 && x > -1)) {
        result = -0.0;
      } else {
        result = y + 1;
      }
    } else {
      result = x;
    }
  }
  return result;
}
