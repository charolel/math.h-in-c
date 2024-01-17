#include "s21_math.h"

long double s21_asin(double x) {
  long double res;
  if (x == 1.0)
    res = S21_PI / 2;
  else if (x == -1.0)
    res = -S21_PI / 2;
  else if (s21_fabs(x) < 1) {
    res = x;
    float max;
    if (s21_fabs(x) <= 0.930)
      max = 90.0;
    else
      max = 350.0;

    // first iteration: x + 1/2 * x^3 / 3
    long double an = 0.5 * (x * x * x / 3.0);

    for (float n = 2.0; n < max; n++) {
      res += an;
      an = an * ((2.0 * n - 1.0) / (2.0 * n)) *
           (x * x * (2.0 * n - 1.0) / (2.0 * n + 1.0));
    }

  } else
    res = S21_NAN;
  return res;
}