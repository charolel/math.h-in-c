#include "s21_math.h"

long double s21_exp(double x) {
  if (S21_IS_NAN(x)) return S21_NAN;
  if (S21_IS_INF(x)) return x < 0 ? 0 : S21_INF;
  if (x > 7.097827e+002) return S21_INF;
  if (x < -7.097827e+002) return 0.0;

  int sign = x < 0;
  if (sign) x *= -1.0;
  long double res = 1.0;
  long double temp = x;
  unsigned flag = 1;
  while (s21_fabs(temp) >= S21_MIN_VAL) {
    res += temp;
    temp = (temp * x) / ++flag;
  }
  if (s21_fabs(x - 0.69314718056) <= S21_MIN_VAL) res = 2.0;
  return sign ? (1 / res) : res;
}