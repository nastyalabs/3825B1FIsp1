#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1001

void main(){  
    printf("select the mode \n");
    srand(time(NULL));
    int choice;
    scanf_s("%d", &choice);
    switch (choice)
    {
    case 1:
    {  
        printf("guess the number \n");
        int value = 1 + rand() % N;  
        int guess;  
        
        while (guess != value){
            scanf_s("%d", &guess);
            if (guess < value){
                printf("more \n");
            }
            if (guess > value){
                printf("less \n");
            }
        }
        printf("win");
        break;
    }

    case 2: 
    {
        printf("make a number \n");
        int num;
        scanf_s("%d", &num);
        if (num < 1 || num > 1000){
            printf("incorrect values");
            break;
        }
        
        int v;
        int max = 1001, min = 1;
        char znak;
        
        do
        {
            v = min + rand() % (max - min);
            printf("is it %d? (>/</=): ", v);
            scanf_s(" %c", &znak); 
            
            switch (znak)
            {
            case '>':
                min = v + 1;
                break;
            case '<':
                max = v;
                break;
            case '=':
                if (v == num) {
                    printf("computer win\n");
                } else {
                    printf("you lied\n");
                }
                break;
            default:
                printf("use >, < or =\n");
                break;
            }
        } while (znak != '=');
        
        break;
    }
    
    default:
        printf("invalid choice\n");
        break;
    }
    

}