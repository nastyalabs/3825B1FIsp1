#include <stdio.h>
#include <math.h>
#include <locale.h>

void main(){
    setlocale(LC_CTYPE, "rus");

    float raznost_radiusov, d_mejdu_centrami, centr1X, centr1Y, centr2X, centr2Y, r1, r2;
    
    printf("Центр1 (x y), Центр2 (x y), радиус1, радиус2\n");
    scanf("%f %f %f %f %f %f", &centr1X, &centr1Y, &centr2X, &centr2Y, &r1, &r2);
    d_mejdu_centrami = sqrt((centr2X - centr1X) * (centr2X - centr1X) + (centr2Y - centr1Y) * (centr2Y - centr1Y));

    if (r1 > r2) 
        raznost_radiusov = r1 - r2;
    else 
        raznost_radiusov = r2 - r1;
    if (d_mejdu_centrami == 0 && r1 == r2) 
        printf("Окружности совпадают\n");
    else if (d_mejdu_centrami > r1 + r2) 
        printf("Окружности не пересекаются\n");
    else if (d_mejdu_centrami == r1 + r2) 
        printf("Окружности касаются в 1-ой точке\n");
    else if (d_mejdu_centrami > raznost_radiusov && d_mejdu_centrami < r1 + r2) 
        printf("Окружности пересекаются в двух точках\n");
    else if (d_mejdu_centrami < raznost_radiusov) 
        printf("Одна окружность находится внутри другой\n");
    
    
}
