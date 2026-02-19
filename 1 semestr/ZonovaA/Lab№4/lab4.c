#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<math.h>
#include<string.h>
#include<ctype.h>

#define SIZE 4
#define MAX_PROD 5
#define NAME_LEN 50

//у программы есть режимы 1-сканировать товар 2-вывести описание отсканированного товара 3-добавить данные о товаре в чек 4-сформировать чек за покупку 5-рассчитать итоговую сумму к оплате
//хранение данных о товаре
char product_code[MAX_PROD][SIZE + 1];
char product_name[MAX_PROD][NAME_LEN];
int product_price[MAX_PROD];
int product_skidon[MAX_PROD];

//хранение данных чека
char chek_code[MAX_PROD][SIZE + 1];
int chek_kolvo[MAX_PROD];
int chek_curcnt = 0;

//текущий отсканированный товар
char scan_code[SIZE + 1];
int scan_index = -1;

//функция инициализации базы данных товаров
void vvod_product_base() {
	//штрихкоды strcpy - функция для копирования строки
	strcpy(product_code[0], "1234");
	strcpy(product_code[1], "5678");
	strcpy(product_code[2], "9012");
	strcpy(product_code[3], "3456");
	strcpy(product_code[4], "7890");

	//названия
	strcpy(product_name[0], "Hleb");
	strcpy(product_name[1], "Moloko");
	strcpy(product_name[2], "Kefir");
	strcpy(product_name[3], "Kuriza");
	strcpy(product_name[4], "Banan");

	//цены
	product_price[0] = 40;
	product_price[1] = 90;
	product_price[2] = 95;
	product_price[3] = 300;
	product_price[4] = 20;

	//скидки
	product_skidon[0] = 3;
	product_skidon[1] = 4;
	product_skidon[2] = 3;
	product_skidon[3] = 5;
	product_skidon[4] = 3;
}

//функция поиска товара по коду
int find_product(const char* code) {
	for (int i = 0; i < MAX_PROD; i++) {
		if (strcmp(product_code[i], code) == 0) {//strcmp - функция сравнения строк, если она равна 0, то строки идентичны
			return i; //товар найден
		}
	}
	return -1; //товар не найден
}

//функция сканирования товара
int scan_product(const char* code) {
	//проверки
	if (strlen(code) != SIZE) {
		printf("Error: code need lenght %d!\n", SIZE);
		return 0;
	}
	for (int i = 0; i < SIZE; i++) {
		if (code[i] < 0 && code[i] > 9) {
			printf("Error: code need only number(0...9)!\n");
			return 0;
		}
	}

	int prod_ind = find_product(code);
	if (prod_ind == -1) {
		printf("Product this code not find!\n");
		return 0;
	}
	strcpy(scan_code, code);
	scan_index = prod_ind;
	printf("Product scan right!\n");
	return 1;

}

//вывод отсканированного продукта
void opis_scan_prod() {
	if (scan_index == -1) {
		printf("Now scan product!\n");
		return;
	}
	int price_with_skidon = product_price[scan_index] - (product_price[scan_index] * product_skidon[scan_index] / 100);
	printf("\n=== OPISANIE PRODUCT ===\n");
	printf("Code: %s\n", scan_code);
	printf("Name product: %s\n", product_name[scan_index]);
	printf("Price: %d rubles\n", product_price[scan_index]);
	printf("Skidon: %d%%\n", product_skidon[scan_index]);
	printf("Price with skidon: %d rubles\n", price_with_skidon);
	printf("============================\n");
}

//добавление товара в чек
void dobav_chek(int kolvo) {
	if (scan_index == -1) {
		printf("Now scan product!\n");
		return;
	}
	if (kolvo <= 0) {
		printf("Error: kol - vo product need plus!\n");
		return;
	}
	//есть ли такой товар в чеке
	for (int i = 0; i < chek_curcnt; i++) {
		if (strcmp(chek_code[i], scan_code) == 0) {
			//товар уже есть в чеке увличиваем кол-во
			chek_kolvo[i] += kolvo;
			printf("Kolvo product '%s' up with %d\n", product_name[scan_index], chek_kolvo[i]);
			return;
		}
	}
	//новый товар
	if (chek_curcnt >= MAX_PROD) {
		printf("Error: max kolvo position in chek!\n");
		return;
	}
	strcpy(chek_code[chek_curcnt], scan_code);
	chek_kolvo[chek_curcnt] = kolvo;
	chek_curcnt++;
	printf("Product '%s' in chek his kolvo = %d\n", product_name[scan_index], kolvo);
}

