#include <stdio.h>

int BubbleSort(int arr[], int N){
    for (int i = 0; i < N; i++){
        for (int j = i+1; j < N; j++){
            if (arr[j]<arr[i]){
                int replace = arr[j];
                arr[j] = arr[i];
                arr[i] = replace;
            }
        }
    }
    return 0;
};

int vstavka(int arr[], int N){
    for (int i = 0; i < N; i++){
        int index = i;
        int numbers = arr[i];
        while (index > 0 && arr[index-1]>numbers){
            arr[index] = arr[index-1];
            index--;
        }
        arr[index]=numbers;
    }
}

int main(){

    int n;
    int arr1[] = {4,2,14,5,22,1};
    int arr2[] = {5,8,19,1,2,3,144};
    int arr3[] = {10,88,75,43,51,-10,-99,168};
    int *arrs[] = {arr1,arr2,arr3};
    int sizes[] = {sizeof(arr1)/sizeof(arr1[0]),sizeof(arr2)/sizeof(arr2[0]),sizeof(arr3)/sizeof(arr3[0])};

    printf("Choose Directory(0,1,2):\n");
    scanf_s("%d",&n);

    if (n == 0 || n == 1 || n == 2){
        for (int i = 0; i < sizes[n];i++){
            printf("%d ", arrs[n][i]);
        }
        printf("\nChoose sort: \n");
        printf("1-Bubble \n2-Vstavka \n");
        int n1;
        scanf_s("%d", &n1);
        switch (n1)
        {
        case 1:

        BubbleSort(arrs[n],sizes[n]);
            for (int i = 0; i < sizes[n];i++){
                printf("%d ", arrs[n][i]);
            }

            break;
        
        case 2:

        vstavka(arrs[n],sizes[n]);
            for (int i = 0; i < sizes[n];i++){
                printf("%d ", arrs[n][i]);
            }

            break;
        
        default:
            break;
        }
    } 
    else{
        printf("error, incorrect directory");
    }

    return 0;
}

