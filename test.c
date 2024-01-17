#include <check.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#include "s21_math.h"

#define DIFF 1e-7

START_TEST(test_abs) {
  int const buf[4] = {5, -5, -2147483648, 2147483647};
  for (int i = 0; i < 4; i++) ck_assert_int_eq(s21_abs(buf[i]), abs(buf[i]));
}
END_TEST

START_TEST(test_fabs) {
  long double const buf[4] = {0.0, 2.5, -3.5, 4.0};
  for (int i = 0; i < 4; i++)
    ck_assert_ldouble_eq_tol(s21_fabs(buf[i]), fabsl(buf[i]), DIFF);
}
END_TEST

START_TEST(test_floor) {
  double const buf[6] = {0.0, 2.5, -3.1, 4.0, NAN, INFINITY};
  for (int i = 0; i < 6; i++)

    if (isnan(floor(buf[i])))
      ck_assert(isnan(s21_floor(buf[i])));
    else if (isinf(floor(buf[i])))
      ck_assert(isinf(s21_floor(buf[i])));
    else
      ck_assert_ldouble_eq(s21_floor(buf[i]), floor(buf[i]));
}
END_TEST

START_TEST(test_ceil) {
  double const buf[14] = {-34,  -10,      -3244.4, 456.876,  32.957,
                          1.0,  0.086875, 4.0,     -60.0,    0.0,
                          12.0, INFINITY, NAN,     -INFINITY};
  for (int i = 0; i < 14; i++) {
    if (isnan(ceil(buf[i])))
      ck_assert(isnan(s21_ceil(buf[i])));
    else if (isinf(ceil(buf[i])))
      ck_assert(isinf(s21_ceil(buf[i])));
    else
      ck_assert_ldouble_eq(s21_ceil(buf[i]), ceil(buf[i]));
  }
}
END_TEST

START_TEST(test_pow) {
  double const buf[58] = {1.0,       NAN,         4.0,
                          NAN,       3.45546,     NAN,
                          4.64738,   1.7548,      -4.64738,
                          1.7548,    -4.64738,    -1.7548,
                          -8.574862, 7.993099,    8.181928,
                          -1.950393, -8.140663,   -6.153770,
                          -8.190569, 4.068785,    -3.313375,
                          -0.682443, -7.730617,   1.083946,
                          -3.049562, 8.660237,    -2,
                          234.3,     0,           2.457203,
                          6.52355,   -2,          -30.3,
                          3.0,       -30.3,       2,
                          -52,       3,           4325678976438,
                          4362578,   4567,        0,
                          -4567,     0,           20,
                          12,        NAN,         NAN,
                          -16.0,     -2.0,        NAN,
                          -INFINITY, NAN,         INFINITY,
                          10.234,    236857540.0, 56784.0,
                          0.758435};
  int j = 1;
  for (int i = 0; i <= 57; i += 2) {
    if (isnan(pow(buf[i], buf[j])))
      ck_assert(isnan(s21_pow(buf[i], buf[j])));
    else if (isinf(pow(buf[i], buf[j])))
      ck_assert(isinf(s21_pow(buf[i], buf[j])));
    else
      ck_assert_ldouble_eq_tol(s21_pow(buf[i], buf[j]), pow(buf[i], buf[j]),
                               DIFF);

    j += 2;
  }
}
END_TEST

START_TEST(test_sqrt) {
  double const buf[12] = {-34.4, 456.876, 32.957,   1.0, 0.086875, 4.0, -60.0,
                          0.0,   12.0,    INFINITY, NAN, -INFINITY};
  for (int i = 0; i < 12; i++) {
    if (isnan(sqrt(buf[i])))
      ck_assert(isnan(s21_sqrt(buf[i])));
    else if (isinf(sqrt(buf[i])))
      ck_assert(isinf(s21_sqrt(buf[i])));
    else
      ck_assert_ldouble_eq_tol(s21_sqrt(buf[i]), sqrt(buf[i]), DIFF);
  }
}
END_TEST

START_TEST(test_fmod) {
  double const buf[10] = {7, 8, 59, 2, 5, 567, -5, 5, 0.53456, 0.0067};
  int j = 1;
  for (int i = 0; i < 9; i += 2) {
    if (isnan(fmod(buf[i], buf[j])))
      ck_assert(isnan(s21_fmod(buf[i], buf[j])));
    else if (isinf(fmod(buf[i], buf[j])))
      ck_assert(isinf(s21_fmod(buf[i], buf[j])));
    else
      ck_assert_ldouble_eq_tol(s21_fmod(buf[i], buf[j]), fmod(buf[i], buf[j]),
                               DIFF);
    j += 2;
  }
}
END_TEST

