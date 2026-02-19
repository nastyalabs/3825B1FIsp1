#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <locale.h>
#include <string.h>
#include <malloc.h>
//Функция на фозрастание
void vozr(char **arr, int *ar) 
{
	int flag = 0,box;
	char *boxx;
	while (flag == 0) 
	{
		flag = 1;
		for (int i = 0; i < 2;)
		{
			if (ar[i] > ar[i + 1]) { 
				box = ar[i], ar[i] = ar[i + 1], ar[i+1] = box; 
				boxx = arr[i], arr[i] = arr[i + 1], arr[i+1] = boxx;
				flag = 0;
			}
			i++;
		}
	}
	
}
//Функция на убывание
void ubiv(char** arr, int* ar)
{
	int flag = 0, box;
	char *boxx;
	while (flag == 0)
	{
		flag = 1;
		for (int i = 0; i < 2;)
		{
			if (ar[i] < ar[i + 1]) {
				box = ar[i], ar[i] = ar[i + 1], ar[i + 1] = box;
				boxx = arr[i], arr[i] = arr[i + 1], arr[i + 1] = boxx;
				flag = 0;
			}
			i++;
		}
	}

}
//функция вывода массива
void perch(int*ar, char **arr)
{
for (int i = 0; i <3;)
	{
		printf("\n%d - C:/Users/Артём/Desktop/", i+1);
		printf("%s", arr[i]);
		printf(" %d Mb", ar[i]);
		i++;
	}
}
//основная функция
void main1()
{
	int inp = 1, in = 1;
	char** pc2, ** pc0, ** pc1;
	int* pc2m, * pc0m, * pc1m;
	//разыменование указателей
	pc2 = (char**)calloc(3, sizeof(char*));
	pc2m = (int*)calloc(3, sizeof(int));

	pc0 = (char**)calloc(3, sizeof(char*));
	pc0m = (int*)calloc(3, sizeof(int));

	pc1 = (char**)calloc(3, sizeof(char*));
	pc1m = (int*)calloc(3, sizeof(int));
	//значения 
	pc0[0] = "Матанализ";
	pc0[1] = "Дискрет. мат";
	pc0[2] = "Аиг";
	pc0m[0] = 22;
	pc0m[1] = 9;
	pc0m[2] = 14;

	pc1[0] = "Фото1";
	pc1[1] = "Фото2";
	pc1[2] = "Фото3";
	pc1m[0] = 7;
	pc1m[1] = 5;
	pc1m[2] = 6;

	pc2[0] = "Видео1";
	pc2[1] = "Видео2";
	pc2[2] = "Видео3";
	pc2m[0] = 120;
	pc2m[1] = 144;
	pc2m[2] = 32;
	//выбор пути
	printf("\n\nВыберете путь: ");
	
	printf("\n1 - C:/Users/Артём/Desktop/Лекции/");
	printf("\n2 - C:/Users/Артём/Desktop/Фото/");
	printf("\n3 - C:/Users/Артём/Desktop/Видео/");
	do {
		printf("\n----> ");
		scanf_s("%d", &inp);
		if (inp != 1 && inp != 2 && inp != 3) { printf("\nНекорекктный путь, попробуйте еще раз"); }
		
	
	} while (inp != 1 && inp != 2 && inp!= 3);

	//следование выбранному пути

	if (inp == 1) { 
		perch(pc0m, pc0);

		printf("\n\nВыберете способ сортировки ");
		printf("\n1 - По возрастанию");
		printf("\n2 - По убыванию");
		do {
			if (in < 1 || in>2) { printf("\nНекорекктное значение, попробуйте еще раз"); }
			printf("\n----> ");
			scanf_s("%d", &in);

		} while (in < 1 || in>2);

		if (in == 1) { vozr(pc0, pc0m); }
		if (in == 2) { ubiv(pc0, pc0m); }

		perch(pc0m, pc0);
	}




	if (inp == 2) { 
		perch(pc1m, pc1);

		printf("\n\nВыберете способ сортировки ");
		printf("\n1 - По возрастанию");
		printf("\n2 - По убыванию");
		do {
			if (in < 1 || in>2) { printf("\nНекорекктное значение, попробуйте еще раз"); }
			printf("\n----> ");
			scanf_s("%d", &in);

		} while (in < 1 || in>2);
		if (in == 1) { vozr(pc1, pc1m); }
		if (in == 2) { ubiv(pc1, pc1m); }
		perch(pc1m, pc1);
	}






	if (inp == 3) {
		perch(pc2m, pc2);

		printf("\n\nВыберете способ сортировки ");
		printf("\n1 - По возрастанию");
		printf("\n2 - По убыванию");
		do {
			if (in < 1 || in>2) { printf("\nНекорекктное значение, попробуйте еще раз"); }
			printf("\n----> ");
			scanf_s("%d", &in);

		} while (in < 1 || in>2);
		if (in == 1) { vozr(pc2, pc2m); }
		if (in == 2) { ubiv(pc2, pc2m); }
		perch(pc2m, pc2);
	}

	// Освобождаем память
	free(pc0); free(pc0m);
	free(pc1); free(pc1m);
	free(pc2); free(pc2m);

	
	
}
//типо меню
void main()
{
	int inp;
	setlocale(0, "Rus");
	do {
		printf("\n\nНачать - 1\nВыйти - 0\n---> ");
		scanf_s("%d", &inp);
		main1();

	
	} while (inp!=0);

}
