#include <stdio.h>
#include <locale.h>
#define N 100


const int prices[] = { 50, 200, 100, 100, 200, 120, 30, 70, 120 };


int sum = 0;
int counts[9] = { 0 };


void Tovar(int n) {
    switch (n) {
    case 1111: printf("Хлеб\t\t%d руб.\n", prices[0]); break;
    case 2222: printf("Колбаса\t\t%d руб.\n", prices[1]); break;
    case 3333: printf("Молоко\t\t%d руб.\n", prices[2]); break;
    case 4444: printf("Шоколад\t\t%d руб.\n", prices[3]); break;
    case 5555: printf("Пельмени\t%d руб.\n", prices[4]); break;
    case 6666: printf("Творог\t\t%d руб.\n", prices[5]); break;
    case 7777: printf("Вода\t\t%d руб.\n", prices[6]); break;
    case 8888: printf("Печенье\t\t%d руб.\n", prices[7]); break;
    case 9999: printf("Сыр\t\t%d руб.\n", prices[8]); break;
    default: printf("Неверный код \n");
    }
}

void cena(int n) {
    switch (n) {
    case 1111: sum += prices[0]; counts[0]++; break;
    case 2222: sum += prices[1]; counts[1]++; break;
    case 3333: sum += prices[2]; counts[2]++; break;
    case 4444: sum += prices[3]; counts[3]++; break;
    case 5555: sum += prices[4]; counts[4]++; break;
    case 6666: sum += prices[5]; counts[5]++; break;
    case 7777: sum += prices[6]; counts[6]++; break;
    case 8888: sum += prices[7]; counts[7]++; break;
    case 9999: sum += prices[8]; counts[8]++; break;
    }
}

int main() {
    setlocale(LC_ALL, "rus");
    printf("Введите код товара, чтобы закончить нажмите 0\n\n");
    int n = 1;
    int arr[N];
    int i = 0;

    while ((n != 0)) {
        scanf_s("%d", &n);
        if (n != 0) {
            arr[i++] = n;
            Tovar(n);
            cena(n);
        }
    }
    printf("Ваш чек:\n");
    for (int k = 0; k < 9; k++) {
        if (counts[k] > 0) {
            switch (k) {
            case 0: printf("Хлеб x %d шт., общая стоимость: %d руб.\n", counts[k], counts[k] * prices[k]); break;
            case 1: printf("Колбаса x %d шт., общая стоимость: %d руб.\n", counts[k], counts[k] * prices[k]); break;
            case 2: printf("Молоко x %d шт., общая стоимость: %d руб.\n", counts[k], counts[k] * prices[k]); break;
            case 3: printf("Шоколад x %d шт., общая стоимость: %d руб.\n", counts[k], counts[k] * prices[k]); break;
            case 4: printf("Пельмени x %d шт., общая стоимость: %d руб.\n", counts[k], counts[k] * prices[k]); break;
            case 5: printf("Творог x %d шт., общая стоимость: %d руб.\n", counts[k], counts[k] * prices[k]); break;
            case 6: printf("Вода x %d шт., общая стоимость: %d руб.\n", counts[k], counts[k] * prices[k]); break;
            case 7: printf("Печенье x %d шт., общая стоимость: %d руб.\n", counts[k], counts[k] * prices[k]); break;
            case 8: printf("Сыр x %d шт., общая стоимость: %d руб.\n", counts[k], counts[k] * prices[k]); break;
            }
        }
    }
    printf("Итого: %d руб.\n", sum);
    return 0;
}