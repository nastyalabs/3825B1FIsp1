#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int randomNumber = rand() % 1000;
    printf("%d\n", randomNumber);// для удобства проверки
    int num;
    printf("Компьютер загадал число попробуй угадай\n");
    do {
        scanf("%d", &num);
        if (num < 1 || num > 1000) {
            printf("Вы вышли за предел от 1 до 1000, введите снова\n");
            continue;
        }
        if (num == randomNumber) {
            printf("Ты угадал");
        } else if (num > randomNumber) {
            printf("Число меньше\n");
        } else if (num < randomNumber) {
            printf("Число больше\n");
        }

    } while (num != randomNumber || num < 1 || num > 1000);

}


