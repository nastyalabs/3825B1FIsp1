//#include <stdio.h>
//#define N 100
//void main() {
//	int array[N];
//	for (int i = 0; i < N; i++)
//		scanf_s("%d",&array[i]);
//	int iskomoe_chislo;
//	scanf_s("%d", &iskomoe_chislo);
//	int rez=-1;
//	for (int i = 0; i < N; i++) {
//		if (array[i] == iskomoe_chislo) {
//			rez = i;
//		}
//	}
//	if (rez == -1) {
//		printf("Net takogo chisla");
//	}
//	printf("Rezultat %d", rez);
//}

//#include <stdio.h>
//#define N 100
//void main() {
//	int array[N];
//	for (int i = 0; i < N; i++)
//		scanf_s("%d", &array[i]);
//	int iskomoe_chislo;
//	scanf_s("%d", &iskomoe_chislo);
//	int rez = -1;
//	int i = 0;
//	while (i < N) {
//		if (array[i] == iskomoe_chislo) {
//			rez = i;
//		}
//		i++;
//	}
//	if (rez == -1)
//		printf("Net takogo chisla");
//	else
//		printf("Resultat %d", rez);
//}

#include <stdio.h>
#define N 10
void main() {
	int num;
	scanf_s("%d", &num);
	int b_arr[N] = {0};
	int b = 0;
	while (num > 0) {
		int digit = num % 10;
		b_arr[digit]++;
		num = num / 10;
	}
	for (int i = 1; i < N; i++) {
		b = b * 10 + b_arr[i];
	}
	printf("Result: %d", b);
}