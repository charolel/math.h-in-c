#include "s21_math.h"

long double s21_fmod(double x, double y) {
  long double res;
  if (y == 0.0 || S21_IS_NAN(x) || S21_IS_NAN(y) || S21_IS_INF(x) ||
      S21_IS_INF(y))
    res = S21_NAN;
  else {
    long long int mod;
    mod = x / y;
    res = (long double)x - mod * (long double)y;
  }
  return res;
}