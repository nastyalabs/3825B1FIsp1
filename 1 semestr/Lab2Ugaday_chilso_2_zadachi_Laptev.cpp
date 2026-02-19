#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int n;
    int max_val, min_val;
    printf("choose rezhim 1 or 2: ");
    scanf_s("%d", &n);
    if (n == 1) {
        int min_val = 1, max_val = 1000;
        int randomNum = (rand() % (max_val - min_val + 1)) + min_val;
        bool otvet = false;
        while (otvet != true) {
            int ch;
            scanf_s("%d", &ch);
            if (ch < randomNum) {
                printf("zagadannoe chislo bolshe: \n");
                otvet = false;
            }
            else if (ch > randomNum) {
                printf("zagadannoe chislo menshe: \n");
                otvet = false;
            }
            else {
                printf("chislo ugadano: \n");
                otvet = true;
                break;
            }
        }
    }
    else if (n == 2) {
        printf("vvedite chislo kotoroe zagadali: ");
        int ch;
        scanf_s("%d", &ch);

        char cha;
        int konlev = 1, konprav = 1000;
        int v;
        v = (konprav + konlev) / 2;
        printf("%d\n", v);
        scanf_s("%c", &cha);
        while (cha != '=') {
            scanf_s("%c", &cha);
            if (cha == '>') {
                konlev = v;
                v = (konprav + konlev) / 2;
                printf("%d\n", v);
                scanf_s("%c", &cha);
            }
            else if (cha == '<') {
                konprav = v;
                v = (konlev + konprav) / 2;
                printf("%d\n", v);
                scanf_s("%c", &cha);
            }
        }
        printf("verno!!!\n");

    }
}