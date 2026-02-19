#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include<ctype.h>
#include <locale.h>
typedef struct {             //создаём структуру
	char name[100];
	long size;
}Inf_file

void vst_sort(Inf_file* files, int cnt) {           //сортировка вставками
	int k;
	for (int i = 1; i < cnt; i++) {
		Inf_file tmp = files[i];
		k = i - 1;
		while (k >= 0 && files[k].size > tmp.size) {
			files[k + 1] = files[k];
			k = k - 1;
		}
		files[k + 1] = tmp;
	}
	printf("\n%s %s\n", "Имя файла", "Size file (bite)");
	for (int i = 0; i < cnt; i++) {
		printf("%s %ld\n", files[i].name, files[i].size);
	}
}

void bubble_sort(Inf_file* files, int cnt) {              //пузырьковая сортировка
	int n_swp;
	for (int i = cnt - 1; i >= 0; i--) {
		n_swp = 1;
		for (int k = 0; k < i; k++) {
			if (files[k].size > files[k + 1].size) {
				Inf_file tmp = files[k];
				files[k] = files[k + 1];
				files[k + 1] = tmp;
				n_swp = 0;
			}
		}
		if (n_swp == 1) {
			break;
		}
	}
	printf("\n%s %s\n", "Имя файла", "Размер файлах в битах");
	for (int i = 0; i < cnt; i++) {
		printf("%s %ld\n", files[i].name, files[i].size);
	}
}

Inf_file* createfile(int* cnt) {                 //создание файлов
	*cnt = 5;
	Inf_file* files = malloc(*cnt * sizeof(Inf_file));    //инициализация массива через указатель
	Inf_file* f = files;
	strcpy(f->name, "Note.txt");
	f->size = 1000;
	f++;
	strcpy(f->name, "Meter.txt");
	f->size = 4100;
	f++;
	strcpy(f->name, "README.txt");
	f->size = 2300;
	f++;
	strcpy(f->name, "Label.txt");
	f->size = 5600;
	f++;
	strcpy(f->name, "WN_Manual.pdf");
	f->size = 3200;
	f++;

	return files;
}

void printfile(Inf_file* files, int cnt) {             //вывод файлов
	printf("\n%s %s\n", "Имя файла", "Размер файла в битах");
	for (int i = 0; i < cnt; i++) {
		printf("%s %ld\n", files[i].name, files[i].size);
	}
}

int main() {
	setlocale(LC_ALL, "Russian");
	int file_cnt, vibor, sort = 1;       //1 - вставками, 2 - пузырьковая
	char arr[100];

	Inf_file* orig = createfile(&file_cnt);
	Inf_file* by_sort = malloc(file_cnt * sizeof(Inf_file));

	printf("Менеджер файлов.\n");
	printf("\nВведите директорию: ");
	fgets(arr, sizeof(arr), stdin); 
	printf("Директория: %s", arr);

	do {
		memcpy(by_sort, orig, file_cnt * sizeof(Inf_file));                //копируем массиы
		printf("\nМеню сортировки\n");
		printf("1.Показать файлы\n");
		printf("2.Выберите сортировку (сейчас: %s)\n", sort == 1 ? "Вставками" : "Пузырьковая");
		printf("3.Завершить\n");
		printf("Выберите дейтвие: ");
		scanf("%d", &vibor);
		switch (vibor) {
		case 1:
			printfile(by_sort, file_cnt);
		case 2:
			printf("\nВыберите сортировку:\n");
			printf("1.Вставками\n2.Пузырьковая\n");
			printf("Выбор: ");
			scanf("%d", &sort);
			if (sort == 1 || sort == 2) {
				clock_t start = clock();
				if (sort == 1) {
					vst_sort(by_sort, file_cnt);
				}
				else {
					bubble_sort(by_sort, file_cnt);
				}
				clock_t end = clock();
				double time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
				printf("\nКонец сортировки\n");

				printf("Сортировка: %s\n", sort == 1 ? "Вставками" : "Пузырьковая");
				printf("Время сортировки: %.3f mc\n", time);
				break;
			}
			else {
				break;
			}
		case 3:
			printf("Выход из программы\n");
			break;
		default:
			printf("Неверный выбор, попробуйте снова\n");
		}

		while (getchar() != '\n');

	} while (vibor != 3);

	free(orig);
	free(by_sort);

	return 0;
}