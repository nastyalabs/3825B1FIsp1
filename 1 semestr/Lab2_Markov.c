#include<stdio.h>
#include<locale>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int random_in_range(int l, int r){
	return l + rand() % (r - l + 1);
}

void mode_1(){
	int chislo = random_in_range(1, 1000);
	int polz = -1, k = 0;
	printf("\nЯ загадал число от 1 до 1000\n");
	do{
		printf("\nВведите предположение: ");
		scanf(" %d", &polz);
		k++;
		if (polz < chislo){
			printf("\nЗагаданное число больше");
		}
		else if (polz > chislo){
			printf("\nЗагаданное число меньше");
		}
		else{
			printf("\nВы угадали, число попыток %d\n", k);
			break;
		}
	}
	while(polz != chislo);
	return;
}

void mode_2(){
	printf("\nЗагадайте число от 1 до 1000\n");
	int l = 1, r = 1000, pred = random_in_range(l, r), k = 0;
	char inp = '0';
	do{
		if (l > r){
			printf("\nВы меня обманываете!");
			return;
		}
		printf("\nМоё предположение: %d", pred);
		k++;
		printf("\nУкажите, моё предположение >, < или = загаданному числу: ");
		scanf(" %c", &inp);
		switch (inp){
		case '<':
			r = pred;
			break;
		case '>':
			l = pred;
			break;
		case '=':
			break;
		}
		pred = random_in_range(l, r);
	}
	while ((inp != '=') && (r - l > 150));
	//бинарный поиск для маленького диапазона
	while (inp != '='){
		if (l > r){
			printf("\nВы меня обманываете!");
			return;
		}
		pred = l + (r - l) / 2;
		printf("\nМоё предположение: %d", pred);
		k++;
		printf("\nУкажите, моё предположение >, < или = загаданному числу: ");
		scanf(" %c", &inp);
		switch (inp){
		case '<':
			r = pred - 1;
			break;
		case '>':
			l = pred + 1;
			break;
		case '=':
			break;
		}
	}

	printf("\nУра!\nЯ угадал за %d попыток\n", k);
	return;
}

int main(){
    setlocale(LC_ALL, "Russian");
    srand(time(NULL));

    //Угадай число
    int r;
    printf("Программа \"Угадай число\"\nРежимы: 1 - Угадать загаданное программой число\n        2 - Программа угадывает загаданное вами число ");
    printf("\nВведите режим: ");
    scanf("%d", &r);
    switch (r){
  	case 1:
   		mode_1();
   		break;
    case 2:
		mode_2();
		break;
	default:
		printf("Введен некорректный режим");
		break;
	}

    return 0;
}
