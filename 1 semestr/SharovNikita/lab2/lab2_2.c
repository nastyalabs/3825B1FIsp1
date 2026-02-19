#include<stdio.h>
#include <stdlib.h>
#include <time.h>

void main() {
    int l = 1, h = 1000;
    int num, attempts = 0;
    char sign;
    srand(time(NULL));
    while (1) {
        attempts++;
        num = rand() % (h - l + 1) + l;
        printf("%d\n", num);

        do {
            scanf(" %c", &sign);
            if (sign != '<' && sign != '>' && sign != '=') {
                printf("Eror: знак должен быть только <, >, =");

            }
        }while (sign != '<' && sign != '>' && sign != '=');
        switch (sign) {
            case '<': {
                if (num <= 1) {
                    printf("EROR: загаданное заначение должно быть от 1 до 1000");
                    return;
                }
                h = num - 1;
                break;
            }
            case '>':
                if (num >= 1000) {
                    printf("EROR: загаданное заначение должно быть от 1 до 1000");
                    return;
                }
                l = num + 1; break;
            case '=': printf("Угадал: %d, попыток: %d", num, attempts); return;
            default: break;
        }

    }


}
