#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14159265358979323846
// Прототипы функций
unsigned long long factorial(int number);
double taylor_sin(double x, double epsilon, int N, int* used_attempt);
double taylor_cos(double x, double epsilon, int N, int* used_attempt);
double taylor_exp(double x, double epsilon, int N, int* used_attempt);
double taylor_arccos(double x, double epsilon, int N, int* used_attempt);
void print_menu(void);
// Факториал
unsigned long long factorial(int number) {
    unsigned long long result = 1;
    for (int i = 2; i <= number; i++) {
        result *= i;
    }
    return result;
}
// Ряд Тейлора для sin(x)
double taylor_sin(double x, double epsilon, int N, int* used_attempt) {
    double sum = 0.0;
    double term = x; // первый член ряда
    int n = 0;
    // Приведение x к интервалу [-π, π] для лучшей сходимости
    while (x > PI) x -= 2 * PI;
    while (x < -PI) x += 2 * PI;
    term = x; // обновляем первый член
    for (n = 0; n < N; n++) {
        sum += term;
        if (fabs(term) < epsilon && n > 0) break;
        // Рекуррентное вычисление следующего члена
        term = -term * x * x / ((2 * n + 2) * (2 * n + 3));
    }
    *used_attempt = n + 1;
    return sum;
}
// Ряд Тейлора для cos(x)
double taylor_cos(double x, double epsilon, int N, int* used_attempt) {
    double sum = 0.0;
    double term = 1.0; // первый член ряда
    int n = 0;
    // Приведение x к интервалу [-π, π]
    while (x > PI) x -= 2 * PI;
    while (x < -PI) x += 2 * PI;
    term = 1.0; // cos(0) = 1
    for (n = 0; n < N; n++) {
        sum += term;
        if (fabs(term) < epsilon && n > 0) break;
        // Рекуррентное вычисление
        term = -term * x * x / ((2 * n + 1) * (2 * n + 2));
    }
    *used_attempt = n + 1;
    return sum;
}
// Ряд Тейлора для exp(x)
double taylor_exp(double x, double epsilon, int N, int* used_attempt) {
    double sum = 0.0;
    double term = 1.0; // первый член ряда
    int n = 0;
    for (n = 0; n < N; n++) {
        sum += term;
        if (fabs(term) < epsilon && n > 0) break;
        // Рекуррентное вычисление
        term = term * x / (n + 1);
    }
    *used_attempt = n + 1;
    return sum;
}
// Ряд Тейлора для arccos(x)
double taylor_arccos(double x, double epsilon, int N, int* used_attempt) {
    // Проверка области определения
    if (x < -1.0 || x > 1.0) {
        printf("Ошибка: arccos(x) определен только для x ∈ [-1, 1]\n");
        *used_attempt = 0;
        return NAN; // Not a Number
    }
    double sum = PI / 2.0;
    double term = x;
    int n = 0;
    for (n = 0; n < N; n++) {
        sum -= term;
        if (fabs(term) < epsilon && n > 0) break;
        // Вычисление коэффициента биномиального ряда
        double coeff = 1.0;
        for (int k = 1; k <= n + 1; k++) {
            coeff *= (double)(2 * k - 1) / (2 * k);
        }
        term = coeff * pow(x, 2 * n + 3) / (2 * n + 3);
    }
    *used_attempt = n + 1;
    return sum;
}
void print_menu(void) {
    printf("Выберите функцию:\n");
    printf("1 - sin(x)\n");
    printf("2 - cos(x)\n");
    printf("3 - exp(x)\n");
    printf("4 - arccos(x)\n");
}
int main(void) {
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
    // Указатели на функции
    double (*func)(double, double, int, int*) = NULL;
    double (*ref_func)(double) = NULL;
    // Выбор функции
    switch (f) {
    case 1:
        func = taylor_sin;
        ref_func = sin;
        break;
    case 2:
        func = taylor_cos;
        ref_func = cos;
        break;
    case 3:
        func = taylor_exp;
        ref_func = exp;
        break;
    case 4:
        func = taylor_arccos;
        ref_func = acos;
        break;
    default:
        printf("Неверный номер функции!\n");
        return 1;
    }
    double x;
    printf("Введите x: ");
    scanf_s("%lf", &x);
    if (mode == 1) {
        // Однократный расчет
        double epsilon;
        int N;
        printf("Введите число элементов ряда (1..1000): ");
        scanf_s("%d", &N);
        if (N < 1 || N > 1000) {
            printf("Неверное число элементов!\n");
            return 1;
        }
        printf("Введите точность (например, 0.000001): ");
        scanf_s("%lf", &epsilon);
        if (epsilon <= 0) {
            printf("Точность должна быть положительной!\n");
            return 1;
        }
        int used = 0;
        double value = func(x, epsilon, N, &used);
        double ref = ref_func(x);
        printf("\n=== Результат ===\n");
        printf("Эталонное значение:       %.15lf\n", ref);
        printf("Вычисленная оценка:       %.15lf\n", value);
        printf("Разница:                  %.15le\n", fabs(ref - value));
        printf("Использовано слагаемых:   %d\n", used);
        printf("Относительная погрешность: %.15le\n", fabs((ref - value) / ref));
    }
    else if (mode == 2) {
        // Серийный эксперимент
        int NMax;
        printf("Введите число экспериментов (1..25): ");
        scanf_s("%d", &NMax);
        if (NMax < 1 || NMax > 25) {
            printf("Неверное число экспериментов!\n");
            return 1;
        }
        double ref = ref_func(x);
        printf("\nЭталонное значение: %.15lf\n", ref);
        printf("\nТаблица:\n");
        printf(" N   | Значение                | Разница          | Использовано\n");
        printf("-------------------------------------------------------------\n");
        for (int n = 1; n <= NMax; n++) {
            int used = 0;
            // Используем маленькую точность для серийного эксперимента
            double val = func(x, 1e-15, n, &used);
            printf("%3d | %.15lf | %.15le | %d\n",
                n, val, fabs(ref - val), used);
        }
    }
    else {
        printf("Неверный режим!\n");
        return 1;
    }
    return 0;
}