//расчет итоговых сумм
void raschet(int* itog_price, int* itog_skidon, int* final) {
	*itog_price = 0;
	*itog_skidon = 0;
	*final = 0;

	for (int i = 0; i < chek_curcnt; i++) {
		int product_index = find_product(chek_code[i]);
		if (product_index != -1) {
			int curitog = product_price[product_index] * chek_kolvo[i];
			int curskidon = (product_price[product_index] * product_skidon[product_index] / 100) * chek_kolvo[i];
			*itog_price += curitog;
			*itog_skidon += curskidon;
		}
	}
	*final = *itog_price - *itog_skidon;
}

//формирование и вывод чека
void chek() {
	if (chek_curcnt == 0) {
		printf("Now scan product!\n");
		return;
	}
	int itog_price, itog_skidon, final;
	raschet(&itog_price, &itog_skidon, &final);
	printf("\n");
	printf("==========================================\n");
	printf("                 CHEK                     \n");
	printf("==========================================\n");
	printf("Name -- Price -- Kol-vo -- Summa\n");
	printf("-----------------------------------------\n");
	for (int i = 0; i < chek_curcnt; i++) {
		int product_index = find_product(chek_code[i]);
		if (product_index != -1) {
			int curfinalprice = (product_price[product_index] - (product_price[product_index] * product_skidon[product_index] / 100)) * chek_kolvo[i];
			printf("%s - %d - %d - %d rubles\n", product_name[product_index], product_price[product_index], chek_kolvo[i], curfinalprice);
		}
	}
	printf("-----------------------------------------\n");
	printf("All summa: %d rubles\n", itog_price);
	printf("Summa skidon: %d rubles\n", itog_skidon);
	printf("FINAL BY PAY: %d rubles\n", final);
	printf("==========================================\n");
}

//вывод итоговой суммы к оплате
void print_final() {
	if (chek_curcnt == 0) {
		printf("Now scan product!\n");
		return;
	}

	int itog_price, itog_skidon, final;
	raschet(&itog_price, &itog_skidon, &final);
	printf("\nFINAL BY PAY: %d rubles\n", final);
}

//отображение всех товаров в базе
void all_product() {
	printf("\n=== ALL PRODUCTS IN BASE ===\n");
	for (int i = 0; i < MAX_PROD; i++) {
		int price_with_skidon = product_price[i] - (product_price[i] * product_skidon[i] / 100);
		printf("%s - %s - %d rubles - %d%% skidon (%d rubles)\n", product_code[i], product_name[i], product_price[i], product_skidon[i], price_with_skidon);
	}
	printf("==========================================\n");
}

//отображение меню
void menu() {
	printf("\n=== KASSA ===\n");
	printf("1.Scan product\n");
	printf("2.Show opisanie with product\n");
	printf("3.Plus product with chek\n");
	printf("4.Show chek\n");
	printf("5.Final summa raschet\n");
	printf("6.Show all products\n");
	printf("0.Exite\n");
	printf("Operation: ");
}

//инициализация чека
void ini_chek() {
	chek_curcnt = 0;
	scan_index = -1;
}

int main() {
	char code_input[SIZE + 1];
	int cnt, kolvo;
	vvod_product_base();
	ini_chek();

	printf("Welcome in the kassa!\n");

	while (1) {
		menu();
		scanf("%d", &cnt);

		switch (cnt) {
		case 1:
			printf("Input code (%d number): ", SIZE);
			scanf("%4s", code_input);
			scan_product(code_input);
			break;
		case 2:
			opis_scan_prod();
			break;
		case 3:
			if (scan_index == -1) {
				printf("Now scan product!\n");
				break;
			}
			printf("Input kolvo: ");
			scanf("%d", &kolvo);
			dobav_chek(kolvo);
			break;
		case 4:
			chek();
			break;
		case 5:
			print_final();
			break;
		case 6:
			all_product();
			break;
		case 0:
			printf("Exite in programm. By!\n");
			return 0;
		default:
			printf("Not right choice! Try again.\n");
		}
	}
	return 0;
}