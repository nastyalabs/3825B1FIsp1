#include<stdio.h>
#include<locale>
#include<stdlib.h>
#include<math.h>
#include<time.h>

void read_array(int arr[], int size){
    for (int i = 0; i < size; i++){
        scanf(" %d", &arr[i]);
    }
}

void print_array(int arr[], int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

int random_in_range(int l, int r){
	return l + rand() % (r - l + 1);
}

int generate_unq(int arr[], int n){
	int sost[10]; // массив состояний для проверки использовалась ли уже цифра для генерации
	for (int i = 0; i < 10; i++) sost[i] = 0;
	arr[0] = random_in_range(1, 9);
	sost[arr[0]] = 1;
	for (int i = 1; i < n; i++){
		do{
			arr[i] = rand() % 10;
		}
		while (sost[arr[i]] != 0);
		sost[arr[i]] = 1;
	}
}

void count_bulls_and_cows(int generated[], int predp[], int n, int *bulls, int *cows) {
    *bulls = 0;
    *cows = 0;

    for (int i = 0; i < n; i++) {
        if (predp[i] == generated[i]) {
            (*bulls)++;
        } else {
            for (int j = 0; j < n; j++) {
                if (predp[i] == generated[j]) {
                    (*cows)++;
                    break;
                }
            }
        }
    }
}

int main(){
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
	

    printf("\tИгра \"Быки и Коровы\"\n");
    int n;
    do{
    	printf("\nВыберите длину загадываемого числа от 2 до 5: ");
    	scanf("%d", &n);
	}
	while(n < 2 || n > 5);

	int arr[5];
	generate_unq(arr, n);
    printf("\nЯ задумал %d-значное число с неповторяющимися цифрами\n", n);
    
	while(getchar() != '\n'); //чистим буфер после scanf
    int f = 0;
    do {
    	int predp[5];
    	int i = 0, attempts = 0;
    	char ch;
    	printf("\nВведите предположение: ");
    	while((ch = getchar()) != '\n'){
    		predp[i] = ch - 48;
    		i++;
    		attempts++;
		}
		int bulls, cows;
        count_bulls_and_cows(arr, predp, n, &bulls, &cows);

        printf("Результат: %d бык(ов), %d коров(ы)\n", bulls, cows);

        if (bulls == n) {
            printf("\nПоздравляем! Вы угадали число за %d попыток!\n", attempts);
            f = 1;
        }
	}
    while(!f);

    return 0;
}
