#include <stdio.h>
#include <math.h>
#include <locale.h>
#include <stdlib.h>

void game()
{
	int man[10], pc[10],out[5]= {-1,-1,-1,-1,-1}, len, inp, num = 0;
	
	do 
	{
		printf("\n\nВведите длину числа от 2 до 5\n-----> ");
		scanf_s("%d", &len);

	} while (len < 2 || len>5);
	
	printf("\n\nВведите число длины %d поразрядно, начиная со старшего\n", len);
	len = len - 1;
	
	for (int i = 0;i <= len;) {
		printf("\n----> ");
		
		if (i == 0) 
		{
			do
			{
				scanf_s("%d", &inp);
				if (inp < 1 || inp > 9) { printf("\n\nВведите цифру 1-9\n----> "); }
				
			} while (inp<1 || inp>9);
			man[i] = inp;
		}

		else 
		{
			do
			{
				scanf_s("%d", &inp);
				if (inp < 0 || inp > 9) { printf("\n\nВведите цифру 0-9\n----> "); }
				
			} while (inp < 0 || inp > 9);
			man[i] = inp;
			
		}
		i++;
	}

//pc creat random number
	
	printf("\nЧисло пк ---> ");
	for (int i = 0; i <= len;) 
	{
		int flag = 1;
		int set = randm();

		for (int j=0; j < i;) 
		{
			if (set == pc[j]) { flag = 0;break; }
			j++;
		}
		if (flag == 1 && pc[0] != 1) { pc[i] = set;printf("%d", pc[i]);i++; }
		
	}
	
//pc & man i0 -- in == j0 -- jn
	for (int i =0;i <= len;)
	{
		for (int j=0; j <= len;)
		{
			if (pc[i] == man[j]) { num = num + 1;out[i]=pc[i];break; }
			j++;
		}
		i++;

	}

//pc & man i=j
	printf("\n\nСовпадений цифр по позициям ---> ");
	for (int i = 0; i<= len;)
	{
		if (pc[i] == man[i]) { printf(" %d", pc[i]); }
		else { printf(" -"); }
		i++;
	}
	printf("\nВсего совпавших цифр %d (", num);
	for (int i = 0; i < 5;) { if (out[i] > -1) { printf(" %d ", out[i]); } i++; }
	printf(")");
}


int randm()
{
	srand(time(NULL));
	return 0 + rand() % 10;
}
void main() 
{
	int flag;
	setlocale(0, "Rus");
	do {
		
		printf("\n\n\n--__--__--__--__--__--__--__--__--__--__\nНачать - 1\nВыйти - 0\n-----> ");
		scanf_s("%d", &flag);
		printf("\n__--__--__--__--__--__--__--__--__--__--\n");
		if (flag == 1) { game(); }
	
	} while(flag == 1);
	



}