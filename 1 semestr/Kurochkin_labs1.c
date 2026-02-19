#include <stdio.h>
#include <locale.h>

void main(){
    setlocale(LC_ALL, "Russian");

    float h,w,d;
    float dsp = 1.5, dvp = 0.5, tree = 1.0;
    scanf_s("%f %f %f",&h,&w,&d);
    
    if (180<=h<=220 && 80<=w<=120 && 50<=d<=90){
        int shelves = h/40-1;

        float result;
        result = (h*d*2*dsp + dvp*h*w + 2*dsp*w*d + h*w*tree + shelves*d*w*dsp)/1000; // две боковины + задняя + верх + низ + двери + полки

        printf("%.2f", result);
    }
    else{
        printf("Bad shkaf");
        
    }
}
