#include <stdio.h>
#include <math.h>
int main() {
	char figure;
	scanf_s("%c", &figure, 1);
	int x1, y1, x2, y2, i = 0;
	scanf_s("%d %d %d %d", &x1, &y1, &x2, &y2);
	if (figure == 'k') { // k - korol
		if ((abs(x2 - x1) <= 1) && (abs(y2 - y1) <= 1))
		{
			printf("da");
			i++;
		}
		else printf("net\n");
	}
	if (figure == 'f') { // f - ferz
		if ((x1 == x2) || (y1 == y2) || (abs(x2 - x1) == abs(y2 - y1)))
		{
			printf("da");
			i++;
		}
		else printf("net\n");
	}
	if (figure == 'l') { // l - ladya
		if ((x1 == x2) || (y1 == y2))
		{
			printf("da");
			i++;
		}
		else printf("net\n");
	}
	if (figure == 's') { // s - slon
		if (abs(x2 - x1) == abs(y2 - y1))
		{
			printf("da");
			i++;
		}
		else printf("net\n");
	}
	if (figure == 'h') { // h - horse
		if ((abs(x2 - x1) == 1 && abs(y2 - y1) == 2) || (abs(x2 - x1) == 2 && abs(y2 - y1) == 1))
		{
			printf("da");
			i++;
		}
		else printf("net\n");
	}
	if (i==0)
	{
		if ((abs(x2 - x1) <= 1) && (abs(y2 - y1) <= 1)) printf("korol\n");
		if ((x1 == x2) || (y1 == y2) || (abs(x2 - x1) == abs(y2 - y1))) printf("ferz\n");
		if ((x1 == x2) || (y1 == y2)) printf("ladya\n");
		if (abs(x2 - x1) == abs(y2 - y1)) printf("slon\n");
		if ((abs(x2 - x1) == 1 && abs(y2 - y1) == 2) || (abs(x2 - x1) == 2 && abs(y2 - y1) == 1)) printf("horse");

	}
}