#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
// Загадывает отгадывает число лаба 2
int random() {
	srand(time(NULL));
	return  0 + rand() % 1001;
}
int guess() 
{
	int in, rd;
	rd = random();
	
	printf("\nВаше предположение ---> ");
	do {
		
		scanf_s("%d", &in);
		if (in < 0 || in>1000) { printf("\n\nПожалуйста введите число от 0 до 1000\n----> "); }
		
	} while (in < 0 || in>1000);
	while (in != rd) 
	{
		if (in > rd) { printf("\n\nЗагаданное число меньше, попробуйте еще раз ----> "); }
		else { printf("\n\nЗагаданное число больше, попробуйте еще раз ----> "); }
		
		do 
		{
			scanf_s("%d", &in);
			if (in < 0 || in > 1000) { printf("\nПожалуйста введите число от 0 до 1000 "); }
		} while (in < 0 || in > 1000);
	}
	if (in == rd) { printf("\n\nПоздравляю вы отгадали число ----> %d", in); }

}
int proverka(int a, int b, int otvet) 
{
	int fl=1;
	char inp[2];
	printf("\n\n Ваше число относительно %d <, >, = ?\n---> ", otvet);

	
	while (fl == 1) {
		scanf_s("%s", &inp, 2);
		switch (inp[0]) {
		case '<':
			a = a;
			b = otvet;
			fl = 0;
			return 2;
			break;

		case '>':
			a = otvet;
			b = b;
			fl = 0;
			return 3;
			break;

		case '=':
			otvet = otvet;
			fl = 0;
			return 1;
			break;
		default: printf("\n\nПожалуйста введите корректный символ\n---> ");fl = 1;break;
		}
	}

}

int asked() 
{
	int otvet, a, b, flag=0;
	a = 0;
	b = 1000;
	while (flag == 0) {
		otvet =(b-a)/2+a;
		switch (proverka(a, b, otvet)) {
		case 1:
			printf("\nВаше число %d", otvet);
			flag = 1;
			break;
		case 2:
			b = otvet;
			break;
		case 3:
			a = otvet;
			break;
		}
	}



}
int main() 
{
	int flag = 1, answer;
	int menu;
	setlocale(0, "Rus");
	

	
	do {
		printf("\n\n---------------------------------------\n1 - Отгадай мое число\n2 - Загадай число я отгадаю\n0 - Выйти\n----> ");
		scanf_s("%d", &menu);
		printf("---------------------------------------\n");

		if (menu < 0 || menu > 2) { printf("\n\nПожалуйста введите коррекнтыное значение\n\n"); }
		else {
			switch (menu)
			{
			case 1:
				asked();
				break;
			case 2:
				guess();
				break;
			case 0:
				flag = 0;
				break;
			}
			}

	} while (menu < 0 || menu > 2|| flag == 1 );
	

	}
	


