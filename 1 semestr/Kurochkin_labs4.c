#include <stdio.h>

int* invert(int num,int arr[]){
    for (int i = 0; i < 4; i++) {
        arr[4-1-i] = num % 10;
        num = num / 10;
    }
    return arr;
}

int compareArrays(int arr1[], int arr2[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr1[i] != arr2[i]) {
            return 0;
        }
    }
    return 1;
}

int main(){
    int milk[4] = {1,2,3,4};
    int bread[4] = {4,3,2,1};
    int carrot[4] = {1,4,7,4};
    int* products[3] = {milk,bread,carrot};
    char* sproducts[3] = {"milk","bread","carrot"};

    char* cheque[100] = {0};
    int k = 0;
    int num;
    printf("Nado vvesti code producta (1234,4321,1474)\n");
    printf("esli zakonchili to pishem 9999\n");
    while (num!=9999){

        scanf_s("%d",&num);

        int result[4]; 
        if ((num < 1000 || num > 9999)){
            printf("Error \n");
        }
        else {
        
        invert(num,result);
        


        for (int i = 0; i < sizeof(products)/sizeof(products[0]);i++){
            if (compareArrays(result, products[i], 4)) {
                printf("%s\n", sproducts[i]);
                cheque[k] = sproducts[i];
                k++;
                }
        

            }
        }
    
    }
    printf("...CHEQUE LIST...\n");
    int i = 0;
    int price = 0;
    while (cheque[i]!=NULL){
        if (cheque[i]=="milk"){
            printf("%s %d",cheque[i],60);
            printf("\n");
            price += 60;
        }
        if (cheque[i]=="carrot"){
            printf("%s %d",cheque[i],30);
            printf("\n");
            price += 30;
        }
        if (cheque[i]=="bread"){
            printf("%s %d",cheque[i],80);
            printf("\n");
            price += 80;
        }
 
        i++;
    }
    printf("Price: %d", price);

}