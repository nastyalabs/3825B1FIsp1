#include <stdio.h>

void bubble_sort_vosr(int arr[], int razmer){
    int tmp;
    for (int i = 0; i < razmer - 1; i++){
        int flag = 0;
        for (int j = 0; j < razmer - 1 - i; j++){
            if (arr[j] > arr[j + 1]){
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag++;
            }
        }
        if (flag == 0)
            break;
    }
}
void bubble_sort_ubiv(int arr[], int razmer){
    int tmp;
    for (int i = 0; i < razmer - 1; i++){
        int flag = 0;
        for (int j = 0; j < razmer - 1 - i; j++){
            if (arr[j] < arr[j + 1]){
                tmp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tmp;
                flag++;
            }
        }
        if (flag == 0)
            break;
    }
}
void selection_sort_vosr(int arr[], int razmer){
    int tmp, min_index;

    for (int i = 0; i < razmer - 1; i++){
        min_index = i;
        for (int j = i + 1; j < razmer; j++){
            if (arr[j] < arr[min_index])
                min_index = j;
        }
        tmp = arr[i];
        arr[i] = arr[min_index];
        arr[min_index] = tmp;
    }
}
void selection_sort_ubiv(int arr[], int razmer){
    int tmp, max_index;

    for (int i = 0; i < razmer - 1; i++){
        max_index = i;
        for (int j = i + 1; j < razmer; j++){
            if (arr[j] > arr[max_index])
                max_index = j;
        }
        tmp = arr[i];
        arr[i] = arr[max_index];
        arr[max_index] = tmp;
    }
}

int main(){
    int arr1[] = {4, 2, 14, 5, 22, 1};
    int arr2[] = {5, 8, 19, 1, 2, 3, 144};
    int arr3[] = {10, 88, 75, 43, 51, -10, -99, 168};

    int* arrs[] = {arr1, arr2, arr3};
    int razmeri[] = {sizeof(arr1) / sizeof(arr1[0]),
        sizeof(arr2) / sizeof(arr2[0]),
        sizeof(arr3) / sizeof(arr3[0])
    };

    int vibor_massiva, vibor_sort, napravlenie;

    printf("Viberite massiv (0, 1, 2):\n");
    scanf("%d", &vibor_massiva);

    if (vibor_massiva < 0 || vibor_massiva > 2){
        printf("Oshibka: nevernii massiv\n");
        return 0;
    }

    printf("Ishodnii massiv:\n");
    for (int i = 0; i < razmeri[vibor_massiva]; i++){
        printf("%d ", arrs[vibor_massiva][i]);
    }

    printf("\n\nViberite sortirovku:\n");
    printf("1 - Bubble sort\n");
    printf("2 - Selection sort\n");
    scanf("%d", &vibor_sort);

    printf("\nViberite napravlenie:\n");
    printf("1 - Po vozrastaniyu\n");
    printf("2 - Po ubivaniyu\n");
    scanf("%d", &napravlenie);

    if (vibor_sort == 1){
        if (napravlenie == 1)
            bubble_sort_vosr(arrs[vibor_massiva], razmeri[vibor_massiva]);
        else if (napravlenie == 2)
            bubble_sort_ubiv(arrs[vibor_massiva], razmeri[vibor_massiva]);
    }
    else if (vibor_sort == 2){
        if (napravlenie == 1)
            selection_sort_vosr(arrs[vibor_massiva], razmeri[vibor_massiva]);
        else if (napravlenie == 2)
            selection_sort_ubiv(arrs[vibor_massiva], razmeri[vibor_massiva]);
    }
    else{
        printf("Oshibka: nevernii vibor sortirovki\n");
        return 0;
    }

    printf("\nOtsortirovannii massiv:\n");
    for (int i = 0; i < razmeri[vibor_massiva]; i++){
        printf("%d ", arrs[vibor_massiva][i]);
    }

    return 0;
}
