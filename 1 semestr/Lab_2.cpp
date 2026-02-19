#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
int main() {
	setlocale(LC_CTYPE, "rus");
	int mode;
	printf("Режим 1 - я угадываю\nРежим 2 - компьютер угадывает\nВыбор: ");
	scanf_s("%d", &mode);
	if (mode == 1) {
		srand(time(NULL));
		int number = rand() % 1000 + 1;
		int guess, attempts = 0;
		while (1) {
			printf("Введите число: ");
			scanf_s("%d", &guess);
			attempts++;
			if (guess < number) {
				printf("Больше\n");
			}
			else if (guess > number) {
				printf("Меньше\n");
			}
			else {
				printf("Угадали! Попыток: %d\n", attempts);
				break;
			}
		}
	}
	else if (mode == 2) {
		int min = 1, max = 1000, attempts = 0;
		char answer;
		while (min <= max) {
			int guess = (min + max) / 2;
			attempts++;
			printf("Моя догадка: %d\nВаш ответ (> < =): ", guess);
			scanf_s(" %c", &answer);
			if (answer == '>') min = guess + 1;
			else if (answer == '<') max = guess - 1;
			else if (answer == '=') {
				printf("Угадал! Попыток: %d\n", attempts);
				break;
			}
		}
	}
	return 0;
}