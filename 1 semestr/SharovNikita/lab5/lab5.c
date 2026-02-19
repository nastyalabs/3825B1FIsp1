#include <stdio.h>
#include <string.h>
#include <time.h>

#define MAX_FILES 5
#define MAX_DIRS  3

typedef struct {
    char name[50];
    int size;
} File;

typedef struct {
    char path[50];
    File files[MAX_FILES];
    int count;
} Directory;

void bubbleSort(File files[], int n, int ascending) {
    File temp;
    int needSwap;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (ascending == 1) {
                if (files[j].size > files[j + 1].size)
                    needSwap = 1;
                else
                    needSwap = 0;
            } else {
                if (files[j].size < files[j + 1].size)
                    needSwap = 1;
                else
                    needSwap = 0;
            }

            if (needSwap == 1) {
                temp = files[j];
                files[j] = files[j + 1];
                files[j + 1] = temp;
            }
        }
    }
}

int main() {
    Directory dirs[MAX_DIRS] = {
        {"/docs", {{"a.txt",120}, {"report.pdf",5600}, {"code.c",980}}, 3},
        {"/music", {{"song1.mp3",15000}, {"song2.mp3",24000}}, 2},
        {"/pics", {{"img1.jpg",20480}, {"img2.png",12000}}, 2}
    };

    char inputPath[50];
    int choice;
    int dirIndex = -1;

    printf("Введите путь к каталогу (/docs, /music, /pics): ");
    scanf("%49s", inputPath);

    for (int i = 0; i < MAX_DIRS; i++) {
        if (strcmp(inputPath, dirs[i].path) == 0) {
            dirIndex = i;
            break;
        }
    }

    if (dirIndex == -1) {
        printf("Каталог не найден\n");
        return 0;
    }

    printf("Выберите порядок сортировки:\n");
    printf("1 — по возрастанию\n");
    printf("2 — по убыванию\n");
    scanf("%d", &choice);

    clock_t start = clock();

    bubbleSort(dirs[dirIndex].files,
               dirs[dirIndex].count,
               choice == 1);

    clock_t end = clock();

    printf("\nКаталог: %s\n", dirs[dirIndex].path);
    printf("Отсортированный список файлов:\n");

    for (int i = 0; i < dirs[dirIndex].count; i++) {
        printf("%-15s %d байт\n",
               dirs[dirIndex].files[i].name,
               dirs[dirIndex].files[i].size);
    }

    printf("\nВремя сортировки: %.6f секунд\n",
           (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}