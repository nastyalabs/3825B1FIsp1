#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int valid_guess(char s[], int n) {
    for (int i = 0; i < n; i++) {
        if (s[i] < '0' || s[i] > '9') return 0;
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) return 0;
        }
    }
    return 1;
}
void generate_number(char number[], int n) {
    int used[10] = { 0 };
    int i = 0;

    while (i < n) {
        int d = rand() % 10;
        if (!used[d]) {
            used[d] = 1;
            number[i] = '0' + d;
            i++;
        }
    }
}
int main() {
    setlocale(LC_ALL, "Russian");
    srand((unsigned)time(NULL));
    int n;
    printf("Введите длину числа (от 2 до 5): ");
    scanf_s("%d", &n);
    if (n < 2 || n > 5) {
        printf("Неверная длина.\n");
        return 0;
    }
    char secret[6];
    char guess[6];
    generate_number(secret, n);
    secret[n] = '\0';
    printf("Компьютер загадал %d-значное число с неповторяющимися цифрами.\n", n);
    while (1) {
        printf("Введите попытку: ");
        if (scanf_s("%5s", guess, (unsigned)sizeof(guess)) != 1) {
            printf("Ошибка ввода.\n");
            return 0;
        }
        int len = 0;
        while (guess[len] != '\0') len++;
        if (len != n || !valid_guess(guess, n)) {
            printf("Ошибка: нужно %d цифр без повторов.\n", n);
            continue;
        }
        int bulls = 0;
        int cows = 0;
        for (int i = 0; i < n; i++) {
            if (guess[i] == secret[i]) {
                bulls++;
            }
            else {
                for (int j = 0; j < n; j++) {
                    if (guess[i] == secret[j]) {
                        cows++;
                        break;
                    }
                }
            }
        }
        printf("Быков: %d, Коров: %d\n", bulls, cows);
        if (bulls == n) {
            printf("Ура!! Вы отгадали число: %s\n", secret);
            break;
        }
    }
    return 0;
}