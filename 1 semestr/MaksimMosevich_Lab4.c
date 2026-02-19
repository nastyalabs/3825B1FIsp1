#include <stdio.h>
#define size 10
/*
    {barcode - "1011", name - Hleb Borodinskiy, price - 50, skidka - 5},
    {barcode - "2313", name - Moloko Prostokvashino 1l, price - 85, skidka - 10},
    {barcode - "4123", name - Makarony Makfa, price - 65, skidka - 0},
    {barcode - "1234", name - Shokolad Alpen Gold, price - 120, skidka - 15},
    {barcode - "5555", name - Chay Greenfield, price - 200, skidka - 20},
    {barcode - "7777", name - Kofe Jacobs, price - 450, skidka - 25},
    {barcode - "8888", name - Mylo Dove, price - 75, skidka - 3},
    {barcode - "9999", name - Voda mineralnaya 1.5l, price - 60, skidka - 1},
    {barcode - "1001", name - Pechene Yubileynoe, price - 90, skidka - 12},
    {barcode - "4815", name - Syr Rossiyskiy 1kg, price - 700, skidka - 30}
*/

int tovar_barcodes[size] = {1011, 2313, 4123, 1234, 5555, 7777, 8888, 9999, 1001, 4815};
float tovar_prices[size] = {50, 85, 65, 120, 200, 450, 75, 60, 90, 700};
float tovar_skidki[size] = {5, 10, 0, 15, 20, 25, 3, 1, 12, 30};
int tovar_kolichestvo[size] = {0};

int  ind = 0;

float total_cost = 0;
float total_skidka = 0;
float total_to_pay = 0;

void scan_tovar(int pokupki[]){

    int barcode;

    int flag;
    do{
        flag = 0;
        
        printf("Vvedite barcode tovara\n");
        scanf("%d", &barcode);

        for (int i = 0; i < size; i++){
            if (barcode == tovar_barcodes[i]){
                pokupki[ind++] = i;
                flag = 1;
                break;
            }
        }
        if (flag == 0){
            printf("Vvedite barcode esco raz\n");
        }
    } while(flag == 0);
}
void info_tovar(int pokupki[]){

    if (ind == 0) {  
        printf("Net otskenirovannyh tovarov\n");
        return;
    }

    int last_index = pokupki[ind-1];

    switch(last_index){
        case 0: printf("Hleb borodinskyi, price  - 50, skidka  - 5\n"); break;
        case 1: printf("Moloko Prostokvashino 1l, price - 85, skidka - 10\n"); break;
        case 2: printf("Makarony Makfa, price - 65, skidka - 0\n"); break;
        case 3: printf("Shokolad Alpen Gold, price - 120, skidka - 15\n"); break;
        case 4: printf("Chay Greenfield, price - 200, skidka - 20\n"); break;
        case 5: printf("Kofe Jacobs, price - 450, skidka - 25\n"); break;
        case 6: printf("Mylo Dove, price - 75, skidka - 3\n"); break;
        case 7: printf("Voda mineralnaya 1.5l, price - 60, skidka - 1\n"); break;
        case 8: printf("Pechene Yubileynoe, price - 90, skidka - 12\n"); break;
        case 9: printf("Syr Rossiyskiy 1kg, price - 700, skidka - 30\n"); break;
        default: break;
    }
}

void dobavit_dannei_v_chek(int pokupki[]){

    int last_index = pokupki[ind-1];  

    tovar_kolichestvo[last_index]++;  
    printf("Tovar dobavlen v chek\n");

}
void sformirovat_chek(){


    printf(" VASH CHek \n");
    
    for (int i = 0; i < size; i++){
        if (tovar_kolichestvo[i] > 0){
            float cost = tovar_kolichestvo[i] * tovar_prices[i];
            float skidka_amount = cost * tovar_skidki[i] / 100;
            float final_cost = cost - skidka_amount;
            
            total_cost += cost;
            total_skidka += skidka_amount;
            total_to_pay += final_cost;

            switch(i){
                case 0: printf("Hleb borodinskyi - %d koll - %.2f rub ( skidka %.2f rub)\n", 
                        tovar_kolichestvo[0], final_cost, skidka_amount); break;
                case 1: printf("Moloko Prostokvashino 1l - %d koll - %.2f rub ( skidka %.2f rub)\n", 
                        tovar_kolichestvo[1], final_cost, skidka_amount); break;
                case 2: printf("Makarony Makfa - %d koll - %.2f rub ( skidka %.2f rub)\n", 
                        tovar_kolichestvo[2], final_cost, skidka_amount); break;
                case 3: printf("Shokolad Alpen Gold - %d koll - %.2f rub ( skidka %.2f rub)\n", 
                        tovar_kolichestvo[3], final_cost, skidka_amount); break;
                case 4: printf("Chay Greenfield - %d koll - %.2f rub ( skidka %.2f rub)\n", 
                        tovar_kolichestvo[4], final_cost, skidka_amount); break;
                case 5: printf("Kofe Jacobs - %d koll - %.2f rub ( skidka %.2f rub)\n", 
                        tovar_kolichestvo[5], final_cost, skidka_amount); break;
                case 6: printf("Mylo Dove - %d koll - %.2f rub ( skidka %.2f rub)\n", 
                        tovar_kolichestvo[6], final_cost, skidka_amount); break;
                case 7: printf("Voda mineralnaya 1.5l - %d koll - %.2f rub ( skidka %.2f rub)\n", 
                        tovar_kolichestvo[7], final_cost, skidka_amount); break;
                case 8: printf("Pechene Yubileynoe - %d koll - %.2f rub ( skidka %.2f rub)\n", 
                        tovar_kolichestvo[8], final_cost, skidka_amount); break;
                case 9: printf("Syr Rossiyskiy 1kg - %d koll - %.2f rub ( skidka %.2f rub)\n", 
                        tovar_kolichestvo[9], final_cost, skidka_amount); break;
            }
        }
    }
}

void itog_summa(){

    printf("Itogo stoimost %f\n", total_cost);
    printf("Itogo skidka %f\n", total_skidka);
    printf("Itogo stoimost %f\n", total_to_pay);
}

void main(){
    int pokupki[1000];
    
    int flag = 0, rejim;

    do{
        printf("Viebrete deistvie\n");
        printf("1 - scan tovara\n");
        printf("2 - info o poslednem scanirovanom tovare\n");
        printf("3 - dobavit v chek poslednyi scanirovanniy tovar\n");
        printf("4 - vivesti chek\n");
        printf("5 - itogovya summa\n");

        scanf("%d", &rejim);

        switch(rejim){
            case 1: scan_tovar(pokupki); break;
            case 2: info_tovar(pokupki); break;
            case 3: dobavit_dannei_v_chek(pokupki); break;
            case 4: sformirovat_chek(); break;
            case 5: itog_summa(); flag = 1; break;
            default: printf("Nepravilnyi vibor!\n"); break;
        }
    }while(flag != 1);

}