#include <stdio.h>
#include <math.h>

#ifndef M_PI
#define M_PI    3.14159265358979323846
#endif

// Указатель на функцию
typedef double (*math_func)(double);

// Функции Тейлора:
double taylor_sin(double x, double eps, int max_terms, int *terms_used);
double taylor_cos(double x, double eps, int max_terms, int *terms_used);
double taylor_exp(double x, double eps, int max_terms, int *terms_used);
double taylor_arctg(double x, double eps, int max_terms, int *terms_used);

// Эталонные функции (встроенные)
double ref_sin(double x);
double ref_cos(double x);
double ref_exp(double x);
double ref_arctg(double x);

// Функции меню
void single_calculation();
void series_experiment();


int main() {
    int mode;
    printf("=== Калькулятор функций через ряд Тейлора ===\n");
    printf("Выберите режим работы:\n");
    printf("1 - Однократный расчет\n");
    printf("2 - Серийный эксперимент\n");
    printf("Ваш выбор: ");
    scanf("%d", &mode);

    if (mode == 1) {
        single_calculation();
    } else if (mode == 2) {
        series_experiment();
    } else {
        printf("Неверный режим.\n");
    }

    return 0;
}


// sin(x) 
double taylor_sin(double x, double eps, int max_terms, int *terms_used) {
    // Приведение x к диапазону [0, 2*PI] для лучшей сходимости
    x = fmod(x, 2 * M_PI);
    
    double sum = x;  // первый член ряда: x
    double term = x;
    int n = 1;
    
    for (int i = 1; i <= max_terms; i++) {
        term *= -x * x / ((2 * i) * (2 * i + 1));
        sum += term;
        n++;
        if (fabs(term) < eps) break;
    }
    *terms_used = n;
    return sum;
}

double ref_sin(double x) {
    return sin(x);
}

// cos(x)
double taylor_cos(double x, double eps, int max_terms, int *terms_used) {
    double sum = 1.0;
    double term = 1.0;
    int n = 1;
    
    // Приведение x к диапазону [0, 2*PI] для лучшей сходимости
    x = fmod(x, 2 * M_PI);
    
    for (int i = 1; i <= max_terms; i++) {
        term *= -x * x / ((2 * i - 1) * (2 * i));
        sum += term;
        n++;
        if (fabs(term) < eps) break;
    }
    *terms_used = n;
    return sum;
}

double ref_cos(double x) {
    return cos(x);
}

// exp(x)
double taylor_exp(double x, double eps, int max_terms, int *terms_used) {
    double sum = 1.0;
    double term = 1.0;
    int n = 1;
    
    for (int i = 1; i <= max_terms; i++) {
        term *= x / i;
        sum += term;
        n++;
        if (fabs(term) < eps) break;
    }
    *terms_used = n;
    return sum;
}

double ref_exp(double x) {
    return exp(x);
}

// arctg(x)
double taylor_arctg(double x, double eps, int max_terms, int *terms_used) {
    double sum = 0.0;
    int n = 0;
    int sign = 1;
    double xx;
    
    // Используем свойство нечетности: arctg(-x) = -arctg(x)
    if (x < 0) {
        x = -x;
        sign = -1;
    }
    
    // Для |x| > 1 используем формулу: arctg(x) = PI/2 - arctg(1/x)
    if (x > 1) {
        xx = 1.0 / x;
    } else {
        xx = x;
    }
    
    // Ряд Тейлора для arctg(x) = x - x^3/3 + x^5/5 - x^7/7 + ...
    for (int i = 0; i < max_terms; i++) {
        double term = pow(xx, 2*i+1) / (2*i+1);
        if (i % 2 == 1) term = -term;  // Знакочередующийся ряд
        sum += term;
        n++;
        if (fabs(term) < eps) break;
    }
    
    // Если x > 1, применяем преобразование
    if (x > 1) {
        sum = M_PI/2 - sum;
    }
    
    *terms_used = n;
    return sign * sum;
}

double ref_arctg(double x) {
    return atan(x);
}

