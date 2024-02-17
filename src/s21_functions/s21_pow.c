#include "../s21_math.h"

long double s21_pow(double base, double exp) {
  long double result = 1;
  if (base != base)
    result = S21_NAN;
  else if (base == 1)
    result = 1;
  else if (base == 0 && exp == 0)
    result = 1;
  else if (base == 0)
    result = 0;
  else if (exp == -S21_INF)
    result = 0;
  else if (exp == S21_INF && base == -S21_INF)
    result = S21_INF;
  else if (exp == 1)
    result = base;
  else {
    if (exp > 0) {
      for (long long int i = 0; i < (long long int)exp; i++) {
        result *= base;
        if (result > MAX_DOUBLE) {
          result = S21_INF;
          break;
        }
      }
    }
    if (exp < 0) {
      for (long long int i = 0; i > (long long int)exp; i--) {
        result /= base;
        if (exp < -4000) {
          result = 0.0;
          break;
        }
      }
    }
    long double exp_tail = s21_fabs(exp) - s21_fabs((long long int)exp);
    if (exp > 0 && exp_tail > 0)
      result *= s21_exp(s21_log(base) * exp_tail);
    else if (exp < 0 && exp_tail > 0)
      result *= s21_exp(s21_log(1 / base) * exp_tail);
  }
  return result;
}