#include<stdio.h>
#include<locale>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define Max_Product 15
#define Max_Cart_Size 50

typedef struct {
	char barcode[5];
	char description[20];
	int price;
	int discount;
} product;

typedef struct {
	product item;
	int cnt;
} cart_item;

product product_base[Max_Product] = {
	{"5612", "Батон", 50, 5},
	{"1542", "Молоко", 102, 10},
	{"6134", "Сыр", 380, 13},
	{"1948", "Пасатижи", 500, 6},
	{"6932", "Кола", 120, 10},
	{"9817", "Колбаса", 560, 50},
	{"4531", "Шоколад", 150, 25},
	{"3217", "Мармелад", 80, 32},
	{"4865", "Чипсы", 224, 10},
	{"2375", "Сытник", 45, 5}
};

int size_of_base = sizeof(product_base) / sizeof(product);
cart_item cart[Max_Cart_Size];
int cart_size = 0;
product last_scanned;
int scanned = 0;

void scan() {
    printf("\nОтсканируйте товар (Введите штрих-код): ");
	char temp_barcode[5];
	scanf("%4s", temp_barcode);
	int f = 0;

	int found = -1;
    for (int i = 0; i < size_of_base; i++) {
        if (strcmp(product_base[i].barcode, temp_barcode) == 0) {
            found = i;
            break;
        }
    }

    if (found == -1) {
        printf("\nДанного товара нет в базе\n");
        scanned = 0;
    } else {
        last_scanned = product_base[found];
        scanned = 1;
        printf("\nТовар найден: %s - %s\n", last_scanned.barcode, last_scanned.description);
    }
}

void print_description() {
    if (!scanned) {
        printf("\nСначала отсканируйте товар\n");
        return;
    }
    printf("\nОписание товара:\n");
    printf("Штрих-код: %s\n", last_scanned.barcode);
    printf("Название: %s\n", last_scanned.description);
    printf("Цена: %d руб.\n", last_scanned.price);
    printf("Скидка: %d%%\n", last_scanned.discount);
}

void add_in_receipt() {
    if (!scanned) {
        printf("\nСначала отсканируйте товар\n");
        return;
    }

    int found = -1;
    for (int i = 0; i < cart_size; i++) {
        if (strcmp(cart[i].item.barcode, last_scanned.barcode) == 0) {
            found = i;
            break;
        }
    }

    if (found != -1) {
        cart[found].cnt++;
        printf("\nТовар \"%s\" добавлен, текущее количество: %d\n", last_scanned.description, cart[found].cnt);
    } else {
        cart[cart_size].item = last_scanned;
        cart[cart_size].cnt = 1;
        printf("\nТовар \"%s\" добавлен, текущее количество: 1\n", last_scanned.description);
        cart_size++;
    }
    scanned = 0;
}

void print_receipt() {
    if (scanned){
        printf("\nСначала добавьте последний продукт в корзину\n");
        return;
    }
    if (cart_size == 0) {
        printf("\nКорзина пустая!\n");
        return;
    }

    printf("\n========== ЧЕК ==========\n");
    printf("№  Штрих-Код  Название     Цена  Скидка  Кол-во  Сумма\n");
    printf("---------------------------------------------------------\n");
    int total = 0;
    for (int i = 0; i < cart_size; i++) {
		int price_with_discount = cart[i].item.price * (100 - cart[i].item.discount) / 100;
        int sum = price_with_discount * cart[i].cnt;
        total += sum;
        printf("%-2d %-10s %-12s %-5d %-7d %-7d %-6d\n",
               i + 1,
               cart[i].item.barcode,
               cart[i].item.description,
               cart[i].item.price,
               cart[i].item.discount,
               cart[i].cnt,
               sum);
    }
    printf("---------------------------------------------------------\n");
}

void calc_total_sum() {
    if (scanned){
        printf("\nСначала добавьте последний продукт в корзину\n");
        return;
    }
    if (cart_size == 0) {
        printf("\nКорзина пуста!\n");
        return;
    }

    int total = 0;
    for (int i = 0; i < cart_size; i++) {
        int price_with_discount = cart[i].item.price * (100 - cart[i].item.discount) / 100;
        total += price_with_discount * cart[i].cnt;
    }
	
	printf("\n==========================");
    printf("\nСУММА К ОПЛАТЕ: %d руб.\n", total);
    printf("==========================\n");
}

int main(){
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

	printf("  \"Электронная кассса\"\n");

	printf("\nДоступные штрих-коды: ");
	for (int i = 0; i < size_of_base; i++){
		printf("%s ", product_base[i].barcode);
	}
	printf("\n");

	printf("\nДоступные операции:\n1 - Сканировать товар\n2 - Описание отсканированного товара\n3 - Добавить данные о товаре в чек\n");
	printf("4 - Сформировать чек за покупку\n5 - Рассчитать итоговую сумму\n0 - выйти из программы\n");
	int op = 100;
	while (op){
		printf("\nВыберите операцию: "); scanf("%d", &op);
		switch (op){
		case 1:
			scan();
			break;
		case 2:
			print_description();
			break;
		case 3:
			add_in_receipt();
			break;
		case 4:
			print_receipt();
			break;
		case 5:
			calc_total_sum();
			break;
		default:
			if (op != 0) printf("\nВведите другой номер операции\n");
		}
	}

    return 0;
}