START_TEST(test_exp) {
  double const buf[] = {5,
                          4,
                          13,
                          -3.0,
                          -1.0,
                          -0.5,
                          1.0,
                          -1.0,
                          -3.0,
                          -6,
                          0.69314718056,
                          21.0,
                          4567,
                          -4567,
                          (-S21_PI / 2),
                          (S21_PI / 4),
                          NAN,
                          -INFINITY,
                          INFINITY};
  for (int i = 0; i < 19; i++) {
    if (isnan(exp(buf[i])))
      ck_assert(isnan(s21_exp(buf[i])));
    else if (isinf(exp(buf[i])))
      ck_assert(isinf(s21_exp(buf[i])));
    else
      ck_assert_ldouble_eq_tol(s21_exp(buf[i]), expl(buf[i]), DIFF);
  }
}
END_TEST

START_TEST(test_sin) {
  double const buf[27] = {-36864579.672396,
                          417009446.032815,
                          677759473.527670,
                          -896528420.456000,
                          46837396.010215,
                          -803885256.314597,
                          1100497120.572486,
                          55105461.764664,
                          -1842504121.289823,
                          1033233481.940456,
                          634,
                          -634,
                          0.0,
                          1.570796,
                          -1.0472,
                          6.63225,
                          634787698.0,
                          -634787698.0,
                          INFINITY,
                          NAN,
                          -INFINITY,
                          (-S21_PI / 2),
                          (S21_PI / 2),
                          (-S21_PI / 4),
                          (-S21_PI / 5),
                          3 * (-S21_PI / 2),
                          3 * (S21_PI / 2)};
  for (int i = 0; i < 27; i++) {
    // printf("sin(%lf) \nori: %.12Lf \nour: %.12LF\n", buf[i], sinl(buf[i]),
    // s21_sin(buf[i]));
    if (isnan(sin(buf[i])))
      ck_assert(isnan(s21_sin(buf[i])));
    else if (isinf(sin(buf[i])))
      ck_assert(isinf(s21_sin(buf[i])));
    else
      ck_assert_ldouble_eq_tol(s21_sin(buf[i]), sin(buf[i]), DIFF);
  }
}
END_TEST

START_TEST(test_cos) {
  double const buf[29] = {-30071291.155215,
                          -1408190445.698886,
                          543179138.816511,
                          1211786089.097981,
                          -1511200530.226901,
                          1252688476.467826,
                          1935223994.746443,
                          1309679703.465514,
                          -213223855.110455,
                          346667158.578833,
                          -3267,
                          -565478,
                          -21,
                          -1,
                          0.0,
                          1.570796,
                          -1.0472,
                          6.63225,
                          634787698.0,
                          -634787698.0,
                          INFINITY,
                          NAN,
                          -INFINITY,
                          (-S21_PI / 2),
                          (S21_PI / 2),
                          (-S21_PI / 4),
                          (-S21_PI / 5),
                          3 * (-S21_PI / 2),
                          3 * (S21_PI / 2)};
  for (int i = 0; i < 29; i++) {
    if (isnan(cos(buf[i])))
      ck_assert(isnan(s21_cos(buf[i])));
    else if (isinf(cos(buf[i])))
      ck_assert(isinf(s21_cos(buf[i])));
    else
      ck_assert_ldouble_eq_tol(s21_cos(buf[i]), cos(buf[i]), DIFF);
  }
}
END_TEST

START_TEST(test_tan) {
  double const buf[15] = {
      0.0,           1.560796,          -1.0472,         6.63225,
      634787698.0,   -634787698.0,      INFINITY,        NAN,
      -INFINITY,     (-S21_PI / 2),     (S21_PI / 2),    (-S21_PI / 4),
      (-S21_PI / 5), 3 * (-S21_PI / 2), 3 * (S21_PI / 2)};

  for (int i = 0; i < 15; i++) {
    // printf("tan(%lf) \nori: %.12Lf \nour: %.12LF\n", buf[i], atanl(buf[i]),
    // s21_atan(buf[i]));
    if (isnan(tan(buf[i])))
      ck_assert(isnan(s21_tan(buf[i])));
    else if (isinf(tan(buf[i])))
      ck_assert(isinf(s21_tan(buf[i])));
    else
      ck_assert_ldouble_eq_tol(s21_tan(buf[i]), tan(buf[i]), DIFF);
  }
}
END_TEST

