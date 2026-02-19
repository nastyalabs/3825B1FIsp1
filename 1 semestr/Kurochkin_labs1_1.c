#include <stdio.h>
#include <locale.h>

void main(){

    int x1,y1,x2,y2;

    scanf_s("%d %d %d %d",&x1,&y1,&x2,&y2);
    if (x1==x2 && y1==y2){
        printf("stay\n");
    }
    else{
        
    if ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) <= 2){
        printf("King\n");
    }
    if ((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) == 5)
    {
        printf("Horse\n");
    }
    if (x1==x2 || y1==y2)
    {
        printf("Lad\n");
    }
    if (x1+y1==x2+y2 || x1-y1==x2-y2)
    {
        printf("Elephant\n");
    }
    if (x1+y1==x2+y2 || x1-y1==x2-y2 || x1==x2 || y1==y2){
        printf("Queen\n");
    }
    }
    

}