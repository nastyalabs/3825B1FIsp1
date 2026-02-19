#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

struct Product {
	int barcode;
	char name[50];
	int quantity;
	int price;
	int discount;
};

struct Product product1 = { 1023, "Молоко Домик в деревне", 0, 98, 10 };
struct Product product2 = { 4567, "Чипсы Lay's сметана", 0, 145, 15 };
struct Product product3 = { 8901, "Сыр Российский", 0, 320, 20 };
struct Product product4 = { 2468, "Пельмени Сибирская коллекция", 0, 255, 25 };
struct Product product5 = { 1357, "Шоколад Alpen Gold", 0, 85, 5 };
int cheque[5] = { -1 };
int k=0;

int scan() {           /// скан товара
	int barcode, a = -1;;
	printf("Введите штрихкод товар:\n 1023, Молоко Домик в деревне;\n 4567, Чипсы Lay's сметана;\n 8901, Сыр Российский;\n 2468, Пельмени Сибирская коллекция;\n 1357, Шоколад Alpen Gold.\n\n");
	scanf_s("%d", &barcode);
	switch (barcode) {
	case 1023: 
		a = 1;
		break;
	case 4567:
		a = 2;
		break;
	case 8901:
		a = 3;
		break;
	case 2468:
		a = 4;
		break;
	case 1357:
		a = 5;
		break;
	default:
		printf("Вы ввели неправильный штрихкод.\n\n"); break;
	}
	return a;
}

int conclusion(int k) { /// вывод отсканированного товара
	switch (k) {
	case 1:
		printf("штрих-код:%d наименование:%s стоимость:%d скидка:%d\n\n", product1.barcode, product1.name, product1.price, product1.discount);break;
	case 2:
		printf("штрих-код:%d наименование:%s стоимость:%d скидка:%d\n\n", product2.barcode, product2.name, product2.price, product2.discount);break;
	case 3:
		printf("штрих-код:%d наименование:%s стоимость:%d скидка:%d\n\n", product3.barcode, product3.name, product3.price, product3.discount);break;
	case 4:
		printf("штрих-код:%d наименование:%s стоимость:%d скидка:%d\n\n", product4.barcode, product4.name, product4.price, product4.discount);break;
	case 5:
		printf("штрих-код:%d наименование:%s стоимость:%d скидка:%d\n\n", product5.barcode, product5.name, product5.price, product5.discount);break;
	default: printf("Вы не отсканировали товар."); break;
	}
	return 0;
}

int add_data(int a) {    /// добавление товара в чек
	int s = 0;
	switch (a) {
	case 1:
		product1.quantity++;
		if (product1.quantity == 1)
			s = 1;
		break;
	case 2:
		product2.quantity++;
		if (product2.quantity == 1)
			s = 2;
		break;
	case 3:
		product3.quantity++;
		if (product3.quantity == 1)
			s = 3;
		break;
	case 4:
		product4.quantity++;
		if (product4.quantity == 1)
			s = 4;
		break;
	case 5:
		product5.quantity++;
		if (product5.quantity == 1)
			s = 5;
		break;
	}
	if (s != 0) {
		cheque[k] = s;
		k++;
	}
	return 0;
}	

int summary_cheque() { /// Формирование чека
	int summ = 0;
	int total_summ = 0;
	for (int i = 0; i < 5; i++) {
		switch (cheque[i]) {
		case 1:
			printf("наименование:%s стоимость:%d количество: %d скидка:%d\n", product1.name, product1.price, product1.quantity, product1.discount);
			total_summ += product1.quantity * product1.price;
			summ += product1.quantity * product1.price * (100 - product1.discount) / 100; break;
		case 2:
			printf("наименование:%s стоимость:%d количество: %d скидка:%d\n", product2.name, product2.price, product2.quantity, product2.discount);
			total_summ += product2.quantity * product2.price;
			summ += product2.quantity * product2.price * (100- product2.discount) / 100; break;
		case 3:
			printf("наименование:%s стоимость:%d количество: %d скидка:%d\n", product3.name, product3.price, product3.quantity, product3.discount);
			total_summ += product3.quantity * product3.price;
			summ += product3.quantity * product3.price * (100 - product3.discount) / 100; break;
		case 4:
			printf("наименование:%s стоимость:%d количество: %d скидка:%d\n", product4.name, product4.price, product4.quantity, product4.discount);
			total_summ += product4.quantity * product4.price;
			summ += product4.quantity * product4.price * (100 - product4.discount) / 100; break;
		case 5:
			printf("наименование:%s стоимость:%d количество: %d скидка:%d\n", product5.name, product5.price, product5.quantity, product5.discount);
			total_summ += product5.quantity * product5.price;
			summ += product5.quantity * product5.price * (100- product5.discount) / 100; break;
		default: break;
		}
	}
	printf("Итоговая скидка: %d %\nИтоговая сумма: %d\n\n", 100-(summ*100 / total_summ)-1, summ);
	return summ;
}

int main() {
	int oper, a=-1, summ=0;
	setlocale(LC_ALL, "Rus");
	do {
		printf("Выберите операцию:\n 1 - сканировать товар;\n 2 - вывести описание отсканированного товара;\n 3 - добавить данные о товаре в чек;\n 4 - сформировать чек за покупку;\n 5 - расчитать итоговую сумму к оплате.\n\n");
		scanf_s("%d", &oper);
		switch (oper) {
		case 1:
			a = scan(); break;
		case 2:
			conclusion(a); break;
		case 3:
			add_data(a); break;
		case 4:
			summ = summary_cheque(); break;
		case 5:
			if (summ == 0) 
				printf("Чек ещё не сформирован. Сначала сформируйте чек (операция 4).\n");
			else
				printf("Итоговая сумма: %d", summ);
			break;
		default:
			printf("Ошибка.Выберите одну из предложенных операций.\n\n"); break;
		}
	} while (oper != 5);
	return 0;
}
