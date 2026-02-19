#include<stdio.h>
#include<locale.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

typedef struct{
	char name[20];
	int size;
} file;

file folder_1[20] = {
    {"Bread", 15}, {"Cheese", 21},
    {"Okak", 3}, {"Vot", 1},
    {"Document", 45}, {"Presentation", 67},
    {"Spreadsheet", 89}, {"Image", 12},
    {"Video", 156}, {"Audio", 34},
    {"Archive", 78}, {"Executable", 92},
    {"SourceCode", 54}, {"Database", 123},
    {"Backup", 200}, {"LogFile", 23},
    {"Config", 8}, {"Readme", 5},
    {"License", 19}, {"Script", 31}
};
    
file folder_2[20] = {
    {"Coffee", 25}, {"Sugar", 18},
    {"Milk", 32}, {"Eggs", 24},
    {"Report", 56}, {"Budget", 73},
    {"Invoice", 91}, {"Photo", 14},
    {"Movie", 210}, {"Podcast", 42},
    {"ZipFile", 65}, {"Installer", 88},
    {"Python", 47}, {"BackupDB", 145},
    {"Snapshot", 180}, {"ErrorLog", 29},
    {"Settings", 11}, {"Changelog", 7},
    {"Agreement", 22}, {"BatchFile", 38}
};

file folder_3[20] = {
    {"Butter", 12}, {"Yogurt", 26},
    {"Rice", 8}, {"Salt", 2},
    {"Manual", 51}, {"Schedule", 69},
    {"Database", 94}, {"Diagram", 16},
    {"Tutorial", 187}, {"Music", 53},
    {"RarArchive", 71}, {"AppImage", 96},
    {"JavaScript", 49}, {"LogArchive", 134},
    {"SystemBackup", 220}, {"AccessLog", 31},
    {"Profile", 9}, {"Instructions", 6},
    {"Warranty", 17}, {"AutoScript", 44}
};

int global_for_comparator = 0;
int current_folder;

int compare_size(file *a, file *b, int* c){
	if (*c == 1){
		return (a->size < b->size ? 1 : 0);
	}
	else if (*c == 2){
		return (a->size > b->size ? 1 : 0);
	}
}

void bubble_sort(file arr[], int sz, int (*comparator)(file*, file*, int*)){
	for (int i = 0; i < sz; i++){
		for (int j = 0; j < sz; j++){
			if (comparator(&arr[i], &arr[j], &global_for_comparator)){
				file tmp = arr[j];
				arr[j] = arr[i];
				arr[i] = tmp;
			}
		}
	}
}

void Merge(file arr[], int st, int fin, file res[], int (*comparator)(file*, file*, int*)){
    int i, j, k, mid = st + (fin - st)/2;
    i = st; j = mid+1;
    k = st;
    while (i<=mid && j <= fin){
        if (comparator(&arr[i], &arr[j], &global_for_comparator)){
            res[k++] = arr[i++];
        }
        else{
            res[k++] = arr[j++];
        }
    }
    while (i <= mid){
        res[k++] = arr[i++];
    }
    while (j <= fin){
        res[k++] = arr[j++];
    }
}

void Mergesort (file arr[], int st, int fin, file res[], int (*comparator)(file*, file*, int*)){
    if (st == fin) return;
    int mid = st + (fin-st)/2;
    Mergesort(arr, st, mid, res, comparator);
    Mergesort(arr, mid+1, fin, res, comparator);
    Merge(arr, st, fin, res, comparator);
    for (int i = st; i <= fin; i++){
        arr[i] = res[i];
    }
}

void print_folder(file arr[], int size) {
    printf("\n%-20s %s\n", "Имя файла", "Размер");
    printf("--------------------------------\n");
    for (int i = 0; i < size; i++) {
        printf("%-20s %d\n", arr[i].name, arr[i].size);
    }
    printf("--------------------------------\n");
}

void copy_folder(file a[], file b[], int* size){
	for (int i = 0; i < *size; i++){
		b[i] = a[i];
	}
}

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));
    
    int choice = -1, is_sorted = 0;
    int n = 20;
    
    file *folders[3] = {folder_1, folder_2, folder_3};
    
    printf("          \"Сортировщик файлов\"        \n\n");
    printf("Выберите директорию для работы(1, 2 или 3): ");
	scanf(" %d", &current_folder); current_folder--;
    
    printf("\nДоступные функции\n1. Вывести исходный список файлов\n2. Выбрать метод и тип сортировки\n3. Вывести отсортированный список\n4. Сменить директорию\n0. Выход");
    
    file temp_folder[20], merge_temp[20]; 
    
    do {
        printf("\nВыберите операцию: ");
        scanf(" %d", &choice);
        
        switch(choice) {
            case 1:
            	printf("\nТекущая директория: %d", current_folder+1);
                printf("\nИсходный список файлов:\n");
                print_folder(folders[current_folder], n);
                break;
            case 2:
            	int sort_choice, order_choice;
                copy_folder(folders[current_folder], temp_folder, &n);
                
                printf("\nВыберите порядок сортировки:\n");
                printf("1. По возрастанию размера\n2. По убыванию размера\n");
                do{
                	printf("Ваш выбор: ");
                	scanf(" %d", &order_choice);
                	if(order_choice > 2 || order_choice < 1){
                		printf("Неверный выбор!\n\n");
					}
					else printf("\n");
				} while(order_choice > 2 || order_choice < 1);
                
                global_for_comparator = order_choice;
                    
                printf("Выберите метод сортировки:\n");
                printf("1. Сортировка пузырьком\n2. Сортировка слиянием\n");
                do{
                	printf("Ваш выбор: ");
                	scanf(" %d", &sort_choice);
                	if(sort_choice > 2 || sort_choice < 1){
                		printf("Неверный выбор!\n");
					}
					else printf("\n");
				} while(sort_choice > 2 || sort_choice < 1);
                    
                if (sort_choice == 1) {
                    bubble_sort(temp_folder, n, compare_size);
                }
                else if (sort_choice == 2) {
                    Mergesort(temp_folder, 0, n-1, merge_temp, compare_size);
                }
                printf("Сортировка завершена!\n");
                is_sorted = 1;
                break;
            case 3:
            	if (is_sorted == 0){
            		printf("\nСписок не отсортирован, сначала выполните сортировку!\n");
            		break;
				}
            	printf("\nТекущая директория: %d", current_folder+1);
                printf("\nОтсортированный список файлов:\n");
                print_folder(temp_folder, n);
                break;
            case 4:
            	printf("\nВыберите директорию для работы(1, 2 или 3): ");
				scanf(" %d", &current_folder); current_folder--;
				is_sorted = 0;
            	break;
            case 0:
            	printf("\nВыход из программы.");
            	break;
            default:
                printf("Неверный выбор!\n");
                break;
        }
    } while (choice);
    
    return 0;
}

