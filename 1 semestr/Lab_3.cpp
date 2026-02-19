#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main() {
    int n; 
    int i, j, k; 
    int comp_number; 
    int my_number; 
    int bulls, cows; 
    int attempts = 0; 
    setlocale(LC_CTYPE, "rus");
    printf("\n=== Игра 'Быки и коровы' ===\n");
    // Ввод длины числа
    printf("Введите длину числа (2-5): ");
    scanf_s("%d", &n);
    while (n < 2 || n > 5) {
        printf("Ошибка! Введите от 2 до 5: ");
        scanf_s("%d", &n);
    }
    // Генерация случайного числа компьютера
    srand(time(NULL));
    // Создаем массив для цифр компьютера
    int comp_digits[5];
    // Заполняем массив уникальными цифрами
    for (i = 0; i < n; i++) {
        int new_digit;
        int unique;
        do {
            unique = 1; // предполагаем, что цифра уникальна
            // Генерируем цифру от 0 до 9
            // Первая цифра не может быть 0
            if (i == 0) {
                new_digit = rand() % 9 + 1; 
            }
            else {
                new_digit = rand() % 10; 
            }
            
            for (j = 0; j < i; j++) {
                if (comp_digits[j] == new_digit) {
                    unique = 0; 
                    break;
                }
            }
        } while (unique == 0);
        comp_digits[i] = new_digit;
    }
    // Собираем число из цифр
    comp_number = 0;
    for (i = 0; i < n; i++) {
        comp_number = comp_number * 10 + comp_digits[i];
    }
    printf("\nКомпьютер загадал %d-значное число. Попробуйте угадать!\n\n", n);
    // Основной игровой цикл
    do {
        attempts++;
        printf("Попытка %d: ", attempts);
        scanf_s("%d", &my_number);
        // Проверяем, что число правильной длины
        int temp = my_number;
        int count_digits = 0;
        while (temp > 0) {
            temp = temp / 10;
            count_digits++;
        }

        if (count_digits != n) {
            printf("Ошибка! Введите %d-значное число!\n", n);
            attempts--; 
            continue;
        }
        // Разбиваем число игрока на цифры
        int my_digits[5];
        temp = my_number;
        for (i = n - 1; i >= 0; i--) {
            my_digits[i] = temp % 10;
            temp = temp / 10;
        }
        // Проверяем на повторяющиеся цифры
        int repeat = 0;
        for (i = 0; i < n; i++) {
            for (j = i + 1; j < n; j++) {
                if (my_digits[i] == my_digits[j]) {
                    repeat = 1;
                    break;
                }
            }
            if (repeat == 1) break;
        }
        if (repeat == 1) {
            printf("Ошибка! Цифры не должны повторяться!\n");
            attempts--; // не считаем эту попытку
            continue;
        }
        // Подсчет быков и коров
        bulls = 0;
        cows = 0;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                if (my_digits[i] == comp_digits[j]) {
                    if (i == j) {
                        bulls++; 
                    }
                    else {
                        cows++; 
                    }
                }
            }
        }
        printf("Результат: %d быков, %d коров\n\n", bulls, cows);
    } while (bulls != n); 
    printf("Ура! Вы угадали число %d за %d попыток!\n", comp_number, attempts);
    return 0;
}