//#include <stdio.h>
//#include <locale.h>
//#define N 5
//#define M 4
//void main() {
//	setlocale(LC_ALL, "Russian");
//	int arr1[N], arr2[M], arr[N + M], k = 0, j = 0, i = 0;
//	printf("Введите первый упорядоченный массив из %d элементов\n", N);
//	for (int i = 0; i < N; i++)
//		scanf_s("%d", &arr1[i]);
//	printf("Введите второй упорядоченный массив из %d элементов\n", M);
//	for (int i = 0; i < M; i++)
//		scanf_s("%d", &arr2[i]);
//	while ((i < N) && (j < M)) {
//		if (arr1[i] < arr2[j])
//			arr[k++] = arr1[i++];
//		if (arr2[j] < arr1[i])
//			arr[k++] = arr2[j++];
//	}
//	while (i < N) {
//		arr[k++] = arr1[i++];
//	}
//	while (j < M) {
//		arr[k++] = arr2[j++];
//	}
//	printf("Слияние массивов:\n");
//	for (int i = 0; i < (N + M); i++)
//		printf("%d ", arr[i]);
//}
//#include <stdio.h>
//#include <locale.h>
//#define N 8
//void main() {
//	setlocale(LC_ALL, "Russian");
//	int arr[N];
//	printf("Введите массив из %d элементов\n", N);
//	for (int i = 0; i < N; i++)
//		scanf_s("%d", &arr[i]);
//	for (int i = 0; i < N; i++)
//		for (int k = i+1; k < N; k++)
//			if (arr[i] == arr[k])
//				arr[k] = -1000;
//	printf("Массив без повторений: ");
//	for (int i = 0; i < N; i++)
//		if (arr[i] != -1000)
//			printf("%d ", arr[i]);
//}
#include <stdio.h>
#include <locale.h>
#define N 5
void main() {
	setlocale(LC_ALL, "Russian");
	int arr[N], otv[N];
	for (int i = 0; i < N; i++)
		scanf_s("%d", &arr[i]);
	for (int i = 0; i < N; i++)
		otv[i] = arr[N-1-i];
	for (int i = 0; i < N; i++)
		printf("%d ", otv[i]);
}