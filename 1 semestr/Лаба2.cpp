//#include <stdio.h>
//#include <stdlib.h>
//#include <time.h>
//#include <locale.h>
//void main() {
//	setlocale(LC_ALL, "Russian");
//	srand(time(NULL));
//	int rezhim;
//	printf("Выберите режим\n");
//	scanf_s("%d", &rezhim);
//	if (rezhim == 1) {
//		int x1, p1, k1 = 0;
//		x1 = 1 + rand() % (1000 - 1 + 1);
//		printf("Введите число от 1 до 1000\n");
//		while (k1 != (-1)) {
//			printf("Мой ответ : ");
//			scanf_s("%d", &p1);
//			if (x1 < p1) {
//				printf("Загаданное число меньше ");
//				printf("(%d)\n", x1);
//				k1++;
//			}
//			else if (x1 == p1) {
//				printf("Угадали! ");
//				printf("(%d)\n", x1);
//				k1++;
//				printf("Количество попыток : %d", k1);
//				k1 = -1;
//			}
//			else {
//				printf("Загаданное число больше ");
//				printf("(%d)\n", x1);
//				k1++;
//			}
//		}
//	}
//	else if (rezhim == 2) {
//		int x2, p2, k2 = 0;
//		x2 = 1 + rand() % (1000 - 1 + 1);
//		char z;
//		printf("Введите число от 1 до 1000\n");
//		printf("Загаданное число : ");
//		scanf_s("%d", &p2);
//		while (k2 != (-1)) {
//			printf("Ответ программы : %d\n", x2);
//			printf("Введите подсказку : ");
//			scanf_s(" %c", &z, 1);
//			if (z == '<') {
//				x2 = 1 + rand() % (x2 - 1);
//				k2++;
//			}
//			else if (z == '>') {
//				x2 = x2 + rand() % (1000 - 1);
//				k2++;
//			}
//			else if (z == '=') {
//				printf("Программа угадала число\n");
//				k2++;
//				printf("Количество попыток : %d", k2);
//				k2 = -1;
//			}
//			else printf("Некорректный знак\n");
//		}
//	}
//}
#include <stdio.h>
#include <locale.h>
#define True 1
#define False 0
void main() {
    setlocale(LC_ALL, "Russian");
    int c, words = 0, numbers = 0;;
    int is_num = False, is_word = False, last, flag_num = True, flag_word = True;
    while ((c = getchar()) != '\n' && c != EOF) {
        if (c >= '0' && c <= '9') {
            is_num = True;
            is_word = False;
            last = c;
            flag_word = False;
        }
        else if (c != '\t' && c != ' ') {
            is_num = False;
            is_word = True;
            last = c;
            flag_num = False;
        }
        else {
            if (is_num && flag_num) {
                numbers++;
            }
            else if (is_word && flag_word) {
                words++;
            }
            flag_num = True;
            flag_word = True;
        }
    }
    if (c != ' ' && c != '\t') {
        if (last >= '0' && last <= '9' && flag_num) {
            numbers++;
        }
        else if (flag_word) {
            words++;
        }
    }
    printf("Количество слов: %d\n", words);
    printf("Количество чисел: %d\n", numbers);
}