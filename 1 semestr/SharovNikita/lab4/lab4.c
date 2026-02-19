#include <stdio.h>
#include <string.h>

#define MAX_PRODUCTS 5
#define MAX_CHECK 50

char barcodes[MAX_PRODUCTS][5] = { "1234", "5678", "1111", "2222", "9999" };
char names[MAX_PRODUCTS][20]  = { "Milk", "Bread", "Apple", "Juice", "Tea" };
int prices[MAX_PRODUCTS]       = { 60, 40, 10, 90, 120 };
int discounts[MAX_PRODUCTS]    = { 10, 0, 20, 5, 15 };

int checkIndex[MAX_CHECK];
int checkQty[MAX_CHECK];
int checkCount = 0;

int findBarcode(char code[]) {
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        if (strcmp(barcodes[i], code) == 0)
            return i;
    }
    return -1;
}

void addCheck(int id) {
    for (int i = 0; i < checkCount; i++) {
        if (checkIndex[i] == id) {
            checkQty[i]++;
            return;
        }
    }

    if (checkCount < MAX_CHECK) {
        checkIndex[checkCount] = id;
        checkQty[checkCount] = 1;
        checkCount++;
    }
}

void check() {
    printf("\n======= ЧЕК =======\n");

    int total = 0;
    int totalSale = 0;

    if (checkCount == 0) {
        printf("Чек пуст\n");
        return;
    }

    for (int i = 0; i < checkCount; i++) {
        int id = checkIndex[i];
        int qty = checkQty[i];

        int cost = prices[id] * qty;
        int discount = cost * discounts[id] / 100;

        printf("%s x%d = %d руб (-%d)\n",
               names[id], qty, cost - discount, discount);

        total += cost;
        totalSale += discount;
    }

    printf("----------------------\n");
    printf("Сумма без скидки: %d\n", total);
    printf("Скидка: %d\n", totalSale);
    printf("ИТОГО: %d\n", total - totalSale);
}

int main() {
    char code[5];

    printf("=== СПИСОК ТОВАРОВ ===\n");
    for (int i = 0; i < MAX_PRODUCTS; i++) {
        printf("%s — %s (цена %d руб, скидка %d%%)\n",
               names[i], barcodes[i], prices[i], discounts[i]);
    }

    printf("\nВводите штрих-коды товаров\n");
    printf("Введите 0 для печати чека\n\n");

    while (1) {
        printf("Штрих-код: ");
        scanf("%s", code);

        if (strcmp(code, "0") == 0)
            break;

        int id = findBarcode(code);

        if (id == -1) {
            printf("Товар не найден!\n");
        } else {
            addCheck(id);
            printf("Добавлено: %s\n", names[id]);
        }
    }

    check();

    return 0;
}