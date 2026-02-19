//#include <stdio.h>
//#define N 5
//void main() {
//	int arr[N];
//	printf("Enter array: ");
//	for (int i = 0; i < N; i++)
//		scanf_s("%d", &arr[i]);
//	int a;
//	for (int i = N-1; i >= 0; i--) {
//		int fl = 1;
//		for (int j = 0; j < i; j++) {
//			if (arr[j] > arr[j + 1]) {
//				a = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = a;
//				fl = 0;
//			}
//		}
//		if (fl == 1)
//			break;
//	}
//	printf("Sorted array: ");
//	for (int i = 0; i < N; i++)
//		printf("%d ", arr[i]);
//}

#include <stdio.h>
#define N 5
void main() {
	int arr[N];
	printf("Enter array: ");
	for (int i = 0; i < N; i++)
		scanf_s("%d", &arr[i]);
	int left = 0;
	int right = N - 1;
	int a;
	int b;
	while (left <= right) {
		for (int i = right; i > left; i--) {
			if (arr[i - 1] > arr[i]) {
				a = arr[i-1];
				arr[i-1] = arr[i];
				arr[i] = a;
			}
		}
		left++;
		for (int i = left; i < right; i++) {
			if (arr[i] > arr[i + 1]) {
				b = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = b;
			}
		}
		right--;
	}
	printf("Sorted array: ");
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
}