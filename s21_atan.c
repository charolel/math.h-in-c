#include "s21_math.h"

long double for_atan(double x) {
  long double res = x, atan = x, n = 1.0;
  while (s21_fabs(atan) > S21_MIN_VAL) {
    atan = -1.0 * atan * x * x * (2.0 * n - 1.0) / (2.0 * n + 1.0);
    n += 1.0;
    res += atan;
  }
  return res;
}

long double s21_atan(double x) {
  long double res = 0.0;
  if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (S21_IS_INF(x)) {
    res = S21_PI / 2.0;
    if (x == -S21_INF || x < 0.0) res = -res;
  } else if (s21_fabs(x) == 1.0) {
    res = S21_PI / 4.0;
    if (x < 0.0) res = -res;
  } else if (x == 0.0)
    res = 0.0;
  else if (s21_fabs(x) < 1.0)
    res = for_atan(x);
  else if (s21_fabs(x) > 1.0) {
    res = S21_PI / 2.0;
    if (x > 0.0) res -= for_atan(1.0 / x);
    if (x < 0.0) res = -res - for_atan(1.0 / x);
  }
  return res;
}