#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265358979323846L

long double taylor_sin(long double x, int N, long double calculation_accuracy, int* used_count)
{
	long double TWO_PI = PI * 2.0L; 
	x = fmodl(x, TWO_PI);
	if (x > PI)
	{
		x = x - TWO_PI;
	}
	else if (x < -PI)
	{
		x = x + TWO_PI;
	}

	long double result = x; 
	long double term = x; 
	*used_count = 1;

	for (int i = 1; i < N; i++)
	{
		term = -term * x * x / ((2.0L * i) * (2.0L * i + 1.0L)); 
		result = result + term;
		(*used_count)++;
		if (fabsl(term) < calculation_accuracy)
		{
			break;
		}
	}
	return result;

}
long double taylor_cos(long double x, int N, long double calculation_accuracy, int* used_count)
{
	long double TWO_PI = PI * 2.0L; 
	x = fmodl(x, TWO_PI);
	if (x > PI)
	{
		x = x - TWO_PI;
	}
	else if (x < -PI)
	{
		x = x + TWO_PI;
	}


	long double result = 1.0L; 
	long double term = 1.0L;
	*used_count = 1;

	for (int i = 1; i < N; i++)
	{
		term = -term * x * x / ((2.0L * i) * (2.0L * i - 1.0L));
		result = result + term;
		(*used_count)++;
		if (fabsl(term) < calculation_accuracy)
		{
			break;
		}
	}
	return result;
}
long double taylor_exp(long double x, int N, long double calculation_accuracy, int* used_count)
{
	long double result = 1.0L;  
	long double term = 1.0L; 
	*used_count = 1;

	for (int i = 1; i < N; i++)
	{
		term = term * (x / i);
		result = result + term;
		(*used_count)++;
		if (fabsl(term) < calculation_accuracy)
		{
			break;
		}
	}
	return result;
}
long double taylor_sh(long double x, int N, long double calculation_accuracy, int* used_count)
{
	long double result = x;  
	long double term = x; 
	*used_count = 1;

	for (int i = 1; i < N; i++) {
		term = term * x * x / ((2.0L * i) * (2.0L * i + 1.0L));
		result = result + term;
		(*used_count)++;
		if (fabsl(term) < calculation_accuracy)
		{
			break;
		}
	}
	return result;
}

void serial_experiment(int function_choice, long double x, int Nmax)
{
	
	printf("%-20s %-30s %-30s\n", "Count of elements", "Our calculation", "Difference");

	for (int n = 1; n <= Nmax; n++)
	{
		int used_count;
		long double intermediate_value = 0.0L;
		long double difference = 0.0L;

		switch (function_choice)
		{
		case 1:
			intermediate_value = taylor_sin(x, n + 1, 0.0L, &used_count);
			difference = fabsl(intermediate_value - sinl(x));
			printf("%-20d %-30.15Lf %-25.20Lf\n", n, intermediate_value, difference);
			break;
		case 2:
			intermediate_value = taylor_cos(x, n + 1, 0.0L, &used_count);
			difference = fabsl(intermediate_value - cosl(x));
			printf("%-20d %-30.15Lf %-25.20Lf\n", n, intermediate_value, difference);
			break;
		case 3:
			intermediate_value = taylor_exp(x, n + 1, 0.0L, &used_count);
			difference = fabsl(intermediate_value - expl(x));
			printf("%-20d %-30.15Lf %-25.20Lf\n", n, intermediate_value, difference);
			break;
		case 4:
			intermediate_value = taylor_sh(x, n + 1, 0.0L, &used_count);
			difference = fabsl(intermediate_value - sinhl(x));
			printf("%-20d %-30.15Lf %-25.20Lf\n", n, intermediate_value, difference);
			break;
		}

	}

}

