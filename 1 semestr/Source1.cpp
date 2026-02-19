#include <stdio.h>
#include <math.h>
int main() {
	double x1, y1, x2, y2, d, r1, r2;
	scanf_s("%f %f %f %f %f %f", &x1, &y1, &x2, &y2, &r1, &r2);
	d = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
	printf("%f\n", d);
	if (d > r1 + r2) {
		printf("0");
	}
	if (d < r1 + r2) {
		printf("2");
	}
	if (d = r1 + r2) {
		printf("1");
	}
	return 0;
}