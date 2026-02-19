
#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

int figure() {
	int fig=0;
	printf("Выберете фигуру:\n 1 - Король\n 2 - Ферзь\n 3 - Ладья\n 4 - Слон\n 5 - Конь\n-----> ");
	do {
		scanf_s("%d", &fig);
		if (fig < 1 || fig>5) { printf("\nПожалуйста введите число от 1 до 5\n----->"); }

	} while (fig < 1 || fig>5);
	return fig;
}





void main() {

	setlocale(0, "Rus");

	char xy1[3], xy2[3];
	int fig;

	//0- Король\n 1 - Ферзь\n 2 - Ладья\n 3 - Слон\n 4 - Конь\n

	int absol[5] = { 0, 0, 0, 0, 0 };
	int x1, x2, y1, y2,x,y;
	
	fig = figure();

	printf("\nВведите начальную позицию <A1>\n-----> ");
	do {
		
		scanf_s("%s", &xy1,3);
		x1 = xy1[0] - 'A';
		y1 = xy1[1] - '1';
		
		if (x1 < 0 || x1>7 || y1 < 0 || y1>7) { "\nПожалуйста введите корректные значения\n-----> "; }
	} while (x1 < 0 || x1>7 || y1 < 0 || y1>7);

	printf("\nВведите конечную позицию <A1>\n-----> ");
	do {

		scanf_s("%s", &xy2, 3);
		x2 = xy2[0] - 'A';
		y2 = xy2[1] - '1';

		if (x2 < 0 || x2>7 || y2 < 0 || y2>7) { "\nПожалуйста введите корректные значения\n-----> "; }
	} while (x2 < 0 || x2>7 || y2 < 0 || y2>7);

	x = abs(x1 - x2);
	y = abs(y1 - y2);

	//Проверка на достижение цели

	if ((x == 1 && y == 0) || (x == 0 && y == 1) || (x == 1 && y == 1)) { absol[0] = 1; absol[1] = 1; }

	if ((x == 0 && y >= 1 && y <= 7) || (y == 0 && x >= 1 && x <= 7)) { absol[2] = 1;absol[1] = 1; }

	if ((x == y)&& (x!=0)) { absol[3] = 1; absol[1] = 1; }
	
	if ((x == 2 && y == 1) || (y == 2 && x == 1)) { absol[4] = 1;}
	
	if (x == y && x == 0) { printf("\nУвы и ах, вы пропустили свой ход :)"); }
	

	if (absol[fig - 1]) { printf("\nВыбранная фигура может попасть в эту позицию"); }
	else { printf("\nВаша фигура не сможет попасть в эту точку"); }
	for (int i=0; i <= 4; i++) {

		if (absol[i]) {
			printf("\n\nВ эту клетку может попасть ----> ");
			switch(i+1) 
			{
				case 1:
					printf("Король ");
					break;
				
				case 2:
					printf("Ферзь ");
					break;

				case 3:
					printf("Ладья ");
					break;

				case 4:
					printf("Слон ");
					break;

				case 5:
					printf("Конь ");
					break;
			}

			
		}
	}


}