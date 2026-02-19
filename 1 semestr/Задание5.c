#include <stdio.h>
#include <time.h>

// Функция для вывода массива
void printArray(int arr[], int size[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Элемент: %d, Размер: %d\n", arr[i], size[i]);
    }
    printf("\n");
}

// Пузырьковая сортировка (с направлением)
void bubbleSort(int arr[], int size[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            int needSwap = 0;
            if (ascending) {
                // По возрастанию
                if (size[j] > size[j + 1]) {
                    needSwap = 1;
                }
            } else {
                // По убыванию
                if (size[j] < size[j + 1]) {
                    needSwap = 1;
                }
            }
            
            if (needSwap) {
                // Обмен размерами
                int tempSize = size[j];
                size[j] = size[j + 1];
                size[j + 1] = tempSize;
                
                // Обмен элементами
                int tempArr = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = tempArr;
            }
        }
    }
}

// Сортировка выбором (с направлением)
void selectionSort(int arr[], int size[], int n, int ascending) {
    for (int i = 0; i < n - 1; i++) {
        int targetIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (ascending) {
                // По возрастанию - ищем минимальный
                if (size[j] < size[targetIndex]) {
                    targetIndex = j;
                }
            } else {
                // По убыванию - ищем максимальный
                if (size[j] > size[targetIndex]) {
                    targetIndex = j;
                }
            }
        }
        
        // Обмен размерами
        int tempSize = size[targetIndex];
        size[targetIndex] = size[i];
        size[i] = tempSize;
        
        // Обмен элементами
        int tempArr = arr[targetIndex];
        arr[targetIndex] = arr[i];
        arr[i] = tempArr;
    }
}

// Функция для копирования массивов (чтобы сохранить оригинальные данные)
void copyArrays(int sourceArr[], int sourceSize[], int destArr[], int destSize[], int n) {
    for (int i = 0; i < n; i++) {
        destArr[i] = sourceArr[i];
        destSize[i] = sourceSize[i];
    }
}

int main() {
    // Исходные данные - 3 массива
    int array1[] = {1, 2, 3, 4, 5};
    int sizes1[] = {50, 20, 80, 10, 30};
    int n1 = 5;
    
    int array2[] = {10, 20, 30, 40};
    int sizes2[] = {15, 5, 25, 35};
    int n2 = 4;
    
    int array3[] = {100, 200, 300};
    int sizes3[] = {45, 60, 15};
    int n3 = 3;
    
    // Рабочие копии массивов
    int workArray1[5], workSizes1[5];
    int workArray2[4], workSizes2[4];
    int workArray3[3], workSizes3[3];
    
    int choice, sortMethod, sortDirection;
    clock_t start, end;
    double time_taken;
    
    printf("=== Файловый менеджер - Сортировка массивов ===\n");
    
    do {
        printf("\nВыберите массив для сортировки:\n");
        printf("1 - Массив 1 (5 элементов)\n");
        printf("2 - Массив 2 (4 элемента)\n");
        printf("3 - Массив 3 (3 элемента)\n");
        printf("0 - Выход\n");
        printf("Ваш выбор: ");
        scanf("%d", &choice);
        
        if (choice == 0) {
            break;
        }
        
        if (choice < 1 || choice > 3) {
            printf("Неверный выбор! Попробуйте снова.\n");
            continue;
        }
        
        printf("\nВыберите метод сортировки:\n");
        printf("1 - Пузырьковая сортировка\n");
        printf("2 - Сортировка выбором\n");
        printf("Ваш выбор: ");
        scanf("%d", &sortMethod);
        
        if (sortMethod < 1 || sortMethod > 2) {
            printf("Неверный выбор метода сортировки!\n");
            continue;
        }
        
        printf("\nВыберите направление сортировки:\n");
        printf("1 - По возрастанию\n");
        printf("2 - По убыванию\n");
        printf("Ваш выбор: ");
        scanf("%d", &sortDirection);
        
        if (sortDirection < 1 || sortDirection > 2) {
            printf("Неверный выбор направления сортировки!\n");
            continue;
        }
        
        // Копируем исходные данные в рабочие массивы
        if (choice == 1) {
            copyArrays(array1, sizes1, workArray1, workSizes1, n1);
        } 
        else if (choice == 2) {
            copyArrays(array2, sizes2, workArray2, workSizes2, n2);
        } 
        else {
            copyArrays(array3, sizes3, workArray3, workSizes3, n3);
        }
        
        printf("\nИсходный массив:\n");
        if (choice == 1) {
            printArray(array1, sizes1, n1);
        } 
        else if (choice == 2) {
            printArray(array2, sizes2, n2);
        } 
        else {
            printArray(array3, sizes3, n3);
        }
        
        // Выполняем сортировку и замеряем время
        start = clock();
        
        int ascending = (sortDirection == 1); // 1 - возрастание, 0 - убывание
        
        if (choice == 1) {
            if (sortMethod == 1) {
                bubbleSort(workArray1, workSizes1, n1, ascending);
            } 
            else {
                selectionSort(workArray1, workSizes1, n1, ascending);
            }
        } else if (choice == 2) {
            if (sortMethod == 1) {
                bubbleSort(workArray2, workSizes2, n2, ascending);
            } 
            else {
                selectionSort(workArray2, workSizes2, n2, ascending);
            }
        } 
        else {
            if (sortMethod == 1) {
                bubbleSort(workArray3, workSizes3, n3, ascending);
            } 
            else {
                selectionSort(workArray3, workSizes3, n3, ascending);
            }
        }
        
        end = clock();
        // CLOCKS_PER_SEC - константа, которая показывает сколько тактов процессора в одной секунде.
        time_taken = ((double)(end - start)) / CLOCKS_PER_SEC; // Разница тактов в процессере / кол-во тактов в 1-ой секунде
        
        printf("Отсортированный массив (%s):\n", ascending ? "по возрастанию" : "по убыванию");
        if (choice == 1) {
            printArray(workArray1, workSizes1, n1);
        } 
        else if (choice == 2) {
            printArray(workArray2, workSizes2, n2);
        } 
        else {
            printArray(workArray3, workSizes3, n3);
        }
        
        printf("Время сортировки: %.6f секунд\n", time_taken);
        
    } while (1);
    
    printf("Программа завершена.\n");
    return 0;
}