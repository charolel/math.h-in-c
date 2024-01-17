#include "s21_math.h"

long double s21_ceil(double x) {
  long double res = 0.0;

  if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (s21_fabs(x) == S21_INF)
    res = x;
  else {
    // Если x >= 0, рассчитываем верхнюю границу
    if (x >= 0.0) {
      long double condition = x - (long long int)x;
      // Если остаток меньше некоторой маленькой величины, результат равен x
      if (condition <= S21_MIN_VAL)
        res = x;
      else
        res = (long long int)x + 1.0;
    } else
      res = (long long int)x;
    // Если x < 0, результат равен (long long int)x
  }
  return res;
}