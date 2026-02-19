#include <stdio.h>
#include <locale.h>
#include <string.h>
int main() {
	setlocale(LC_ALL, "rus");
	char hit1[20] = "Документы";
	char hit2[20] = "Фотогроафии";
	char hit3[20] = "Музыка";

	char names1[10][50] = { "1_реферат.doc", "2_реферат.doc", "3_реферат.doc", "4_реферат.doc", "5_реферат.doc" };
	int sizes1[10] = { 500, 2300, 45000, 15000, 28500 };
	int count1 = 5;

	char names2[10][50] = { "1_фото.jpg", "2_фото.jpg", "3_фото.jpg", "4_фото.jpg", "5_фото.jpg" };
	int sizes2[10] = { 600, 4300, 25000, 13000, 22500 };
	int count2 = 5;

	char names3[10][50] = { "1_песня.mp3", "2_песня.mp3", "3_песня.mp3", "4_песня.mp3", "5_песня.mp3" };
	int sizes3[10] = { 300, 9700, 75000, 33000, 66500 };
	int count3 = 5;

	int current_hit = 1;
	int choise, i, j;
	char tname[50];
	int tsize;

	while (1) {
		printf("\n=== ФАЙЛОВЫЙ МЕНЕДЖЕР ===\n");
		if (current_hit == 1) {
			printf("Текущая папка: %s\n", hit1);
		}
		else if (current_hit == 2) {
			printf("Текущая папка: %s\n", hit2);
		}
		else {
			printf("Текущая папка: %s\n", hit3);
		}
		printf("1. Показать все файлы\n");
		printf("2. Сортировка по возрастанию\n");
		printf("3. Сортировка по убыванию\n");
		printf("4. Добавить файл\n");
		printf("5. Сменить папку\n");
		printf("6. Выход\n");
		printf("Выберите действие: ");
		scanf_s("%d", &choise);
		switch (choise) {
		case 1:
			printf("\n=== Файлы в папке ===\n");
			if (current_hit == 1) {
				for (i = 0; i < count1; i++) {
					printf("%s\t%d байт\n", names1[i], sizes1[i]);
				}
				printf("Всего файлов: %d\n", count1);
			}
			else if (current_hit == 2) {
				for (i = 0; i < count2; i++) {
					printf("%s\t%d байт\n", names2[i], sizes2[i]);
				}
				printf("Всего файлов: %d\n", count2);
			}
			else {
				for (i = 0; i < count3; i++) {
					printf("%s\t%d байт\n", names3[i], sizes3[i]);
				}
				printf("Всего файлов: %d\n", count3);
			}
			break;
		case 2:
			printf("Отсортированные по возрастанию файлы:\n");
			if (current_hit == 1) {
				for (i = 0; i < count1 - 1; i++) {
					for (j = 0; j < count1 - i - 1; j++) {
						if (sizes1[j] > sizes1[j + 1]) {
							tsize = sizes1[j];
							sizes1[j] = sizes1[j + 1];
							sizes1[j + 1] = tsize;
							strcpy_s(tname, names1[j]);
							strcpy_s(names1[j], names1[j + 1]);
							strcpy_s(names1[j + 1], tname);
						}
					}
				}
			}
			else if (current_hit == 2) {
				for (i = 0; i < count2 - 1; i++) {
					for (j = 0; j < count2 - i - 1; j++) {
						if (sizes2[j] > sizes2[j + 1]) {
							tsize = sizes2[j];
							sizes2[j] = sizes2[j + 1];
							sizes2[j + 1] = tsize;
							strcpy_s(tname, names2[j]);
							strcpy_s(names2[j], names2[j + 1]);
							strcpy_s(names2[j + 1], tname);
						}
					}
				}
			}
			else {
				for (i = 0; i < count3 - 1; i++) {
					for (j = 0; j < count3 - i - 1; j++) {
						if (sizes3[j] > sizes3[j + 1]) {
							tsize = sizes3[j];
							sizes3[j] = sizes3[j + 1];
							sizes3[j + 1] = tsize;
							strcpy_s(tname, names3[j]);
							strcpy_s(names3[j], names3[j + 1]);
							strcpy_s(names3[j + 1], tname);
						}
					}
				}
			}
			printf("Сортировка завершена\n");
			break;
		case 3:
			printf("Отсортированные по убыванию файлы:\n");
			if (current_hit == 1) {
				for (i = 0; i < count1 - 1; i++) {
					for (j = 0; j < count1 - i - 1; j++) {
						if (sizes1[j] < sizes1[j + 1]) {
							tsize = sizes1[j + 1];
							sizes1[j + 1] = sizes1[j];
							sizes1[j] = tsize;
							strcpy_s(tname, names1[i]);
							strcpy_s(names1[i], names1[j]);
							strcpy_s(names1[j], tname);
						}
					}
				}
			}
			else if (current_hit == 2) {
				for (i = 0; i < count2 - 1; i++) {
					for (j = 0; j < count2 - i - 1; j++) {
						if (sizes2[j] < sizes2[j + 1]) {
							tsize = sizes2[j + 1];
							sizes2[j + 1] = sizes2[j];
							sizes2[j] = tsize;
							strcpy_s(tname, names2[i]);
							strcpy_s(names2[i], names2[j]);
							strcpy_s(names2[j], tname);
						}
					}
				}
			}
			else {
				for (i = 0; i < count3 - 1; i++) {
					for (j = 0; j < count3 - i - 1; j++) {
						if (sizes3[j] < sizes3[j + 1]) {
							tsize = sizes3[j + 1];
							sizes3[j + 1] = sizes3[j];
							sizes3[j] = tsize;
							strcpy_s(tname, names3[i]);
							strcpy_s(names3[i], names3[j]);
							strcpy_s(names3[j], tname);
						}
					}
				}
			}
			printf("Сортировка завершена\n");
			break;
		case 4:
			printf("Добавление файла:\n");
			if (current_hit == 1) {
				if (count1 < 10) {
					printf("Введите имя нового файла: ");
					scanf_s("%s", names1[count1], 50);
					printf("Введите размер файла в байтах: ");
					scanf_s("%d", &sizes1[count1]);
					count1++;
					printf("Файл успешно добавлен!\n");
				}
				else {
					printf("Ошибка! Нельзя добавить больше 10 файлов.\n");
				}
			}
			else if (current_hit == 2) {
				if (count2 < 10) {
					printf("Введите имя нового файла: ");
					scanf_s("%s", names2[count2], 50);
					printf("Введите размер файла в байтах: ");
					scanf_s("%d", &sizes2[count2]);
					count2++;
					printf("Файл успешно добавлен!\n");
				}
				else {
					printf("Ошибка! Нельзя добавить больше 10 файлов.\n");
				}
			}
			else {
				if (count3 < 10) {
					printf("Введите имя нового файла: ");
					scanf_s("%s", names3[count3], 50);
					printf("Введите размер файла в байтах: ");
					scanf_s("%d", &sizes3[count3]);
					count3++;
					printf("Файл успешно добавлен!\n");
				}
				else {
					printf("Ошибка! Нельзя добавить больше 10 файлов.\n");
				}
			}
			break;
		case 5:
			printf("\nВыберите папку:\n");
			printf("1. %s (%d файлов)\n", hit1, count1);
			printf("2. %s (%d файлов)\n", hit2, count2);
			printf("3. %s (%d файлов)\n", hit3, count3);
			printf("Ваш выбор (1-3): ");
			scanf_s("%d", &current_hit);
			if (current_hit < 1 || current_hit > 3) {
				printf("Нет такой папки! Остаемся в текущей.\n");
				current_hit = 1;
			}
			break;
		case 6:
			printf("Выход из программы\n");
			return 0;
		default:
			printf("Неверный выбор!\n");
		}
	}
	return 0;
}