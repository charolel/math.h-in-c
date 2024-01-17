#include "s21_math.h"

long double s21_sin(double x) {
  long double res;
  if (S21_IS_INF(x) || S21_IS_NAN(x))
    res = S21_NAN;
  else {
    // для точности, если нам приходит огрооомное число, тип double не подходит
    long double ax = s21_fmod(x, S21_PI * 2.0);
    res = ax;

    // first iteration, an = (x^(2 * 1 + 1 = 3)/((2 * 1 + 1 = 3)!) * (-1)^1)
    long double an = -((ax * ax * ax) / 6.0);

    // оптимизированный ряд Тейлора:
    for (float n = 1.0; n <= 120.0; n++) {
      res += an;
      an = -an * (ax * ax) / ((2.0 * n + 2.0) * (2.0 * n + 3.0));
    }
  }
  return res;
}