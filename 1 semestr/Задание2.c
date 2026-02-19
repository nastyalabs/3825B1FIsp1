#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main()
{
    int game_mode; // режим игры
    int count = 0; // количество попыток
    int correct_number, selected_number; // загаданное число, выбранное число
    char symbol; // символ < > =
    
    printf("Программа <Угадай число>\n");
    printf("Выберите режим игры:\n");
    printf("1 - Компьютер загадывает, вы угадываете\n");
    printf("2 - Вы загадываете, компьютер угадывает\n");
    printf("Ваш выбор: ");
    scanf("%d", &game_mode);
    
    // Инициализация генератора случайных чисел
    srand(time(NULL));
    
    if (game_mode == 1) {
        // Режим игры 1: Компьютер загадывает
        correct_number = rand() % 1000 + 1; // Случайное число от 1 до 1000
        printf("\nКомпьютер загадал число от 1 до 1000.\n\n");

        selected_number = 0;
        while (correct_number != selected_number){
            printf("Ваша попытка: ");
            scanf("%d", &selected_number);
            count++;
            
            if (selected_number < correct_number) {
                printf("Загаданное число БОЛЬШЕ\n");
            } 
            else if (selected_number > correct_number) {
                printf("Загаданное число МЕНЬШЕ\n");
            }
        }
    printf("Поздравляю! Вы угадали число %d за %d попыток!\n", correct_number, count);    
    }

    else if(game_mode == 2){
        // Режим игры 2: Пользователь загадывает
        printf("\nЗагадайте число от 1 до 1000 и введите его: ");
        scanf("%d", &correct_number);
        
        int min = 1;    // нижняя граница
        int max = 1000; // верхняя граница
        
        printf("\nКомпьютер будет пытаться угадать ваше число. Отвечайте:\n");
        printf("> - если ваше число больше\n");
        printf("< - если ваше число меньше\n");
        printf("= - если компьютер угадал\n\n");
        

        while (correct_number != selected_number){
            selected_number = (min + max) / 2;
            count++;

            printf("Попытка %d: %d\n", count, selected_number);
            printf("Ваш ответ (> или < или =): ");
            scanf(" %c", &symbol); 

            if(symbol == '>'){
                min = selected_number + 1; // Если число больше, то сдвигаем нижнюю границу
            }
            else if (symbol == '<'){
                max = selected_number - 1; // Если число меньше, то сдвигаем верхнюю границу
            }
            else if (symbol == '='){
                selected_number = correct_number;
            }
            else{
                printf("Неверный ввод символа. Используйте только >, < или =\n");
                count--; // Не считаем эту попытку
            }

        }
        printf("Компьютер угадал ваше число %d за %d попыток!\n", selected_number, count);   
    }

    else
        printf("Выберите режим игры 1 или 2\n");

    return 0;
}