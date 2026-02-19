#include <stdio.h>
#include <math.h>
#include <clocale>

double taylor_cos(double x, double eps, int max_n, int* n_used) {
    double sum = 1, term = 1;
    *n_used = 1;
    for (int i = 1; i < max_n && fabs(term) > eps; i++) {
        term *= -x * x / (2 * i * (2 * i - 1));
        sum += term;
        (*n_used)++;
    }
    return sum;
}

double taylor_exp(double x, double eps, int max_n, int* n_used) {
    double sum = 1, term = 1;
    *n_used = 1;
    for (int i = 1; i < max_n && fabs(term) > eps; i++) {
        term *= x / i;
        sum += term;
        (*n_used)++;
    }
    return sum;
}

double taylor_sin(double x, double eps, int max_n, int* n_used) {
    double sum = x, term = x;
    *n_used = 1;
    for (int i = 1; i < max_n && fabs(term) > eps; i++) {
        term *= -x * x / (2 * i * (2 * i + 1));
        sum += term;
        (*n_used)++;
    }
    return sum;
}

double taylor_arcsin(double x, double eps, int max_n, int* n_used) {
    if (x < -1 || x > 1) return NAN;
    double sum = x, term = x;
    *n_used = 1;
    for (int i = 1; i < max_n && fabs(term) > eps; i++) {
        term *= x * x * (2 * i - 1) * (2 * i - 1) / (2 * i * (2 * i + 1));
        sum += term;
        (*n_used)++;
    }
    return sum;
}

void single() {
    int f, n, used, digits;
    double x, eps, ref, calc, diff;

    printf("Функция (1-cos 2-exp 3-sin 4-arcsin): ");
    scanf_s("%d", &f);
    printf("x: ");
    scanf_s("%lf", &x);
    printf("До какого знака после запятой (1-10): ");
    scanf_s("%d", &digits);
    printf("Макс. слагаемых (1-1000): ");
    scanf_s("%d", &n);

    eps = 1.0;
    for (int i = 0; i < digits; i++) {
        eps /= 10.0;
    }

    double (*func)(double, double, int, int*) = NULL;

    if (f == 1) { func = taylor_cos; ref = cos(x); }
    else if (f == 2) { func = taylor_exp; ref = exp(x); }
    else if (f == 3) { func = taylor_sin; ref = sin(x); }
    else if (f == 4) { func = taylor_arcsin; ref = asin(x); }

    if (func) {
        calc = func(x, eps, n, &used);
        diff = calc - ref;
        printf("\nТочность: до %d знака после запятой (eps = %.10g)\n", digits, eps);
        printf("Эталон: %.*lf\n", digits + 2, ref);
        printf("Расчет: %.*lf\n", digits + 2, calc);
        printf("Разница: %.*lf\n", digits + 2, diff);
        printf("Слагаемых: %d\n", used);
    }
}

void series() {
    int f, n_max, used;
    double x, ref, calc, diff;

    printf("Функция (1-cos 2-exp 3-sin 4-arcsin): ");
    scanf_s("%d", &f);
    printf("x: ");
    scanf_s("%lf", &x);
    printf("Экспериментов (1-25): ");
    scanf_s("%d", &n_max);

    double (*func)(double, double, int, int*) = NULL;

    if (f == 1) { func = taylor_cos; ref = cos(x); }
    else if (f == 2) { func = taylor_exp; ref = exp(x); }
    else if (f == 3) { func = taylor_sin; ref = sin(x); }
    else if (f == 4) { func = taylor_arcsin; ref = asin(x); }

    if (func) {
        printf("\nЭталон: %.10lf\n\n", ref);
        printf("N   Расчет        Разница\n");
        for (int n = 1; n <= n_max; n++) {
            calc = func(x, 1e-20, n, &used);
            diff = calc - ref;
            printf("%d %.8lf %.8lf\n", n, calc, diff);
        }
    }
}

int main() {
    int mode;
    setlocale(LC_ALL, "Russian");
    printf("1-Одиночный 2-Серийный: ");
    scanf_s("%d", &mode);

    if (mode == 1) single();
    else if (mode == 2) series();
    else printf("Ошибка\n");

    return 0;
}