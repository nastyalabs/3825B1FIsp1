#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int mode;
    printf("=== Guess the Number Game ===\n");
    printf("Choose a mode:\n");
    printf("1 - I think of a number, you try to guess it\n");
    printf("2 - You think of a number, I try to guess it\n");
    printf("Enter 1 or 2: ");
    scanf_s("%d", &mode);
    if (mode == 1) {
        srand((unsigned)time(NULL));      
        int secret = rand() % 1000 + 1;   
        int guess = 0;
        int tries = 0;
        printf("\nI have chosen a number between 1 and 1000.\nTry to guess it!\n");
        do {
            printf("Your guess: ");
            scanf_s("%d", &guess);
            tries++;
            if (guess < secret)
                printf("The secret number is GREATER!\n");
            else if (guess > secret)
                printf("The secret number is SMALLER!\n");
            else
                printf("You guessed it!\n");
        } while (guess != secret);
        printf("Number of attempts: %d\n", tries);
    }
    // === MODE 2 === //
    else if (mode == 2) {
        int low = 1, high = 1000;
        int tries = 0;
        char answer;

        printf("\nThink of a number between 1 and 1000 and remember it.\n");
        printf("I will try to guess it. Please respond with:\n");
        printf(" '>' - if your number is greater\n");
        printf(" '<' - if your number is smaller\n");
        printf(" '=' - if I guessed correctly\n\n");

        while (low <= high) {
            int guess = (low + high) / 2;   
            tries++;
            printf("My guess: %d\n", guess);
            printf("Your answer (>, <, =): ");
            scanf_s(" %c", &answer);          

            if (answer == '>')
                low = guess + 1;
            else if (answer == '<')
                high = guess - 1;
            else if (answer == '=') {
                printf("Yay! I guessed your number %d in %d tries!\n", guess, tries);
                break;
            }
            else {
                printf("Please enter only >, <, or =.\n");
                tries--; 
            }
        }
        if (low > high)
            printf("Something is wrong with your answers — they are inconsistent!\n");
    }

    else {
        printf("Error: please choose mode 1 or 2.\n");
    }
    return 0;
}