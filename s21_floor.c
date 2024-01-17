#include "s21_math.h"

long double s21_floor(double x) {
  long double res = 0;

  if (S21_IS_NAN(x) || S21_IS_INF(x))
    res = x;
  else {
    if (x >= 0)
      res = (long long int)x;
    else {
      long double condition = x - (long long int)x;
      if (condition >= -S21_MIN_VAL)
        res = x;
      else
        res = (long long int)x - 1;
    }
  }
  return res;
}