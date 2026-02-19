#include <stdio.h>
#include <locale.h>
#include<math.h>
#include <stdlib.h>
#include <string.h>
//kod[<категория>,<товар>,<вес>,<цена*вес*коеф>]
// категории 0 - жидкость 1 - снеки 2- яйица 3- сладости 4- хлеббулочные
// товары (0) 0- вода 1 молоко  (1)- 0- сухарики 1- чипсы (2) 0 - С0 1 - С1 (3) 0- печенье 1- конфеты (4) 0 - батон 1 - буханка серого 
// пример вода 0.2-0.5-1.0=20-40-(60-90-102-120) (0000 - 0010 - 0020-0021-0022-0023)


int cost(int kod[4], int koef)
{
	int kg=0, cs=0;
	printf(" Вес: ");
	if (kod[2] == 0) { printf(" 0.2kg "); kg = 2; }
	if (kod[2] == 1) { printf(" 0.5kg "); kg = 4; }
	if (kod[2] == 2) { printf(" 1kg ");kg = 6; }
	printf(" Цена: ");
	if (kod[3] == 0) { printf("%d",(cs=10*kg*koef) ); }
	if (kod[3] == 1) { printf("%d", (cs=15 * kg * koef)); }
	if (kod[3] == 2) { printf("%d", (cs=17 * kg * koef)); }
	if (kod[3] == 3) { printf("%d", (cs=20 * kg * koef)); }
	return cs;
}

// Функции распределения категории товара из outkod()
int kat0(int kod[4])
{
	int koef;
	printf("\n\nТовар: ");
	switch (kod[1]) {
	case 0:
		printf("\nВода ");
		koef = 1;
		break;
	case 1:
		printf("\nМолоко ");
		koef = 2;
		break;
}
	return cost(kod, koef);
}
int kat1(int kod[4]) 
{
	printf("\n\nТовар: ");
	switch (kod[1]) {
	case 0:
		printf("\nСухарики (Три Корки) ");
		break;
	case 1:
		printf("\nЧипсы (Картофан) ");
		break;
	}
	return cost(kod, 1);
}
int kat2(int kod[4]) 
{
	printf("\n\nТовар: ");
	switch (kod[1]) {
	case 0:
		printf("\nЯйица С0 ");
		break;
	case 1:
		printf("\nЯйица С1 ");
		break;
	}
	return cost(kod, 3);
}
int kat3(int kod[4]) 
{
	printf("\nТовар: ");
	switch (kod[1]) {
	case 0:
		printf("\nПеченье (Хрумка) ");
		break;
	case 1:
		printf("\nКонфеты (Кот Барис) ");
		break;
	}
	return cost(kod, 4);
}
int kat4(int kod[4]) 
{
	printf("\n\nТовар: ");
	switch (kod[1]) {
	case 0:
		printf("\nБатон (Городецкий) ");
		break;
	case 1:
		printf("\nБуханка Серого (Балахнинский) ");
		break;
	}
	return cost(kod, 1);
}

//Функция вывода продукта
int outkod(int kod[4])
{
	switch(kod[0]) // категория 
	{
	case 0 :
		return kat0(kod);
		break;
	case 1:
		return kat1(kod);
		break;
	case 2:
		return kat2(kod);
		break;
	case 3:
		return kat3(kod);
		break;
	case 4:
		return kat4(kod);
		break;
	}
	
}



// Функция проверки занятости позиции
int notpoz(int poz[20][4])
{
	int flag = 1;
	for (int i = 0; i < 19;)
	{
		if (poz[i][0] == -1)
		{
			flag = 0;
			return i;
			
		
		}
		else { i++; }
		
	}
	if (flag == 1) { return -1; }
}

void scan(int (poz)[20][4])
{
	int kod[4],qr,clear, schet = 0,flag=0;
	if (notpoz(poz) == -1) { printf("\n\nК сожалению корзина заполнена, добавте этот товар в следущую покупку."); }
	else 
	{
		do {
			schet = 0;
			while ((clear = getchar()) != '\n' && clear != EOF);
			int i = 0;
			printf("\n\nВведите штрихкод **** ----> ");

			while ((qr = getchar()) != '\n' && qr != EOF)
			{
				kod[i] = qr - '0';
				schet++;

				i++;

			}
			if (kod[0] < 0 || kod[0]>4 || kod[1] < 0 || kod[1]>1 || kod[2] < 0 || kod[2]>2 || kod[3] < 0 || kod[3]>3) { flag = 1;printf("\nК сожалению такого кода не существует, попробуйте еще раз "); }
			printf("%d", schet);
		} while (schet != 4);
		if (flag == 0) {
			outkod(kod);
			printf("\n\n\nДобавить в корзину ?\n 0 - нет   1 - да\n ----> ");
			scanf_s("%d", &flag);
			if (flag == 1)
			{
				int	i = notpoz(poz);
				for (int j = 0; j < 4;)
				{
					poz[i][j] = kod[j]; j++;
				}
			}
		}
	}
}

	


void chek(int poz[20][4])
{
	int sum = 0, pr = 0, inpt=0, pozih = 0;
	int j = notpoz(poz);
	if (j == -1) { j = 18; }
	printf("\n");
	
	for (int i = 0; i < j; )
	{	
		printf("\n%d. ", pozih);
		pr = outkod(poz[i]);
		sum = sum + pr ;
		i++;
		pozih++;
	}
	
	poz[19][3] = sum;
	printf(" \n\nИтого к оплате: %d", sum);
	do {
		printf("\n\nУдалить товар?\n0 - нет \n1 - да\n---> ");
		scanf_s("%d", &inpt);
	} while (inpt < 0 || inpt > 1);
	if (inpt == 1)
	{//[ kod -1 kod kod -1 kod kod -1 -1 .. sum]
		printf("\n\nВведите позицию\n---> ");
		scanf_s("%d", &inpt);
		poz[inpt][0] = -1;
		int i = inpt;
		
		while (i < j) {int s = 0; while (s < 4) { poz[i][s] = poz[i + 1][s]; s++; } i++; }
		poz[j-1][0] = -1;
		chek(poz);
	}
	else { printf("\n-------------------"); }
	
	

}

void sbp(int poz[20][4])
{
	chek(poz);
	int inp, price = poz[19][3];
	printf("\n\nВведите желаемую скидку\n----> ");
	scanf_s("%d", &inp);
	if (inp > 10) { printf("Увы, максимальная скидка 10% "); price = price - (price * inp / 100); }
	if (inp <= 10) { printf("Поздравляю, ваша скидка будет 10% "); price =  price - (price * inp / 100);}
	do {
	printf("\n\nВыберете способ оплаты\n 0 - Card  1 - Наличка\n\n---> ");
	scanf_s("%d", &inp);
	} while (inp<0 || inp>1);
	printf("\n\nК оплате %d\nСпасибо за покупку!", price);

}

void main()
{
	int inp;
	int poz[20][4];
	memset(poz, -1, sizeof(poz));
	setlocale(0, "Rus");
	do {
		printf("\n\n------------------\n 1 - Сканировать\n 2 - Сформировать чек\n 3 - Оплата\n 0 - Выйти\n----> ");
		scanf_s("%d", &inp);
		printf("\n------------------");
		switch (inp)
		{ 
		case 1:
			scan(poz);
			break;
		case 2:
			chek(poz);
			break;
		case 3:
			sbp(poz);
			break;
		case 0:
			printf("\nПриходите к нам еще!");
		}
	} while (inp != 0);
	
}
