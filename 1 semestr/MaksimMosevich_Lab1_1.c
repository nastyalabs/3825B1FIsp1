#include <stdio.h>
#include <math.h>
#include <stdlib.h>


void main(){
    int x1, y1, x2, y2;

    printf("V moem reshenie koordinata x - ne bukva(kak na real'noi doske), a chislo ot 1 do 8\n");

    do{
        printf("Vvedite nachalnuyu koordinatu(x, y), 1 <= x <= 8, 1 <= y <= 8\n");
        scanf("%d %d", &x1, &y1);
        printf("Vvedite konechnuyu koordinatu(x, y), 1 <= x <= 8, 1 <= y <= 8\n");
        scanf("%d %d", &x2, &y2);
    } while(y2 > 8 || y2 < 1 || y1 > 8 || y1 < 1 || x2 > 8 || x2 < 1 || x1 > 8 || x1 < 1 || (x1 == x2 && y1 == y2));


    char figura;
    printf("Vvedite figuru(k - korol', f - ferz', l - lad'ya, s - slon, c - con')\n");
    scanf(" %c", &figura);

    int dy = abs(y2 - y1);
    int dx = abs(x2 - x1);
    
    int status = 0;

    switch (figura){
        case 'k': if (dy <= 1 && dx <= 1) status = 1; break;

        case 'l': if (x1 == x2 || y1 == y2) status = 1; break;

        case 's': if (dy == dx) status = 1; break;
        
        case 'c': if ((dy == 2 && dx == 1) || (dy == 1 && dx == 2)) status = 1; break;

        case 'f': if (x1 == x2 || y1 == y2 ||  dy == dx) status = 1; break;
    }
    
    if (status == 1)
        printf("Figura mojet tuda pereity!");

    else{
        printf("V etom sluchae vivedu spisok teh, kto mojet shodit' v etu tochku:\n");

        char arr[5] = {0};
        int index = 0;

        if (dy <= 1 && dx <= 1)
            arr[index++] = 'k';
        
        if (x1 == x2 || y1 == y2)
            arr[index++] = 'l';
        
        if (dy == dx)
            arr[index++] = 's';
        
        if ((dy == 2 && dx == 1) || (dy == 1 && dx == 2)) 
            arr[index++] = 'c';
        
        if (x1 == x2 || y1 == y2 ||  dy == dx)
            arr[index++] = 'f';
        
        for (int i = 0; i < index; i++){
            printf("%c ", arr[i]);
        }
    }
}