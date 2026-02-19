#include <stdio.h>
#include <math.h>
#include <clocale>
//void main() {
//	setlocale(LC_ALL, "RU");
//	float w, d, h, mass = 0;
//	printf("Введите высоту шкафа в сантиметрах от 180 до 220: ");
//	scanf_s("%f", &h);
//	printf("Введите ширину шкафа в сантиметрах от 80 до 120: ");
//	scanf_s("%f", &w);
//	printf("Введите глубину шкафа в сантиметрах от 50 до 90: ");
//	scanf_s("%f", &d);
//	if ((220 < h) || (h < 180) || (w < 80) || (w > 120) || (d < 50) || (d > 90)) {
//		printf("Некорректные данные");
//	}
//	else {
//		//плотности взяты из интернета
//		float dsp = 650, dvp = 800, wood = 800;
//		h = h / 100;
//		w = w / 100;
//		d = d / 100;
//		mass = mass + (h * w * 0.005 * dvp);
//		mass = mass + (2 * h * d * 0.015 * dsp);
//		mass = mass + (2 * d * w * 0.015 * dsp);
//		mass = mass + (2 * h * (w / 2) * 0.01 * wood);
//		int polki = (int)(h * 100) / 40;
//		mass = mass + (polki * d * w * 0.015 * dsp);
//		printf("Масса шкафа: %f", mass);
//	}
//}
void main() {
	setlocale(LC_ALL, "RU");
	int x1, x2, y1, y2;

	printf("Введите координаты K1 от 1 до 8 (сначала x, потом y): ");
	scanf_s("%d %d", &x1, &y1);
	printf("Введите координаты K2 от 1 до 8 (сначала x, потом y): ");
	scanf_s("%d %d", &x2, &y2);


	int figura;
	printf("Выберите фигуру (1-конь, 2-ладья, 3-ферзь, 4-слон, 5-король): ");
	scanf_s("%d", &figura);
	int dx = abs(x1 - x2);
	int dy = abs(y1 - y2);
	
	int status = 0;
	switch (figura) {
	case 1:
		if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1)) status = 1; break;
	case 2:
		if (dx == 0 || dy == 0) status = 1; break;
	case 3:
		if (dx == 0 || dy == 0 || dx == dy) status = 1; break;
	case 4:
		if (dx == dy) status = 1; break;
	case 5:
		if (dx <= 1 && dy <= 1) status = 1; break;
	} 

	int n = 0;
	const char* figuri[] = {"конь", "ладья", "ферзь", "слон", "король"};
	if (status) {
		printf("Может перейти за 1 ход");
	}
	else {
		printf("Не может перейти\n");
		printf("Могут перейти: ");
		if ((dx == 1 && dy == 2) || (dx == 2 && dy == 1)) {
			printf(" конь ");
			n++;
		}
		if (dx == 0 || dy == 0) {
			printf(" ладья ");
			n++;
		}
		if (dx == 0 || dy == 0 || dx == dy) {
			printf(" ферзь ");
			n++;
		}
		if (dx == dy) {
			printf(" слон ");
			n++;
		}
		if (dx <= 1 && dy <= 1) {
			printf(" король ");
			n++;
		}
		if (n == 0) {
			printf("Ни одна фигура не может перейти");
		}
	}
}