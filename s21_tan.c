#include "s21_math.h"

long double s21_tan(double x) {
  long double res;
  if (s21_fabs(s21_fabs(x) - (S21_PI / 2.0)) < S21_MIN_VAL) {
    res = 16331239353195370.0;
    if (x < 0.0) res *= -1;
  } else if (s21_fabs(s21_fabs(x) - 3.0 * S21_PI / 2.0) < S21_MIN_VAL) {
    res = 5443746451065123.0;
    if (x < 0.0) res *= -1;
  } else if (s21_cos(x) == 0.0)
    res = S21_INF;
  else
    res =
        (S21_IS_INF(x) || S21_IS_NAN(x)) ? S21_NAN : (s21_sin(x) / s21_cos(x));
  return res;
}