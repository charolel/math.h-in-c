#include "s21_math.h"

long double s21_sqrt(double x) {
  long double res = x;

  for (int n = 1; n <= 50; n++) {
    res = 0.5 * (res + (x / res));
  }

  if (x == S21_INF) res = S21_INF;
  if (x < S21_MIN_VAL && x >= 0.0) res = 0.0;
  if (x < 0.0 || x == -S21_INF) res = S21_NAN;

  return res;
}