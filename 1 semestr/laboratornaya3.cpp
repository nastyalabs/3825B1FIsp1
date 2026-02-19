#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <math.h>
int number_generation(len)
{
	int a = 0;
	long long int chislo = 0;
	for (int i = 0; i < len; i++)
	{
		a = rand() % 10;
		if (i == 0 && a == 0)
		{
			while (a == 0)
			{
				a = rand() % 10;
			}
		}
		chislo = chislo * 10 + a;
	}
	return chislo;
}
int proverka_na_povtor(len,chislo)
{
	int digits[10] = { 0 };
	int digit;
	int count1 = 0;
	while (chislo > 0)
	{
		digit = chislo % 10;
		digits[digit]++;
		chislo = chislo / 10;
	}
	for (int i = 0; i < 10; i++)
	{
		if (digits[i] > 1)
		{
			return 6;
		}
	}
	return 7;
}
void main()
{
	int len,count=0;
	int a = 0, b = 0;
	long long int chislo_prime = 0, chislo = 0;
	srand(time(NULL));
	printf("Enter a count of digits in number: ");
	scanf_s("%d", &len);
	chislo = number_generation(len);
	b = proverka_na_povtor(len, chislo);
	while (b != 7)
	{
		switch (b)
		{
		case 7: break;
		case 6:
		{
			chislo = number_generation(len);
		}
		default: break;
		}
		b = proverka_na_povtor(len, chislo);


	}
	chislo_prime = chislo;
	int cheker = 0;
	while (cheker != len+1)
	{
		long int player_number = 0;
		printf("\nTry to guess which number ur PC hide from u): ");
		scanf_s("%ld", &player_number);
		printf("\n%ld", player_number);
		int arraypc[5], arrayplayer[5];
		int len1 = len - 1;
		int count1 = 0;
		int c = 0;
		for (len1; len1 > -1; len1 = len1 - 1)
		{
			c = (10 * pow(10, count1));
			arraypc[len1] = (chislo_prime % c) / pow(10, count1);
			count1++;
		}
		int count2 = 0;
		int c1 = 0;
		int len2 = len - 1;
		for (len2; len2 > -1; len2 = len2 - 1)
		{
			c1 = (10 * pow(10, count2));
			arrayplayer[len2] = (player_number % c1) / pow(10, count2);
			count2++;
		}
		int cheker = 0;
		printf("\n");
		int count_of_cow = 0, count_of_bik = 0;
		for (int i = 0; i < len; i++)
		{
			for (int j = 0; j < len; j++)
			{
				if (arraypc[i] == arrayplayer[j] && j == i)
				{
					count_of_bik++;
					cheker++;
				}
				if (arraypc[i] == arrayplayer[j] && j != i)
				{
					count_of_cow++;
				}
			}
		}
		printf("Count of bik: %d\n", count_of_bik);
		printf("Count of cow: %d\n", count_of_cow);
		count_of_cow = 0, count_of_bik = 0;
		if (cheker == len)
		{
			break;
		}
		cheker = 0;
	}
	printf("\n:) you win!!! it was number: %ld",chislo_prime);
}