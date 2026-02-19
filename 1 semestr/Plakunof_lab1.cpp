#include <stdio.h>
#include <math.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int h, w, d;
	float densidadDSP, densidadDVP, densidadWOOD, stenka1, bokovina2, verhnizh2, door2, polki;
	printf("Введите высоту, ширину и глубину.\n");
	scanf_s("%d%d%d", &h, &w, &d);
	printf("Введите плотность ДСП, ДВП, дерева.\n");
	scanf_s("%f%f%f", &densidadDSP, &densidadDVP, &densidadWOOD);
	
	stenka1 = h * w / 2 * densidadDVP;
	bokovina2 = 2 * h * d * 3 / 2 * densidadDSP;
	verhnizh2 = 2 * w * d * 3 / 2 * densidadDSP;
	door2 = 2 * h * (w / 2) * densidadWOOD;
	polki = int(h / 40) * w * d * densidadDSP * 3 / 2;
	printf("Масса шкафа: %f", stenka1 + bokovina2 + verhnizh2 + door2 + polki);
}