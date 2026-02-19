#include <stdio.h> 
#include <math.h>
/*void main() {
	float v1, v2, s,t;
	scanf_s("%f %f %f", &v1, &v2, &s);
    t = s / (v1 + v2);
	printf("%f", t);

}*/
/*void main() {
	float v1, v2,t=1.5,a1,a2,a;
	scanf_s("%f %f", &v1, &v2);
    
	a1 = v1 * t;
	a2 = v2 * t;
	a = fabs(a1 - a2);
	printf("%f", a);

}*/
void main() {
	float x1,y1,r1,x2,y2,r2;
	scanf_s("%f %f %f %f %f %f", &x1, &y1, &r1, &x2, &y2, &r2);
	float rasxy = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));
	float rasr = r1 + r2;
	if (rasxy > rasr) {
		printf("ne kasautsa");
	}
	else if (rasxy == rasr) {
		printf("kasautsa");
	}
	else {
		printf("peresekautsa");
	}

}
