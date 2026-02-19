#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>

typedef double (*TaylorFunc)(double, double, int, int*);
typedef double (*StandardFunc)(double);

typedef struct {
    const char* name;
    TaylorFunc taylor_calc;
    StandardFunc std_calc;
} MathFunctionList;

double recurrent_sin(double x, double eps, int max_n, int* terms_count) {
    double sum = x;
    double term = x;
    int n = 1;
    
    while (n < max_n && fabs(term) > eps) {
        term *= -1.0 * x * x / ((2.0 * n) * (2.0 * n + 1.0));
        sum += term;
        n++;
    }
    *terms_count = n;
    return sum;
}

double recurrent_cos(double x, double eps, int max_n, int* terms_count) {
    double sum = 1.0;
    double term = 1.0;
    int n = 1;
    
    while (n < max_n && fabs(term) > eps) {
        term *= -1.0 * x * x / ((2.0 * n - 1.0) * (2.0 * n));
        sum += term;
        n++;
    }
    *terms_count = n;
    return sum;
}

double recurrent_exp(double x, double eps, int max_n, int* terms_count) {
    double sum = 1.0;
    double term = 1.0;
    int n = 1;

    while (n < max_n && fabs(term) > eps) {
        term *= x / (double)n;
        sum += term;
        n++;
    }
    *terms_count = n;
    return sum;
}

double recurrent_sec(double x, double eps, int max_n, int* terms_count) {
    int cos_terms;
    double cos_val = recurrent_cos(x, eps, max_n, &cos_terms);
    
    if (fabs(cos_val) < 1e-15) {
        printf("Предупреждение: cos(x) близок к нулю, sec(x) может быть неопределен\n");
        *terms_count = cos_terms;
        return 0.0;
    }
    
    *terms_count = cos_terms;
    return 1.0 / cos_val;
}

double std_sec(double x) {
    double cos_val = cos(x);
    if (fabs(cos_val) < 1e-15) {
        return 0.0;
    }
    return 1.0 / cos_val;
}

int main() {
    setlocale(LC_ALL, "Russian"); 

    MathFunctionList functions[] = {
        {"sin(x)", recurrent_sin, sin},
        {"cos(x)", recurrent_cos, cos},
        {"exp(x)", recurrent_exp, exp},
        {"sec(x)", recurrent_sec, std_sec} 
    };

    printf("      Вычисление функций по ряду Тейлора      \n");
    printf("\nРежимы работы:\n");
    printf("1. Однократный расчет функции\n");
    printf("2. Серийный эксперимент\n");
    printf("0. Выйти из программы\n");
    
    int mode = 1;
    
    while (mode) {
        printf("Выберите режим: ");
        do{
        	scanf(" %d", &mode);
        	if (mode < -1 || mode > 2) printf("Неверный режим.\n");
		}
		while(mode < -1 || mode > 2);
		
		if (mode == 0){
			printf("\nВыход из программы.");
    		break;
		}

        printf("\nВыберите функцию из доступных в списке:\n");
        for (int i = 0; i < 4; i++) {
            printf("%d. %s\n", i + 1, functions[i].name);
        }
        
        int function_number;
        printf("Ваш выбор: ");
        do{
        	scanf(" %d", &function_number);
        	if (function_number < 1 || function_number > 4) printf("Неверный режим. Попробуйте снова.\n");
		}
		while(function_number < 1 || function_number > 4);
        function_number--; 

        double x;
        printf("Введите точку x: ");
        scanf(" %lf", &x);
		
		switch (mode) {
		case 1: {
			double eps;
            int n_max;
            printf("Введите точность вычисления (например, 1e-6): ");
            scanf(" %lf", &eps);
            printf("Введите максимальное число слагаемых в разложении (от 1 до 1000): ");
            do{
        		scanf(" %d", &n_max);
        		if (n_max < 1 || n_max > 1000) printf("Число слагаемых должно быть от 1 до 1000.\n");
			}
			while(n_max < 1 || n_max > 1000);
			
            int count_terms = 0;
            double calc_val = functions[function_number].taylor_calc(x, eps, n_max, &count_terms);
            double ref_val = functions[function_number].std_calc(x);
            double diff = fabs(calc_val - ref_val);

            printf("\nРезультаты для %s в точке %.5f:\n", functions[function_number].name, x);
            printf("Эталонное значение:     %.15f\n", ref_val);
            printf("Вычисленная оценка:     %.15f\n", calc_val);
            printf("Разница:                %.15f\n", diff);
            printf("Количество слагаемых:   %d\n", count_terms);
            printf("Относительная погрешность: %.2e\n", diff / fabs(ref_val > 1e-15 ? ref_val : 1.0));
            printf("\n");
			break;
		}
		case 2:	{
            int n_experiments;
            printf("Введите число экспериментов (от 1 до 25): ");
            do{
        		scanf("%d", &n_experiments);
        		if (n_experiments < 1 || n_experiments > 25) printf("Число экспериментов должно быть от 1 до 25.\n");
			}
			while(n_experiments < 1 || n_experiments > 25);
            
            double ref_val = functions[function_number].std_calc(x);

            printf("\nСерийный эксперимент для %s, x=%.5f\n", functions[function_number].name, x);
            printf("Эталонное значение: %.15f\n\n", ref_val);
            printf("|-------|--------------------|--------------------|\n");
            printf("| %-5s | %-18s | %-18s |\n", "N", "Оценка", "Разница");
            printf("|-------|--------------------|--------------------|\n");

            for (int i = 1; i <= n_experiments; i++) {
                int terms_out = 0;
                double val = functions[function_number].taylor_calc(x, 0.0, i, &terms_out);
                double diff = fabs(val - ref_val);
                printf("| %-5d | %18.10f | %18.10f |\n", i, val, diff);
            }
            printf("|-------|--------------------|--------------------|\n");
            printf("\n");
    		break;
    	}
		}
    }

    return 0;
}
