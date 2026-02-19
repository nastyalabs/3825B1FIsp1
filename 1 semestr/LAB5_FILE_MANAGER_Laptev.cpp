#include <stdio.h>
#include <string.h>
#include <locale.h>
#define FILES 5
#define MAX 256

void bubbleSort(char names[][MAX], long sizes[], int n, int sort) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (sort == 0 && sizes[j] > sizes[j + 1]) {
                long zamSize = sizes[j];
                sizes[j] = sizes[j + 1];
                sizes[j + 1] = zamSize;
            }
            else if (sort == 1 && strcmp(names[j], names[j + 1]) > 0) {
                char zamName[MAX];
                strcpy_s(zamName, names[j]);
                strcpy_s(names[j], names[j + 1]);
                strcpy_s(names[j + 1], zamName);
            }
        }
    }
}
void vstavkaSort(char names[][MAX], long sizes[], int n, int sort) {
    for (int i = 1; i < n; i++) {
        char keyName[MAX];
        long keySize = sizes[i];
        strcpy_s(keyName, names[i]);
        int j = i - 1;

        if (sort == 0) {
            while (j >= 0 && sizes[j] > keySize) {
                sizes[j + 1] = sizes[j];
                strcpy_s(names[j + 1], names[j]);
                j--;
            }
        }
        else if (sort == 1) {
            while (j >= 0 && strcmp(names[j], keyName) > 0) {
                strcpy_s(names[j + 1], names[j]);
                sizes[j + 1] = sizes[j];
                j--;
            }
        }
        if (sort == 0) {
            sizes[j + 1] = keySize;
        }
        else if (sort == 1) {
            strcpy_s(names[j + 1], keyName);
        }
    }
}

void display(char names[][MAX], long sizes[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%s (%ld)\n", names[i], sizes[i]);
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    char names[FILES][MAX];
    long sizes[FILES];
    int n = 0;
    int sort;
    int method;
    const char* paths[] = { "/path1", "/path2", "/path3" };
    int pathIndex;

    while (1) {
        printf("Выберите путь:\n");
        printf("0 - /path1\n");
        printf("1 - /path2\n");
        printf("2 - /path3\n");
        scanf_s("%d", &pathIndex);
        if (pathIndex == 0) {
            strcpy_s(names[0], "file1.txt");
            sizes[0] = 100;
            strcpy_s(names[1], "file2.txt");
            sizes[1] = 200;
            strcpy_s(names[2], "file3.txt");
            sizes[2] = 50;
            strcpy_s(names[3], "file4.txt");
            sizes[3] = 150;
            strcpy_s(names[4], "file5.txt");
            sizes[4] = 300;
            n = 5;
        }
        else if (pathIndex == 1) {
            strcpy_s(names[0], "file6.txt");
            sizes[0] = 120;
            strcpy_s(names[1], "file7.txt");
            sizes[1] = 180;
            strcpy_s(names[2], "file8.txt");
            sizes[2] = 90;
            strcpy_s(names[3], "file9.txt");
            sizes[3] = 210;
            strcpy_s(names[4], "file10.txt");
            sizes[4] = 250;
            n = 5;
        }
        else if (pathIndex == 2) {
            strcpy_s(names[0], "file11.txt");
            sizes[0] = 130;
            strcpy_s(names[1], "file12.txt");
            sizes[1] = 190;
            strcpy_s(names[2], "file13.txt");
            sizes[2] = 80;
            strcpy_s(names[3], "file14.txt");
            sizes[3] = 220;
            strcpy_s(names[4], "file15.txt");
            sizes[4] = 260;
            n = 5;
        }
        else {
            printf("Ошибка выбора\n");
            continue;
        }

        printf("Выберите метод сортировки:\n");
        printf("0 - по размеру\n");
        printf("1 - по имени\n");
        scanf_s("%d", &sort);

        printf("Выберите метод сортировки:\n");
        printf("0 - пузырьковая\n");
        printf("1 - вставкой\n");
        scanf_s("%d", &method);

        if (method == 0) {
            bubbleSort(names, sizes, n, sort);
        }
        else {
            vstavkaSort(names, sizes, n, sort);
        }

        printf("Отсортированный список файлов:\n");
        display(names, sizes, n);

        printf("Нажмите 0 для возврата: ");
        int ch;
        scanf_s("%d", &ch);
        if (ch != 0) break;
    }

    return 0;
}