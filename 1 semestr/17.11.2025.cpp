//#include <stdio.h>
//#define N 2
//#define M 2
//void main() {
//	int m1[N][M];
//	int m2[N][M];
//	int rez[N][M];
//	printf("Vvedite 1 matritsu");
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			scanf_s("%d", &m1[i][j]);
//		}
//	}
//	printf("Vvedite 2 matritsu");
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			scanf_s("%d", &m2[i][j]);
//		}
//	}
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++) {
//			rez[i][j] = 0;
//			for (int k = 0; k < M; k++) {
//				rez[i][j] += m1[i][k] * m2[k][j];
//			}
//		}
//	}
//	printf("Rezultat");
//	for (int i = 0; i < N; i++) {
//		for (int j = 0; j < M; j++)
//			printf("%d ", rez[i][j]);
//	}
//}

#include <stdio.h>
#include <limits.h>
#define N 3
void main() {
	int m[N][N];
	int strok_min[N];
	int stolb_max[N];
	printf("Vvedite matritsu");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf_s("%d", &m[i][j]);
		}
	}
	for (int i = 0; i < N; i++) {
		int mn = INT_MAX;
		for (int j = 0; j < N; j++)
			if (m[i][j] < mn) mn = m[i][j];
		strok_min[i] = mn;
	}
	for (int j = 0; j < N; j++) {
		int mx = INT_MIN;
		for (int i = 0; i < N; i++)
			if (m[i][j] > mx) mx = m[i][j];
		stolb_max[j] = mx;
	}
	int rez = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			if (m[i][j] == strok_min[i] && m[i][j] == stolb_max[j]) rez++;
	}
	printf("rezultat ");
	printf("%d ", rez);
}