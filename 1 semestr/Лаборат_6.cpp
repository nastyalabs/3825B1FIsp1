#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

#define PI 3.14159265358979323846 // число пи

typedef double (*RaschetTaylor)(double arg, double tochn, int max_slag, int* ispolz_slag);     // тип указателя на функцию для расчета по ряду Тейлора

typedef double (*EtalonRaschet)(double);         // тип указателя на эталонную функцию

typedef struct {                 // хранения информации о функции
    const char* imya_func;
    RaschetTaylor func_taylor;
    EtalonRaschet func_etalon;
} InfoFunc;

double raschet_sin_t(double arg, double tochn, int max_slag, int* ispolz_slag);
double raschet_cos_t(double arg, double tochn, int max_slag, int* ispolz_slag);
double raschet_exp_t(double arg, double tochn, int max_slag, int* ispolz_slag);
double raschet_ctg_t(double arg, double tochn, int max_slag, int* ispolz_slag);

double etalon_sin(double arg) { return sin(arg); }
double etalon_cos(double arg) { return cos(arg); }
double etalon_exp(double arg) { return exp(arg); }
double etalon_ctg(double arg) {
    double sin_val = sin(arg);
    if (fabs(sin_val) < 1e-10) return NAN;     // обработка деления на ноль
    return cos(arg) / sin_val;
}

InfoFunc spisok_func[] = {
    {"sin(x)", raschet_sin_t, etalon_sin},
    {"cos(x)", raschet_cos_t, etalon_cos},
    {"exp(x)", raschet_exp_t, etalon_exp},
    {"ctg(x)", raschet_ctg_t, etalon_ctg}
};

const int KOL_FUNC = sizeof(spisok_func) / sizeof(InfoFunc);       // количество функций

void vyvod_menu_func() {              // вывода меню выбора функции
    printf("Выберите функцию для расчета:\n");
    for (int i = 0; i < KOL_FUNC; i++) {
        printf("%d - %s\n", i + 1, spisok_func[i].imya_func);
    }
}

void rezhim_odnokrat() {             // режима однократного расчета
    int vybor_func;
    double arg_x, tochnost_eps;
    int max_N, ispolz_slag = 0;

    vyvod_menu_func();
    printf("Ваш выбор: ");
    scanf_s("%d", &vybor_func);
    vybor_func--;

    if (vybor_func < 0 || vybor_func >= KOL_FUNC) {
        printf("Ошибка: неверный выбор функции!\n");
        return;
    }

    printf("Введите значение x: ");
    scanf_s("%lf", &arg_x);

    printf("Введите точность (от 0.000001 и больше): ");
    scanf_s("%lf", &tochnost_eps);
    if (tochnost_eps < 0.000001) {
        printf("Ошибка: точность должна быть не меньше 0.000001!\n");
        return;
    }

    printf("Введите максимальное число слагаемых (1-1000): ");
    scanf_s("%d", &max_N);
    if (max_N < 1 || max_N > 1000) {
        printf("Ошибка: число слагаемых должно быть от 1 до 1000!\n");
        return;
    }

    double znach_taylor = spisok_func[vybor_func].func_taylor(arg_x, tochnost_eps, max_N, &ispolz_slag);                // расчет по Тейлору
    double znach_etalon = spisok_func[vybor_func].func_etalon(arg_x);           // эталонное значение

    if (isnan(znach_taylor)) {
        printf("Ошибка: значение не может быть вычислено (деление на ноль или подобное)!\n");
        return;
    }

    double raznitsa = fabs(znach_taylor - znach_etalon);

    printf("\nРезультаты расчета:\n");
    printf("Эталонное значение: %.15lf\n", znach_etalon);
    printf("Оценка по Тейлору: %.15lf\n", znach_taylor);
    printf("Разница: %.15lf\n", raznitsa);
    printf("Использовано слагаемых: %d\n", ispolz_slag);
}

