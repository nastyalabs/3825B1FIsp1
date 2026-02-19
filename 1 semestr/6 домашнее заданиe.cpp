#include <stdio.h>
#include <math.h>
#include <locale.h>
#define PI 3.14159265358979323846
typedef double (*taylor_func)(double x, double eps, int N, int* used_terms);
double taylor_cos(double x, double eps, int N, int* used_terms) {
    double sum = 0.0;
    double term = 1.0;     
    int n = 0;

    for (n = 0; n < N; n++) {
        if (n > 0)
            term *= (-1) * x * x / ((2 * n - 1) * (2 * n));

        sum += term;
        if (fabs(term) < eps) break;
    }

    *used_terms = n + 1;
    return sum;
}
double taylor_exp(double x, double eps, int N, int* used_terms) {
    double sum = 0.0;
    double term = 1.0;   
    int n = 0;
    for (n = 0; n < N; n++) {
        if (n > 0)
            term *= x / n;

        sum += term;
        if (fabs(term) < eps) break;
    }

    *used_terms = n + 1;
    return sum;
}
double taylor_arccos(double x, double eps, int N, int* used_terms) {
    double sum = PI / 2;
    double term = x;
    int n = 0;
    for (n = 0; n < N; n++) {
        double coeff = 1.0;
        for (int k = 1; k <= n; k++)
            coeff *= (double)(n + k) / k;
        coeff /= pow(4.0, n);
        term = coeff * pow(x, 2 * n + 1) / (2 * n + 1);
        sum -= term;
        if (fabs(term) < eps) 
            break;
    }
    *used_terms = n + 1;
    return sum;
}
void print_menu() {
    setlocale(LC_ALL, "Russian");
    printf("Выберите функцию:\n");
    printf("1 - cos(x)\n");
    printf("2 - exp(x)\n");
    printf("3 - arccos(x)\n");
}
int main() {
    setlocale(LC_ALL, "Russian");
    int mode;
    printf("Выберите режим работы:\n");
    printf("1 - Однократный расчет\n");
    printf("2 - Серийный эксперимент\n");
    printf("Ваш выбор: ");
    scanf_s("%d", &mode);
    print_menu();
    int f;
    printf("Введите номер функции: ");
    scanf_s("%d", &f);
    taylor_func func = NULL;
    double (*ref_func)(double) = NULL;
    if (f == 1) {
        func = taylor_cos;
        ref_func = cos;
    }
    else if (f == 2) {
        func = taylor_exp;
        ref_func = exp;
    }
    else if (f == 3) {
        func = taylor_arccos;
        ref_func = acos;
    }
    else {
        printf("Неверный номер функции!\n");
        return 0;
    }
    double x;
    printf("Введите x: ");
    scanf_s(" %lf", &x);
    if (mode == 1) {
        double eps;
        int N;
        printf("Введите число элементов ряда (1..1000): ");
        scanf_s(" %d", &N);    
        printf("Введите точность (eps >= 0.000001): ");
        scanf_s(" %lf", &eps);
        int used = 0;
        double value = func(x, eps, N, &used);
        double ref = ref_func(x);
        printf("\n=== Результат ===\n");
        printf("Эталонное значение:       %.15lf\n", ref);
        printf("Вычисленная оценка:       %.15lf\n", value);
        printf("Разница:                  %.15lf\n", fabs(ref - value));
        printf("Использовано слагаемых:  %d\n", used);
    }
    else if (mode == 2) {
        int NMax;
        printf("Введите число экспериментов (1..25): ");
        scanf_s("%d", &NMax);

        double ref = ref_func(x);
        printf("\nЭталонное значение: %.15lf\n", ref);

        printf("\nТаблица:\n");
        printf(" N   | Значение                | Разница\n");
        printf("----------------------------------------------\n");

        for (int n = 1; n <= NMax; n++) {
            int used = 0;
            double val = func(x, 0.0, n, &used);
            printf("%3d | %.15lf | %.15lf\n", n, val, fabs(ref - val));
        }
    }
    else {
        printf("Неверный режим!\n");
    }
    return 0;
}

