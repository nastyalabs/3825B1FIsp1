#include <stdio.h>
#include <math.h>
#include <locale.h>

int main()
{
	setlocale(LC_ALL, "Russian");
	int x1, y1, r1, x2, y2, r2;
	int d;
	scanf_s("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
	d = sqrt(pow((x2 - x1), 2) + pow((y2 - y1), 2)); // расстояние между 2-мя окр
	if (d > r1 + r2) {
		printf("0");
	}
	if (d = r1 + r2) {
		printf("1");
	}
	if (d < r1 + r2) {
		printf("2");
	}
	return 0;

}