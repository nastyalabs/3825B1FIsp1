#include<stdio.h>
#include<locale>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int random_in_range(int l, int r){
	return l + rand() % (r - l + 1);
}

int is_letter(char ch){
	return (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z') || ('А' <= ch && ch <= 'Я') || ('а' <= ch && ch <= 'я'));
}

int main(){
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
	
    //Количество слов и чисел во входном потоке символов
    int word = 0, number = 0;
    char ch;
    int f1 = 0, f2 = 0; //f1 - находимся в слове, f2 - находимся в числе 
    printf("Введите набор слов и чисел:\n");
    
    while ((ch = getchar()) != '\n') {
        if (is_letter(ch)) {
        	if (f1 == 0){
        		word++;
            	f1 = 1;
			}
        }
        else if ('0' <= ch && ch <= '9') {
        	if (f2 == 0){
        	    number++;
            	f2 = 1;
			}
        }
        else if (ch == ' ' || ch == '\t') {
            f1 = 0;
            f2 = 0;
        }
    }
    
    printf("\nЧисло слов в строке: %d\n", word);
    printf("Число чисел в строке: %d\n", number);
    
    return 0;
}
