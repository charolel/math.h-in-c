#ifndef S21_MATH
#define S21_MATH

#define S21_E 2.7182818284590452353602874713526624977572
#define S21_PI 3.1415926535897932384626433832795028841971
#define S21_MIN_VAL 1e-17
#define S21_NAN 0.0 / 0.0
#define S21_IS_NAN(x) (!(x >= 0.0) && !(x < 0.0))
#define S21_INF 1.0 / 0.0
#define S21_IS_INF(x) ((x == S21_INF) || (x == -S21_INF))
#define S21_OVER_DOUBLE(x) ((x < 1.7e-308) || (x > 1.7e+308))

/// @brief abs() returns the absolute value of x. If x < 0 then x *= -1. If x ==
/// MIN_INT then x = MIN_INT.
/// @param x integer
/// @return |x|: absolute value of x
int s21_abs(int x);

/// @brief Mathematically, acos(x) = cos^(-1)(x).
/// @param x floating-point argument (1 ≥ x ≥ -1)
/// @return arc cosine in radians
long double s21_acos(double x);

/// @brief Mathematically, asin(x) = sin^(-1)(x). The asin() function takes a
/// single argument in the range of [-1, +1]. It's because the value of sine is
/// in the range of 1 and -1. The asin() functions returns the value in range of
/// [-π/2, +π/2] in radians. If the parameter passed to the asin() function is
/// less than -1 or greater than 1, the function returns NaN (not a number).
/// @param x floating-point argument (1 ≥ x ≥ -1)
/// @return arc sine in radians
long double s21_asin(double x);

/// @brief atan(x) is the value of the angle expressed in radians for which
/// tg(y) = x
/// @param x is a result of tg(y)
/// @return y angle in radians
long double s21_atan(double x);

/// @brief ceil(x) returns the smallest integer value greater than or equal to
/// x.
/// @param x floating-point number x
/// @return int x >= double x
long double s21_ceil(double x);

/// @brief cos(x) is a trigonometric function that is equal to the ratio of
/// adjacent and hypotenuse of a right triangle. The result ranges from -1 to 1.
/// @param x floating-point number x (angle in radians)
/// @return floating-point result of cos(x)
long double s21_cos(double x);

/// @brief fabs() returns the value of e raised to the xth power.
/// @param x floating-point number x
/// @return e^x
long double s21_exp(double x);

/// @brief fabs() returns the absolute value of x. If x < 0.0 then x *= -1.
/// @param x floating-point number x
/// @return |x|: absolute value of x
long double s21_fabs(double x);

/// @brief floor(x) returns the largest integer value less than or equal to x.
/// @param x floating-point number x
/// @return int x <= double x
long double s21_floor(double x);

/// @brief s21_fmod(x, y) returns the remainder of the division from x/y.
// If y = 0, the function returns NaN.
/// @param x numerator
/// @param y denominator
/// @return int x <= double x
long double s21_fmod(double x, double y);

/// @brief log(x) returns the natural logarithm (base e) of x, for x greater
/// than 0.
/// @param x floating-point number x
/// @return ln(x): natural logarithm
long double s21_log(double x);

/// @brief pow(base, exp) returns the result of a number raised to a power
/// @param base variable to be raised to the degree of extent
/// @param exp degree
/// @return base^exp (x^n)
long double s21_pow(double base, double exp);

/// @brief sin(x) is a trigonometric function that is equal to the ratio of
/// perpendicular and hypotenuse of a right triangle. The result ranges from -1
/// to 1.
/// @param x floating-point number x (angle in radians)
/// @return floating-point result of sin(x)
long double s21_sin(double x);

/// @brief sqrt(x) returns square root of x.
/// @param x number x
/// @return square root of x
long double s21_sqrt(double x);

/// @brief tan(x) is a trigonometric function that is equal to the ratio of of
/// sin(x) to
/// cos(x).
/// @param x floating-point number x (angle in radians)
/// @return floating-point result of tan(x)
long double s21_tan(double x);

#endif