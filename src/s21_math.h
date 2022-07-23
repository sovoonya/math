#ifndef SRC_S21_MATH_H_
#define SRC_S21_MATH_H_

#include <stdio.h>

#define s21_INF 1.0 / 0.0
#define s21_NAN 0.0 / 0.0
#define S21_M_PI ((long double)3.141592653589793238462643)
#define S21_M_PI12 (S21_M_PI/12.F)
#define S21_M_PI6 (S21_M_PI/6.F)
#define S21_M_PI2 (S21_M_PI/2.F)
#define S21_SQRT3 ((float)1.732050807569)
#define S21_EPS 1E-17
#define S21_DBL_MAX 1.7976931348623157e+308

enum{NORMAL, EDOM};

int s21_abs(int x);
long double s21_acos(double x);
long double s21_asin(long double x);
long double s21_atan(long double x);
long double s21_ceil(double x);
long double s21_cos(double x);
long double s21_exp(double x);
long double s21_fabs(double x);
long double s21_floor(double x);
long double s21_fmod(double x, double y);
long double s21_log(double x);
long double s21_pow(double base, double exp);
long double s21_sin(double x);
long double s21_sqrt(double x);
long double s21_tan(double x);

long double s21_fact(long double x);
long double s21_pow_int(double base, double exp);

#endif  // SRC_S21_MATH_H_
