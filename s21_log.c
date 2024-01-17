#include "s21_math.h"

long double s21_log(double x) {
  long double res = 0.0;
  if (x < 0.0)
    res = S21_NAN;
  else if (s21_fabs(s21_fabs(x) - S21_E) <= S21_MIN_VAL) {
    res = 1.0;
  } else if (S21_IS_INF(x))
    res = S21_INF;
  else if (S21_IS_NAN(x))
    res = S21_NAN;
  else if (x == 0.0)
    res = -S21_INF;
  else if (x < 1.0) {
    long double an = x - 1.0;
    for (float n = 2.0; n < 280.0; n++) {
      res += an;
      an *= -(n - 1.0) * (x - 1.0) / n;
    }
  } else if (x > 1.0) {
    // ряд Тейлора неэффективен, альтернативa - метод Галлея или метод Ньютона
    // an_n+1 = an_n + 2 * (x - exp(an_n))/(x + exp(an_n))
    long double an = 0.0;
    for (float n = 0.0; n < 300.0; n++) {
      an += 2 * (x - s21_exp(an)) / (x + s21_exp(an));
    }
    res = an;
  }
  return res;
}