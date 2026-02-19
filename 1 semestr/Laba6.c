#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define M_PI 3.14159265358979323846
#include <locale.h>


//функция для обработки точности 
double toch(int p)
{
	double d = 1;
	for (int i = 0; i < p;i++)
	{
		d = 0.1 * d;
	}
	if (p == 0) { d = 1; }
	if (p < 1) { d = 0.000000000001; }
	return d;
}


// фунция для расчета факториала
double fac(int n)
{
	
	
	double result = 1.0;
	for (int i = 2; i <= n; i++) {
		result *= i;
	}
	return result;
}


//функции для разложения на Тейлора

///
double cost(double x, double N, double pip )

{
	int max = (int)N;
	
	double d_f = 0.0, delt = 1.0;
	pip = toch(pip);
	x = fmod(x, 2 * M_PI);
	for (int n = 0; n < max;n++)
	{
		
		
		//формула расчета элемента ряда
		double i = (double)n;
		double del = (fac(2 * i));
		double delit = (pow((-1), i) * pow(x, 2 * i));
		delt = delit / del;
		
		
		
		//сумма ряда
		d_f = d_f + delt;
		
		
		//проверка на точность
		double delta_TM = fabs(d_f) - fabs(cos(x));
		
		if (fabs(delta_TM) <= pip) { d_f = d_f ;break; }

		
		
		
	}

	return d_f;
}
///
double sint(double x, int max_iter, double epsilon)
{
	x = fmod(x, 2 * M_PI);
	double term = x; 
	double sum = term;
	double x_sq = x * x;

	for (int n = 1; n <= max_iter; n++)
	{
		// вычисляем следующий член рекуррентно
		term = term * (-x_sq) / ((2 * n) * (2 * n + 1));
		sum += term;

		if (fabs(term) < epsilon) break;
	}

	return sum;
}

int ctgt(double x, double N, double pip){
	double sin_val = sint(x, N, pip);
	double cos_val = cost(x, N, pip);

	// Проверка на нулевой синус
	if (fabs(sin_val) < 1e-12) {
		printf("Ошибка: синус слишком близок к нулю\n");
		return NAN;
	}

	return cos_val / sin_val;
}




// функция экспоненты 
double expt(double x, int max_n, double eps)
{
	double result = 0.0;
	double term = 1.0; // первый член ряда при n=0

	for (int n = 0; n <= max_n; n++)
	{
		result += term;

		// следующий член ряда рекуррентно
		if (n < max_n) {
			term = term * x / (n + 1);
		}

		

		if (fabs(term) <= eps) {
			
			break;
		}
	}

	return result;
}

/// 





//функц котангенса
int ctg(double x)
{
	double res;
	res = cos(x) / sin(x);
	return res;
}

void onemain()
{
	
	int inp, pip;
	double x, N, res_Tail, res_Math;
	printf("\n\n---------------------\nВведите точку для расчета\n---> ");
	//gif dotch
	scanf_s("%lf", &x);

	//gif tochnost 
	
	printf("\nВведите желаемое количкство знаков после запятой 1-6 \n---> ");
	do {

		scanf_s("%d", &pip);

		if (pip < 1 || pip > 6) { inp = 0; printf("\nВведите значение от 0 до 6\n---> "); }
		else { inp = 1; }
	} while (inp == 0);

	// gif N  количество разбиений
	printf("\nВведите элементов ряда от 1 до 1000\n---> ");
	
	do {

		scanf_s("%lf", &N);

		if (pip < 0 || pip > 1000) { inp = 0; printf("\nВведите значение от 0 до 1000\n---> "); }
		else { inp = 1; }

	} while (inp == 0);

	

	// Выбор функции
	printf("\nВыберете функцию :\n1. cos(x) \n2. exp(x) \n3. ctg(x) \n---> ");
	do {

		scanf_s("%d", &inp);
		switch (inp)
		{
		case 1:
			res_Tail = cost(x, N, pip);
			res_Math = cos(x);
			break;
		case 2:
			res_Tail = expt(x, N, pip);
			res_Math = exp(x);
			break;
		case 3:
			res_Tail = ctgt(x, N, pip);
			res_Math = ctg(x);
			break;
		}
		if (inp < 1 || inp > 3) { inp = 0; printf("\nВведите корректное значение\n---> "); }
		else { inp = 1; }

	} while (inp == 0);
	double dlta = abs((res_Math - res_Tail));
	printf("\n---Вывод---\n");
	printf("*Эталонный результат = %.*f\n",pip, res_Math);
	printf("*Ряд Тейлора = %.*f\n", pip,res_Tail );
	printf("*Количество элементов в р. Телора = %d\n",(int) N);
	printf("*Разница эталона и полученного =%f\n",fabs(dlta) );
	printf("\n---------------------");
	
}

