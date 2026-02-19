#include <stdio.h>
/*
int main() {
	float v1 = 10;
	float v2 = 20;
	float s = 100;
float t = s/(v1 + v2);
printf(" % f", t); };
*/
/*
int main() {
	int v1 = 10;
	int v2 = 10;
	int t = 45;
	int s = t * (v1 + v2);
	printf("%d", s);
};*/
#include <math.h>
int main() {
	float c1x = 2;
	float c1y = 3;
	float c2x = 2;
	float c2y = 3;
	float r1 = 5;
	float r2 = 5;
	float kvx = c2x - c1x;
	float kvy = c2y - c1y;
	float rcntr = sqrt(pow(kvx,2) + pow(kvy,2));
	if ((rcntr < (r1 + r2)) and (rcntr!=0)) {
		printf("peresekat");
	}
	else if (rcntr == (r1 + r2)) {
		printf("kasat");
		printf("%f", rcntr);
	}
	else if (rcntr > (r1 + r2)) {
		printf("ne peresekat");
	}
	else if ((r1 == r2) and (c1x == c2x) and (c2y == c1y)) {
		printf("sovpadat");
	}
	else if ((c1x == c2x) and (c1y == c2y)) {
		printf("odna v drugoy");
	}


};