#include <stdio.h>

int main() {
    int count_words = 0, count_numbers = 0;     // счётчик слов, счётчик букв
    char last_char = ' ';                       // последний символ
    char symbol;                                // текущий символ
    
    printf("Введите текст: ");
    
    while ((symbol = getchar()) != '\n') {
        if (symbol >= '0' && symbol <= '9') {
            // Если это цифра и предыдущий символ был разделителем, увеличиваем счетчик чисел
            if (last_char == ' ' || last_char == '\t') {
                count_numbers++;
            }
        }
        // Если текущий символ не разделитель и предыдущий символ был разделителем, увеличиваем счетчик слов
        else if (symbol != ' ' && symbol != '\t') {
            if (last_char == ' ' || last_char == '\t') {
                count_words++;
            }
        }
        last_char = symbol;
    }
    
    printf("Количество слов: %d\n", count_words);
    printf("Количество чисел: %d\n", count_numbers);
    
    return 0;
}
