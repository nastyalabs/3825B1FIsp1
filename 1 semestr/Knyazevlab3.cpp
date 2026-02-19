#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <locale.h>
#include <stdlib.h>
int isUnique(int num, int length) {
    int digits[10] = { 0 };
    for (int i = 0; i < length; i++) {
        int digit = num % 10;
        if (digits[digit])
            return 0;
        digits[digit] = 1;
        num /= 10;
    }
    return 1;
}

int generateNumber(int length) {
    int min = 1;
    for (int i = 1; i < length; i++) min *= 10;

    int num;
    do {
        num = rand() % (min * 10 - min) + min;
    } while (!isUnique(num, length));
    return num;
}

int main() {
    srand(time(NULL));
    setlocale(LC_ALL, "Russian");
    int n;
    printf("Введите длину числа от 2 до 5: ");
    scanf_s("%d", &n);

    int secret = generateNumber(n);
    int attempts = 0;
    int guess;

    while (1) {
        attempts++;
        printf("Попытка %d: ", attempts);
        scanf_s("%d", &guess);

        int temp = guess, len = 0;
        while (temp > 0) {
            len++;
            temp /= 10;
        }

        if (len != n) {
            printf("Нужно %d-значное число\n\n", n);
            attempts--;
            continue;
        }


        if (!isUnique(guess, n)) {
            printf("Цифры не должны повторяться\n\n");
            attempts--;
            continue;
        }

        int s = secret, g = guess;
        int secret_digits[5], guess_digits[5];

        for (int i = n - 1; i >= 0; i--) {
            secret_digits[i] = s % 10;
            guess_digits[i] = g % 10;
            s /= 10;
            g /= 10;
        }

        printf("Ответ: ");
        int bulls = 0, cows = 0;

        for (int i = 0; i < n; i++) {
            if (secret_digits[i] == guess_digits[i]) {
                printf("[Б:%d] ", guess_digits[i]);
                bulls++;
            }
            else {
                int found = 0;
                for (int j = 0; j < n; j++) {
                    if (i != j && secret_digits[j] == guess_digits[i]) {
                        printf("[К:%d] ", guess_digits[i]);
                        cows++;
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf(" %d  ", guess_digits[i]);
                }
            }
        }

        printf(" Быки: %d, Коровы: %d\n\n", bulls, cows);

        if (bulls == n) {
            printf("Число %d угадано за %d попыток!\n", secret, attempts);
            break;
        }
    }

    return 0;
}