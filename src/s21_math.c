#include "s21_math.h"

int s21_abs(int x) {
    if (x < 0) {
        x = - x;
    }
    return x;
}

long double s21_acos(double x) {
    long double a;
    if (x > 1 || x < -1) {
        a = s21_NAN;
    } else {
        a = s21_asin(x);
        a = S21_M_PI2 - (a);
    }
    return(a);
}

long double s21_asin(long double x) {
    float a = 1;
    if (x > 1 || x < -1) {
        a = s21_NAN;
    } else {
        if (x <- 1.F) {a = 0;}
        if (x == -1.F) {a = -S21_M_PI2;}
        if (x > 1.F) {a = 0;}
        if (x == 1.F) {a = S21_M_PI2;}
        if (a == 1) {
            x /= s21_sqrt(1.F - x * x);
            a = s21_atan(x);
        }
    }
    return(a);
}


long double s21_atan(long double x) {
    int sta = 0, sp = 0;
    long double x2, a;
    if (x < 0.F) {
        x = -x;
        sta|=1;
    }
    if (x > 1.F) {
        x = 1.F / x;
        sta|=2;
    }
    while (x > S21_M_PI12) {
        sp++;
        a = x + S21_SQRT3;
        a = 1.F / a;
        x *= S21_SQRT3;
        x -= 1.F;
        x *= a;
    }
    x2 = x * x; a = x2 + 1.4087812F; a = 0.55913709F / a; a += 0.60310579F;
    a -= 0.05160454F * x2; a *= x;
    while (sp > 0) {a += S21_M_PI6; sp--;}
    if (sta&2) a = S21_M_PI2 - a;
    if (sta&1) a =- a;
    return a;
}

long double s21_ceil(double x) {
    long int t = (long int)x;
    if (x >= 0) {
        if ((double)t != x) {t += 1;}
    }
    long double res = (long double)t;
    return res;
}

long double s21_cos(double x) {
    if (x < -2 * S21_M_PI || x > 2 * S21_M_PI) {
        x = s21_fmod(x, 2 * S21_M_PI);
    }
    long double result = 0;
    result = s21_sin(S21_M_PI / 2 + x);
    return result;
}

long double s21_exp(double x) {
    long double res = 1;
    long double temp = 1;
    long double i = 1;
    int flag = 0, flag2 = 0;
    if (x < 0) {
        x *= -1;
        flag = 1;
    }
    while (s21_fabs(res) > S21_EPS && flag2 == 0) {
        res *= x / i;
        i += 1;
        temp += res;
        if (temp > S21_DBL_MAX) {
            temp = s21_INF;
            flag2 = 1;
        }
    }
    if (flag == 1) {
        if (temp > S21_DBL_MAX) {
          temp = 0;
        } else {
          temp = 1. / temp;
        }
    }
    if (temp > S21_DBL_MAX) {
        temp = s21_INF;
    }
    return temp;
}

long double s21_fabs(double x) {
    if (x <= 0)
    x = (long double)(x - (2 * x));
    return (long double)x;
}

long double s21_floor(double x) {
    if (x < 0 && (long double)((long int)x) != x) {x--;}
    long double u = (long double)((long int)x);
    return u;
}


long double s21_fmod(double x, double y) {
    double res1, res2, res;
    res1 = x / y;
    if (x < 0 && y < 0) {
        res2 = s21_abs(res1);
    } else if (x < 0 || y < 0) {
        res2 = (-1) * s21_abs(res1);
    } else {
        res2 = s21_abs((long int)res1);
    }
    res = x - res2 * y;
    if (y == 0) {
        res = 0 / 0.0;
    }
    return res;
}

long double s21_log(double x) {
    long double znam, result = 0;
    long double del;
    int n = 1;
    long double torch = 1;
    if (x < 0) {
        result = s21_NAN;
    } else if (x == 0) {
        result = - s21_INF;
    } else if (s21_fabs(x - 1) < 1) {
        while (s21_fabs(result - torch) > S21_EPS) {
            del = n;
            znam = s21_pow_int((- 1), n + 1);
            torch = result;
            result = result + ((znam/del) * s21_pow_int((x - 1), n));
            n++;
        }
    } else {
        x = x / (x - 1);
        while (s21_fabs(result - torch) > S21_EPS) {
            del = n * s21_pow_int(x, n);
            znam = 1;
            torch = result;
            result = result + znam / del;
            n++;
        }
    }
    return result;
}

long double s21_pow(double base, double ex) {
    long double result = 0;
    if ((int)ex == ex) {
        result = s21_pow_int(base, ex);
    } else {
         result = s21_exp(ex * s21_log(base));
    }
    return result;
}

long double s21_pow_int(double base, double exp) {
    long double result = 1;
    if (exp == 0) {
        result = 1;
    } else if (exp < 0) {
        exp = -exp;
        while (exp) {
            if (s21_fmod(exp, 2) == 0) {
                exp /= 2;
                base *= base;
            } else {
                exp--;
                result *= base;
            }
            result = 1/result;
        }
    } else {
        while (exp) {
            if (s21_fmod(exp, 2) == 0) {
                exp /= 2;
                base *= base;
            } else {
                exp--;
                result *= base;
            }
        }
    }
    return result;
}

long double s21_sin(double x) {
    if (x < -2 * S21_M_PI || x > 2 * S21_M_PI) {
            x = s21_fmod(x, 2 * S21_M_PI);
    }
    long double result = 0, znam, del;
    int n = 1;
    while (s21_fabs(s21_pow(x, 2 * n - 1) / s21_fact(n)) > S21_EPS) {
        del = s21_fact(2 * n - 1);
        znam = s21_pow(-1, n - 1) * s21_pow(x, 2 * n - 1);
        result = result + (znam / del);
        n++;
    }
    return result;
}

long double s21_fact(long double x) {
    long double result = 1;
    for (long double i = 1; i <= x; i++) {
        result *= i;
    }
    return result;
}


long double s21_sqrt(double x) {
    double l = 0.0;
    double r = 1e100;  // большое число
    double m;
    while (r - l > 1e-8) {  // точность
        m = l + (r - l) / 2.0;
        if (m * m > x)
            r = m;
        else
            l = m;
    }
    if (x < 0) {l = s21_NAN;}
    return l;
}

long double s21_tan(double x) {
    return s21_sin(x) / s21_cos(x);
}
