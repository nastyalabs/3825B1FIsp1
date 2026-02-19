#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

//1.разбить строку на слова(непроверенное)
/*//1.разбить строку на слова
void main() {
	char str[] = "He vi ol";
	int len = strlen(str);
	int start = 0;

	for (int i = 0; i <= len; i++) {
		// ≈сли достигли конца строки или пробела
		if (isspace(str[i]) || str[i] == '\0') {
			// ≈сли перед этим был текст
			if (i > start) {
				// ѕечатаем слово
				printf("word: ");
				for (int j = start; j < i; j++) {
					printf("%c", str[j]);
				}
				printf("\n");
			}
			// ѕереходим к следующему потенциальному слову
			start = i + 1;
		}
	}
}*/

struct person{
	char lastname[20];
	char num[20];
	double ball;
};

int main() {
	struct person people[3];

	printf("Input dannye:\n");
	for (int i = 0; i < 3; i++) {
		printf("\nLastname: ");
		scanf("%s", &people[i].lastname);
		printf("Number group: ");
		scanf("%s", &people[i].num);
		printf("Ball: ");
		scanf("%lf", &people[i].ball);
	}
	printf("\nStudents:\n");
	for (int i = 0; i < 3; i++) {
		printf("\nLastname: %s", people[i].lastname);
		printf("\nNumber group: %s", people[i].num);
		printf("\nBall: %lf\n", people[i].ball);
	}

	for (int i = 0; i < 3; i++) {
		if (people[i].ball >= 4.5) {
			printf("\n\n%d student is great: ", i+1);
			printf("\nLastname: %s", people[i].lastname);
			printf("\nNumber group: %s", people[i].num);
			printf("\nBall: %lf\n", people[i].ball);
		}
		else {
			printf("\n\n%d student is not great.\n", i+1);
		}
	}

	return 0;
}