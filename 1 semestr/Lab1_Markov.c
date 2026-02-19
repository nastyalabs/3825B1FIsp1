#include<stdio.h>
#include<locale.h>
#include<math.h>

const float Plot_DSP = 0.6, Plot_DVP = 0.5, Plot_Derevo = 0.8;

char figures[5][10] = {"Король", "Ферзь", "Ладья", "Слон", "Конь"};

int check_king(int x1, int y1, int x2, int y2) {
	return (abs(x1 - x2) <= 1 && abs(y1 - y2) <= 1);
}

int check_queen(int x1, int y1, int x2, int y2) {
	return ((x1 == x2) || (y1 == y2) || (abs(x1 - x2) == abs(y1 - y2)));
}

int check_ladya(int x1, int y1, int x2, int y2) {
	return (x1 == x2 || y1 == y2);
}

int check_slon(int x1, int y1, int x2, int y2) {
	return (abs(x1 - x2) == abs(y1 - y2));
}

int check_horse(int x1, int y1, int x2, int y2) {
	return ((abs(x1 - x2) == 1 && abs(y1 - y2) == 2) || (abs(x1 - x2) == 2 && abs(y1 - y2) == 1));
}


int main() {
	setlocale(LC_ALL, "Russian");

	// Задание 1 - масса шкафа
	/*
	float h = 0.0, w = 0.0, d = 0.0;
	printf("Введи параметры h w d в см: ");
	scanf(" %f %f %f", &h, &w, &d);
	if (h < 180 || h > 220 || w < 80 || w > 120 || d < 50 || d > 90) {
		printf("Введены некорректные параметры!\n");
		return 0;
	}
	float M = 0.0;
	M += (h * w * 0.5) * Plot_DVP; //задняя стенка
	M += 2 * (h * d * 1.5) * Plot_DSP; // две боковины
	M += 2 * (w * d * 1.5) * Plot_DSP; // накладные крышки
	M += h * w * Plot_Derevo; // накладные двери
	M += ceil(h / 40) * w * d * Plot_DSP; // внутренние полки
	M /= 1000; // переводим в килограммы
	printf("Масса шкафа: %.2f килограммов", M);
	*/

	// Задание 1' - шахматы

	char p1, p2, figure;
	int y1 = 0, y2 = 0, x1, x2;

    do{
        printf("Введите координаты первой клетки через пробел: ");
        scanf(" %c %d", &p1, &y1);
        x1 = p1 - 'A' + 1;
        if (x1 > 8 || x1 < 0 || y1 > 8 || y1 < 0){
            printf("\nВведите корректные координаты\n\n");
        }
    }
    while(x1 > 8 || x1 < 0 || y1 > 8 || y1 < 0);

	do{
        printf("\nВведите координаты второй клетки через пробел: ");
        scanf(" %c %d", &p2, &y2);
        x2 = p2 - 'A' + 1;
        if (x2 > 8 || x2 < 0 || y2 > 8 || y2 < 0){
            printf("\nВведите корректные координаты\n");
        }
    }
    while(x2 > 8 || x2 < 0 || y2 > 8 || y2 < 0);

	int f = 1;
	printf("\nВыберите фигуру\nПодсказка:\nK - Король\nF - ферзь\nL - ладья\nS - слон\nH - конь\nВведите тип фигуры: ");
	scanf(" %c", &figure);

	switch (figure) {
	case 'K':
		if (check_king(x1, y1, x2, y2)) {
			printf("\nКороль может перейти за один ход\n");
			f = 0;
		}
		break;
	case 'F':
		if (check_queen(x1, y1, x2, y2)) {
			printf("\nФерзь может перейти за один ход\n");
			f = 0;
		}
		break;
	case 'L':
		if (check_ladya(x1, y1, x2, y2)) {
			printf("\nЛадья может перейти за один ход\n");
			f = 0;
		}
		break;
	case 'S':
		if (check_slon(x1, y1, x2, y2)) {
			printf("\nСлон может перейти за один ход\n");
			f = 0;
		}
		break;
	case 'H':
		if (check_horse(x1, y1, x2, y2)) {
			printf("\nКонь может перейти за один ход\n");
			f = 0;
		}
		break;
	default:
		printf("\nНеизвестный тип фигуры\n");
		f = 0;
		break;
	}
	
	int arr[5] = { 0, 0, 0, 0, 0 };
	int f1 = 0;
	if (f) {
		if (check_king(x1, y1, x2, y2)) {
			arr[0]++; f1++;
		}
		if (check_queen(x1, y1, x2, y2)) {
			arr[1]++; f1++;
		}
		if (check_ladya(x1, y1, x2, y2)) {
			arr[2]++; f1++;
		}
		if (check_slon(x1, y1, x2, y2)) {
			arr[3]++; f1++;
		}
		if (check_horse(x1, y1, x2, y2)) {
			arr[4]++; f1++;
		}
	}

	if (f && f1) {
		printf("\nСовершить данный ход могут следующие фигуры: ");
		for (int i = 0; i < 5; i++) {
			if (arr[i]) {
				printf("%s ", figures[i]);
			}
		}
		printf("\n");
	}
	else if (f && !f1) {
		printf("\nНи одна фигура не может совершить данный ход\n");
	}

	return 0;
}
