#define _CRT_SECURE_NO_WARNINGS
#include<math.h>
#include<stdio.h>

//Задача 1
void main() {
	double h, d, w;
	double const pDSP = 0.735;    //в г/см^2
	double const pDVP = 0.8;    //в г/см^2
	double const pderev = 0.6;  //в г/см^2
	double const tol_st = 0.5;  //в см
	double const tol_bok = 1.5;  //в см
	double const tol_cr = 1.5;  //в см
	double const tol_dv = 1;  //в см
	double const tol_pol = 0.5;  //в см


	printf("Cabinet weight counter\n");
	printf("----------------------\n");

	printf("Enter the desired cabinet height h(180-220 cm): ");
	scanf("%lf", &h);

	printf("Enter the desired cabinet width w(80-120 cm): ");
	scanf("%lf", &w);

	printf("Enter the desired cabinet depth d(50-90 cm): ");
	scanf("%lf", &d);

	if (h < 180 || h > 220 || w < 80 || w > 120 || d < 50 || d > 90) {
		printf("The entered parameters do not meet the requirements!\n");
		return 1;
	}

	double mas_st = (h * tol_st * w) * pDVP;
	double mas_bok = 2 * (h * tol_bok * d) * pDSP;
	double mas_cr = 2 * (d * tol_cr * w) * pDSP;
	double mas_dv = (h * tol_dv * w) * pderev;
	double mas_pol = (d * tol_pol * w) * pDSP;   //масса одной полки

	double mas_res = mas_st + mas_bok + mas_cr + mas_dv + floor((h - 2 * tol_cr) / 40.5) * mas_pol;  //на высоту от 180 до 220 см - толщина крышек сверху и снизу деленное на толщину полок и расстояние между ними
	printf("Total weight = %lf", mas_res / 1000);  //масса в кг

}


//Задача 2
// мне нужно знать входные данные, и кого он выбрал (король, королева, ладья - башня, конь, слон) поле 8*8
void main() {
	// начальные координаты: Ox1, Oy1; конечные координаты: Ox2, Oy2
	printf("Enter the initial position of the shape (A = 1, B = 2...): \n");

	int Ox1 = 0, Oy1 = 0;

	printf("Ox1(A(1)-H(8)) = "); scanf("%d", &Ox1);
	printf("Oy1(1-8) = "); scanf("%d", &Oy1);

	printf("Enter the final position of the shape (A = 1, B = 2...): \n");

	int Ox2 = 0, Oy2 = 0;

	printf("Ox2(A(1)-H(8)) = "); scanf("%d", &Ox2);
	printf("Oy2(1-8) = "); scanf("%d", &Oy2);

	//выбор фигуры: (король - 1, королева - 2, башня - 3, слон - 4, конь - 5
	printf("Choose a shape (King - 1, Queen - 2, Rook - 3, Bishop - 4, Knight - 5): \n");

	int shape = 0;

	printf("Shape = "); scanf("%d", &shape);

	//разница координат
	int Ox = abs(Ox2 - Ox1);
	int Oy = abs(Oy2 - Oy1);

	//законстантим фигурам свои номера
	enum shape {
		King = 1,
		Queen = 2,
		Rook = 3,
		Bishop = 4,
		Knight = 5,
	};

	//проверка
	if (Ox1 < 1 || Ox2 < 1 || Oy1 < 1 || Oy2 < 1 || Ox1 > 8 || Ox2 > 8 || Oy1 > 8 || Oy2 > 8 || shape < 1 || shape > 5) {
		printf("Incorrect input, try again");
		return 0;
	}
	else if (Ox == 0 && Oy == 0) {
		printf("The starting and ending positions are the same, and the shapes cannot move in this way, try again");
		return 0;
	}

	//всевозможные исходы
	else if (Ox == 0 || Oy == 0 || Ox == Oy) {
		if (shape == Queen) {
			printf("Chosen shape can move to that space\n");
		}
		else {
			printf("Queen can move to that space\n");
		}


		if (Ox <= 1 && Oy <= 1) {
			if (shape == King) {
				printf("Chosen shape can move to that space\n");
			}
			else {
				printf("King can move to that space\n");
			}
		}

		if (Ox == 0 || Oy == 0) {
			if (shape == Rook) {
				printf("Chosen shape can move to that space\n");
			}
			else {
				printf("Rook can move to that space\n");
			}
		}

		if (Ox == Oy) {
			if (shape == Bishop) {
				printf("Chosen shape can move to that space\n");
			}
			else {
				printf("Bishop can move to that space\n");
			}
		}

		if ((Ox == 2 && Oy == 1) || (Ox == 1 && Oy == 2)) {
			if (shape == Knight) {
				printf("Chosen shape can move to that space\n");
			}
			else {
				printf("Knight can move to that space\n");
			}
		}
	}

	else {
		printf("No piece can reach that position in one move.\n");
	}
}
