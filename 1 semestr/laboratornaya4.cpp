#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
void product_list()
{
	printf("Product list: \n");
	printf("1. Bread 50p. -10%% (previous price - 55 p.) (1578)\n");
	printf("2. Milk 100p. -5%% (previoust price - 105 p.) (3479)\n");
	printf("3. Energy drink 90p. -10%% (previous price -100 p.)(2567)\n");
	printf("4. Rice 200p. -10%% (previous price - 220 p.) (3751)\n");
	printf("5. Eggs 10 100p. -25%% (previous price - 125 p.) (4612)\n");
	printf("6. Sausage 250p. -26%% (previous price - 315 p.) (2091)\n");
	printf("7. Coffee arabika very tasty 500p. -50%% (previous prise - 1000 p.) (3481)\n");
}
void main()
{
	product_list();
	srand(time(NULL));
	int barcode, decision;
	int arr_barcode[4];
	int check[7] = { 0 };
	int final_decision = 0, final_summ = 0, final_discount = 0;
	while (final_decision != 2)
	{
		printf("\n\nWhat do you want to do?\n");
		printf("1. Scan new barcode\n");
		printf("2. Calculate the final summ\n");
		printf("\n-----> ");
		scanf_s("%d", &decision);
		switch (decision)
		{
		case 1:
		{
			printf("\nInput a barcode: ");
			scanf_s("%d", &barcode);
			int count = 4;
			int barcode1 = barcode;
			while (barcode > 0)
			{
				arr_barcode[count=count-1] = barcode % 10;
				barcode = barcode / 10;
			}
			
			switch (barcode1)
			{
			case 1578: check[0]++; printf("Bread 50p."); break;
			case 3479: check[1]++; printf("Milk 100p."); break;
			case 2567: check[2]++; printf("Energy drink 90p."); break;
			case 3751: check[3]++; printf("Rice 200p."); break;
			case 4612: check[4]++; printf("Eggs 10 100p."); break;
			case 2091: check[5]++; printf("Sausage 250p."); break;
			case 3481: check[6]++; printf("Coffee arabika very tasty 500p."); break;
			default: printf("there is no product with this barcode");
			}
			break;
		}
		case 2: final_decision=2;
		default: break;
		}
	}
	printf("Check: \n");
	for (int i = 0; i < 7; i++)
	{
		if (check[i] > 0)
		{
			switch (i)
			{
			case 0: printf("%dx bread -- %d p.\n", check[i], check[i] * 50); final_discount = final_discount + (5 * check[i]); final_summ = final_summ + 50 * check[i]; break;
			case 1: printf("%dx milk -- %d p.\n", check[i], check[i] * 100); final_discount = final_discount + (5 * check[i]); final_summ = final_summ + 100 * check[i]; break;
			case 2: printf("%dx energy drink -- %d p.\n", check[i],check[i]*90); final_discount = final_discount + (10 * check[i]); final_summ = final_summ + 90 * check[i]; break;
			case 3: printf("%dx rice -- %d p.\n", check[i],check[i]*200); final_discount = final_discount + (20 * check[i]); final_summ = final_summ + 200 * check[i]; break;
			case 4: printf("%dx eggs -- %d p.\n", check[i],check[i]*100); final_discount = final_discount + (25 * check[i]); final_summ = final_summ + 100 * check[i]; break;
			case 5: printf("%dx sausage -- %d p.\n", check[i],check[i]*250); final_discount = final_discount + (65 * check[i]); final_summ = final_summ + 250 * check[i]; break;
			case 6: printf("%dx coffee aravica very tasty -- %d p.\n", check[i],check[i]*500); final_discount = final_discount + (500 * check[i]); final_summ = final_summ + 500 * check[i]; break;
			}
		}
	}
	printf("\nFinal summ -- %d p.\n",final_summ);
	printf("Final discount -- %d p.", final_discount);
}