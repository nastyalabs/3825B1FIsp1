#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

//создадим структуру для хранения информации о файлах
typedef struct {
	char name[256]; //максимальная длина слова 256
	long size; //задаем размер файлов
}Infafile;

//функция сортировки пузырьком
void bubblesort(Infafile *files, int cnt) {
	int noswap;
	for (int i = cnt - 1; i >= 0; i--) {
		noswap = 1;
		for (int j = 0; j < i; j++) {
			if (files[j].size > files[j + 1].size) {
				Infafile tmp = files[j];
				files[j] = files[j + 1];
				files[j + 1] = tmp;
				noswap = 0;
			}
		}
		if (noswap == 1) {
			break;
		}
	}
	printf("\n%s %s\n", "Name file", "Size file (bite)");
	for (int i = 0; i < cnt; i++) {
		printf("%s %ld\n", files[i].name, files[i].size);
	}
}

//функция сортировки вставками
void vstsort(Infafile* files, int cnt) {
	int j;
	for (int i = 1; i < cnt; i++) {
		Infafile tmp = files[i];
		j = i - 1;
		while (j >= 0 && files[j].size > tmp.size) {
			files[j + 1] = files[j];
			j = j - 1;
		}
		files[j + 1] = tmp;
	}
	printf("\n%s %s\n", "Name file", "Size file (bite)");
	for (int i = 0; i < cnt; i++) {
		printf("%s %ld\n", files[i].name, files[i].size);
	}
}

//функция для создания файлов
Infafile* createfile(int* cnt) {
	*cnt = 5;
	Infafile* files = malloc(*cnt * sizeof(Infafile));
	//инициализация массива через указатель
	Infafile* f = files;
	//данные массива
	strcpy(f->name, "History.txt");
	f->size = 1200;
	f++;

	strcpy(f->name, "Math.pdf");
	f->size = 5200;
	f++;

	strcpy(f->name, "English.txt");
	f->size = 3300;
	f++;

	strcpy(f->name, "Russian.txt");
	f->size = 3600;
	f++;

	strcpy(f->name, "Literature.txt");
	f->size = 6200;
	f++;

	return files;
}

//функция вывода файлов
void printfile(Infafile* files, int cnt) {
	printf("\n%s %s\n", "Name file", "Size file (bite)");
	for (int i = 0; i < cnt; i++) {
		printf("%s %ld\n", files[i].name, files[i].size);
	}
}

int main() {
	int file_cnt;
	int choice;
	int sort = 1; //1-пузырьковая, 2-вставками

	//тестовый массив
	Infafile* original = createfile(&file_cnt);
	//рабочий массив
	Infafile* bysort = malloc(file_cnt * sizeof(Infafile));

	printf("File meneger.\n");
	printf("\nInput directori: ");

	char arr[256];
	fgets(arr, sizeof(arr), stdin); //не вызывает переполнения буфера
	printf("Directori: %s", arr);

	do {
		//копируем оригинальный массив
		memcpy(bysort, original, file_cnt * sizeof(Infafile));

		printf("\nMenu by sort\n");
		printf("1.Show files\n");
		printf("2.Choose an algorithm (now: %s)\n", sort == 1 ? "Bubble":"Vstavka");
		printf("3.Exite\n");
		printf("Choose action: ");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			printfile(bysort, file_cnt);
		case 2:
			printf("\nChoose an algorithm:\n");
			printf("1.Bubble\n2.Vstavka\n");
			printf("Your choice: ");
			scanf("%d", &sort);
			if (sort == 1 || sort == 2){
				clock_t start = clock();
				if (sort == 1) {
					bubblesort(bysort, file_cnt);
				}
				else {
					vstsort(bysort, file_cnt);
				}
				clock_t end = clock();
				double time = ((double)(end - start)) / CLOCKS_PER_SEC * 1000;
				printf("\nSorted end!\n");

				printf("Algorithm: %s\n", sort == 1 ? "Bubble" : "Vstavka");
				printf("Time to work sort: %.3f mc\n", time);
				break;
			}
			else {
				break;
			}
		case 3:
			printf("Exit in programm.\n");
			break;
		default:
			printf("Not right choice. Try again.\n");
		}

		while (getchar() != '\n');

	} while (choice != 3);

	free(original);
	free(bysort);

	return 0;
}
