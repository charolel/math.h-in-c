#include "s21_math.h"

long double s21_pow(double base, double exp) {
  long double res = 1.0;
  if ((S21_IS_INF(base) || S21_IS_INF(exp)) &&
      !(S21_IS_NAN(base) || S21_IS_NAN(exp))) {
    if (base == S21_INF) res = S21_INF;
    if (exp == S21_INF) res = S21_INF;
    if (base == -S21_INF) res = -S21_INF;
    if (exp == -S21_INF) res = 0.0;
  } else if ((S21_IS_NAN(base) || S21_IS_NAN(exp)) &&
             (base != 0.0 && exp != 0.0) && !(base < 0.0 && exp == 0.0)) {
    if (base == 1.0 && S21_IS_NAN(exp))
      res = 1.0;
    else
      res = S21_NAN;
  } else if (base == 0.0 && exp == 0.0 &&
             !(S21_IS_NAN(base) || S21_IS_NAN(exp)))
    res = 1.0;
  else if (exp != 0.0 && s21_fabs(res) != S21_INF) {
    long double x = base;
    if (x < 0.0) x *= -1;
    res = s21_exp(exp * s21_log(x));

    if (base < 0.0 && s21_fmod(exp, 2) != 0) res *= -1;

    // проверка, что под корнем не отрицательное число
    if (!(s21_fabs(exp - (long long int)exp) < S21_MIN_VAL) && base < 0.0)
      res = S21_NAN;

    if (exp != 0.0 && (s21_fabs(exp - (long long int)exp) < S21_MIN_VAL) &&
        (s21_fabs(base - (long long int)base) < S21_MIN_VAL)) {
      res = 1.0;
      for (float n = 1.0; n <= s21_fabs(exp); n++) res *= base;
      if (exp < 0.0 && res != 0.0) res = 1.0 / res;
    }
  }
  return res;
}