void single_calculation() {
    int choice, max_terms, terms_used;
    double x, eps, result, reference, diff;
    
    printf("\n=== ОДНОКРАТНЫЙ РАСЧЕТ ===\n");
    printf("Выберите функцию:\n");
    printf("1 - sin(x)\n");
    printf("2 - cos(x)\n");
    printf("3 - exp(x)\n");
    printf("4 - arctg(x)\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);
    
    printf("Введите x: ");
    scanf("%lf", &x);
    
    printf("Введите точность (>= 0.000001): ");
    scanf("%lf", &eps);
    if (eps < 1e-6) {
        printf("Точность увеличена до 0.000001\n");
        eps = 1e-6;
    }
    
    printf("Введите максимальное число слагаемых (1-1000): ");
    scanf("%d", &max_terms);
    if (max_terms < 1) max_terms = 1;
    if (max_terms > 1000) max_terms = 1000;
    
    // Выбор функции через указатель
    double (*taylor_func)(double, double, int, int*) = NULL;
    double (*ref_func)(double) = NULL;
    
    switch(choice) {
        case 1:
            taylor_func = taylor_sin;
            ref_func = ref_sin;
            break;
        case 2:
            taylor_func = taylor_cos;
            ref_func = ref_cos;
            break;
        case 3:
            taylor_func = taylor_exp;
            ref_func = ref_exp;
            break;
        case 4:
            taylor_func = taylor_arctg;
            ref_func = ref_arctg;
            break;
        default:
            printf("Неверный выбор функции.\n");
            return;
    }
    
    if (taylor_func == NULL || ref_func == NULL) {
        printf("Ошибка выбора функции.\n");
        return;
    }
    
    // Расчет
    result = taylor_func(x, eps, max_terms, &terms_used);
    reference = ref_func(x);
    diff = result - reference;
    
    // Вывод результатов
    printf("\n=== РЕЗУЛЬТАТЫ ===\n");
    printf("Эталонное значение: %.10f\n", reference);
    printf("Вычисленное значение: %.10f\n", result);
    printf("Разница: %.10f\n", diff);
    printf("Количество использованных слагаемых: %d\n", terms_used);
}

void series_experiment() {
    int choice, n_max, terms_used;
    double x, result, reference, diff;
    
    printf("\n=== СЕРИЙНЫЙ ЭКСПЕРИМЕНТ ===\n");
    printf("Выберите функцию:\n");
    printf("1 - sin(x)\n");
    printf("2 - cos(x)\n");
    printf("3 - exp(x)\n");
    printf("4 - arctg(x)\n");
    printf("Ваш выбор: ");
    scanf("%d", &choice);
    
    printf("Введите x: ");
    scanf("%lf", &x);
    
    printf("Введите количество экспериментов (1-25): ");
    scanf("%d", &n_max);
    if (n_max < 1) n_max = 1;
    if (n_max > 25) n_max = 25;
    
    // Выбор функции
    double (*taylor_func)(double, double, int, int*) = NULL;
    double (*ref_func)(double) = NULL;
    
    switch(choice) {
        case 1:
            taylor_func = taylor_sin;
            ref_func = ref_sin;
            break;
        case 2:
            taylor_func = taylor_cos;
            ref_func = ref_cos;
            break;
        case 3:
            taylor_func = taylor_exp;
            ref_func = ref_exp;
            break;
        case 4:
            taylor_func = taylor_arctg;
            ref_func = ref_arctg;
            break;
        default:
            printf("Неверный выбор функции.\n");
            return;
    }
    
    if (taylor_func == NULL || ref_func == NULL) {
        printf("Ошибка выбора функции.\n");
        return;
    }
    
    reference = ref_func(x);
    
    printf("\n=== РЕЗУЛЬТАТЫ ===\n");
    printf("Эталонное значение: %.10f\n\n", reference);
    printf("%-10s %-20s %-20s\n", "Слагаемые", "Приближение", "Разница");
    printf("--------------------------------------------------\n");
    
    // Серийный эксперимент с разным количеством слагаемых
    for (int n = 1; n <= n_max; n++) {
        result = taylor_func(x, 1e-15, n, &terms_used); // Очень малая точность для использования всех n слагаемых
        diff = result - reference;
        printf("%-10d %-20.10f %-20.10f\n", n, result, diff);
    }
}