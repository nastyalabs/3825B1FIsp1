#include <stdio.h>

int main() {
    float h, w, d;
    float DensityDsp = 650, DensityDvp = 900, DensityWood = 600,WeightDvp, WeightDsp, WeightWood, WeightCabinet;
    float ThicknessDvp = 0.5;
    float ThicknessDsp = 1.5;
    float ThicknessDoor = 1.0;

    printf("Введите h w d (в см): ");
    scanf("%f %f %f", &h, &w, &d);


    int shelves = 0;
    for (float i = 40; i < h; i += 40) {
        shelves++;
    }

    WeightDvp = w * h * ThicknessDvp * DensityDvp;
    WeightDsp = (2 * h * d * ThicknessDsp + 2 * w * d * ThicknessDsp + shelves * w * d * ThicknessDsp) * DensityDsp;
    WeightWood = w * h * ThicknessDoor * DensityWood;
    WeightCabinet = (WeightDvp + WeightDsp + WeightWood) * 0.000001;

    printf("Масса шкафа: %.2f\n", WeightCabinet);

    return 0;
}