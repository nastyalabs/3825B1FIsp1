#include <stdio.h>
#include <string.h>

int main(){
    // База данных товаров: штрих-код, название, цена, скидка
    char barcodes[5][5] = {"1234", "5678", "9012", "3456", "7890"}; // xxxx\0 - 5 
    char names[5][20] = {"Хлеб", "Молоко", "Сыр", "Колбаса", "Вода"};
    int prices[5] = {50, 80, 200, 300, 40};
    int discounts[5] = {10, 5, 15, 20, 0};
    
    // Чек: штрих-код, название, цена, количество, сумма
    char receipt_barcodes[10][5];
    char receipt_names[10][20];
    int receipt_prices[10];
    int receipt_quantities[10] = {0};
    int receipt_total[10];
    int receipt_count = 0; // сколько позиций в чеке
    
    // Текущий отсканированный товар
    char current_barcode[5];
    char current_name[20];
    int current_price;
    int current_discount;
    int product_scanned = 0; // 0 - не отсканирован, 1 - отсканирован
    
    int choice;
    int i, j;
    
    printf("=== ЭЛЕКТРОННАЯ КАССА ===\n");
    
    while (1) {
        printf("\n1. Сканировать товар\n");
        printf("2. Показать информацию о товаре\n");
        printf("3. Добавить товар в чек\n");
        printf("4. Сформировать чек\n");
        printf("5. Рассчитать итоговую сумму\n");
        printf("0. Выход\n");
        printf("Выберите операцию: ");
        scanf("%d", &choice);
        
        if (choice == 1) {
            // Сканировать товар
            printf("Введите штрих-код (4 цифры): ");
            scanf("%4s", current_barcode); // беру первые 4 символа без \0
            
            // Поиск товара по штрих-коду
            int found = 0;
            for (i = 0; i < 5; i++) {
                int match = 1;
                for (j = 0; j < 4; j++) {
                    if (barcodes[i][j] != current_barcode[j]) { // при несовпадении выходит из внутреннего цикла
                        match = 0;
                        break;
                    }
                }
                if (match) { // при совпадении текущего штрих-кода с штрих-кодом в массиве - 1
                    // Копируем данные товара
                    for (j = 0; j < 20; j++) {
                        current_name[j] = names[i][j];
                    }
                    current_price = prices[i];
                    current_discount = discounts[i];
                    product_scanned = 1;
                    found = 1;
                    printf("Товар отсканирован!\n");
                    break;
                }
            }
            if (!found) { // если штрих-код не найден ни в одной позиции массива
                printf("Товар с таким штрих-кодом не найден!\n");
                product_scanned = 0;
            }
            
        } else if (choice == 2) {
            // Показать информацию о товаре
            if (!product_scanned) {
                printf("Сначала отсканируйте товар!\n");
            } else {
                printf("\n=== Информация о товаре ===\n");
                printf("Штрих-код: %s\n", current_barcode);
                printf("Наименование: %s\n", current_name);
                printf("Цена: %d руб.\n", current_price);
                printf("Скидка: %d%%\n", current_discount);
                printf("============================\n");
            }
            
        } else if (choice == 3) {
            // Добавить товар в чек
            if (!product_scanned) {
                printf("Сначала отсканируйте товар!\n");
            } else {
                int quantity;
                printf("Введите количество: ");
                scanf("%d", &quantity);
                
                if (quantity <= 0) {
                    printf("Количество должно быть положительным!\n");
                } else {
                    // Проверяем, есть ли уже такой товар в чеке
                    int found_index = -1;
                    for (i = 0; i < receipt_count; i++) {
                        int match = 1;
                        for (j = 0; j < 4; j++) {
                            if (receipt_barcodes[i][j] != current_barcode[j]) {
                                match = 0;
                                break;
                            }
                        }
                        if (match) {
                            found_index = i;
                            break;
                        }
                    }
                    
                    if (found_index != -1) {
                        // Увеличиваем количество существующего товара
                        receipt_quantities[found_index] += quantity;
                        int total_without_discount = receipt_quantities[found_index] * receipt_prices[found_index];
                        int discount_amount = (total_without_discount * current_discount) / 100;
                        receipt_total[found_index] = total_without_discount - discount_amount;
                        printf("Количество товара обновлено!\n");
                    } else {
                        // Добавляем новый товар в чек
                        if (receipt_count < 10) {
                            // Копируем штрих-код
                            for (j = 0; j < 5; j++) {
                                receipt_barcodes[receipt_count][j] = current_barcode[j];
                            }
                            // Копируем название
                            for (j = 0; j < 20; j++) {
                                receipt_names[receipt_count][j] = current_name[j];
                            }
                            receipt_prices[receipt_count] = current_price;
                            receipt_quantities[receipt_count] = quantity;
                            
                            int total_without_discount = quantity * current_price;
                            int discount_amount = (total_without_discount * current_discount) / 100;
                            receipt_total[receipt_count] = total_without_discount - discount_amount;
                            
                            receipt_count++;
                            printf("Товар добавлен в чек!\n");
                        } else {
                            printf("Чек переполнен! Максимум 10 товаров.\n");
                        }
                    }
                }
            }
            
        } else if (choice == 4) {
            // Сформировать чек
            if (receipt_count == 0) {
                printf("Чек пуст! Сначала добавьте товары.\n");
            } 
            else {
                int total_all = 0;
                int total_discount_all = 0;
                
                printf("\n");
                printf("         ЭЛЕКТРОННЫЙ ЧЕК\n");
                printf("==================================\n");
                printf(" Товар      Цена   Кол-во  Сумма\n");
                printf("----------------------------------\n");
                
                for (i = 0; i < receipt_count; i++) {
                    printf(" %-10s  %5d  %6d  %6d\n", 
                           receipt_names[i],
                           receipt_prices[i],
                           receipt_quantities[i],
                           receipt_total[i]);
                    
                    int without_discount = receipt_prices[i] * receipt_quantities[i];
                    total_all += without_discount;
                    total_discount_all += (without_discount - receipt_total[i]);
                }
                
                int final_total = total_all - total_discount_all;
                
                printf("==================================\n");
                printf(" Общая стоимость: %10d руб.\n", total_all);
                printf(" Скидка:          %10d руб.\n", total_discount_all);
                printf(" ИТОГО К ОПЛАТЕ:  %10d руб.\n", final_total);
                printf("==================================\n");
            }
            
        } else if (choice == 5) {
            // Рассчитать итоговую сумму
            if (receipt_count == 0) {
                printf("Чек пуст! Нет товаров для расчета.\n");
            } else {
                int total_all = 0;
                int total_discount_all = 0;

                for (i = 0; i < receipt_count; i++) {
                    int without_discount = receipt_prices[i] * receipt_quantities[i];
                    total_all += without_discount;
                    total_discount_all += (without_discount - receipt_total[i]);
                }
                
                int final_total = total_all - total_discount_all;
                
                printf("\n=== РАСЧЕТ ===\n");
                printf("Общая стоимость: %d руб.\n", total_all);
                printf("Скидка: %d руб.\n", total_discount_all);
                printf("ИТОГО К ОПЛАТЕ: %d руб.\n", final_total);
            }
            
        } else if (choice == 0) {
            printf("Выход из программы.\n");
            break;
        } else {
            printf("Неверный выбор!\n");
        }
    }
    
    return 0;
}