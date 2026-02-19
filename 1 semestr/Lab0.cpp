#include <stdio.h>
#include <locale.h>
#include <math.h>
int main() {
    setlocale(LC_CTYPE, "rus");
    float a, b, c;
    printf("Введите 3 стороны треугольника: ");
    scanf_s("%f %f %f", &a, &b, &c);
    if ((a >= b + c) || (b >= a + c) || (c >= a + b) || a <= 0 || b <= 0 || c <= 0) {
        printf("Треугольник не существует\n");
        return 0;
    }
    if (a == b && b == c) {
        printf("Треугольник равносторонний\n");
    }
    else if (a == b || a == c || b == c) {
        printf("Треугольник равнобедренный\n");
    }
    else {
        printf("Треугольник рзносторонний\n");
    }
    float a2 = a * a, b2 = b * b, c2 = c * c;
    if (a2 == b2 + c2 || b2 == a2 + c2 || c2 == b2 + a2) {
        printf("Треугольник прямоугольный\n");
    }
    else if (a2 < b2 + c2 && b2 < a2 + c2 && c2 < b2 + a2) {
        printf("Треугольник остроугольный\n");
    }
    else {
        printf("Треугольник тупоугольный\n");
    }
    return 0;
}