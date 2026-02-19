#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
int prime(int a, int n) {

    int RN;

    while (1) {
        RN = rand() % a;

        if (RN < a / 10) continue;

        int n0=0,n1=0,n2=0,n3=0,n4=0,n5=0,n6=0,n7=0,n8=0,n9=0;
        int x = RN, c;


        for (int i = 0; i < n; i++) {
            c = x % 10; x /= 10;
            switch (c) {
                case 0: n0++; break;
                case 1: n1++; break;
                case 2: n2++; break;
                case 3: n3++; break;
                case 4: n4++; break;
                case 5: n5++; break;
                case 6: n6++; break;
                case 7: n7++; break;
                case 8: n8++; break;
                case 9: n9++; break;
            }
        }


        if (n0<=1 && n1<=1 && n2<=1 && n3<=1 && n4<=1 &&
            n5<=1 && n6<=1 && n7<=1 && n8<=1 && n9<=1) {
            return RN;
            }

    }

}
int main() {
    int n, a, num;

    printf("Введите размер числа от 2 до 5\n");
    scanf("%d", &n);
    int arr[n], b[n];
    a = pow(10, n);
    srand(time(NULL));

    int randomNumber;

    randomNumber = prime(a, n);

    printf("%d\n", randomNumber);// для удобства проверки
    int secret = randomNumber;
    for (int i = n - 1; i >= 0; i--) {
        arr[i] = randomNumber % 10;
        randomNumber = randomNumber / 10;

    }
    printf("Введи число\n");
    do {
        scanf("%d", &num);
        if (num > a || num < a/10) {
            printf("Выход за границы, попробуйте снова\n");
            continue;
        }
        int number = num;
        for (int i = n - 1; i >= 0; i--) {
            b[i] = number % 10;
            number = number / 10;
        }
        for (int i = 0; i < n; i++) {
            if (b[i] == arr[i]) {
                printf("2");
                continue;
            }
            int flag = 0;
            for (int j = 0; j < n; j++) {
                if (arr[j] == b[i]) {
                    printf("1");
                    flag = 1;
                    break;

                }
            }
            if (!flag) {
                printf("0");
            }
        }
    printf("\n");

    } while (num != secret);


    return 0;




}