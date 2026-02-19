#include <stdio.h>
#include <string.h>
#include <locale.h>
#define MAX_NAME 50
#define MAX_ITEMS 50
typedef struct {
    char barcode[5];     
    char name[MAX_NAME];
    int price;           
    int discount;        
} Product;
typedef struct {
    Product product;
    int count;
} ReceiptItem;
Product products[5] = {
    {"1234", "Хлеб", 50, 10},
    {"2345", "Молоко", 80, 5},
    {"3456", "Сыр", 300, 20},
    {"4567", "Яблоки", 120, 15},
    {"5678", "Кофе", 500, 30}
};
ReceiptItem receipt[MAX_ITEMS];
int receiptSize = 0;
Product* lastScanned = NULL;
Product* findProduct(char code[]) {
    for (int i = 0; i < 5; i++) {
        if (strcmp(products[i].barcode, code) == 0)
            return &products[i];
    }
    return NULL;
}
void printProduct(Product* p) {
    if (p == NULL) {
        printf("Товар не найден.\n");
        return;
    }
    printf("Наименование: %s\n", p->name);
    printf("Цена: %d руб\n", p->price);
    printf("Скидка: %d%%\n", p->discount);
}
void addToReceipt(Product* p) {
    if (!p) {
        printf("Сначала отсканируйте товар.\n");
        return;
    }
    for (int i = 0; i < receiptSize; i++) {
        if (strcmp(receipt[i].product.barcode, p->barcode) == 0) {
            receipt[i].count++;
            printf("Добавлено. Теперь количество: %d\n", receipt[i].count);
            return;
        }
    }
    receipt[receiptSize].product = *p;
    receipt[receiptSize].count = 1;
    receiptSize++;
    printf("Товар добавлен в чек.\n");
}
int calculateTotal() {
    int total = 0;
    for (int i = 0; i < receiptSize; i++) {
        int price = receipt[i].product.price;
        int disc = receipt[i].product.discount;

        int discounted = price - (price * disc) / 100;
        total += discounted * receipt[i].count;
    }
    return total;
}
int calculateDiscount() {
    int discountSum = 0;
    for (int i = 0; i < receiptSize; i++) {
        int price = receipt[i].product.price;
        int disc = receipt[i].product.discount;
        int oneDiscount = price * disc / 100;
        discountSum += oneDiscount * receipt[i].count;
    }
    return discountSum;
}
void printReceipt() {
    if (receiptSize == 0) {
        printf("Чек пуст.\n");
        return;
    }
    printf("\n========== ЧЕК ==========\n");
    for (int i = 0; i < receiptSize; i++) {
        int price = receipt[i].product.price;
        int disc = receipt[i].product.discount;
        int discounted = price - price * disc / 100;

        printf("%s - %d руб - %d шт - %d руб (со скидкой)\n",
            receipt[i].product.name,
            price,
            receipt[i].count,
            discounted * receipt[i].count);
    }
    printf("--------------------------\n");
    printf("Суммарная скидка: %d руб\n", calculateDiscount());
    printf("Итого к оплате: %d руб\n", calculateTotal());
    printf("==========================\n\n");
}
int main() {
    setlocale(LC_ALL, "Russian");
    int choice;
    char barcode[5];
    while (1) {
        printf("\nМеню:\n");
        printf("1 — Сканировать товар\n");
        printf("2 — Показать отсканированный товар\n");
        printf("3 — Добавить в чек\n");
        printf("4 — Показать чек\n");
        printf("5 — Итоговая сумма\n");
        printf("6 — Выход\n");
        printf("Ваш выбор: ");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            printf("Введите 4-значный штрих-код: ");
            scanf_s("%4s", barcode, (unsigned)sizeof(barcode));
            lastScanned = findProduct(barcode);
            if (lastScanned)
                printf("Товар найден: %s\n", lastScanned->name);
            else
                printf("Товар с таким штрих-кодом не найден.\n");
            break;
        case 2:
            printProduct(lastScanned);
            break;
        case 3:
            addToReceipt(lastScanned);
            break;
        case 4:
            printReceipt();
            break;
        case 5:
            printf("Итого к оплате: %d руб\n", calculateTotal());
            break;
        case 6:
            printf("Выход...\n");
            return 0;
        default:
            printf("Неверный выбор.\n");
        }
    }
    return 0;
}
