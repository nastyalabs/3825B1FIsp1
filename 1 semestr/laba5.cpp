#include <stdio.h>
#include <stdlib.h>
#define N 10
#define L 2
void main()
{
	srand(time(NULL));
	int directory_choise, showcase_choise, option_of_sorting, choise_whithoutchoise;
	printf("Selected path: \n"); printf("D:\\folder_main");
	printf("\n\nWhere you want to go?: \n1.folder1\n---->  ");
	scanf_s("%d", &choise_whithoutchoise);
	printf("\nSelected path: \n"); printf("D:\\folder_main\\folder1");
	printf("\n\nWhere you want to go?: \n1.files1\n2.files2\n3.files3\n---->  ");
	scanf_s("%d", &directory_choise);
	switch (directory_choise)
	{
	case 1:
	{
		printf("\nSelected path: \n"); printf("D:\\folder_main\\folder1\\files1\n");
		printf("\ndo you want to see files in this directory?:\n1.yes\n2.no\n---->  ");
		scanf_s("%d", &showcase_choise);
		switch (showcase_choise)
		{
		case 1: printf("1.file1 (790kb)\n2.file2 (222kb)\n3.file3 (250kb)\n4.file4 (666kb)\n5.file5 (228kb)\n6.file6 (112kb)\n7.file7 (1500kb)\n8.file8 (888kb)\n9.file9 (668kb)\n10.file10 (10kb)\n"); break;
		case 2: break;
		default: break;
		}
		int arr1[N][L] = { {1,790},{2,222},{3,250},{4,666},{5,228},{6,112},{7,1500},{8,888},{9,668},{10,10} };
		printf("\nwhich sorting option you wanna use?:\n1. bubble sort\n2. choise sort (unfortunately not available)\n---->  ");
		scanf_s("%d", &option_of_sorting);
		if (option_of_sorting == 2)
		{
			printf("\nERROR!!!!!");
			return 0;
		}
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < N - i - 1; j++)
			{
				if (arr1[j][1] > arr1[j + 1][1])
				{
					for (int k = 0; k < L; k++)
					{
						int temp = arr1[j][k];
						arr1[j][k] = arr1[j + 1][k];
						arr1[j + 1][k] = temp;
					}
				}
			}
		}
		printf("\nsorted array: \n");
		for (int i = 0; i < N; i++)
		{
			printf("file");
			for (int j = 0; j < L; j++)
			{
				if (j == 0)
				{
					printf("%d", arr1[i][j]);
				}
				else
				{
					printf("   %d kb", arr1[i][j]);
				}

			}
			printf("\n");
		}
		break;
	}
	case 2:
	{
		printf("\nSelected path: \n"); printf("D:\\folder_main\\folder1\\files2\n");
		printf("\ndo you want to see files in this directory?:\n1.yes\n2.no\n---->  ");
		scanf_s("%d", &showcase_choise);
		switch (showcase_choise)
		{
		case 1: printf("1.file1 (345kb)\n2.file2 (2233kb)\n3.file3 (2502kb)\n4.file4 (6666kb)\n5.file5 (218kb)\n6.file6 (15kb)\n7.file7 (150kb)\n8.file8 (88kb)\n9.file9 (628kb)\n10.file10 (100kb)\n"); break;
		case 2: break;
		default: break;
		}
		int arr1[N][L] = { {1,345},{2,2233},{3,2502},{4,6666},{5,218},{6,15},{7,150},{8,88},{9,628},{10,100} };
		printf("\nwhich sorting option you wanna use?:\n1. bubble sort\n2. choise sort (unfortunately not available)\n---->  ");
		scanf_s("%d", &option_of_sorting);
		if (option_of_sorting == 2)
		{
			printf("\nERROR!!!!!");
			return 0;
		}
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < N - i - 1; j++)
			{
				if (arr1[j][1] > arr1[j + 1][1])
				{
					for (int k = 0; k < L; k++)
					{
						int temp = arr1[j][k];
						arr1[j][k] = arr1[j + 1][k];
						arr1[j + 1][k] = temp;
					}
				}
			}
		}
		printf("\nsorted array: \n");
		for (int i = 0; i < N; i++)
		{
			printf("file");
			for (int j = 0; j < L; j++)
			{
				if (j == 0)
				{
					printf("%d", arr1[i][j]);
				}
				else
				{
					printf("   %d", arr1[i][j]);
				}

			}
			printf("\n");
		}
		break;
	}
	case 3:
	{
		printf("\nSelected path: \n"); printf("D:\\folder_main\\folder1\\files3\n");
		printf("\ndo you want to see files in this directory?:\n1.yes\n2.no\n---->  ");
		scanf_s("%d", &showcase_choise);
		switch (showcase_choise)
		{
		case 1: printf("1.file1 (555kb)\n2.file2 (120kb)\n3.file3 (333kb)\n4.file4 (777kb)\n5.file5 (2288kb)\n6.file6 (1122kb)\n7.file7 (4kb)\n8.file8 (44kb)\n9.file9 (1337kb)\n10.file10 (100kb)\n"); break;
		case 2: break;
		default: break;
		}
		int arr1[N][L] = { {1,555},{2,120},{3,333},{4,777},{5,2288},{6,1122},{7,4},{8,44},{9,1337},{10,100} };
		printf("\nwhich sorting option you wanna use?:\n1. bubble sort\n2. choise sort (unfortunately not available)\n---->  ");
		scanf_s("%d", &option_of_sorting);
		if (option_of_sorting == 2)
		{
			printf("\nERROR!!!!!");
			return 0;
		}
		for (int i = 0; i < N - 1; i++)
		{
			for (int j = 0; j < N - i - 1; j++)
			{
				if (arr1[j][1] > arr1[j + 1][1])
				{
					for (int k = 0; k < L; k++)
					{
						int temp = arr1[j][k];
						arr1[j][k] = arr1[j + 1][k];
						arr1[j + 1][k] = temp;
					}
				}
			}
		}
		printf("\nsorted array: \n");
		for (int i = 0; i < N; i++)
		{
			printf("file");
			for (int j = 0; j < L; j++)
			{
				if (j == 0)
				{
					printf("%d", arr1[i][j]);
				}
				else
				{
					printf("   %d", arr1[i][j]);
				}

			}
			printf("\n");
		}
		break;
	}
	default:break;
	}
}