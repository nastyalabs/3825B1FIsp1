#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void main()
{
	srand(time(NULL));
	int gamemode, a = rand() % 1000, b, c, input;
	int check=0, count=0;
	char simvol;
	int d = 1000, d1 = 0;
	printf("Choise your game mode: ");
	scanf_s("%d", &gamemode);
	switch (gamemode)
	{
		case 1:
		{
			while (check != 5)
			{
				printf("Enter number: ");
				scanf_s("%d", &input);
				if (input > a)
				{
					printf("Unlucky, the hidden number is smaller, try again\n");
					count++;
				}
				if (input < a)
				{
					printf("Unlucky, the hidden number is bigger, try again\n");
					count++;
				}
				if (input == a)
				{
					printf("Woah, you get it, good job!\n");
					check = 5;
					count++;
					printf("%s%d", "Count of attempts: ", count);
				}
			}
			break;
		}
		case 2:
		{
			printf("Enter number that the PC will try to guess: ");
			scanf_s("%d", &b);
			while (check != 5)
			{
				c = rand() % d + d1;
				printf("%s%d\n", "I guess it's a ", c);
				printf("Enter >,< or = : ");
				scanf_s("%c\n", &simvol);
				if (simvol == '>')
				{
					d = 1000 - c;
					d1 = c;
				}
				else if (simvol == '<')
				{
					d = c;
					d1 = 0;
				}
				else if (simvol == '=')
				{
					break;
				}
			
	//я не понимаю, почему я ввожу любой символ, должно сначала выполнятся что в IF, но он сначала уходит на новый цикл, и только потом выполняет то, что в IF, получается некая задержкав 1 круг цикла
	//в итоге это все, что получилось сделать. Плюс сам алгоритм поиска получился корявым, в общем не пошла у меня 2 игра.
				count++;

			}
			printf("%s%d\n", "I understand it now, your guessed number is: ", c);
			printf("%s%d%s", "I understood this for ", count, " attempts, easy)");
			break;
		}
		default: return;
	}
}