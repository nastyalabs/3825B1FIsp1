#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <locale.h>

int main() {
    setlocale(LC_ALL, "Russian");
    char str[1000];  
    
    fgets(str, sizeof(str), stdin);
    
    int word_count = 0;
    int number_count = 0;
    int i = 0;
    int len = strlen(str);
    
    while (i < len) {
        if (str[i] == ' ' || str[i] == '\t') {
            i++;
            continue;
        }
        
        if (isalpha((unsigned char)str[i]) || 
            (str[i] >= 'А' && str[i] <= 'я')) {
            word_count++;
            while (i < len && (isalpha((unsigned char)str[i]) || 
                              (str[i] >= 'А' && str[i] <= 'я') ||
                              str[i] == '-' || str[i] == '\'')) {
                i++;
            }
        }
        else if (isdigit((unsigned char)str[i])) {
            number_count++;
            while (i < len && isdigit((unsigned char)str[i])) {
                i++;
            }
        }
        else {
            i++; 
        }
    }
    
    printf("Количество слов: %d\n", word_count);
    printf("Количество чисел: %d\n", number_count);
    
    return 0;
}