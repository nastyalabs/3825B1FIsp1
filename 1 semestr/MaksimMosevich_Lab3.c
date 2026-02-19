#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int vozvesti_v_stepen(int a, int n){
    int chislo = 1;
    for (int i = 1; i <= n; i++)
        chislo = chislo * a;
    return chislo;
}

char nepovtor_chislo(int a, int n){

    int arr[n], index = 0;
    while (a != 0){
        arr[index++] = a % 10;
        a = a / 10;
    }
    for (int i = 0; i < n; i++){
        for (int j = i + 1; j < n; j++){
            if (arr[i] == arr[j]){
                return '0';
            }    
        }
    }
    return '1';
}

void sravnenie_chisel(int zagadannoe_chislo, int chislo_polz, int n){
    int zag_arr[n], polz_arr[n], index_z = 0, index_p = 0, korovi = 0, bik = 0;

    while (zagadannoe_chislo != 0){
        zag_arr[index_z++] = zagadannoe_chislo % 10;
        zagadannoe_chislo = zagadannoe_chislo / 10;
    }

    while (chislo_polz != 0){
        polz_arr[index_p++] = chislo_polz % 10;
        chislo_polz = chislo_polz / 10;
    }

    for (int i = 0; i < n; i++){
        if (zag_arr[i] == polz_arr[i]){
            bik++;
        }
        else{
            for(int j = 0; j < n; j++){
                if (zag_arr[i] == polz_arr[j] && i != j)
                    korovi++;
            }
        }
    }
    printf("%d korovi, and %d bik\n", korovi, bik);

}
void main(){
    int n, chislo_polz;
    
   
    do{
         printf("Vvedite dlinu zagadimavaemogo slova(2 <= n <= 5\n");
        scanf("%d", &n);
    }while(n < 2 || n > 5);

    srand(time(NULL));
    int min_chislo = vozvesti_v_stepen(10, n-1);
    int max_chislo = vozvesti_v_stepen(10, n) - 1;
    int zagadannoe_chislo = min_chislo + rand() % (max_chislo - min_chislo + 1);
    
    while (nepovtor_chislo(zagadannoe_chislo, n) == '0'){
         zagadannoe_chislo = min_chislo + rand() % (max_chislo - min_chislo + 1);
    }

    int count = 1;
    do{
        printf("Popitaites' otgadat' chsilo - popitka %d\n", count++);
        scanf("%d", &chislo_polz);
        sravnenie_chisel(zagadannoe_chislo, chislo_polz, n);
    } while(chislo_polz != zagadannoe_chislo);

    printf("Ura! You otgadal s %d popitki", count);
}   