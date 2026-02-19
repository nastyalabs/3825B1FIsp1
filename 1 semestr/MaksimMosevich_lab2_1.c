#include <stdio.h>

#define True 1
#define False 0

void main(){
    int c;
    int words = 0, numbers = 0;
    int is_numbers = False, is_word = False, last, flag_number = True, flag_word = True;

    while ((c = getchar()) != '\n' && c != EOF) {
        if (c >= '0' && c <= '9' ){
            is_numbers = True;
            is_word = False;
            last = c;
            flag_word = False;
        }
        else if(c != '\t' && c != ' '){
            is_numbers = False;
            is_word = True;
            last = c;
            flag_number = False;
        }
        else{
            if (is_numbers && flag_number)
                numbers++;
            else if (is_word && flag_word)
                words++;
            flag_number = True;
            flag_word = True;
        }
    }

    if (c != ' ' && c != '\t'){
        if (last >= '0' && last <= '9' && flag_number)
            numbers++;
        else if(flag_word)
            words++;
    }
    printf("Kolichestvo slov: %d\n", words);
    printf("Kolichestvo chisel: %d\n", numbers);
}