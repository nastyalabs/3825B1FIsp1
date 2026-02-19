#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int n, min_val, max_val;
    int avn;
    printf("vvedite n ot 2 do 5: ");
    scanf_s("%d", &n);

    switch (n) {
    case 2:  min_val = 10;  max_val = 99; break;
    case 3:  min_val = 100;  max_val = 999; break;
    case 4:  min_val = 1000;  max_val = 9999; break;
    case 5:  min_val = 10000;  max_val = 99999; break;
    default: printf("Nekorrektnye dannye\n"); return 1;
    }

    int randomNum = (rand() % (max_val - min_val + 1)) + min_val;
    printf("%d\n", randomNum);
    int bik = 0;
    while (bik != n) {
        printf("Vvedite chislo: ");
        scanf_s("%d", &avn);

        int kor = 0;
        int randomNum2 = randomNum;
        int avn2 = avn;
        bik = 0;

        for (int i = 0; i < n; i++) {
            int sr = avn2 % 10;
            int srrn = randomNum2 % 10;

            if (sr == srrn) {
                bik += 1;
            }
            else {
                int randomNum3 = randomNum;
                for (int j = 0; j < n; j++) {
                    int srrn2 = randomNum3 % 10;
                    if (sr == srrn2) {
                        kor += 1;
                        break;
                    }
                    randomNum3 /= 10;
                }
            }

            randomNum2 /= 10;
            avn2 /= 10;
        }

        printf("korov kolvo: %d \n", kor);
        printf("bik kolvo: %d \n", bik);
    }

    printf("pravilno!!!!\n");

    return 0;
}