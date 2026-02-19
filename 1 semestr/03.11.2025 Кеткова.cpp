//#include <stdio.h>
//#define N 5
//#define M 6
//void main() {
//	int array1[N];
//	int array2[M];
//	printf("Vvedite 1 massiv");
//	for (int i = 0; i < N; i++)
//		scanf_s("%d", &array1[i]);
//	printf("Vvedite 2 masiiv");
//	for (int i = 0; i < M; i++)
//		scanf_s("%d", &array2[i]);
//	int array[N + M];
//	int i = 0;
//	int j = 0;
//	int k = 0;
//	while (i < N && j<M ) {
//		if (array1[i] < array2[j])
//			array[k++] = array1[i++];
//		else
//			array[k++] = array2[j++];
//	}
//	while (i < N) {
//		array[k++] = array1[i++];
//	}
//	while (j < M) {
//		array[k++] = array2[j++];
//	}
//	for (int i = 0; i < (N+M); i++)
//		printf("%d ", array[i]);
//}

//#include <stdio.h>
//#define N 5
//void main() {
//	int arr[N];
//	printf("Vvedite massiv");
//	for (int i = 0; i < N; i++)
//		scanf_s("%d", &arr[i]);
//	for (int i = 0; i < N; i++) {
//		for (int j = i+1; j < N; j++) {
//			if (arr[i] == arr[j])
//				arr[j] = -100;
//		}
//	}
//	for (int i = 0; i < N; i++) {
//		if (arr[i] != -100)
//			printf("%d", arr[i]);
//	}
//}

#include <stdio.h>
#define N 5
void main() {
	int arr[N];
	int rez[N];
	for (int i = 0; i < N; i++)
		scanf_s("%d", &arr[i]);
	for (int i = 0; i < N; i++) {
		rez[i] = arr[N - 1 - i];
	}
	for (int i = 0; i < N; i++)
		printf("%d ", rez[i]);

}