START_TEST(test_asin) {
  long double const buf[19] = {0.9300,
                               0.9858880,
                               -1,
                               1,
                               2651.948949,
                               -60382.269817,
                               -844808.808456,
                               -525894.660282,
                               -711555.357888,
                               889099.974134,
                               -896734.736812,
                               579278.405560,
                               (-S21_PI / 2),
                               (S21_PI / 2),
                               (-S21_PI / 4),
                               (-S21_PI / 5),
                               INFINITY,
                               NAN,
                               -INFINITY};
  for (int i = 0; i < 19; i++) {
    // printf("asin(%Lf) \nori: %Lf \nour: %LF\n", buf[i], asinl(buf[i]),
    // s21_asin(buf[i]));
    if (isnan(asin(buf[i])))
      ck_assert(isnan(s21_asin(buf[i])));
    else if (isinf(asin(buf[i])))
      ck_assert(isinf(s21_asin(buf[i])));
    else
      ck_assert_ldouble_eq_tol(s21_asin(buf[i]), asin(buf[i]), DIFF);
  }
}
END_TEST

START_TEST(test_acos) {
  long double const buf[21] = {2651.948949,
                               -60382.269817,
                               -844808.808456,
                               -525894.660282,
                               -711555.357888,
                               889099.974134,
                               -896734.736812,
                               579278.405560,
                               (-S21_PI / 2),
                               (S21_PI / 2),
                               (-S21_PI / 4),
                               (-S21_PI / 5),
                               0.9300,
                               0.9858880,
                               -1,
                               1,
                               INFINITY,
                               NAN,
                               -INFINITY};
  for (int i = 0; i < 21; i++) {
    if (isnan(acos(buf[i])))
      ck_assert(isnan(s21_acos(buf[i])));
    else if (isinf(acos(buf[i])))
      ck_assert(isinf(s21_acos(buf[i])));
    else
      ck_assert_ldouble_eq_tol(s21_acos(buf[i]), acos(buf[i]), DIFF);
  }
}
END_TEST

START_TEST(test_atan) {
  long double const buf[11] = {(-S21_PI / 2),
                               (S21_PI / 2),
                               (-S21_PI / 4),
                               (-S21_PI / 5),
                               0.9300,
                               0.9858880,
                               -1,
                               1,
                               NAN,
                               INFINITY,
                               -INFINITY};
  for (int i = 0; i < 11; i++) {
    if (isnan(atan(buf[i])))
      ck_assert(isnan(s21_atan(buf[i])));
    else if (isinf(atan(buf[i])))
      ck_assert(isinf(s21_atan(buf[i])));
    else
      ck_assert_ldouble_eq_tol(s21_atan(buf[i]), atan(buf[i]), DIFF);
  }
}
END_TEST

START_TEST(test_log) {
  double const buf[11] = {-1.0,    0.0,     S21_E,  1.0,  3.086875, 0.05643,
                          0.15643, 0.65643, 8.5473, 12.0, 60.0};

  for (int i = 0; i < 11; i++) {
    if (isnan(log(buf[i])))
      ck_assert(isnan(s21_log(buf[i])));
    else if (isinf(log(buf[i])))
      ck_assert(isinf(s21_log(buf[i])));
    else
      ck_assert_ldouble_eq_tol(s21_log(buf[i]), log(buf[i]), DIFF);
  }
}
END_TEST

START_TEST(test_fmod_marginal) {
  if (isnan(fmod(NAN, 3.1))) ck_assert(isnan(s21_fmod(NAN, 3.1)));
  if (isnan(fmod(3.2, NAN))) ck_assert(isnan(s21_fmod(3.2, NAN)));
  if (isnan(fmod(INFINITY, 3.3))) ck_assert(isnan(s21_fmod(INFINITY, 3.3)));
  if (isnan(fmod(3.4, INFINITY))) ck_assert(isnan(s21_fmod(3.4, INFINITY)));
  if (isnan(fmod(INFINITY, INFINITY)))
    ck_assert(isnan(s21_fmod(INFINITY, INFINITY)));
  else
    ck_assert_ldouble_eq_tol(s21_fmod(4.1, 4.2), fmod(4.1, 4.2), DIFF);
}
END_TEST

START_TEST(test_sin_marginal) {
  if (isnan(sin(NAN))) ck_assert(isnan(s21_sin(NAN)));
  if (isnan(sin(INFINITY))) ck_assert(isnan(s21_sin(INFINITY)));
  if (isnan(sin(-INFINITY))) ck_assert(isnan(s21_sin(-INFINITY)));
}
END_TEST

