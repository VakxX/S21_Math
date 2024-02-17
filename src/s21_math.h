#include <float.h>
#include <stdio.h>
#include <stdlib.h>

#define S21_PI 3.14159265358979323846L
#define S21_PI_2 1.57079632679489661923L
#define S21_E 2.71828182845904523536028747135266250
#define S21_2PI 6.28318530718
#define S21_NAN (__builtin_nanf(""))
#define S21_INF (__builtin_huge_vall())
#define S21_INF_MIN (-__builtin_huge_vall())
#define S21_IS_NAN(x) __builtin_isnan(x)
#define S21_IS_INF(x) __builtin_isinf_sign(x)
#define S21_NEGZERO -1.0 / 0.0
#define S21_ZERO +1.0 / 0.0
#define S21_EPS 1e-6
#define MAX_DOUBLE 1.7e308

int s21_abs(int x);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_acos(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_asin(double x);
long double s21_exp(double x);
long double s21_fmod(double x, double y);
long double s21_atan(double x);
long double s21_cos(double x);
long double s21_tan(double x);
long double s21_ceil(double x);
long double s21_sin(double x);
long double s21_sqrt(double x);
