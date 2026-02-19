#include <stdio.h>
#include <math.h>
#include <stdlib.h>



unsigned long long factorial(int number){
    unsigned long long tmp = 1;

    for (int i = 1; i <= number; i++){
        tmp *= (long long)i;
    }

    return tmp;
}

long double my_cos(long double point, int N, int tochnost, int *count_out) {
    point = fmod(point, 2 * 3.14);

    long double res = 0.0L, summ;
    long double epsilont = powl(10.0L, -tochnost);  
    int count = 0;

    for (int i = 0; i < N ; i++) {
        int n_2 = 2 * i;      

        summ = powl(point, n_2) / factorial(n_2);
        
        if (i % 2 == 1)
            summ = -summ;

        res += summ;
        count++;

        if (fabsl(summ) < epsilont) 
            break; 
        if (n_2 > 40) 
            break;
        
    }
    *count_out = count;
    return res;
}
long double my_sin(long double point, int N, int tochnost, int *count_out) {
    point = fmod(point, 2 * 3.14);

    long double res = 0.0L, summ;
    long double epsilont = powl(10.0L, -tochnost);  
    int count = 0;

    for (int i = 0; i < N ; i++) {
        int n_2 = 2 * i + 1;     
        summ = powl(point, n_2) / factorial(n_2);
        
        if (i % 2 == 1)
            summ = -summ;

        res += summ;
        count++;

        if (fabsl(summ) < epsilont) 
            break; 
        if (n_2 > 40) 
            break;
        
    }
    *count_out = count;
    return res;
}
long double my_exp(long double point, int N, int tochnost, int *count_out) {
    long double res = 0.0L, summ;
    long double epsilont = powl(10.0L, -tochnost);  
    int count = 0;

    for (int i = 0; i < N ; i++) {
  
        summ = powl(point, i) / factorial(i);
        res += summ;
        count++;

        if (fabsl(summ) < epsilont) 
            break; 
        if (i > 20) 
            break;
        
    }
    *count_out = count;
    return res;
}
long double my_sec(long double point, int N, int tochnost, int *count_out) {
    int steps_cos = 0;
    long double cos_val = my_cos(point, N, tochnost, &steps_cos);

    *count_out = steps_cos;
    return 1.0L / cos_val;
}


int main(){
    int rejim, steps;

    printf("Vvdeti rejim raboti programmi(1 or 2)\n");
    scanf("%d", &rejim);
    
    long double point_for_value;

    if (rejim == 1){
        
        int func_polz, number_slagaemih, tochnost;

        printf("Viberete function(1 - sin(x), 2 - cos(x), 3 - exp(x), 4 - sec(x)\n");
        scanf("%d", &func_polz);
        
        printf("Vvedite tochku, v kotoroi hotite uznat' znachenie func.\n");
        scanf("%Lf", &point_for_value);

        printf("Vvedite tochnost vichisleniy(napishte N, (1/10) ^ N)\n");
        scanf("%d", &tochnost);

        printf("Vvedite chislo(1 - 1000) elementov ryada, v kotoryi budet razlogena vasha func.\n");
        scanf("%d", &number_slagaemih);

        long double r;
        switch(func_polz){
            case 1: 
                r = my_sin(point_for_value, number_slagaemih, tochnost, &steps);
                printf("Etallonnoe znachenie - %.25Lf, znachenie moey func - %.25Lf, raznitsya %.25Lf,\nkol-o slagaemih c razlojenii %d\n", sinl(point_for_value), r, fabsl(sinl(point_for_value) - r), steps);
                break;
            case 2: 
                r = my_cos(point_for_value, number_slagaemih, tochnost, &steps);
                printf("Etallonnoe znachenie - %.25Lf, znachenie moey func - %.25Lf, raznitsya %.25Lf,\nkol-o slagaemih c razlojenii %d\n", cosl(point_for_value), r, fabsl(cosl(point_for_value) - r), steps);
                break;
            case 3: 
                r = my_exp(point_for_value, number_slagaemih, tochnost, &steps);
                printf("Etallonnoe znachenie - %.25Lf, znachenie moey func - %.25Lf, raznitsya %.25Lf,\nkol-o slagaemih c razlojenii %d\n", expl(point_for_value), r, fabsl(expl(point_for_value) - r), steps);
                break;
            case 4:
                r = my_sec(point_for_value, number_slagaemih, tochnost, &steps);
                printf("Etallonnoe znachenie - %.25Lf, znachenie moey func - %.25Lf, raznitsya %.25Lf,\nkol-o slagaemih c razlojenii %d\n", 1/cosl(point_for_value), r, fabsl(1/cosl(point_for_value) - r), steps);
                break;
        }
    }

    else if (rejim == 2){

        int func_polz, NMax;

        printf("Viberete function(1 - sin, 2 - cos, 3 - exp, 4 - sec)\n");
        scanf("%d", &func_polz);

        printf("Vvedite tochku, v kotoroi hotite uznat' znachenie func.\n");
        scanf("%Lf", &point_for_value);

        printf("Vvedite NMax (1–25)\n");
        scanf("%d", &NMax);

        if (NMax < 1)
            NMax = 1;
        if (NMax > 25)
            NMax = 25;

        long double etalon;

        switch(func_polz){
            case 1: etalon = sinl(point_for_value); break;
            case 2: etalon = cosl(point_for_value); break;
            case 3: etalon = expl(point_for_value); break;
            case 4: etalon = 1.0L / cosl(point_for_value); break;
        }

        printf("\nEtalonnoe znachenie: %.25Lf\n\n", etalon);
        printf(" n |         approx                |        diff\n");
       

        int tochnost = 25;

        for (int n = 1; n <= NMax; n++){
            int steps_local = 0;
            long double approx;

            if (func_polz == 1)
                  approx = my_sin(point_for_value, n, tochnost, &steps_local);
            else if (func_polz == 2)
                approx = my_cos(point_for_value, n, tochnost, &steps_local);
            else if (func_polz == 3)
                approx = my_exp(point_for_value, n, tochnost, &steps_local);
            else if (func_polz == 4)
                approx = my_sec(point_for_value, n, tochnost, &steps_local);

            long double diff = fabsl(approx - etalon);

            printf("%d | %.25Lf | %.25Lf\n", n, approx, diff);
        }

     
    }

}