#include "s21_math.h"

long double s21_cos(double x) {
  long double angle_for_sin = s21_fmod(x, S21_PI * 2.0) + (S21_PI / 2.0);
  return s21_sin(angle_for_sin);
}