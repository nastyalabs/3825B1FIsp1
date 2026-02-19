#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

#define PI 3.14159265358979323846
//указатель на функцию эталонного решения
typedef double(*EtalFunc)(double x);
//указатнель на функцию вычисдениия ряд Тейлора
typedef double(*TeyFunc)(double x, int n, int *cnt_slag);
//структура для хранения инфы о функции
typedef struct {
	const char* name;
	EtalFunc etal_func;
	TeyFunc tey_fanc;
	double min_x;//минимально допустимое значение
	double max_x;//максимально допустимое значение
}FuncInfo;
//доступные функции
enum FuncType {
	FUNC_SIN,
	FUNC_COS,
	FUNC_EXP,
	FUNC_LN,
	FUNC_CNT
};
//прототипы функций
void menu(void);
FuncInfo* get_func(enum FuncType func_type);
double tey_sin(double x, int n, int* cnt_slag);
double tey_cos(double x, int n, int* cnt_slag);
double tey_exp(double x, int n, int* cnt_slag);
double tey_ln(double x, int n, int* cnt_slag);
void rezim1(void);
void rezim2(void);

//создадим функции
//эталонные функции
double etal_sin(double x) { return sin(x); }
double etal_cos(double x) { return cos(x); }
double etal_exp(double x) { return exp(x); }
double etal_ln(double x) {
	if (x <= 0) return NAN;
	return log(x);
}

//ряды Тейлора
double tey_sin(double x, int n, int* cnt_slag) {
	double result = 0.0;
	double slag = 1.0;
	//приведение числа к диапазону [-p;p]
	while (x > PI) {
		x = x - 2 * PI;
	}
	while (x < -PI) {
		x = x + 2 * PI;
	}
	int i;
	for (i = 0; i < n; i++) {
		result += slag;
		slag = slag * (-x) * x / ((2 * i + 2) * (2 * i + 3));
		if (fabs(slag) < 1e-15) {
			i++;
			break;
		}
	}
	*cnt_slag = i;
	return result;
}

double tey_cos(double x, int n, int* cnt_slag) {
	double result = 0.0;
	double slag = 1.0;
	//приведение числа к диапазону [-p;p]
	while (x > PI) {
		x = x - 2 * PI;
	}
	while (x < -PI) {
		x = x + 2 * PI;
	}
	int i;
	for (i = 0; i < n; i++) {
		result += slag;
		slag = slag * (-x) * x / ((2 * i + 1) * (2 * i + 2));
		if (fabs(slag) < 1e-15) {
			i++;
			break;
		}
	}
	*cnt_slag = i;
	return result;
}

double tey_exp(double x, int n, int* cnt_slag) {
	double result = 0.0;
	double slag = 1.0;

	int i;
	for (i = 0; i < n; i++) {
		result += slag;
		slag = slag * x / (i + 1);
		if (fabs(slag) < 1e-15) {
			i++;
			break;
		}
	}
	*cnt_slag = i;
	return result;
}
//вычисление натурального логарифма через ряды Тейлора при 0<x<2
double tey_ln(double x, int n, int* cnt_slag) {
	if (x <= 0 || x > 2) {
		*cnt_slag = 0;
		return NAN;
	}
	//для x>1: ln(x) = -ln(1/x)
	if (x > 1) {
		double result = -tey_ln(1 / x, n, cnt_slag);
		return result;
	}
	//для 0<x<=1 в окрестности 1
	double z = x - 1; //т.к. x = 1+z, где x<2, поэтому 1<z<1
	double result = 0.0;
	double slag = z;

	int i;
	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {
			result += slag / (i + 1);
		}
		else {
			result -= slag / (i + 1);
		}
		slag = slag * (-z);
		if (fabs(slag / i + 2) < 1e-15) {
			i++;
			break;
		}
	}
	*cnt_slag = i;
	return result;
}
//получение инфы о функции
FuncInfo* get_func(enum FuncType func_type) {
	static FuncInfo func[] = { {"sin(x)", etal_sin, tey_sin, -100, 100}, {"cos(x)", etal_cos, tey_cos, -100, 100}, {"exp(x)", etal_exp, tey_exp, -100, 100}, {"ln(x)", etal_ln, tey_ln, 0.0001, 2} };
	if (func_type >= 0 && func_type < FUNC_CNT) {
		return &func[func_type];
	}
	return NULL;
}
//меню
void menu(void) {
	printf("\nFunction: \n");
	printf("1. sin(x)\n");
	printf("2. cos(x)\n");
	printf("3. exp(x)\n");
	printf("4. ln(x)(0<x<=2)\n");
}

