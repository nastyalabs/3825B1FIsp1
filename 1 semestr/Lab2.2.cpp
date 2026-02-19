#include <stdio.h>
#include <locale.h>
#define MAX 1000

void main() {
	setlocale(LC_ALL, "Rus");
	char g[MAX];
	int i=0, k = 0, h = 0;
	printf("ֲגוהטעו סטלגמכû\n");
	do {
		scanf_s("%c", &g[i], 1);
		i++;
	} while (g[i - 1] != '\n' && g[i - 1] != '\r');
	
	int y = i - 1;
	for (i=0; i < y; i++) {
		if (g[i] != ' ' && g[i] != '\t')
			k++;
		else {
			if (k != 0) {
				k = 0;
				h++;
			}	
		}
	}
	if (k != 0)
		h++;
	printf("%d", h);
}