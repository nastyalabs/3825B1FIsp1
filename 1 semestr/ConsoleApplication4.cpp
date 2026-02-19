//#include <stdio.h>
//void main() {
//	int a, b;
//	scanf_s("Vvedite chisla: %d %d", &a, &b);
//	if (a == b) {
//		printf("NOD = %d", a);
//	}
//	while (a != 0 && b != 0) {
//		if (a > b) {
//			a = a % b;
//		}
//		if (b>a) {
//			b = b % a;
//		}
//	}
//	printf("NOD = %d", a + b);
//}

#include <stdio.h>
int summ_of_numders(int n) {
	int sum = 0;
	while (n>0) {
		sum += n % 10;
		n = n / 10;
	}
	return sum;
}
void main() {
	int num1;
	printf("Enter a numder from 0 to 27: ");
	scanf_s("%d", &num1);
	if (num1 < 0 || num1>27) {
		printf("Error. The numder was supposed to be from 0 to 27");
	}
	else {
		printf("Result: = \n");
		for (int i = 0; i < 1000; i++) {
			if (summ_of_numders(i) == num1) {
				printf("%d\n", i);
			}
		}
	}
}