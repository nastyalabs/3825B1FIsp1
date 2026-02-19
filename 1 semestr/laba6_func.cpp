#include <stdio.h>
#include <math.h>
#include <locale.h>


long double vychislit_ryad(int tip_f, double x_val, int limit_n, double eps) {
    long double summa = 0, slagaemoe = 0;

    if (tip_f == 1) { // Косинус
        slagaemoe = 1.0;
        summa = slagaemoe;
        for (int i = 1; i < limit_n; i++) {
            slagaemoe *= -x_val * x_val / ((2 * i - 1) * (2 * i));
            summa += slagaemoe;
            if (fabsl(slagaemoe) < eps) break;
        }
    }
    else if (tip_f == 2) { // Синус
        slagaemoe = x_val;
        summa = slagaemoe;
        for (int i = 1; i < limit_n; i++) {
            slagaemoe *= -x_val * x_val / ((2 * i) * (2 * i + 1));
            summa += slagaemoe;
            if (fabsl(slagaemoe) < eps) break;
        }
    }
    else if (tip_f == 3) { // Экспонента
        slagaemoe = 1.0;
        summa = slagaemoe;
        for (int i = 1; i < limit_n; i++) {
            slagaemoe *= x_val / i;
            summa += slagaemoe;
            if (fabsl(slagaemoe) < eps) break;
        }
    }
    return summa;
}


int naiti_kolichestvo_shagov(int tip_f, double x_val, int limit_n, double eps) {
    long double slagaemoe = 0;
    int schetchik = 1;

    if (tip_f == 1) {
        slagaemoe = 1.0;
        for (int i = 1; i < limit_n; i++) {
            slagaemoe *= -x_val * x_val / ((2 * i - 1) * (2 * i));
            schetchik++;
            if (fabsl(slagaemoe) < eps) break;
        }
    }
    else if (tip_f == 2) {
        slagaemoe = x_val;
        for (int i = 1; i < limit_n; i++) {
            slagaemoe *= -x_val * x_val / ((2 * i) * (2 * i + 1));
            schetchik++;
            if (fabsl(slagaemoe) < eps) break;
        }
    }
    else if (tip_f == 3) {
        slagaemoe = 1.0;
        for (int i = 1; i < limit_n; i++) {
            slagaemoe *= x_val / i;
            schetchik++;
            if (fabsl(slagaemoe) < eps) break;
        }
    }
    return schetchik;
}

int main() {
    int rezhim_raboty, vybor_funkcii, max_n, shagi;
    double argument_x, tochnost, etalon;
    long double rezultat_ryada;

    setlocale(LC_ALL, "Russian");

    while (1) {
        printf("\nВыберите режим работы [1 - Одиночный, 2 - Серия, 0 - Выход]: ");
        if (scanf_s("%d", &rezhim_raboty) != 1 || rezhim_raboty == 0) break;

        printf("Выберите функцию (1 - cos, 2 - sin, 3 - exp): ");
        scanf_s("%d", &vybor_funkcii);

        if (rezhim_raboty == 1) {
            printf("Введите аргумент x, точность и предел слагаемых: ");
            scanf_s("%lf %lf %d", &argument_x, &tochnost, &max_n);

            rezultat_ryada = vychislit_ryad(vybor_funkcii, argument_x, max_n, tochnost);
            shagi = naiti_kolichestvo_shagov(vybor_funkcii, argument_x, max_n, tochnost);

            if (vybor_funkcii == 1) etalon = cos(argument_x);
            else if (vybor_funkcii == 2) etalon = sin(argument_x);
            else etalon = exp(argument_x);

            printf("\n--- Результаты вычислений ---");
            printf("\nЭталонное значение: %.10f", etalon);
            printf("\nПолученная сумма:   %.10Lf", rezultat_ryada);
            printf("\nПогрешность:        %.10f", fabs((double)rezultat_ryada - etalon));
            printf("\nИспользовано шагов: %d\n", shagi);
        }
        else if (rezhim_raboty == 2) {
            printf("Введите аргумент x и NMax (макс. номер слагаемого): ");
            scanf_s("%lf %d", &argument_x, &max_n);

            if (vybor_funkcii == 1) etalon = cos(argument_x);
            else if (vybor_funkcii == 2) etalon = sin(argument_x);
            else etalon = exp(argument_x);

            printf("\nЭталон: %.10f\n", etalon);
            printf("%-4s | %-15s | %-15s\n", "N", "Результат", "Ошибка");
            for (int i = 1; i <= max_n; i++) {
                rezultat_ryada = vychislit_ryad(vybor_funkcii, argument_x, i, 0);
                printf("%-4d | %.10Lf | %.10f\n", i, rezultat_ryada, fabs((double)rezultat_ryada - etalon));
            }
        }
    }

    return 0;
}
