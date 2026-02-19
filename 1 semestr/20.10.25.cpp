//#include <stdio.h>
//#include <locale.h>
//void main() {
//	setlocale(LC_ALL, "Russian");
//	int a, b;
//	scanf_s("%d %d", &a, &b);
//	if (a == b) {
//		printf("НОД = %d", a);
//	}
//	while (a != 0 && b != 0) {
//		if (a > b) {
//			a = a % b;
//		}
//		else {
//			b = b % a;
//		}
//	}
//	printf("НОД = %d", a + b);
//}

#include <stdio.h>
void main() {
	int a, suma, b = 0, sumb = 0;
	scanf_s("%d", &a);
	suma = (a % 10) + (a / 10);
	while (b != 1000) {
		if (b > 99) {
			sumb = (b / 100) + ((b / 10) % 10) + (b % 10);
		}
		else {
			sumb = (b / 10) + (b % 10);
		}
		if (suma == sumb) {
			printf("%d\n", b);
		}
		b++;
	}
}