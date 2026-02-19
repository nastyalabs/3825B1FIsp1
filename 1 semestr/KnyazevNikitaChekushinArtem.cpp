#include <stdio.h>
#include <math.h>
/*int main() {
	float v1, v2, s, t;
	scanf_s("%f %f %f", &v1, &v2, &s);
	t = s / (v1 + v2);
	printf("%f", t);
}
*/

/*int main() {
	float v1, v2, s1,s2;
	float t = 1.5;
	scanf_s("%f %f", &v1, &v2);
	s1 = v1 * t;
	s2 = v2 * t;
	float s = fabs(s2 - s1);
	printf("%f", s);
}*/

int main() {
	float x1, y1, r1, x2, y2, r2, rasstoyanie, s1, s2, s3;
	scanf_s("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);
	s1 = x2 - x1;
	s2 = y2 - y1;
	s3 = pow(s1, 2) + pow(s2, 2);
	rasstoyanie = sqrt(s3);
	if (r1 + r2 == rasstoyanie) {
		printf("kasania");
	}
	else if (r1 + r2 < rasstoyanie) {
		printf("ne peresekautsya");
	}
	else {
		printf("peresekautsya");
	}
}