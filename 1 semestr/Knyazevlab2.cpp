#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <locale.h>

//void main() {
//	setlocale(LC_ALL, "Russian");
//	int gameMod, number, attemptsNum = 0; 
//  printf("Выберите режим игры: 1 - пк загадывает, 2 - вы загадываете ");
//	scanf_s("%d", &gameMod);		
//	srand(time(NULL));
//	if (gameMod == 1) {
//		int userTry = 0;
//
//		number = 1 + rand() % 1000;
//		while (userTry != number) {
//			printf("\nВведите ваше число: ");
//			scanf_s("%d", &userTry);
//			if (userTry < number) {
//				printf("Загаданное число больше\n");
//				attemptsNum++;
//			}
//			else if (userTry > number) {
//				printf("Загаданное число меньше\n");	
//				attemptsNum++;
//			}
//			else {
//				printf("Угадали, количество попыток: %d", attemptsNum + 1);
//			}
//		}
//	}
//	else if (gameMod == 2) {
//		int min = 1, max = 1000;
//		char pcTry = 0;
//		printf("\nЗагадайте число от 1 до 1000 \n");
//		while (pcTry != '=') {
//			number = min + rand() % (max - min + 1);
//			printf("\nПК думает, что это: %d\n", number);
//			printf("Ваше число: ");
//			scanf_s(" %c", &pcTry); 
//			if (pcTry == '<') {
//				max = number - 1;
//				attemptsNum++;
//			}
//			else if (pcTry == '>') {
//				min = number + 1;
//				attemptsNum++;
//			}
//			else if (pcTry == '=') {
//				printf("\nУгадали, количество попыток : % d", attemptsNum + 1);
//			}
//		}
//	}
//}




//int main() {
//    setlocale(LC_ALL, "Russian");
//    int ch;
//    int state = 0; 
//    int word_count = 0;
//    int number_count = 0;
//
//    printf("Введите текст:\n");
//
//    while ((ch = getchar()) != '\n' && ch != EOF) {
//        int is_alpha = (ch >= 'A' && ch <= 'Z') ||
//            (ch >= 'a' && ch <= 'z') ||
//            (ch >= 192 && ch <= 255); 
//
//        int is_digit = (ch >= '0' && ch <= '9');
//        int is_space = (ch == ' ' || ch == '\t');
//
//        if (is_alpha) {
//            if (state != 1) {
//                word_count++;
//                state = 1;
//            }
//        }
//        else if (is_digit) {
//            if (state != 2) {
//                number_count++;
//                state = 2;
//            }
//        }
//        else if (is_space) {
//            state = 0;
//        }
//        else {
//            state = 0;
//        }
//    }
//
//    printf("\nРезультат:\n");
//    printf("Количество слов: %d\n", word_count);
//    printf("Количество чисел: %d\n", number_count);
//
//    return 0;
//}