void rezhim_seriyn() {                // режим серийного эксперимента
    int vybor_func, max_exp;
    double arg_x;

    vyvod_menu_func();
    printf("Ваш выбор: ");
    scanf_s("%d", &vybor_func);
    vybor_func--;

    if (vybor_func < 0 || vybor_func >= KOL_FUNC) {
        printf("Ошибка: неверный выбор функции!\n");
        return;
    }

    printf("Введите значение x: ");
    scanf_s("%lf", &arg_x);

    printf("Введите число экспериментов (1-25): ");
    scanf_s("%d", &max_exp);
    if (max_exp < 1 || max_exp > 25) {
        printf("Ошибка: число экспериментов должно быть от 1 до 25!\n");
        return;
    }

    double znach_etalon = spisok_func[vybor_func].func_etalon(arg_x);
    printf("\nЭталонное значение: %.15lf\n", znach_etalon);
    printf("\nТаблица результатов:\n");
    printf("Кол-во слаг. | Оценка по Тейлору      | Разница\n");
    printf("---------------------------------------------\n");

    for (int n = 1; n <= max_exp; n++) {
        int ispolz_slag = 0;
        double znach_taylor = spisok_func[vybor_func].func_taylor(arg_x, 0.0, n, &ispolz_slag);       // для серийного используем минимальную точность, чтобы использовать ровно n слагаемых
        if (isnan(znach_taylor)) {
            printf("%12d | %-22s | %-22s\n", n, "Ошибка", "Ошибка");
            continue;
        }
        double raznitsa = fabs(znach_taylor - znach_etalon);
        printf("%12d | %-22.15lf | %-22.15lf\n", n, znach_taylor, raznitsa);
    }
}

double raschet_sin_t(double arg, double tochn, int max_slag, int* ispolz_slag) {          // sin(x) по Тейлору
    arg = fmod(arg, 2 * PI);
    double summa = arg;
    double chlen = arg;
    int k = 1;
    *ispolz_slag = 1;

    while (k < max_slag && fabs(chlen) > tochn) {
        chlen = -chlen * arg * arg / ((2.0 * k) * (2.0 * k + 1.0));
        summa += chlen;
        k++;
        (*ispolz_slag)++;
    }
    return summa;
}

double raschet_cos_t(double arg, double tochn, int max_slag, int* ispolz_slag) {      // cos(x) по Тейлору
    arg = fmod(arg, 2 * PI);
    double summa = 1.0;
    double chlen = 1.0;
    int k = 1;
    *ispolz_slag = 1;

    while (k < max_slag && fabs(chlen) > tochn) {
        chlen = -chlen * arg * arg / ((2.0 * k - 1.0) * (2.0 * k));
        summa += chlen;
        k++;
        (*ispolz_slag)++;
    }
    return summa;
}

double raschet_exp_t(double arg, double tochn, int max_slag, int* ispolz_slag) {     //exp(x) по Тейлору
    double summa = 1.0;
    double chlen = 1.0;
    int k = 1;
    *ispolz_slag = 1;

    while (k < max_slag && fabs(chlen) > tochn) {
        chlen *= arg / (double)k;
        summa += chlen;
        k++;
        (*ispolz_slag)++;
    }
    return summa;
}

double raschet_ctg_t(double arg, double tochn, int max_slag, int* ispolz_slag) {         // ctg(x) как cos(x)/sin(x) с использованием их рядов
    int slag_sin, slag_cos;
    double val_sin = raschet_sin_t(arg, tochn, max_slag, &slag_sin);
    double val_cos = raschet_cos_t(arg, tochn, max_slag, &slag_cos);

    *ispolz_slag = (slag_sin > slag_cos) ? slag_sin : slag_cos;

    if (fabs(val_sin) < 1e-10) return NAN;
    return val_cos / val_sin;
}


int main() {
    setlocale(LC_ALL, "Russian");
    int rezhim_raboty;

    while (1) {
        printf("\nВыберите режим работы программы:\n");
        printf("1 - Однократный расчет\n");
        printf("2 - Серийный эксперимент\n");
        printf("0 - Выход\n");
        printf("Ваш выбор: ");
        scanf_s("%d", &rezhim_raboty);

        if (rezhim_raboty == 0) {
            printf("Программа завершена.\n");
            break;
        }
        else if (rezhim_raboty == 1) {
            rezhim_odnokrat();
        }
        else if (rezhim_raboty == 2) {
            rezhim_seriyn();
        }
        else {
            printf("Ошибка: неверный режим!\n");
        }
    }

    return 0;
}