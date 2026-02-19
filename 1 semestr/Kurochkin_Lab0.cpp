#include <stdio.h>
#include <math.h>
#include <locale.h>

float eps = 0.00001;

int main() {
	setlocale(LC_ALL, "Russian");
	//task 1
	/*float v1, v2;
	float s;
	scanf_s("%f %f %f", &v1, &v2, &s);
	float t = (s / (v1 + v2));
	printf("%f", t);*/

	//task 2
	/*
	float v1, v2;
	float t;
	scanf_s("%f %f %f", &v1, &v2, &t);
	float s = t * (v1 + v2);
	printf("%f",s);
	*/

	float x1, y1, r1, x2, y2, r2;
	scanf_s("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);

	float d = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	//printf("%.4f \n", d);
	if (abs(x1 - x2) < eps && abs(y1 - y2) < eps && abs(r1-r2) < eps) {
		printf("Совпадают");
	}
	else if (d - r1 - r2 > eps) {
		printf("Не пересекаются");
	}
	else if (d - r1 - r2 < eps && d - r1 - r2 >= 0) {
		printf("Касаются");
	}
	else if (d - r1 - r2 < 0) {
		printf("Пересекаются");
	}

	return 0;
}