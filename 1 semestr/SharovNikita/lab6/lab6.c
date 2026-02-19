#include <stdio.h>
#include <math.h>


long double calcCos(double x, int maxTerms, double epsilon, int *usedTerms) {
    long double term = 1.0;
    long double sum = term;
    *usedTerms = 1;

    for (int i = 1; i < maxTerms; i++) {
        term *= -x * x / ((2 * i - 1) * (2 * i));
        sum += term;
        (*usedTerms)++;

        if (fabs(term) < epsilon)
            break;
    }
    return sum;
}


long double calcExp(double x, int maxTerms, double epsilon, int *usedTerms) {
    long double term = 1.0;
    long double sum = term;
    *usedTerms = 1;

    for (int i = 1; i < maxTerms; i++) {
        term *= x / i;
        sum += term;
        (*usedTerms)++;

        if (fabs(term) < epsilon)
            break;
    }
    return sum;
}


long double calcLn(double x, int maxTerms, double epsilon, int *usedTerms) {
    long double term = x;
    long double sum = term;
    *usedTerms = 1;

    for (int i = 2; i <= maxTerms; i++) {
        term *= -x * (i - 1) / i;
        sum += term;
        (*usedTerms)++;

        if (fabs(term) < epsilon)
            break;
    }
    return sum;
}

int main() {
    int mode;
    printf("Введите режим (1 - один расчет, 2 - серия): ");
    scanf("%d", &mode);

    double x;

    if (mode == 1) {
        int func, maxTerms, usedTerms;
        double eps, approx, exact;

        printf("Выберите функцию:\n");
        printf("1 - cos(x)\n2 - exp(x)\n3 - ln(1+x)\n");
        scanf("%d", &func);

        printf("Введите x: ");
        scanf("%lf", &x);

        printf("Введите точность: ");
        scanf("%lf", &eps);

        printf("Введите число слагаемых: ");
        scanf("%d", &maxTerms);

        if (func == 1) {
            approx = calcCos(x, maxTerms, eps, &usedTerms);
            exact = cos(x);
        } else if (func == 2) {
            approx = calcExp(x, maxTerms, eps, &usedTerms);
            exact = exp(x);
        } else {
            approx = calcLn(x, maxTerms, eps, &usedTerms);
            exact = log(1 + x);
        }

        printf("\nЭталон: %.10f\n", exact);
        printf("Приближение: %.10f\n", approx);
        printf("Разница: %.10f\n", fabs(exact - approx));
        printf("Слагаемых использовано: %d\n", usedTerms);
    }

    else if (mode == 2) {
        int func, nMax;

        printf("Функция (1-cos, 2-exp, 3-ln): ");
        scanf("%d", &func);

        printf("Введите x: ");
        scanf("%lf", &x);

        printf("Введите NMax: ");
        scanf("%d", &nMax);

        double exact;
        if (func == 1) exact = cos(x);
        else if (func == 2) exact = exp(x);
        else exact = log(1 + x);

        printf("\nЭталон: %.10f\n", exact);
        printf("n | приближение | разница\n");

        for (int n = 1; n <= nMax; n++) {
            int used;
            double approx;

            if (func == 1)
                approx = calcCos(x, n, 0.0000000001, &used);
            else if (func == 2)
                approx = calcExp(x, n, 0.0000000001, &used);
            else
                approx = calcLn(x, n, 0.0000000001, &used);

            printf("%2d | %.10f | %.10f\n", n, approx, fabs(approx - exact));
        }
    }

    return 0;
}