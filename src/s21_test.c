#include <check.h>
#include <math.h>
#include <stdlib.h>

#include "s21_math.h"

// abs test
START_TEST(s21_abs_f) {
    ck_assert_int_eq(s21_abs(-100), abs(-100));
    ck_assert_int_eq(s21_abs(-1), abs(-1));
    ck_assert_int_eq(s21_abs(0), abs(0));
    ck_assert_int_eq(s21_abs(1), abs(1));
    ck_assert_int_eq(s21_abs(100), abs(100));
    ck_assert_int_eq(s21_abs(2147483646), abs(2147483646));
    ck_assert_int_eq(s21_abs(-2147483646), abs(-2147483646));
}
END_TEST

// acos test
START_TEST(s21_acos_f) {
    ck_assert_ldouble_eq_tol(s21_acos(0.0), acosl(0.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(1), acosl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(-1), acosl(-1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(0.5), acosl(0.49999999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(0.54321), acosl(0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(-0.54321), acosl(-0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(0.999999), acosl(0.999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(-0.999999), acosl(-0.999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(0.00003), acosl(0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(-0.00003), acosl(-0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(0.2147483646), acosl(0.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_acos(-0.2147483646), acosl(-0.2147483646), 1e-7);
    ck_assert_ldouble_nan(s21_acos(10));
    ck_assert_ldouble_nan(s21_acos(-10));
}
END_TEST

// asin
START_TEST(s21_asin_f) {
    ck_assert_ldouble_eq_tol(s21_asin(0), asinl(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_asin(1), asinl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_asin(-1), asinl(-1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_asin(0.5), asinl(0.49999999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_asin(0.54321), asinl(0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_asin(-0.54321), asinl(-0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_asin(0.99999), asinl(0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_asin(-0.99999), asinl(-0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_asin(0.00003), asinl(0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_asin(-0.00003), asinl(-0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_asin(0.2147483646), asinl(0.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_asin(-0.2147483646), asinl(-0.2147483646), 1e-7);
    ck_assert_ldouble_nan(s21_asin(10));
    ck_assert_ldouble_nan(s21_asin(-10));
}
END_TEST

// atan
START_TEST(s21_atan_f) {
    ck_assert_ldouble_eq_tol(s21_atan(0), atanl(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(1), atanl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(-1), atanl(-1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(0.5), atanl(0.49999999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(0.54321), atanl(0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(-0.54321), atanl(-0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(0.99999), atanl(0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(-0.99999), atanl(-0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(0.00003), atanl(0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(-0.00003), atanl(-0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(10), atanl(10), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(-10), atanl(-10), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(0.2147483646), atanl(0.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(-0.2147483646), atanl(-0.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(123456789), atanl(123456789), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(-123456789), atanl(-123456789), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(123456789.987654321), atanl(123456789.987654321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_atan(-123456789.987654321), atanl(-123456789.987654321), 1e-7);
}
END_TEST

// ceil
START_TEST(s21_ceil_f) {
    ck_assert_ldouble_eq_tol(s21_ceil(0), ceill(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(1), ceill(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(-1), ceill(-1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(0.5), ceill(0.49999999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(0.54321), ceill(0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(-0.54321), ceill(-0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(0.99999), ceill(0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(-0.99999), ceill(-0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(0.00003), ceill(0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(-0.00003), ceill(-0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(10), ceill(10), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(-10), ceill(-10), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(7.2147483646), ceill(7.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(-8.2147483646), ceill(-8.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(123456789), ceill(123456789), 1e-7);
    ck_assert_ldouble_eq_tol(s21_ceil(-123456789), ceill(-123456789), 1e-7);
}
END_TEST

// cos
START_TEST(s21_cos_f) {
    ck_assert_ldouble_eq_tol(s21_cos(0), cosl(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(1), cosl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(-1), cosl(-1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(0.5), cosl(0.49999999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(0.54321), cosl(0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(-0.54321), cosl(-0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(0.99999), cosl(0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(-0.99999), cosl(-0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(0.00003), cosl(0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(-0.00003), cosl(-0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(10), cosl(10), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(-10), cosl(-10), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(7.2147483646), cosl(7.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(-8.2147483646), cosl(-8.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(123456789), cosl(123456789), 1e-7);
    ck_assert_ldouble_eq_tol(s21_cos(-123456789), cosl(-123456789), 1e-7);
}
END_TEST

// exp
START_TEST(s21_exp_f) {
    ck_assert_ldouble_eq_tol(s21_exp(0), expl(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(1), expl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(-1), expl(-1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(0.5), expl(0.49999999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(0.54321), expl(0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(-0.54321), expl(-0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(0.99999), expl(0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(-0.99999), expl(-0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(0.00003), expl(0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(-0.00003), expl(-0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(10), expl(10), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(-10), expl(-10), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(7.2147483646), expl(7.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_exp(-8.2147483646), expl(-8.2147483646), 1e-7);
    ck_assert_ldouble_eq(s21_exp(1111120), expl(1111120));
    ck_assert_ldouble_eq(s21_exp(-1111120), expl(-1111120));
    ck_assert_ldouble_eq(s21_exp(1234567.077), expl(1234567.077));
    ck_assert_ldouble_eq(s21_exp(-1234567.077), expl(-1234567.077));
}
END_TEST

// fabs
START_TEST(s21_fabs_f) {
    ck_assert_ldouble_eq_tol(s21_fabs(0.0), fabsl(0.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(1.0), fabsl(1.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(-1.0), fabsl(-1.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(0.5), fabsl(0.5), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(0.000000000000001), fabsl(0.000000000000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(-0.000000000000001), fabsl(-0.000000000000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(0.4444449), fabsl(0.4444449), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(-0.4444449), fabsl(-0.4444449), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(0.99999), fabsl(0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(-0.99999), fabsl(-0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(0.00003), fabsl(0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(-0.00003), fabsl(-0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(10.1), fabsl(10.1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(-10.2), fabsl(-10.2), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(7.2147483646), fabsl(7.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(-8.2147483646), fabsl(-8.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(1111120.8), fabsl(1111120.8), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(-1111120.9), fabsl(-1111120.9), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(1234567.077), fabsl(1234567.077), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(-1234567.077), fabsl(-1234567.077), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(123456789101112131.077), fabsl(123456789101112131.077), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fabs(-123456789101112131.077), fabsl(-123456789101112131.077), 1e-7);
}
END_TEST

// floor
START_TEST(s21_floor_f) {
    ck_assert_ldouble_eq_tol(s21_floor(0.0), floorl(0.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(1.0), floorl(1.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(-1.0), floorl(-1.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(0.5), floorl(0.5), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(0.000000000000001), floorl(0.000000000000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(-0.000000000000001), floorl(-0.000000000000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(0.4444449), floorl(0.4444449), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(-0.4444449), floorl(-0.4444449), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(0.99999), floorl(0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(-0.99999), floorl(-0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(0.00003), floorl(0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(-0.00003), floorl(-0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(10.1), floorl(10.1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(-10.2), floorl(-10.2), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(7.2147483646), floorl(7.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(-8.2147483646), floorl(-8.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(1111120.8), floorl(1111120.8), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(-1111120.9), floorl(-1111120.9), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(1234567.077), floorl(1234567.077), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(-1234567.077), floorl(-1234567.077), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(123456789101112131.000077), floorl(123456789101112131.000077), 1e-7);
    ck_assert_ldouble_eq_tol(s21_floor(-123456789101112131.000077), floorl(-123456789101112131.000077), 1e-7);
}
END_TEST

// fmod_zero
START_TEST(s21_fmod_f_zero) {
    ck_assert_ldouble_eq_tol(s21_fmod(0, 13), fmodl(0, 13), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(0, 13.13), fmodl(0, 13.13), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(0, 123456789101112.1314151617181920),
                                fmodl(0, 123456789101112.1314151617181920), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(0, 0.0000000001), fmodl(0, 0.0000000001), 1e-7);

    ck_assert_ldouble_eq_tol(s21_fmod(0, -13), fmodl(0, -13), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(0, -13.13), fmodl(0, -13.13), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(0, -123456789101112.1314151617181920),
                                fmodl(0, -123456789101112.1314151617181920), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(0, -0.0000000001), fmodl(0, -0.0000000001), 1e-7);

    ck_assert_ldouble_nan(s21_fmod(13, 0));
    ck_assert_ldouble_nan(s21_fmod(13.13, 0));
    ck_assert_ldouble_nan(s21_fmod(123456789101112.1314151617181920, 0));
    ck_assert_ldouble_nan(s21_fmod(0.0000000001, 0));

    ck_assert_ldouble_nan(s21_fmod(-13, 0));
    ck_assert_ldouble_nan(s21_fmod(-13.13, 0));
    ck_assert_ldouble_nan(s21_fmod(-123456789101112.1314151617181920, 0));
    ck_assert_ldouble_nan(s21_fmod(-0.0000000001, 0));

    ck_assert_ldouble_nan(s21_fmod(0, 0));
}
END_TEST

// fmod_x_positive
START_TEST(s21_fmod_f_x_positive) {
    ck_assert_ldouble_eq_tol(s21_fmod(1.0, 1.0), fmodl(1.0, 1.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(1.0, -1.0000001), fmodl(1.0, -1.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(1.0, 0.9999999999), fmodl(1.0, 0.9999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(1.0, -0.0000001), fmodl(1.0, -0.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(1.0, 12345678910111213141516171819.0),
                                fmodl(1.0, 12345678910111213141516171819.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(1.0, -123456789101112131415.161718192),
                                fmodl(1.0, -123456789101112131415.161718192), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(1.0, 13.0), fmodl(1.0, 13.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(1.0, -13.5), fmodl(1.0, -13.5), 1e-7);

    ck_assert_ldouble_eq_tol(s21_fmod(1.0000001, -1.0), fmodl(1.0000001, -1.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(1.0000001, 1.0000001), fmodl(1.0000001, 1.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(1.0000001, -0.9999999999), fmodl(1.0000001, -0.9999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(1.0000001, 0.0000001), fmodl(1.0000001, 0.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(1.0000001, -12345678910111213141516171819.0),
                                fmodl(1.0000001, -12345678910111213141516171819.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(1.0000001, 123456789101112131415.161718192),
                                fmodl(1.0000001, 123456789101112131415.161718192), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(1.0000001, -13.0), fmodl(1.0000001, -13.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(1.0000001, 13.5), fmodl(1.0000001, 13.5), 1e-7);

    ck_assert_ldouble_eq_tol(s21_fmod(0.0000001, -1.0), fmodl(0.0000001, -1.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(0.0000001, 1.0000001), fmodl(0.0000001, 1.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(0.0000001, -0.9999999999), fmodl(0.0000001, -0.9999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(0.0000001, 0.0000001), fmodl(0.0000001, 0.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(0.0000001, -12345678910111213141516171819.0),
                                fmodl(0.0000001, -12345678910111213141516171819.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(0.0000001, 123456789101112131415.161718192),
                                fmodl(0.0000001, 123456789101112131415.161718192), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(0.0000001, -13.0), fmodl(0.0000001, -13.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(0.0000001, 13.5), fmodl(0.0000001, 13.5), 1e-7);

    ck_assert_ldouble_eq_tol(s21_fmod(13.13, -1.0), fmodl(13.13, -1.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(13.13, 1.0000001), fmodl(13.13, 1.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(13.13, -0.9999999999), fmodl(13.13, -0.9999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(13.13, 0.0000001), fmodl(13.13, 0.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(13.13, -12345678910111213141516171819.0),
                                fmodl(13.13, -12345678910111213141516171819.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(13.13, 123456789101112131415.161718192),
                                fmodl(13.13, 123456789101112131415.161718192), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(13.13, -13.0), fmodl(13.13, -13.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(13.13, 13.5), fmodl(13.13, 13.5), 1e-7);
}
END_TEST

// fmod_x_negative
START_TEST(s21_fmod_f_x_negative) {
    ck_assert_ldouble_eq_tol(s21_fmod(-1.0, 1.0), fmodl(-1.0, 1.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-1.0, -1.0000001), fmodl(-1.0, -1.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-1.0, 0.9999999999), fmodl(-1.0, 0.9999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-1.0, -0.0000001), fmodl(-1.0, -0.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-1.0, 12345678910111213141516171819.0),
                                fmodl(-1.0, 12345678910111213141516171819.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-1.0, -123456789101112131415.161718192),
                                fmodl(-1.0, -123456789101112131415.161718192), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-1.0, 13.0), fmodl(-1.0, 13.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-1.0, -13.5), fmodl(-1.0, -13.5), 1e-7);

    ck_assert_ldouble_eq_tol(s21_fmod(-1.0000001, -1.0), fmodl(-1.0000001, -1.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-1.0000001, 1.0000001), fmodl(-1.0000001, 1.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-1.0000001, -0.9999999999), fmodl(-1.0000001, -0.9999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-1.0000001, 0.0000001), fmodl(-1.0000001, 0.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-1.0000001, -12345678910111213141516171819.0),
                                fmodl(-1.0000001, -12345678910111213141516171819.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-1.0000001, 123456789101112131415.161718192),
                                fmodl(-1.0000001, 123456789101112131415.161718192), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-1.0000001, -13.0), fmodl(-1.0000001, -13.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-1.0000001, 13.5), fmodl(-1.0000001, 13.5), 1e-7);

    ck_assert_ldouble_eq_tol(s21_fmod(-0.0000001, -1.0), fmodl(-0.0000001, -1.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-0.0000001, 1.0000001), fmodl(-0.0000001, 1.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-0.0000001, -0.9999999999), fmodl(-0.0000001, -0.9999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-0.0000001, 0.0000001), fmodl(-0.0000001, 0.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-0.0000001, -12345678910111213141516171819.0),
                                fmodl(-0.0000001, -12345678910111213141516171819.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-0.0000001, 123456789101112131415.161718192),
                                fmodl(-0.0000001, 123456789101112131415.161718192), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-0.0000001, -13.0), fmodl(-0.0000001, -13.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-0.0000001, 13.5), fmodl(-0.0000001, 13.5), 1e-7);

    ck_assert_ldouble_eq_tol(s21_fmod(-13.13, -1.0), fmodl(-13.13, -1.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-13.13, 1.0000001), fmodl(-13.13, 1.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(1-3.13, -0.9999999999), fmodl(-13.13, -0.9999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-13.13, 0.0000001), fmodl(-13.13, 0.0000001), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-13.13, -12345678910111213141516171819.0),
                                fmodl(-13.13, -12345678910111213141516171819.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-13.13, 123456789101112131415.161718192),
                                fmodl(-13.13, 123456789101112131415.161718192), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-13.13, -13.0), fmodl(-13.13, -13.0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_fmod(-13.13, 13.5), fmodl(-13.13, 13.5), 1e-7);
}
END_TEST

// log
START_TEST(s21_log_f) {
    ck_assert_ldouble_infinite(s21_log(0));
    ck_assert_ldouble_eq_tol(s21_log(1), logl(1), 1e-7);
    ck_assert_ldouble_nan(s21_log(-1));
    ck_assert_ldouble_eq_tol(s21_log(0.5), logl(0.49999999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_log(0.54321), logl(0.54321), 1e-7);
    ck_assert_ldouble_nan(s21_log(-0.54321));
    ck_assert_ldouble_eq_tol(s21_log(0.99999), logl(0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_log(2.1), logl(2.1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_log(0.00003), logl(0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_log(10), logl(10), 1e-7);
    ck_assert_ldouble_eq_tol(s21_log(7.2147483646), logl(7.2147483646), 1e-7);
}
END_TEST

// pow
START_TEST(s21_pow_f) {
    ck_assert_ldouble_eq_tol(s21_pow(0.0, 2), powl(0.0, 2), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(1.0, 0), powl(1.0, 0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(-1.0, -3), powl(-1.0, -3), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(0.5, 4), powl(0.5, 4), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(0.00001, 1.3), powl(0.00001, 1.3), 1e-7);
    ck_assert_ldouble_nan(s21_pow(-0.00001, -2.333));
    ck_assert_ldouble_eq_tol(s21_pow(0.4444449, 1.2222222), powl(0.4444449, 1.2222222), 1e-7);
    ck_assert_ldouble_nan(s21_pow(-0.4444449, 0.00001));
    ck_assert_ldouble_eq_tol(s21_pow(0.99999, 3), powl(0.99999, 3), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(-0.99999, 34), powl(-0.99999, 34), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(0.00003, 5), powl(0.00003, 5), 1e-7);
    ck_assert_ldouble_nan(s21_pow(-0.00003, 4.00001));
    ck_assert_ldouble_eq_tol(s21_pow(10.1, -10.2), powl(10.1, -10.2), 1e-7);
    ck_assert_ldouble_eq_tol(s21_pow(7.2147483646, -1.1), powl(7.2147483646, -1.1), 1e-7);
}
END_TEST


// sin
START_TEST(s21_sin_f) {
    ck_assert_ldouble_eq_tol(s21_sin(0), sinl(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(1), sinl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(-1), sinl(-1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(0.5), sinl(0.49999999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(0.54321), sinl(0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(-0.54321), sinl(-0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(0.99999), sinl(0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(-0.99999), sinl(-0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(0.00003), sinl(0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(-0.00003), sinl(-0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(10), sinl(10), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(-10), sinl(-10), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(7.2147483646), sinl(7.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(-8.2147483646), sinl(-8.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(123456789), sinl(123456789), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sin(-123456789), sinl(-123456789), 1e-7);
}
END_TEST

// sqrt
START_TEST(s21_sqrt_f) {
    ck_assert_ldouble_eq_tol(s21_sqrt(0), sqrtl(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sqrt(1), sqrtl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sqrt(0.5), sqrtl(0.49999999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sqrt(0.54321), sqrtl(0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sqrt(0.99999), sqrtl(0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sqrt(0.00003), sqrtl(0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sqrt(10), sqrtl(10), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sqrt(7.2147483646), sqrtl(7.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_sqrt(12345678), sqrtl(12345678), 1e-7);
    ck_assert_ldouble_nan(s21_sqrt(-1));
    ck_assert_ldouble_nan(s21_sqrt(-0.00000001));
    ck_assert_ldouble_nan(s21_sqrt(-0.54321));
}
END_TEST

// tan
START_TEST(s21_tan_f) {
    ck_assert_ldouble_eq_tol(s21_tan(0), tanl(0), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(1), tanl(1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(-1), tanl(-1), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(0.5), tanl(0.49999999999999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(0.54321), tanl(0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(-0.54321), tanl(-0.54321), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(0.99999), tanl(0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(-0.99999), tanl(-0.99999), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(0.00003), tanl(0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(-0.00003), tanl(-0.00003), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(10), tanl(10), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(-10), tanl(-10), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(7.2147483646), tanl(7.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(-8.2147483646), tanl(-8.2147483646), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(1234567), tanl(1234567), 1e-7);
    ck_assert_ldouble_eq_tol(s21_tan(-1234567), tanl(-1234567), 1e-7);
}
END_TEST


Suite *lib_suite(void) {
    Suite *s;
    s = suite_create("s21_math test cases");

    // abs
    TCase *tc_abs;
    tc_abs = tcase_create("abs func");
    suite_add_tcase(s, tc_abs);
    tcase_add_test(tc_abs, s21_abs_f);

    // acos
    TCase *tc_acos;
    tc_acos = tcase_create("acos func");
    suite_add_tcase(s, tc_acos);
    tcase_add_test(tc_acos, s21_acos_f);

    // asin
    TCase *tc_asin;
    tc_asin = tcase_create("asin func");
    suite_add_tcase(s, tc_asin);
    tcase_add_test(tc_asin, s21_asin_f);

    // atan
    TCase *tc_atan;
    tc_atan = tcase_create("atan func");
    suite_add_tcase(s, tc_atan);
    tcase_add_test(tc_atan, s21_atan_f);

    // ceil
    TCase *tc_ceil;
    tc_ceil = tcase_create("ceil func");
    suite_add_tcase(s, tc_ceil);
    tcase_add_test(tc_ceil, s21_ceil_f);

    // cos
    TCase *tc_cos;
    tc_cos = tcase_create("cos func");
    suite_add_tcase(s, tc_cos);
    tcase_add_test(tc_cos, s21_cos_f);

    // exp
    TCase *tc_exp;
    tc_exp = tcase_create("exp func");
    suite_add_tcase(s, tc_exp);
    tcase_add_test(tc_exp, s21_exp_f);

    // fabs
    TCase *tc_fabs;
    tc_fabs = tcase_create("fabs func");
    suite_add_tcase(s, tc_fabs);
    tcase_add_test(tc_fabs, s21_fabs_f);

    // floor
    TCase *tc_floor;
    tc_floor = tcase_create("floor func");
    suite_add_tcase(s, tc_floor);
    tcase_add_test(tc_floor, s21_floor_f);

    // fmod
    TCase *tc_fmod;
    tc_fmod = tcase_create("fmod func");
    suite_add_tcase(s, tc_fmod);
    tcase_add_test(tc_fmod, s21_fmod_f_zero);
    tcase_add_test(tc_fmod, s21_fmod_f_x_positive);
    tcase_add_test(tc_fmod, s21_fmod_f_x_negative);

    // log
    TCase *tc_log;
    tc_log = tcase_create("log func");
    suite_add_tcase(s, tc_log);
    tcase_add_test(tc_log, s21_log_f);

    // pow
    TCase *tc_pow;
    tc_pow = tcase_create("pow func");
    suite_add_tcase(s, tc_pow);
    tcase_add_test(tc_pow, s21_pow_f);

    // sin
    TCase *tc_sin;
    tc_sin = tcase_create("sin func");
    suite_add_tcase(s, tc_sin);
    tcase_add_test(tc_sin, s21_sin_f);

    // sqrt
    TCase *tc_sqrt;
    tc_sqrt = tcase_create("sqrt func");
    suite_add_tcase(s, tc_sqrt);
    tcase_add_test(tc_sqrt, s21_sqrt_f);

    // tan
    TCase *tc_tan;
    tc_tan = tcase_create("tan func");
    suite_add_tcase(s, tc_tan);
    tcase_add_test(tc_tan, s21_tan_f);

    return s;
}

int main(void) {
    Suite *s;
    SRunner *sr;

    s = lib_suite();
    sr = srunner_create(s);
    srunner_run_all(sr, CK_NORMAL);
    srunner_free(sr);
    return 0;
}
