#include <stdio.h>

int main(){
    float density_DSP, density_DVP, density_WOOD; // Плотность материалов
    float height_invoice_back_DVP, width_invoice_back_DVP; // Накладная задняя стенка из ДВП
    float height_sidewall_DSP, depth_sidewall_DSP; // Боковина из ДСП
    float width_invoice_upper_lower_DSP, depth_invoice_upper_lower_DSP; // Накладная верхняя и нижняя крышка
    float height_overhead_doors_WOOD, width_overhead_doors_WOOD; // Накладные двери из дерева
    float width_inside_shelves_DSP, depth_inside_shelves_DSP, thickness_inside_shelves_DSP; // Внутренние полки в шкафу

    printf("Введите плотность ДСП, ДВП и дерева:\n");
    scanf("%f %f %f", &density_DSP, &density_DVP, &density_WOOD);

    printf("Введите высоту накладной задней стенки из ДВП:\n");
    scanf("%f", &height_invoice_back_DVP);

    printf("Введите ширину накладной задней стенки из ДВП:\n");
    scanf("%f", &width_invoice_back_DVP);

    float thickness_invoice_back_DVP = 0.5; // Толщина накладная задней стенки из ДВП

    printf("Введите высоту боковины из ДСП:\n");
    scanf("%f", &height_sidewall_DSP);

    printf("Введите глубину боковины из ДСП:\n");
    scanf("%f", &depth_sidewall_DSP);

    float thickness_sidewall_DSP = 1.5; // Толщина боковины из ДСП

    printf("Введите ширину накладной верхней и нижней крышки из ДСП:\n");
    scanf("%f", &width_invoice_upper_lower_DSP);

    printf("Введите глубину накладной верхней и нижней крышки из ДСП:\n");
    scanf("%f", &depth_invoice_upper_lower_DSP);
    
    float thickness_invoice_upper_lower_DSP = 1.5; // Толщина накладной верхней и нижней крышки

    printf("Введите высоту накладной двери из дерева:\n");
    scanf("%f", &height_overhead_doors_WOOD);

    printf("Введите ширину накладной двери из дерева:\n");
    scanf("%f", &width_overhead_doors_WOOD);

    float thickness_overhead_doors_WOOD = 1.0; // Толщина накладной двери из дерева

    printf("Введите толщину внутренний полки:\n");
    scanf("%f", &thickness_inside_shelves_DSP);

    int count_shelves_DSP = (height_invoice_back_DVP - thickness_invoice_upper_lower_DSP * 2) / (40 + thickness_inside_shelves_DSP); // Количество полок

    width_inside_shelves_DSP = width_invoice_upper_lower_DSP - thickness_invoice_back_DVP - thickness_overhead_doors_WOOD; // Ширина внутренний полки
    depth_inside_shelves_DSP = (float)depth_invoice_upper_lower_DSP - 2 * thickness_invoice_upper_lower_DSP; // Глубина внутренний полки

    float weight_DVP = density_DVP * height_invoice_back_DVP * width_invoice_back_DVP * thickness_invoice_back_DVP; // Масса ДВП
    float weight_DSP = 2 * density_DSP * height_sidewall_DSP * depth_sidewall_DSP * thickness_sidewall_DSP + 2 * density_DSP * width_invoice_upper_lower_DSP * \
    depth_invoice_upper_lower_DSP * thickness_invoice_upper_lower_DSP + count_shelves_DSP * density_DSP * width_inside_shelves_DSP * depth_inside_shelves_DSP * \
    thickness_inside_shelves_DSP; // Масса ДСП
    float weight_WOOD = 2 * density_WOOD * height_overhead_doors_WOOD * width_overhead_doors_WOOD * thickness_overhead_doors_WOOD; // Масса дерева

    float weight_wardrobe = weight_DVP + weight_DSP + weight_WOOD; // Масса шкафа
    float cm3_to_m3 = 0.000001; // Перевод объёма из см^3 в м^3
    printf("Масса шкафа: %.2f кг", weight_wardrobe * cm3_to_m3);
}