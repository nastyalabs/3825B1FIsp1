#include <stdio.h>
#include <clocale>

int t1 = 0, t2 = 0, t3 = 0, t4 = 0, t5 = 0, t6 = 0, t7 = 0, t8 = 0, t9 = 0;
int total = 0;
int total_discount = 0; 


void ScanAndDescribe() {
    int kod = 0;
    printf("Введите штрих-код (4 цифры): ");
    scanf_s("%d", &kod);
    

    if (kod == 1111) {
        printf("Товар: молоко\nЦена за единицу: 100 руб\nСкидка: 10%%\n");
    }
    else if (kod == 2222) {
        printf("Товар: хлеб\nЦена за единицу: 40 руб\nСкидка: 5%%\n");
    }
    else if (kod == 3333) {
        printf("Товар: яйца\nЦена за единицу: 120 руб\nСкидка: 15%%\n");
    }
    else if (kod == 4444) {
        printf("Товар: колбаса\nЦена за единицу: 200 руб\nСкидка: 20%%\n");
    }
    else if (kod == 5555) {
        printf("Товар: сыр\nЦена за единицу: 300 руб\nСкидка: 10%%\n");
    }
    else if (kod == 6666) {
        printf("Товар: творог\nЦена за единицу: 250 руб\nСкидка: 15%%\n");
    }
    else if (kod == 7777) {
        printf("Товар: пирог\nЦена за единицу: 70 руб\nСкидка: 5%%\n");
    }
    else if (kod == 8888) {
        printf("Товар: конфеты\nЦена за единицу: 250 руб\nСкидка: 25%%\n");
    }
    else if (kod == 9999) {
        printf("Товар: майонез\nЦена за единицу: 150 руб\nСкидка: 10%%\n");
    }
    else {
        printf("Товар не найден!\n");
        return;
    }

    
    char choice;
    printf("Добавить в чек? (+/-): ");
    scanf_s(" %c", &choice, 1);

    if (choice == '+') {
        if (kod == 1111) { t1++; printf("Молоко добавлено в чек\n"); }
        else if (kod == 2222) { t2++; printf("Хлеб добавлен в чек\n"); }
        else if (kod == 3333) { t3++; printf("Яйца добавлены в чек\n"); }
        else if (kod == 4444) { t4++; printf("Колбаса добавлена в чек\n"); }
        else if (kod == 5555) { t5++; printf("Сыр добавлен в чек\n"); }
        else if (kod == 6666) { t6++; printf("Творог добавлен в чек\n"); }
        else if (kod == 7777) { t7++; printf("Пирог добавлен в чек\n"); }
        else if (kod == 8888) { t8++; printf("Конфеты добавлены в чек\n"); }
        else if (kod == 9999) { t9++; printf("Майонез добавлен в чек\n"); }
    }
}


void Check() {
    printf("\nЧек:\n");
    total = 0;
    total_discount = 0;

    if (t1 > 0) {
        int price = 100 * t1;
        int discount = price * 10 / 100;
        printf("Молоко - 100 руб - %d шт - %d руб (скидка: %d руб)\n", t1, price - discount, discount);
        total += price;
        total_discount += discount;
    }
    if (t2 > 0) {
        int price = 40 * t2;
        int discount = price * 5 / 100;
        printf("Хлеб - 40 руб - %d шт - %d руб (скидка: %d руб)\n", t2, price - discount, discount);
        total += price;
        total_discount += discount;
    }
    if (t3 > 0) {
        int price = 120 * t3;
        int discount = price * 15 / 100;
        printf("Яйца - 120 руб - %d шт - %d руб (скидка: %d руб)\n", t3, price - discount, discount);
        total += price;
        total_discount += discount;
    }
    if (t4 > 0) {
        int price = 200 * t4;
        int discount = price * 20 / 100;
        printf("Колбаса - 200 руб - %d шт - %d руб (скидка: %d руб)\n", t4, price - discount, discount);
        total += price;
        total_discount += discount;
    }
    if (t5 > 0) {
        int price = 300 * t5;
        int discount = price * 10 / 100;
        printf("Сыр - 300 руб - %d шт - %d руб (скидка: %d руб)\n", t5, price - discount, discount);
        total += price;
        total_discount += discount;
    }
    if (t6 > 0) {
        int price = 250 * t6;
        int discount = price * 15 / 100;
        printf("Творог - 250 руб - %d шт - %d руб (скидка: %d руб)\n", t6, price - discount, discount);
        total += price;
        total_discount += discount;
    }
    if (t7 > 0) {
        int price = 70 * t7;
        int discount = price * 5 / 100;
        printf("Пирог - 70 руб - %d шт - %d руб (скидка: %d руб)\n", t7, price - discount, discount);
        total += price;
        total_discount += discount;
    }
    if (t8 > 0) {
        int price = 250 * t8;
        int discount = price * 25 / 100;
        printf("Конфеты - 250 руб - %d шт - %d руб (скидка: %d руб)\n", t8, price - discount, discount);
        total += price;
        total_discount += discount;
    }
    if (t9 > 0) {
        int price = 150 * t9;
        int discount = price * 10 / 100;
        printf("Майонез - 150 руб - %d шт - %d руб (скидка: %d руб)\n", t9, price - discount, discount);
        total += price;
        total_discount += discount;
    }
}


void SummCheck() {
    printf("\nИтог:\n");
    printf("Общая стоимость товаров: %d руб\n", total);
    printf("Суммарная скидка: %d руб\n", total_discount);
    printf("Итого к оплате: %d руб\n", total - total_discount);
}


int main() {
    setlocale(LC_ALL, "Russian");

    int choice = 0;

    while (1) {
        printf("\nВыберите действие:\n");
        printf("1. Сканировать товар\n");
        printf("2. Сформировать чек\n");
        printf("3. Рассчитать сумму\n");
        printf("4. Выход\n");
        printf("Выберите действие: ");
        scanf_s("%d", &choice);

        switch (choice) {
        case 1:
            ScanAndDescribe();
            break;
        case 2:
            Check();
            break;
        case 3:
            SummCheck();
            break;
        case 4:
            return 0;
        default:
            printf("Неверный выбор!\n");
        }
    }
}