#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>
#include <string.h>
int main() {
    setlocale(LC_ALL, "rus");
    // Все в отдельных массивах - самый простой способ
    char names[8][20] = { "Молоко", "Кефир", "Творог", "Тунец", "Вода", "Тушенка", "Кукуруза", "Кола" };
    int prices[8] = { 80, 60, 100, 350, 50, 200, 80, 120 };
    char barcodes[8][5] = { "1234", "2740", "8490", "3950", "6452", "7393", "9405", "4586" };
    int discounts[8] = { 5, 10, 0, 30, 0, 10, 25, 20 };

    // Чек
    char check_names[50][20];
    int check_quantities[50];
    int check_prices[50];
    int check_count = 0;

    int total = 0;
    int choice;
    char barcode[10];
    int quantity;
    int i, j;

    printf("Добро пожаловать в магазин!\n");

    while (1) {
        printf("\n1 - Купить товар\n");
        printf("2 - Посмотреть корзину\n");
        printf("3 - Оплатить\n");
        printf("4 - Выйти\n");
        printf("Ваш выбор: ");
        scanf_s("%d", &choice);

        if (choice == 1) {
            // Показать все товары
            printf("\nСписок товаров:\n");
            for (i = 0; i < 8; i++) {
                printf("%d. %s - %d руб.", i + 1, names[i], prices[i]);
                if (discounts[i] > 0) {
                    printf(" (скидка %d%%)", discounts[i]);
                }
                printf("\n");
            }

            // Простой выбор по номеру (без сканера)
            printf("\nВведите номер товара (1-8): ");
            scanf_s("%d", &i);
            i--;  // Для индекса массива

            if (i >= 0 && i < 8) {
                printf("Выбран: %s - %d руб.\n", names[i], prices[i]);
                printf("Сколько штук? ");
                scanf_s("%d", &quantity);

                // Добавить в корзину
                // Проверить, есть ли уже
                int found = 0;
                for (j = 0; j < check_count; j++) {
                    if (strcmp(check_names[j], names[i]) == 0) {
                        check_quantities[j] += quantity;
                        found = 1;
                        printf("Добавлено еще %d шт. %s\n", quantity, names[i]);
                        break;
                    }
                }

                if (!found) {
                    strcpy_s(check_names[check_count], names[i]);
                    check_prices[check_count] = prices[i];
                    check_quantities[check_count] = quantity;
                    check_count++;
                    printf("Товар добавлен в корзину\n");
                }
            }
            else {
                printf("Неверный номер!\n");
            }
        }
        else if (choice == 2) {
            // Корзина
            if (check_count == 0) {
                printf("Корзина пуста\n");
            }
            else {
                printf("\n=== ВАША КОРЗИНА ===\n");
                total = 0;
                for (i = 0; i < check_count; i++) {
                    // Найти скидку для этого товара
                    int discount = 0;
                    for (j = 0; j < 8; j++) {
                        if (strcmp(check_names[i], names[j]) == 0) {
                            discount = discounts[j];
                            break;
                        }
                    }

                    int item_total = check_prices[i] * check_quantities[i] * (100 - discount) / 100;
                    printf("%s: %d шт. x %d руб. = %d руб.",
                        check_names[i], check_quantities[i], check_prices[i], item_total);
                    if (discount > 0) {
                        printf(" (скидка %d%%)", discount);
                    }
                    printf("\n");
                    total += item_total;
                }
                printf("\nИТОГО: %d руб.\n", total);
            }
        }
        else if (choice == 3) {
            // Оплата
            if (check_count == 0) {
                printf("Корзина пуста!\n");
            }
            else {
                printf("\n=== ЧЕК ===\n");
                total = 0;
                for (i = 0; i < check_count; i++) {
                    // Найти скидку
                    int discount = 0;
                    for (j = 0; j < 8; j++) {
                        if (strcmp(check_names[i], names[j]) == 0) {
                            discount = discounts[j];
                            break;
                        }
                    }

                    int item_total = check_prices[i] * check_quantities[i] * (100 - discount) / 100;
                    printf("%s\t%d x %d = %d руб.\n",
                        check_names[i], check_quantities[i], check_prices[i], item_total);
                    total += item_total;
                }
                printf("-----------------\n");
                printf("К ОПЛАТЕ: %d руб.\n\n", total);
                printf("СПАСИБО ЗА ПОКУПКУ!\n");

                // Очистить корзину после оплаты
                check_count = 0;
            }
        }
        else if (choice == 4) {
            printf("До свидания!\n");
            break;
        }
        else {
            printf("Ошибка! Попробуйте снова.\n");
        }
    }

    return 0;
}