#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int rejim, count_popitok = 0;

    printf("Viberete rejim raboti (1 or 2)\n");
    scanf("%d", &rejim);
    
    if (rejim == 1){
        srand(time(NULL));
        int random_number = rand() % 1001, chislo_polzovatelya;
        
        printf("Vvedite zagadannoe chislo;)\n");
        
        do{
            scanf("%d", &chislo_polzovatelya);
            count_popitok++;
            if (random_number == chislo_polzovatelya){
                printf("Vau! You ugadal s %d popitki", count_popitok);
                return 0;
            }
            else if(chislo_polzovatelya > random_number)
                printf("Tvoe chislo bol'she\n");
            else
                printf("Tvoe chisli malenkoe\n");
        }
        while(chislo_polzovatelya != random_number);       
        
    }
    else if (rejim = 2){
        int random_number;
        printf("Vvedite chislo, kotoroe hotite zagadat, ot 1 do 1000\n");
        scanf("%d", &random_number);

        int arr[1000], chislo = 1;
        for (int i = 0; i < 1000; i++)
            arr[i] = chislo++;
        
        
        char otvet_polzovatelya;
        int l = 0, r = 999;
        while (l <= r){
            int c = (l + r) / 2;
            count_popitok++;
            printf("moe chislo - %d, I ugadal?(vvedite '<' - esli zagadannoe men'she , '>' - esli bol'she, '=' - esli ravno)\n", arr[c]);
            scanf(" %c", &otvet_polzovatelya);

            if (otvet_polzovatelya == '='){
                printf("Ura, I ugadal s %d popitki", count_popitok);
                return 0;
            }
            else if (otvet_polzovatelya == '>')
                l = c + 1;
            else
                r = c - 1;
        }

            

    }
}