int main()
{
	int work_choose, function_choose;
	printf("Choose mode of programm:\n1. One-time calculation of the function at your point\n2. Serial expirement\n----> "); scanf_s("%d", &work_choose); printf("\n"); if (work_choose != 1 && work_choose != 2) { printf("Choose 1 or 2, please"); }
	switch (work_choose)
	{
	case 1:
	{
		int N, used_count;
		long double x, calculation_accuracy;
		printf("Choose function:\n1. sin(x)\n2. cos(x)\n3. exp(x)\n4. sh(x)\n----> "); scanf_s("%d", &function_choose); printf("\n"); if (function_choose < 1 || function_choose>4) { printf("Choose something from list on your screen, please"); break; }
		printf("Choose point x:\n----> "); scanf_s("%Lf", &x); printf("\n");
		printf("Choose calculation accuracy (0.000001 and more):\n----> "); scanf_s("%Lf", &calculation_accuracy); printf("\n"); if (calculation_accuracy > 0.00001) { printf("Enter a accuracy more than 0.00001, please"); break; }
		printf("Choose count of elements in the Taylor series (1-1000):\n----> "); scanf_s("%d", &N); printf("\n"); if (N < 1 || N>1000) { printf("Select count in the range from 1 to 1000, please"); break; }
		switch (function_choose)
		{
		case 1:
		{
			printf("Our calculation: %.20Lf\n", taylor_sin(x, N, calculation_accuracy, &used_count));
			printf("Etalon sin: %.20Lf\n", sinl(x));
			printf("Difference: %.20Lf\n", fabsl(taylor_sin(x, N, calculation_accuracy, &used_count) - sinl(x)));
			printf("Count of used elements in the Taylor series: %d", used_count);
			break;

		}
		case 2:
		{
			printf("Our calculation: %.20Lf\n", taylor_cos(x, N, calculation_accuracy, &used_count));
			printf("Etalon cos: %.20Lf\n", cosl(x));
			printf("Difference: %.20Lf\n", fabsl(taylor_cos(x, N, calculation_accuracy, &used_count) - cosl(x)));
			printf("Count of used elements in the Taylor series: %d", used_count);
			break;
		}
		case 3:
		{
			printf("Our calculation: %.20Lf\n", taylor_exp(x, N, calculation_accuracy, &used_count));
			printf("Etalon exp: %.20Lf\n", expl(x));
			printf("Difference: %.20Lf\n", fabsl(taylor_exp(x, N, calculation_accuracy, &used_count) - expl(x)));
			printf("Count of used elements in the Taylor series: %d", used_count);
			break;
		}
		case 4:
		{
			printf("Our calculation: %.20Lf\n", taylor_sh(x, N, calculation_accuracy, &used_count));
			printf("Etalon sh: %.20Lf\n", sinhl(x));
			printf("Difference: %.20Lf\n", fabsl(taylor_sh(x, N, calculation_accuracy, &used_count) - sinhl(x)));
			printf("Count of used elements in the Taylor series: %d", used_count);
		}
		default: break;
		}
		break;
	}
	case 2:
	{
		int Nmax;
		long double x;
		printf("Choose function:\n1. sin(x)\n2. cos(x)\n3. exp(x)\n4. sh(x)\n----> "); scanf_s("%d", &function_choose); printf("\n"); if (function_choose < 1 || function_choose>4) { printf("Choose something from list on your screen, please"); break; }
		printf("Choose point x:\n----> "); scanf_s("%Lf", &x); printf("\n");
		printf("Choose count of experiments (0-25) (count of elements in the Taylor series):\n----> "); scanf_s("%d", &Nmax); printf("\n"); if (Nmax < 0 || Nmax>25) { printf("Enter count of experiments in the range 0-25, please"); break; }
		switch (function_choose)
		{
		case 1:
		{
			printf("Etalon sin: %.20Lf\n", sinl(x));
			serial_experiment(function_choose, x, Nmax);
			break;
		}
		case 2:
		{
			printf("Etalon cos: %.20Lf\n", cosl(x));
			serial_experiment(function_choose, x, Nmax);
			break;
		}
		case 3:
		{
			printf("Etalon exp: %.20Lf\n", expl(x));
			serial_experiment(function_choose, x, Nmax);
			break;
		}
		case 4:
		{
			printf("Etalon sh: %.20Lf\n", sinhl(x));
			serial_experiment(function_choose, x, Nmax);
			break;
		}
		break;
		}
	default: break;
	}
	return 0;
	}
	return 0;
}
