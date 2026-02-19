#include <stdio.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Rus");
	int count_of_polka, vdsp = 680, vdvp = 900, vwood = 650;
	float h, w, d, back, side, up_down, door, polka, massa;
	printf("¬ведите высоту h в см: ");
	scanf_s("%f", &h);
	printf("¬ведите ширину w в см: ");
	scanf_s("%f", &w);
	printf("¬ведите глубину d в см: ");
	scanf_s("%f", &d);
	h = h / 100;
	w = w / 100;
	d = d / 100;
	count_of_polka = h / 40;
	back = h * w * 0.005 * vdvp;
	side = h * d * 0.015 * vdsp * 2;
	up_down = w * d * 0.015 * vdsp * 2;
	door = h * w * 0.01 * vwood * 2;
	polka = count_of_polka * w * d * vdsp;
	massa = back + side + up_down + door + polka;
	printf("%f", massa);
	return 0;
}