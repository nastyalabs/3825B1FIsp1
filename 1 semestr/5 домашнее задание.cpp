#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <time.h>
#define MAX_FILES 50
#define MAX_NAME 50
typedef struct {
    char name[MAX_NAME];
    int size;
} File;
typedef struct {
    char path[MAX_NAME];
    File files[MAX_FILES];
    int fileCount;
} Directory;
void bubblesortup(File arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].size > arr[j + 1].size) {
                File temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
void bubblesortdown(File arr[], int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (arr[j].size < arr[j + 1].size) {
                File temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
}
void insertionsortup(File arr[], int n) {
    for (int i = 1; i < n; i++) {
        File key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].size > key.size) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void insertionsortdown(File arr[], int n) {
    for (int i = 1; i < n; i++) {
        File key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].size < key.size) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
void printfiles(File files[], int n) {
    printf("\nФайлы в каталоге:\n");
    for (int i = 0; i < n; i++)
        printf("%s - %d байт\n", files[i].name, files[i].size);
}
void initializedirectory(Directory* dir) {
    strcpy_s(dir->path, sizeof(dir->path), "C:\\Пример");
    dir->fileCount = 5;
    strcpy_s(dir->files[0].name, sizeof(dir->files[0].name), "file1.txt"); dir->files[0].size = 1200;
    strcpy_s(dir->files[1].name, sizeof(dir->files[1].name), "file2.doc"); dir->files[1].size = 800;
    strcpy_s(dir->files[2].name, sizeof(dir->files[2].name), "file3.png"); dir->files[2].size = 2500;
    strcpy_s(dir->files[3].name, sizeof(dir->files[3].name), "file4.pdf"); dir->files[3].size = 1500;
    strcpy_s(dir->files[4].name, sizeof(dir->files[4].name), "file5.xls"); dir->files[4].size = 1000;
}
int main() {
    setlocale(LC_ALL, "Russian");
    Directory dir;
    initializedirectory(&dir);
    int choice;
    while (1) {
        printf("\nКаталог: %s\n", dir.path);
        printf("Меню сортировки:\n");
        printf("1 — Пузырьковая сортировка по возрастанию\n");
        printf("2 — Пузырьковая сортировка по убыванию\n");
        printf("3 — Сортировка вставками по возрастанию\n");
        printf("4 — Сортировка вставками по убыванию\n");
        printf("5 — Показать файлы\n");
        printf("6 — Выход\n");
        printf("Выберите действие: ");
        if (scanf_s("%d", &choice) != 1) {
            printf("Ошибка ввода\n");
            return 0;
        }
        clock_t start, end;
        double time_taken;
        switch (choice) {
        case 1:
            start = clock();
            bubblesortup(dir.files, dir.fileCount);
            end = clock();
            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Сортировка пузырьком по возрастанию завершена за %.6f секунд\n", time_taken);
            break;
        case 2:
            start = clock();
            bubblesortdown(dir.files, dir.fileCount);
            end = clock();
            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Сортировка пузырьком по убыванию завершена за %.6f секунд\n", time_taken);
            break;
        case 3:
            start = clock();
            insertionsortup(dir.files, dir.fileCount);
            end = clock();
            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Сортировка вставками по возрастанию завершена за %.6f секунд\n", time_taken);
            break;
        case 4:
            start = clock();
            insertionsortdown(dir.files, dir.fileCount);
            end = clock();
            time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;
            printf("Сортировка вставками по убыванию завершена за %.6f секунд\n", time_taken);
            break;
        case 5:
            printfiles(dir.files, dir.fileCount);
            break;
        case 6:
            printf("Выход...\n");
            return 0;
        default:
            printf("Неверный выбор\n");
        }
    }
    return 0;
}
