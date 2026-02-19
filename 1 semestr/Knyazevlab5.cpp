#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <windows.h>
#include <locale.h>

#define FILE_COUNT 20
#define DIR_COUNT 5

int main() {
    setlocale(LC_ALL, "Russian"); 

    char dirs[DIR_COUNT][50] = {
        "Документы",
        "Загрузки",
        "Музыка",
        "Фото",
        "Видео"
    };

    char files[DIR_COUNT][FILE_COUNT][50] = {
        {"отчет.docx", "презентация.pptx", "таблица.xlsx", "договор.pdf", "резюме.txt",
         "инструкция.doc", "план.txt", "проект.docx", "бюджет.xlsx", "график.pdf",
         "заметки.txt", "черновик.doc", "анализ.docx", "отзыв.pdf", "справка.txt",
         "техзадание.doc", "реферат.docx", "курсовая.pdf", "диплом.docx", "статья.txt"},

         {"установщик.exe", "архив.zip", "образ.iso", "драйвер.msi", "патч.rar",
          "скрипт.py", "библиотека.dll", "игра.exe", "программа.rar", "мод.zip",
          "дополнение.iso", "обновление.exe", "плагин.dll", "пакет.msi", "утилита.rar",
          "инструмент.exe", "биос.bin", "прошивка.iso", "конвертер.exe", "редактор.zip"},

          {"песня1.mp3", "песня2.mp3", "альбом.flac", "плейлист.m3u", "подкаст.wav",
           "мелодия.ogg", "звук.m4a", "композиция.mp3", "трек.flac", "микс.m3u",
           "интервью.wav", "симфония.ogg", "ритм.m4a", "гимн.mp3", "саундтрек.flac",
           "колыбельная.m3u", "концерт.wav", "джем.ogg", "ремикс.m4a", "кавер.mp3"},

           {"отпуск.jpg", "семья.png", "природа.bmp", "портрет.jpeg", "город.gif",
            "арт.webp", "скриншот.jpg", "пейзаж.png", "животное.bmp", "цветок.jpeg",
            "здание.gif", "рисунок.webp", "фото1.jpg", "фото2.png", "фото3.bmp",
            "фото4.jpeg", "фото5.gif", "фото6.webp", "фото7.jpg", "фото8.png"},

            {"фильм.mkv", "клип.mp4", "урок.avi", "запись.mov", "анимация.webm",
             "стрим.flv", "ролик.wmv", "сериал.mkv", "трейлер.mp4", "конференция.avi",
             "вебинар.mov", "мультфильм.webm", "трансляция.flv", "инструкция.wmv",
             "документалка.mkv", "репортаж.mp4", "интервью.avi", "шоу.mov", "фильм2.webm", "клип2.flv"}
    };

    long sizes[DIR_COUNT][FILE_COUNT] = {
        // Документы
        {1048576, 5242880, 2097152, 3145728, 102400, 512000, 25600, 4194304, 8388608, 1572864,
         32768, 65536, 2097152, 524288, 131072, 262144, 10485760, 6291456, 12582912, 2048},

         // Загрузки
         {15728640, 7340032, 41943040, 8388608, 2097152, 1048576, 524288, 31457280, 15728640, 5242880,
          83886080, 20971520, 1048576, 4194304, 2621440, 10485760, 524288, 16777216, 8388608, 4194304},

          // Музыка
          {8388608, 10485760, 31457280, 51200, 15728640, 5242880, 2097152, 6291456, 41943040, 102400,
           20971520, 8388608, 5242880, 12582912, 31457280, 204800, 4194304, 10485760, 6291456, 8388608},

           // Фото
           {4194304, 8388608, 15728640, 6291456, 1048576, 2097152, 3145728, 12582912, 20971520, 5242880,
            8388608, 4194304, 10485760, 6291456, 15728640, 2621440, 5242880, 2097152, 8388608, 4194304},

            // Видео
            {104857600, 20971520, 52428800, 41943040, 15728640, 31457280, 8388608, 209715200, 10485760, 62914560,
             83886080, 31457280, 41943040, 15728640, 104857600, 52428800, 20971520, 83886080, 31457280, 10485760}
    };

    int dir_choice, sort_choice;
    int i, j;

    while (1) {
        printf("\nВыберите директорию:\n");
        for (i = 0; i < DIR_COUNT; i++) {
            printf("%d. %s\n", i + 1, dirs[i]);
        }
        printf("0. Выход\n");
        printf("Ваш выбор: ");
        scanf_s("%d", &dir_choice);

        if (dir_choice == 0) {
            printf("Выход из программы.\n");
            break;
        }

        if (dir_choice < 1 || dir_choice > DIR_COUNT) {
            printf("Ошибка\n");
            continue;
        }

        int dir_index = dir_choice - 1;
        printf("\nДиректория: %s\n", dirs[dir_index]);

        printf("Файлы:\n");
        printf("№  Имя файла              Размер (байт)\n");
        for (i = 0; i < FILE_COUNT; i++) {
            printf("%-2d %-22s %ld\n", i + 1, files[dir_index][i], sizes[dir_index][i]);
        }

        while (1) {
            printf("\nСортировка::\n");
            printf("1. Сортировка пузырьком (по размеру)\n");
            printf("2. Сортировка выбором (по размеру)\n");
            printf("3. Сменить директорию\n");
            printf("0. Выход\n");
            printf("Ваш выбор: ");
            scanf_s("%d", &sort_choice);

            if (sort_choice == 0) {
                printf("Выход из программы.\n");
                return 0;
            }

            if (sort_choice == 3) {
                break;
            }

            if (sort_choice != 1 && sort_choice != 2) {
                printf("Неверный выбор!\n");
                continue;
            }

            char temp_files[FILE_COUNT][50];
            long temp_sizes[FILE_COUNT];

            for (i = 0; i < FILE_COUNT; i++) {
                strcpy(temp_files[i], files[dir_index][i]);
                temp_sizes[i] = sizes[dir_index][i];
            }

              LARGE_INTEGER frequency;
            LARGE_INTEGER start;
            LARGE_INTEGER end;

            QueryPerformanceFrequency(&frequency); 
            QueryPerformanceCounter(&start);      

            if (sort_choice == 1) {
                for (i = 0; i < FILE_COUNT - 1; i++) {
                    for (j = 0; j < FILE_COUNT - i - 1; j++) {
                        if (temp_sizes[j] > temp_sizes[j + 1]) {
                            long temp_size = temp_sizes[j];
                            temp_sizes[j] = temp_sizes[j + 1];
                            temp_sizes[j + 1] = temp_size;

                            char temp_name[50];
                            strcpy(temp_name, temp_files[j]);
                            strcpy(temp_files[j], temp_files[j + 1]);
                            strcpy(temp_files[j + 1], temp_name);
                        }
                    }
                }
            }
            else if (sort_choice == 2) {
                for (i = 0; i < FILE_COUNT - 1; i++) {
                    int min_index = i;
                    for (j = i + 1; j < FILE_COUNT; j++) {
                        if (temp_sizes[j] < temp_sizes[min_index]) {
                            min_index = j;
                        }
                    }

                    if (min_index != i) {
                        long temp_size = temp_sizes[i];
                        temp_sizes[i] = temp_sizes[min_index];
                        temp_sizes[min_index] = temp_size;

                        char temp_name[50];
                        strcpy(temp_name, temp_files[i]);
                        strcpy(temp_files[i], temp_files[min_index]);
                        strcpy(temp_files[min_index], temp_name);
                    }
                }
            }

            QueryPerformanceCounter(&end);
            double time_taken = (double)(end.QuadPart - start.QuadPart) * 1000000.0 / frequency.QuadPart;

            printf("\nРезультат:\n");
            printf("Директория: %s\n", dirs[dir_index]);
            printf("Метод: %s\n", (sort_choice == 1) ? "Пузырьком" : "Выбором");
            printf("Количество файлов: %d\n", FILE_COUNT);
            printf("\nФайлы (отсортированы по размеру):\n");
            printf("№  Имя файла              Размер (байт)\n");
            for (i = 0; i < FILE_COUNT; i++) {
                printf("%-2d %-22s %ld\n", i + 1, temp_files[i], temp_sizes[i]);
            }
            printf("Время сортировки: %.3f микросекунд\n", time_taken);
        }
    }

    return 0;
}