//режим 1
void rezim1(void) {
	int choice, n;
	double x, e, etalon, teylor, difference;
	int cnt_slag = 0;

	menu();
	printf("\nChoice functions(1-4): ");
	scanf("%d", &choice);
	if (choice < 1 || choice > 4) {
		printf("Error. Try again.\n");
		return;
	}
	enum FuncType func_type = choice - 1;
	FuncInfo* func = get_func(func_type);

	printf("Input x: ");
	scanf("%lf", &x);
	//проверка допустимости x
	if (x < func->min_x || x > func->max_x) {
		printf("Error. Try again.\n");
		return;
	}

	printf("Input tochnost (>=0.000001): ");
	scanf("%lf", &e);
	if (e < 0.000001) {
		printf("Error. Try again.\n");
		return;
	}

	printf("Input count slagayem (1-1000): ");
	scanf("%d", &n);
	if (n < 1 || n > 1000) {
		printf("Error. Try again.\n");
		return;
	}

	//вычисление эталонного значения
	etalon = func->etal_func(x);
	//вычисление через ряды
	double cur = 0, prev = 0;
	int i;
	//точность или исчерпание слагаемых
	for (i = 1; i <= n; i++) {
		prev = cur;
		cur = func->tey_fanc(x, n, &cnt_slag);
		//проверка достижения точности
		if (i > 1 && fabs(cur - prev) < e) {
			break;
		}
	}
	teylor = cur;
	difference = teylor - etalon;

	printf("\nResultat\n");
	printf("Function: %s\n", func->name);
	printf("x = %.10f\n", x);
	printf("Tochnost = %.10f", e);
	printf("\nEtalonnoe znachenie: %.10f\n", etalon);
	printf("Teylor znachenie: %.10f\n", teylor);
	printf("Difference znachenie: %.10f\n", difference);
	printf("Count slagaem: %d\n", cnt_slag);
}

//режим 2 
void rezim2() {
	int choice, n_max;
	double x, etalon;

	menu();
	printf("\nChoose function (1-4): ");
	scanf("%d", &choice);

	if (choice < 1 || choice > 4) {
		printf("Error. Try again.\n");
		return;
	}

	enum FuncType func_type = choice - 1;
	FuncInfo* func = get_func(func_type);

	printf("Input x: ");
	scanf("%lf", &x);
	//проверка допустимости x
	if (x < func->min_x || x > func->max_x) {
		printf("Error. Try again.\n");
		return;
	}

	printf("Input count expirience (1-25): ");
	scanf("%d", &n_max);

	if (n_max < 1 || n_max > 25) {
		printf("Error. Try again.\n");
		return;
	}
	//вычисление эталонного значения
	etalon = func->etal_func(x);

	printf("\nResultat\n");
	printf("Function: %s\n", func->name);
	printf("x = %.10f\n", x);
	printf("\nEtalonnoe znachenie: %.10f\n", etalon);
	printf("\n%5s | %25s | %25s\n", "N", "Approximate value", "Difference");

	for (int n = 1; n <= n_max; n++) {
		int cnt_slag;
		double teylor = func->tey_fanc(x, n, &cnt_slag);
		double difference = teylor - etalon;
		printf("%5d | %25.10f | %25.10f\n", cnt_slag, teylor, difference);
	}
}

//основное меню
int main(void) {
	int mode;
	printf("Programm calculation functions for Teylor\n");
	while (1) {
		printf("\nMenu\n");
		printf("1. One-time calculation function\n");
		printf("2. Series expirience\n");
		printf("3. Exit\n");
		printf("Choose rezim: \n");
		scanf("%d", &mode);

		switch (mode) {
		case 1: rezim1();
			break;
		case 2: rezim2();
			break;
		case 3: printf("Exit for programm\n");
			return 0;
		default:
			printf("Not found rezim!\n");
		}
	}
	return 0;
}