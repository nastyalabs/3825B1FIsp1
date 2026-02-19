#include <stdio.h>
#include <time.h>
#include <math.h>
#include <stdlib.h>

int main(){
    srand(time(NULL));
    int len, correct_number;
    int correct_len = 1;
    while(correct_len == 1) { // Бесконечный цикл, до тех пор пока не будет введена корректная длина числа
        printf("Введите длину числа (2-5): ");
        scanf("%d", &len);     
        if (len >= 2 && len <= 5) {
            correct_len = 0;
        } else {
            printf("Ошибка! Длина должна быть от 2 до 5.\n");
        }
    }
    int min = pow(10, len - 1);
    int max = pow(10, len) - 1;

    int repeat_correct = 1; 
    while(repeat_correct == 1){ // Флаг в загаданном числе: 1 - есть повтор; 0 - нет повторов
        correct_number = rand() % (max - min + 1) + min;
        repeat_correct = 0; // Предполагаем, что повторов нет
        for(int i = len - 1; i >= 0; i--){
            int digit_i = correct_number / (int)pow(10, i) % 10;
            for (int j = i - 1; j >= 0; j--){
                int digit_j = correct_number / (int)pow(10, j) % 10;
                if (digit_i == digit_j){
                    repeat_correct = 1; //Нашли повтор
                    break;
                }
            }
            if(repeat_correct == 1) // Выходим из внешнего цикла, если нашли повторение
                break;
        }
    }

    printf("\nЧисло было загадано!\n");
    printf("Быки - правильные цифры на своих местах\n");
    printf("Коровы - правильные цифры не на своих местах\n\n");

    int selected_number;
    while(selected_number != correct_number){
        int repeat_selected = 1;
        while(repeat_selected == 1){ // Флаг в предположенном числе: 1 - есть повтор; 0 - нет повторов
            printf("Введите вашу догадку (%d-значное число): ", len);
            scanf("%d", &selected_number);

            if (selected_number < min || selected_number > max) {
                printf("Ошибка! Число должно быть %d-значным.\n", len);
                repeat_selected = 1;
                continue;
            }
            repeat_selected = 0;
            for(int i = len - 1; i >= 0; i--) {
                int digit_i = selected_number / (int)pow(10, i) % 10;
                for (int j = i - 1; j >= 0; j--) {
                    int digit_j = selected_number / (int)pow(10, j) % 10;
                    if (digit_i == digit_j) {
                        repeat_selected = 1;
                        break;
                    }
                }
            }
            if (repeat_selected == 1) {
                printf("Ошибка! Все цифры должны быть разными.\n");
                continue;
            }
        }

        int bulls = 0;
        int cows = 0;

        for (int i = len - 1; i >= 0; i--){
            int correct_symbol = correct_number / (int)pow(10, i) % 10;
            int selected_symbol = selected_number / (int)pow(10, i) % 10;

            if (selected_symbol == correct_symbol){
                bulls++;
            }
            else{
                for (int j = len - 1; j >= 0; j--) {
                    if(i != j){ // Если стоят на разных позициях
                        int other_symbol = correct_number / (int)pow(10, j) % 10;
                        if (other_symbol == selected_symbol){
                            cows++;
                            break;
                        }
                    }
                }
            }
        }

        printf("Результат: %d быков, %d коров\n", bulls, cows);
        if(bulls == len){
            printf("\nВы угадали число %d!\n", correct_number);
            selected_number = correct_number;
        }
    }
    return 0;
}

