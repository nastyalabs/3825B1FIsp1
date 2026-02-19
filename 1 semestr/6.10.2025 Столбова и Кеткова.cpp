
#include <stdio.h>
/*
void main()
{
	int a, b, c;
	scanf_s("%d %d %d", &a, &b, &c);
	if ((a + b <= c) || (a + c <= b) || (b + c <= a))
		printf("ne treugolnik");
	else if ((a == b) && (a== c))
		printf("ravnostoronniy");
	else if ((a == b) || (a == c) || (b == c))
		printf("ravnobedrenniy");
	else if ((a * a + b * b == c * c) || (a * a + c * c == b * b) || (b * b + c * c == a * a))
		printf("pryamougolniy");
	else
		printf("obychniy :(");
}
*/

#include <math.h>
#include <stdio.h>
void main()
{
	float a, b, c, D;
	float x1, x2;
	scanf_s("%f %f %f", &a, &b, &c);
	if ((a == 0.0) && (b == 0.0)) {
		printf("korney beskonechno mnogo");
	}
	else if (((a == 0.0) && (c == 0.0)) || ((b == 0.0) && (c == 0.0))) {
		printf("otvet = %d", 0);
	}
	else if (a == 0.0) {
		printf("otvet = %f", ((-1 * c) / b));
	}
	else if ((b == 0.0) && (c < 0)) {
		printf("otvet1 = %f\n", sqrt((-1 * c) / a));
		printf("otvet2 = %f", -1 * (sqrt((-1 * c) / a)));
	}
	else if ((b == 0.0) && (c > 0)) {
		printf("net korney");
	}
	else if (c == 0.0) {
		printf("otvet1 = %f\n", ((-1 * b) / a));
		printf("otvet2= %d", 0);
	}
	else {
		D = (b * b) - (4 * a * c);
		if (D < 0.0) {
			printf("net korney");
		}
		else {
			if (D == 0.0) {
				printf("otvet = %f", ((-1 * b) / (2 * a)));
			}
			else
			{
				x1 = (-b + sqrt(D)) / (2 * a);
				x2 = (-b - sqrt(D)) / (2 * a);
				printf("otvet1=%f\n", x1);
				printf("otvet2=%f", x2);
			}
		}
	}
}