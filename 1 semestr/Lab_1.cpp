#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
	setlocale(LC_CTYPE, "rus");
	float h1, w1, d2, Vnzd, V2b, Vnd, Vvp, Mnzd, M2b, Mvnk, Mnd, Mvp, I, Vvnk;
	printf("Введите параметры деталей: 1)Высоту стенки 180-220 см 2)Ширину стенки 80-120 см 3)Глубину боковин 50-90 см\n");
	scanf_s("%f %f %f", &h1, &w1, &d2);
	const int pDSP = 650;
	const int pDVP = 900;
	const int pTree = 700;
	printf("Плотность ДСП 650 кг/куб.м\n");
	printf("Плотность ДВП 900 кг/куб.м\n");
	printf("Плотность Дерева 700 кг/куб.м\n");
	Vnzd = (h1 * w1 * 0.5) / 1000000;
	V2b = (h1 * d2 * 1.5 * 2) / 1000000;
	Vvnk = (w1 * d2 * 1.5 * 2) / 1000000;
	Vnd = (h1 * w1 * 1.0) / 1000000;
	int Kp = (int)(h1 / 40);
	printf("Количество полок: %d\n", Kp);
	Vvp = ((w1 * d2 * 1.0) / 1000000) * Kp;
	Mnzd = Vnzd * pDVP;
	M2b = V2b * pDSP;
	Mvnk = Vvnk * pDSP;
	Mnd = Vnd * pTree;
	Mvp = Vvp * pDSP;
	I = Mnzd + M2b + Mvnk + Mnd + Mvp;
	printf("Масса шкафа в кг: %f\n", I);
	return 0;
}