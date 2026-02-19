#include <stdio.h>
int main() {
	int h, w, d, dvp, dsp, derevo;
	scanf_s("%d %d %d %d %d %d", &h, &w, &d, &dvp, &dsp, &derevo);
	if ((180 <= h <= 220) || (80 <= w <= 120) || (50 <= d <= 90)) {
		float zad, bok, krishki, dveri, polka, polki, m;
		zad = ((h * w * 0.5) / 1000000) * (dvp);
		bok = ((2 * h * d * 1.5) / 1000000) * (dsp);
		krishki = ((2 * w * d * 1.5) / 1000000) * (dsp);
		dveri = ((2 * h * w) / 1000000);
		polka = ((w * d * 1.5) / 1000000) * (dsp);
		if (h <= 200) {
			polki = 4 * polka;
		}
		else {
			polki = 5 * polka;
		}
		m = zad + bok + krishki + dveri + polki;
		printf("% f", m);
	}
}