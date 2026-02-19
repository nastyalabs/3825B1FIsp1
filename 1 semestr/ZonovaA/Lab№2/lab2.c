#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<locale.h>
#include<ctype.h>



//Задача 1. Угадай число, два режима, пользователь угадывает, компьютер угадывает, подсчитывая число попыток
//для начала надо предлагать режим работы, выбором 1 или 2, если введено что-то другое просить ввести заново автоматически
/*
void main() {
	int r;
	srand(time(0));
	printf("Hi. Select the mode: 1.Find number 2.Guess number (1 or 2):\n");
	scanf("%d", &r);

	while (r != 1 && r != 2) {   //проверка на ввод
		printf("Error, try again!\n");
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		printf("Select the mode: 1.Find number 2.Guess number (1 or 2):\n");
		scanf("%d", &r);
	}

	if (r == 1) {   //первый режим
		int n = 0, num, cnt = 0;
		num = 1 + rand() % 1000;
		printf("I made up number, try to guess! Input integer number(1,1000).\n");
		do {
			cnt++;
			printf("Input integer number(1,1000):\n");
			scanf("%d", &n);
			while (n < 1 || n > 1000) {   //проверка на ввод
				printf("Error, try again!\n");
				int c;
				while ((c = getchar()) != '\n' && c != EOF);
				printf("Input number(1,1000):\n");
				scanf("%d", &n);
			}
			if (n < num) {    //угадываем число
				printf("The hidden number is bigger!\n");
			}
			if (n > num) {
				printf("The hidden number is less!\n");
			}
		} while (n != num);

		printf("Great. You guessed my number, cnt = %d!", cnt);
	}

	if (r == 2) { //второй режим
		int n = 500, cnt = 1;
		int oper;

		printf("Guess the number(1,1000), I will try to guess!\n");
		printf("Your number %d? (1.yes or 2.no)\n", n);
		scanf("%d", &oper);
		while (oper != 1 && oper != 2) {
			printf("Error, try again\n");
			int c;
			while ((c = getchar()) != '\n' && c != EOF) {};
			printf("Your number %d? (1.yes or 2.no)\n", n);
			scanf("%d", &oper);
		}

		if (oper == 1) {
			printf("I guessed right, cnt = 1!\n");
		}
		else {
			int oper2, left = 1, right = 1000;
			do {
				n = left + (right - left) / 2;
				cnt++;
				printf("Tell me, your number bigger or less %d or I guessed? (1.'>' or 2.'<' or 3.'='):\n", n);
				scanf("%d", &oper2);
				while (oper2 != 1 && oper2 != 2 && oper2 != 3) {   //проверка на ввод
					printf("Error, try again!\n");
					int c;
					while ((c = getchar()) != '\n' && c != EOF);
					printf("Tell me, your number bigger or less %d or I guessed? (1.'>' or 2.'<' or 3.'='):\n", n);
					scanf("%d", &oper2);
				}
				if (oper2 == 1) {
					left = n + 1;
				}
				if (oper2 == 2) {
					right = n - 1;
				}
			} while (oper2 != 3);
			printf("Great, your number = %d, cnt = %d!", n, cnt);
		}

	}
}*/