START_TEST(test_cos_marginal) {
  if (isnan(cos(NAN))) ck_assert(isnan(s21_cos(NAN)));
  if (isnan(cos(INFINITY))) ck_assert(isnan(s21_cos(INFINITY)));
  if (isnan(cos(-INFINITY))) ck_assert(isnan(s21_cos(-INFINITY)));
}
END_TEST

START_TEST(test_tan_marginal) {
  if (isnan(tan(NAN))) ck_assert(isnan(s21_tan(NAN)));
  if (isnan(tan(INFINITY))) ck_assert(isnan(s21_tan(INFINITY)));
  if (isnan(tan(-INFINITY))) ck_assert(isnan(s21_tan(-INFINITY)));
  if (!(isnan(tan(M_PI / 2.0))))
    ck_assert_ldouble_eq_tol(tan(M_PI / 2.0), s21_tan(M_PI / 2.0), DIFF);
  if (!(isnan(tan(3 * M_PI / 2.0))))
    ck_assert_ldouble_eq_tol(tan(3.0 * M_PI / 2.0), s21_tan(3.0 * M_PI / 2.0),
                             DIFF);
}
END_TEST

START_TEST(test_pow_marginal) {
  if (!(isnan(pow(0.0, 0.0))))
    ck_assert_ldouble_eq_tol(s21_pow(0.0, 0.0), pow(0.0, 0.0), DIFF);
  if (isnan(pow(NAN, 1.0))) ck_assert(isnan(s21_pow(NAN, 1.0)));
  if (isnan(pow(2.0, NAN))) ck_assert(isnan(s21_pow(2.0, NAN)));
  if (isnan(pow(NAN, NAN))) ck_assert(isnan(s21_pow(NAN, NAN)));
  if (isinf(pow(INFINITY, 3.0))) ck_assert(isinf(s21_pow(INFINITY, 3.0)));
  if (isinf(pow(4.0, INFINITY))) ck_assert(isinf(s21_pow(4.0, INFINITY)));
  if (isinf(pow(INFINITY, INFINITY)))
    ck_assert(isinf(s21_pow(INFINITY, INFINITY)));
  if (isinf(pow(-INFINITY, 5.0))) ck_assert(isinf(s21_pow(-INFINITY, 5.0)));
  if (!(isinf(pow(6.0, -INFINITY))))
    ck_assert_ldouble_eq_tol(s21_pow(6.0, -INFINITY), pow(6.0, -INFINITY),
                             DIFF);
  if (!(isinf(pow(-INFINITY, -INFINITY))))
    ck_assert_ldouble_eq_tol(s21_pow(-INFINITY, -INFINITY),
                             pow(-INFINITY, -INFINITY), DIFF);
  if (isnan(pow(NAN, INFINITY))) ck_assert(isnan(s21_pow(NAN, INFINITY)));
  if (isnan(pow(INFINITY, NAN))) ck_assert(isnan(s21_pow(INFINITY, NAN)));
  if (isnan(pow(NAN, -INFINITY))) ck_assert(isnan(s21_pow(NAN, -INFINITY)));
  if (isnan(pow(-INFINITY, NAN))) ck_assert(isnan(s21_pow(-INFINITY, NAN)));
}
END_TEST

Suite *math_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Math");

  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_abs);
  tcase_add_test(tc_core, test_fabs);
  tcase_add_test(tc_core, test_floor);
  tcase_add_test(tc_core, test_ceil);
  tcase_add_test(tc_core, test_pow);
  tcase_add_test(tc_core, test_sqrt);
  tcase_add_test(tc_core, test_fmod);
  tcase_add_test(tc_core, test_exp);
  tcase_add_test(tc_core, test_sin);
  tcase_add_test(tc_core, test_cos);
  tcase_add_test(tc_core, test_tan);
  tcase_add_test(tc_core, test_asin);
  tcase_add_test(tc_core, test_acos);
  tcase_add_test(tc_core, test_atan);
  tcase_add_test(tc_core, test_log);
  tcase_add_test(tc_core, test_fmod_marginal);
  tcase_add_test(tc_core, test_sin_marginal);
  tcase_add_test(tc_core, test_cos_marginal);
  tcase_add_test(tc_core, test_tan_marginal);
  tcase_add_test(tc_core, test_pow_marginal);

  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int number_failed;
  Suite *s;
  SRunner *sr;

  s = math_suite();
  sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);
  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}