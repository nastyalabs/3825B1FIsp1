//#include <stdio.h>
//void main() {
//	int a, b, c;
//	scanf_s("%d %d %d", &a, &b, &c);
//	int mass[] = { a,b,c };
//	int max = -10000;
//	int k=0;
//	int i;
//	for (i = 0; i < 3; i++) {
//		if (mass[i] > max) {
//			max = mass[i];
//			k++;
//		}
//	}
//	printf("maximum = %d\n", max);
//	printf("sravneniya = %d", k);
//}

//#include <stdio.h>
//void main() {
//	float srb, a, b, c;
//	scanf_s("%f %f %f", &a, &b, &c);
//	srb = ((a + b + c) / 3.0);
//	if ((4.5 <= srb) && (srb <= 5))
//		printf("Otlichnik");
//	else if ((3.5 <= srb) && (srb < 4.5))
//		printf("Horoshist");
//	else if ((2.5 <= srb) && (srb < 3.5))
//		printf("Troechnik");
//	else
//		printf("Dvoechik");
//}

#include <stdio.h>
void main() {
	float a, b;
	char oper;
	printf("Vvedite chislo 1 ");
	scanf_s("%f", &a);
	printf("Vvedite operator ");
	scanf_s(" %c", &oper, 1);
	printf("Vvedite chislo 2 ");
	scanf_s("%f", &b);
	switch (oper)
	{
	case '+': printf("Rezultat = %f", a + b); break;
	case '-': printf("Rezultat = %f", a - b); break;
	case '*': printf("Rezultat = %f", a * b); break;
	case '/': 
		if (b == 0) printf("Nevozmozhno");
		else printf("Rezultat = %f", a / b); break;
	default: printf("Neverniy operator");
	}
}