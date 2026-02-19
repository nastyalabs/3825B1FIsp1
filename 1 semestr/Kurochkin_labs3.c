#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h> 

int main() {
    
    srand(time(NULL));

    int n;
    printf("enter num (max 5): \n");
    scanf("%d", &n);
    
    if (n <= 0 || n > 5) {
        printf("error num \n");
        return 1;
    }
    
    int arr[n];
    int arr1[n];

    bool used[10] = {false};
    
    for (int i = 0; i < n; i++) {
        int digit;
        do {
            digit = rand() % 10;
        } while (used[digit]);  
        
        arr[i] = digit;
        used[digit] = true;
    }
    
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("enter unique num \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr1[i]);

        if (arr1[i] < 0 || arr1[i] > 9) {
            printf("error \n");
            return 1;
        }
    }

    printf("your array: \n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr1[i]);
    }
    printf("\n");
    
    bool user_used[10] = {false};
    for (int i = 0; i < n; i++) {
        if (user_used[arr1[i]]) {
            printf("error,dublicate %d \n", arr1[i]);
            return 1;
        }
        user_used[arr1[i]] = true;
    }
    
    int bulls = 0, cows = 0;
    
    for (int i = 0; i < n; i++) {
        if (arr1[i] == arr[i]) {
            bulls++;
        } else {
            for (int j = 0; j < n; j++) {
                if (arr1[i] == arr[j]) {
                    cows++; 
                    break;
                }
            }
        }
    }
    
    printf("bulls: %d \n", bulls);
    printf("cows: %d \n", cows);
    
    if (bulls == n) {
        printf("win \n");
    }
    
    return 0;
}