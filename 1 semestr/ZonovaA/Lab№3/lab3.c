#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<time.h>
#define A 2
#define B 3
#define C 4
#define D 5

//Игрок выбирает длину загадываемого числа, программа генерирует число без повторений, человек отгадывает, комп выдает сколько быков и сколько коров
void main() {
	const int n;
	srand(time(0));
	printf("Input the lenght of the number(2,3,4 or 5): \n");
	scanf("%d", &n);
	while (n < 2 || n > 5) { //проверка
		printf("Error, try again!\n");
		int c;
		while ((c = getchar()) != '\n' && c != EOF);
		printf("Input the lenght of the number(2,3,4 or 5): \n");
		scanf("%d", &n);
	}
	if (n == A){ //загадал массив длины 2
		int arr[A], oper, num;
		for (int i = 0; i < n; i++) {
			oper = 1;
			while (oper) {
				num = 0 + rand() % 10;
				oper = 0;
				for (int j = 0; j < i; j++) {
					if (arr[j] == num) {
						oper = 1;
						break;
					}
				}
			}
			arr[i] = num;
		}
		int c = 0, cn = 0;
		do {
			c = 0;
			cn = 0;
			printf("Input any number of the selected lenght: \n");
			int array[A];
			for (int i = 0; i < n; i++) {
				scanf("%d", &array[i]);
				while (array[i] < 0 || array[i] > 9) { //проверка
					printf("Error, try again!\n");
					int c;
					while ((c = getchar()) != '\n' && c != EOF);
					printf("Input any number of the selected lenght: \n");
					scanf("%d", &array[i]);
				}
			}
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (array[i] == arr[j] && i == j) {
						c++;
					}
					if (array[i] == arr[j] && i != j) {
						cn++;
					}
				}
			}
			printf("Buk = %d, corova = %d\n", c, cn);
			
		} while (c != n || cn != 0);
		
		
	}
	if (n == B) { //загадал массив длины 2
		int arr[B], oper, num;
		for (int i = 0; i < n; i++) {
			oper = 1;
			while (oper) {
				num = 0 + rand() % 10;
				oper = 0;
				for (int j = 0; j < i; j++) {
					if (arr[j] == num) {
						oper = 1;
						break;
					}
				}
			}
			arr[i] = num;
		}
		int c = 0, cn = 0;
		do {
			c = 0;
			cn = 0;
			printf("Input any number of the selected lenght: \n");
			int array[B];
			for (int i = 0; i < n; i++) {
				scanf("%d", &array[i]);
				while (array[i] < 0 || array[i] > 9) { //проверка
					printf("Error, try again!\n");
					int c;
					while ((c = getchar()) != '\n' && c != EOF);
					printf("Input any number of the selected lenght: \n");
					scanf("%d", &array[i]);
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (array[i] == arr[j] && i == j) {
						c++;
					}
					if (array[i] == arr[j] && i != j) {
						cn++;
					}
				}
			}
			printf("Buk = %d, corova = %d\n", c, cn);

		} while (c != n || cn != 0);


	}
	if (n == C) { //загадал массив длины 2
		int arr[C], oper, num;
		for (int i = 0; i < n; i++) {
			oper = 1;
			while (oper) {
				num = 0 + rand() % 10;
				oper = 0;
				for (int j = 0; j < i; j++) {
					if (arr[j] == num) {
						oper = 1;
						break;
					}
				}
			}
			arr[i] = num;
		}
		int c = 0, cn = 0;
		do {
			c = 0;
			cn = 0;
			printf("Input any number of the selected lenght: \n");
			int array[C];
			for (int i = 0; i < n; i++) {
				scanf("%d", &array[i]);
				while (array[i] < 0 || array[i] > 9) { //проверка
					printf("Error, try again!\n");
					int c;
					while ((c = getchar()) != '\n' && c != EOF);
					printf("Input any number of the selected lenght: \n");
					scanf("%d", &array[i]);
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (array[i] == arr[j] && i == j) {
						c++;
					}
					if (array[i] == arr[j] && i != j) {
						cn++;
					}
				}
			}
			printf("Buk = %d, corova = %d\n", c, cn);

		} while (c != n || cn != 0);


	}
	if (n == D) { //загадал массив длины 2
		int arr[D], oper, num;
		for (int i = 0; i < n; i++) {
			oper = 1;
			while (oper) {
				num = 0 + rand() % 10;
				oper = 0;
				for (int j = 0; j < i; j++) {
					if (arr[j] == num) {
						oper = 1;
						break;
					}
				}
			}
			arr[i] = num;
		}
		int c = 0, cn = 0;
		do {
			c = 0;
			cn = 0;
			printf("Input any number of the selected lenght: \n");
			int array[D];
			for (int i = 0; i < n; i++) {
				scanf("%d", &array[i]);
				while (array[i] < 0 || array[i] > 9) { //проверка
					printf("Error, try again!\n");
					int c;
					while ((c = getchar()) != '\n' && c != EOF);
					printf("Input any number of the selected lenght: \n");
					scanf("%d", &array[i]);
				}
			}

			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (array[i] == arr[j] && i == j) {
						c++;
					}
					if (array[i] == arr[j] && i != j) {
						cn++;
					}
				}
			}
			printf("Buk = %d, corova = %d\n", c, cn);

		} while (c != n || cn != 0);


	}
	
}