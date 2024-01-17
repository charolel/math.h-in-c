#include "s21_math.h"

int s21_abs(int x) { return (x < 0 && x != -2147483648) ? -x : x; }