#include <stdio.h>
#include <locale.h>
#include <time.h>

void main() {
	int NN[5], peop[5], k, i, j, flag=0, cow=0, bull=0;
	srand(time(NULL));
	setlocale(LC_ALL, "Rus");

	do {
		printf("Введите длинну загадываемого числа (от 2 до 5)\n");
		scanf_s("%d", &k);
	} while (k < 2 || k>5);

	for (i = 0; i < k; i++, flag = 0) {
		NN[i] = rand() % 10;
		for (j = 0; j < i; j++) {
			if (NN[i] == NN[j])
				flag = 1;
		}
		if (flag == 1)
			i--;
	}
	
	do {
		printf("Введите %d - значное число с неповторяющмися цифрами\n", k);
		scanf_s("%d", &j);
		for (i = 0; i < k; i++, j = j / 10, bull = 0, cow = 0)
			peop[k - i - 1] = j % 10;
		for (i = 0; i < k; i++) {
			if (peop[i] == NN[i])
				bull++;
			for (j = 0; j < k; j++)
				if (peop[i] == NN[j])
					cow++;
		}
		cow -= bull;
		if (bull == k)
			printf("Вы угадали!!!");
		else
			printf("Коров - %d, быков - %d\n", cow, bull);
	} while (bull != k);
}


