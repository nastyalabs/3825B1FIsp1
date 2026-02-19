#include <stdio.h>
#include <stdlib.h>

int main() 
{
    int y1, y2;
    char X1, X2;
    char figure;

    // Ввод координат клеток и фигуры
    printf("Введите координаты первой клетки (например, A1): ");
    scanf(" %c%d", &X1, &y1);

    int x1 = (int)X1;

    // Проверка на верность координат для первой клетки
    if (((x1 > 72) || (x1 < 65)) || ((y1 > 8) || (y1 < 1))){
        printf("Введены неверные координаты для первой клетки");
        return 0;
    }

    printf("Введите координаты второй клетки (например, H8): ");
    scanf(" %c%d", &X2, &y2);

    int x2 = (int)X2;

    // Проверка на верность координат для второй клетки
    if (((x2 > 72) || (x2 < 65)) || ((y2 > 8) || (y2 < 1))){
        printf("Введены неверные координаты для второй клетки");
        return 0;
    }

    if (x1 == x2 && y1 == y2){
        printf("Клетки должны быть различны");
        return 0;
    }

    // Король - King, Ферзь - Queen, Ладья - Rook, Слон - Bishop, Конь - Horse
    printf("Введите фигуру (K - король, Q - ферзь, R - ладья, B - слон, H - конь): "); 
    scanf(" %c", &figure);

    int count = 0; // счётчик: 0 - выбранная фигура может перейти из K1 в K2; 1 - выбранная фигура не может перейти из K1 в K2
    // Проверка хода фигуры
    switch (figure) {
        case 'K': // Король
            if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1) {
                printf("Король может перейти из K1 в K2.\n");
            } else {
                printf("Король не может перейти из K1 в K2.\n");
                count++;
            }
            break;
        case 'Q': // Ферзь
            if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) {
                printf("Ферзь может перейти из K1 в K2.\n");
            } else {
                printf("Ферзь не может перейти из K1 в K2.\n");
                count++;
            }
            break;
        case 'R': // Ладья
            if (x1 == x2 || y1 == y2) {
                printf("Ладья может перейти из K1 в K2.\n");
            } else {
                printf("Ладья не может перейти из K1 в K2.\n");
                count++;
            }
            break;
        case 'B': // Слон
            if (abs(x1 - x2) == abs(y1 - y2)) {
                printf("Слон может перейти из K1 в K2.\n");
            } else {
                printf("Слон не может перейти из K1 в K2.\n");
                count++;
            }
            break;
        case 'H': // Конь
            if ((abs(x1 - x2) == 2 && abs(y1 - y2) == 1) || (abs(x1 - x2) == 1 && abs(y1 - y2) == 2)) {
                printf("Конь может перейти из K1 в K2.\n");
            } else {
                printf("Конь не может перейти из K1 в K2.\n");
                count++;
            }
            break;
        default:
            printf("Неверная фигура.\n");
    }


    int count_other = 0; // счётчик других фигур: 0 - ни одна фигура не может перейти из K1 в K2
    if (count == 1){
        printf("Проверим есть ли фигуры, которые могут перейти из K1 в K2: \n");
        switch ('K') {
        case 'K': // Король
            if (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1) {
                printf("Король\n");
                count_other++;
            } 
        case 'Q': // Ферзь
            if (x1 == x2 || y1 == y2 || abs(x1 - x2) == abs(y1 - y2)) {
                printf("Ферзь\n");
                count_other++;
            } 
        case 'R': // Ладья
            if (x1 == x2 || y1 == y2) {
                printf("Ладья\n");
                count_other++;
            } 
        case 'B': // Слон
            if (abs(x1 - x2) == abs(y1 - y2)) {
                printf("Слон\n");
                count_other++;
            } 
        case 'H': // Конь
            if ((abs(x1 - x2) == 2 && abs(y1 - y2) == 1) || (abs(x1 - x2) == 1 && abs(y1 - y2) == 2)) {
                printf("Конь\n");
                count_other++;
            }
        }
        if (count_other == 0)
            printf("К сожалению, таких фигур нет.\n");        
    }
    
    return 0;
}
