#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>
	
void bubble(char **data, int k, int j) { //пузырькувая сортировка

	for (int i = 0; i < k - 1; i++) {
		for (int p = 0; p < k - i - 1; p++) {
			if (strcmp(data[p], data[p + 1]) * j > 0) {
				char* a = data[p];
				data[p] = data[p + 1];
				data[p + 1] = a;
			}
		}
	}

	for (int i = 0; i < k; i++) {
		printf("%s ", data[i]);
	}
	printf("\n");
}


void insertion(char** data, int k, int j, int a) { //сортировка вставками
	char* key = malloc(a * sizeof(char));
	for (int i = 1; i < k; i++) {
		strncpy_s(key, a, data[i], a);
		int c = i - 1;

		while (c >= 0 && strcmp(data[c], key) * j > 0) {
			strncpy_s(data[c + 1], a, data[c], a);
			c--;
		}
		strncpy_s(data[c + 1], a, key, a);
	}
	for (int i = 0; i < k; i++)
		printf("%s ", data[i]);
	printf("\n");
	free(key);
}



int main() {
	setlocale(LC_ALL, "Rus");
	int k, replay=1;
	clock_t start, end;
	do {                                                           //количество массивов с проверкой
		printf("Введите количество массивов для сортировки.\n"); 
		scanf_s("%d", &k);
		if(k <= 0)
			printf("Введите значение больше 0.\n");
	} while (k <= 0);

	char** data = malloc(k * sizeof(char*));
	int a, mode, alph;

	do {                                                            //максимальная возможная длинна массива с проверкой
		printf("Введите максимально возможный размер массива.\n");
		scanf_s("%d", &a);
		if (a <= 0)
			printf("Введите значение больше 0.\n");
	} while (a <= 0);
	a++;
	
	int c;                                      // убирание \n
	while ((c = getchar()) != '\n' && c != EOF);

	printf("Введите массивы\n");
	for (int i = 0; i < k; i++) {
		data[i] = calloc(a, sizeof(char));
		gets_s(data[i], a);
	}

	printf("Ваши массивы:\n");

	for (int i = 0; i < k; i++) {
		printf("%s ", data[i]);
	}
	printf("\n\n");

	do {
	printf("Выберите метод сортировки: 1-пузырьковая 2-вставками\n");
	scanf_s("%d", &mode);
	printf("Выберите сортировку: 1)A-Z 2)Z-A\n");
	scanf_s("%d", &alph);
	int j = (alph == 1) ? 1 : -1;

		start = clock();
		switch (mode) {
		case 1: bubble(data, k, j); break;
		case 2: insertion(data, k, j, a); break;
		default: printf("Введите предложенный метод");
		}
		end = clock();
		double s_t = ((double)(end - start)) / CLOCKS_PER_SEC;
		printf("Время выполнения: %.6f секунд\nХотите выбрать другой метод сортировки? 0-НЕТ 1-ДА\n", s_t);
		scanf_s("%d", &replay);
	} while (replay != 0);


	for (int i = 0; i < k; i++)
		free(data[i]);
	free(data);
	return 0;
}
