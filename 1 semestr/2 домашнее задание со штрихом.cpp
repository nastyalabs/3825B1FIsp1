#include <stdio.h>
#include <locale.h>
#include <ctype.h>
int main() {
    setlocale(LC_ALL, "Russian");
    char line[256];
    printf("Введите строку:\n");
    if (scanf_s("%255[^\n]", line, (unsigned)sizeof(line)) != 1) {
        printf("Ошибка ввода.\n");
        return 0;
    }
    int words = 0;
    int numbers = 0;
    int i = 0;
    int state = 0; 
    while (line[i] != '\0') {
        char c = line[i];
        int is_russian =((unsigned char)c >= 192 && (unsigned char)c <= 255) || ((unsigned char)c == 168) || ((unsigned char)c == 184); 
        if (isalpha((unsigned char)c) || is_russian) {
            if (state != 1) {
                words++;
                state = 1;
            }
        }
        else if (isdigit((unsigned char)c)) {
            if (state != 2) {
                numbers++;
                state = 2;
            }
        }
        else {
            state = 0;
        }

        i++;
    }
    printf("Количество слов: %d\n", words);
    printf("Количество чисел: %d\n", numbers);
    return 0;
}