void moremain()
	{
		int func_choice, NMax;
		double x;
		int inp;

		printf("\n\n=====================\n");
		printf("СЕРИЙНЫЙ ЭКСПЕРИМЕНТ\n");
		printf("=====================\n");

		// Выбор функции
		printf("\nВыберите функцию:\n1. cos(x) \n2. exp(x) \n3. ctg(x) \n---> ");
		do {
			scanf_s("%d", &func_choice);
			if (func_choice < 1 || func_choice > 3) {
				printf("\nВведите корректное значение (1-3)\n---> ");
				inp = 0;
			}
			else {
				inp = 1;
			}
		} while (inp == 0);

		// Ввод точки x
		printf("\nВведите точку x для расчета\n---> ");
		scanf_s("%lf", &x);

		// Ввод количества экспериментов (NMax)
		printf("\nВведите число экспериментов (от 1 до 25)\n---> ");
		do {
			scanf_s("%d", &NMax);
			if (NMax < 1 || NMax > 25) {
				printf("\nВведите значение от 1 до 25\n---> ");
				inp = 0;
			}
			else {
				inp = 1;
			}
		} while (inp == 0);

		// Вычисление эталонного значения
		double exact_value;
		switch (func_choice) {
		case 1: exact_value = cos(x); break;
		case 2: exact_value = exp(x); break;
		case 3: exact_value = ctg(x); break;
		}

		printf("\n=== РЕЗУЛЬТАТЫ ===\n");
		printf("Эталонное значение: %.10f\n\n", exact_value);
		printf("%-12s %-25s %-25s\n", "Кол-во слаг.", "Оценка функции", "Разница с эталоном");
		printf("-----------------------------------------------------------\n");

		// Вычисление и вывод таблицы
		for (int n = 1; n <= NMax; n++) {
			double approximation;

			// Используем существующие функции с очень маленьким pip (0.000000000001)
			// чтобы отключить проверку точности и гарантировать использование n слагаемых
			double tiny_pip = 0.000000000001; // 10^-12

			switch (func_choice) {
			case 1: // cos(x)
				approximation = cost(x, (double)n, tiny_pip);
				break;
			case 2: // exp(x)
				approximation = expt(x, (double)n, tiny_pip);
				break;
			case 3: // ctg(x)
				approximation = ctgt(x, (double)n, tiny_pip);
				break;
			}

			// Проверка на ошибку (например, деление на ноль для ctg)
			if (isnan(approximation)) {
				printf("%-12d %-25s %-25s\n", n, "ОШИБКА", "ОШИБКА");
			}
			else {
				double difference = fabs(exact_value - approximation);
				printf("%-12d %-25.10f %f\n", n, approximation, difference);
			}
		}

		printf("\n=====================\n");
	}







void main()
{
	int in;
	setlocale(0, "Rus");
	
	

	do {
		printf("\n\n\n---------------------\n1 - Однократный расчет функции в заданной точке\n2 - Серийный эксперемент\n0 - Выйти\n---> ");
		
		scanf_s("%d", &in);
		if (in < 0 || in >2) { printf("\n\nПожалуйста, введите корректное значение. "); }
		switch (in)
		{
		case 1:
			onemain();
			break;
		case 2:
			moremain();
			break;
		}

	} while (in != 0);
	printf("\n---------------------");

}
