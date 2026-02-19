#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <stdlib.h>
void main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL)); // для новой генерации при каждом запуске программы
	int n, k = 0, nepov = 0, p, korova = 0, bik = 0;
	printf("Выберите длину загаданного числа\n");
	scanf_s("%d", &n);
	if (n == 2) {
		#define N 2
		int kom[N] = { 1 + rand() % (9 - 1 + 1), 0 + rand() % (9 - 0 + 1) }; // компьютер генерирует массив из 2-х случайных элементов
		//for (int i = 0; i < N; i++)
		//	printf("%d", kom[i]); // вывожу массив, загаданный компьютером, чтобы проверить точность кода
		for (int i = 0; i < N; i++)
			for (int i1 = i + 1; i1 < N; i1++)
				if (kom[i] == kom[i1])
					k++; // проверка на повторяющиеся цифры в загаданном числе
		if (k == 0) {
			while (bik != N) {
				korova = 0; // обнуляем значения количества быков и коров перед началом нового цикла
				bik = 0;
				printf("\nВведите число длиной %d\n", N);
				scanf_s("%d", &p);
				int pol[N] = { p / 10, p % 10 }; // превожу ответ игрока в массив, чтобы сравнить с загаданным числом
				for (int i = 0; i < N; i++)
					for (int p1 = 0; p1 < N; p1++)
						if ((i != p1) && (kom[i] == pol[p1])) // равны значения, но не позиции
							korova++;
						else if ((i == p1) && (kom[i] == pol[p1])) // равны значения и позиции
							bik++;
				printf("коровы: %d , быки: %d\n", korova, bik);
			}
			printf("Вы отгадали число!");
		}
		else printf("\nКомпьютер загадал число с повторяющимися цифрами. Попробуйте снова");
	} 
	else if (n == 3) { // то же самое для других возможных длин числа
		#define N 3
		int kom[N] = { 1 + rand() % (9 - 1 + 1), 0 + rand() % (9 - 0 + 1), 0 + rand() % (9 - 0 + 1) };
		/*for (int i = 0; i < N; i++)
			printf("%d", kom[i]);*/
		for (int i = 0; i < N; i++)
			for (int i1 = i + 1; i1 < N; i1++)
				if (kom[i] == kom[i1])
					k++;
		if (k == 0) {
			while (bik != N) {
				korova = 0;
				bik = 0;
				printf("\nВведите число длиной %d\n", N);
				scanf_s("%d", &p);
				int pol[N] = { p / 100, (p / 10) % 10, p % 10};
				for (int i = 0; i < N; i++)
					for (int p1 = 0; p1 < N; p1++)
						if ((i != p1) && (kom[i] == pol[p1]))
							korova++;
						else if ((i == p1) && (kom[i] == pol[p1]))
							bik++;
				printf("коровы: %d , быки: %d\n", korova, bik);
			}
			printf("Вы отгадали число!");
		}
		else printf("\nКомпьютер загадал число с повторяющимися цифрами. Попробуйте снова");
	}
	else if (n == 4) {
		#define N 4
		int kom[N] = { 1 + rand() % (9 - 1 + 1), 0 + rand() % (9 - 0 + 1), 0 + rand() % (9 - 0 + 1), 0 + rand() % (9 - 0 + 1) };
		/*for (int i = 0; i < N; i++)
			printf("%d", kom[i]);*/
		for (int i = 0; i < N; i++)
			for (int i1 = i + 1; i1 < N; i1++)
				if (kom[i] == kom[i1])
					k++;
		if (k==0) {
			while (bik != N) {
				korova = 0;
				bik = 0;
				printf("\nВведите число длиной %d\n", N);
				scanf_s("%d", &p);
				int pol[N] = { p / 1000, (p % 1000) / 100, (p % 100) / 10, p % 10 };
				for (int i = 0; i < N; i++)
					for (int p1 = 0; p1 < N; p1++)
						if ((i != p1) && (kom[i] == pol[p1]))
							korova++;
						else if ((i == p1) && (kom[i] == pol[p1]))
							bik++;
				printf("коровы: %d , быки: %d\n", korova, bik);
			}
			printf("Вы отгадали число!");
		}
		else printf("\nКомпьютер загадал число с повторяющимися цифрами. Попробуйте снова");
	}
	else if (n == 5) {
		#define N 5
		int kom[N] = { 1 + rand() % (9 - 1 + 1), 0 + rand() % (9 - 0 + 1), 0 + rand() % (9 - 0 + 1), 0 + rand() % (9 - 0 + 1), 0 + rand() % (9 - 0 + 1) };
		/*for (int i = 0; i < N; i++)
			printf("%d", kom[i]);*/
		for (int i = 0; i < N; i++)
			for (int i1 = i + 1; i1 < N; i1++)
				if (kom[i] == kom[i1])
					k++;
		if (k==0) {
			while (bik != N) {
				korova = 0;
				bik = 0;
				printf("\nВведите число длиной %d\n", N);
				scanf_s("%d", &p);
				int pol[N] = { p / 10000, (p / 1000) % 10, (p / 100) % 10, (p % 100) / 10, p % 10};
				for (int i = 0; i < N; i++)
					for (int p1 = 0; p1 < N; p1++)
						if ((i != p1) && (kom[i] == pol[p1]))
							korova++;
						else if ((i == p1) && (kom[i] == pol[p1]))
							bik++;
				printf("коровы: %d , быки: %d\n", korova, bik);
			}
			printf("Вы отгадали число!");
		}
		else printf("\nКомпьютер загадал число с повторяющимися цифрами. Попробуйте снова");
	}
	else printf("Некорректное значение");
}