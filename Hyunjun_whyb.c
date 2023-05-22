#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "whyb.h"
#include <time.h>

int loadData(food *f[]) {
    const char* filename = "saved_menu_data.txt";
    FILE* file = fopen(filename, "r");

    if (file != NULL) {
        int dataCount = 0;

        while (!feof(file)) {
            f[dataCount] = malloc(sizeof(food)); // 메모리 할당

            fscanf(file, "%d %d %d %d %d %[^\n]s\n",  
                   &f[dataCount]->type,
                   &f[dataCount]->price,
                   &f[dataCount]->cnt,
                   &f[dataCount]->del,
                   &f[dataCount]->get,
                   f[dataCount]->name
            );

            dataCount++;
        }

        fclose(file);

        printf("data loaded\n");

        // 반환: 데이터 개수
        return dataCount;
    } else {
        printf("there is no data\n");

        // 반환: 데이터가 없음
        return 0;
    }
}


int selectMenuTwo(){
     //menu 1 : random pick
     //menu 2 : worldcuup pick
     //menu 0 : quit
    int num;
    printf("\n\n\tWhy bother choose menu? We will choose for you!\n");
    printf("\t-----------------------------------------------\n");
    printf("\t1 : totaly random pick \n");
    printf("\t2 : pick by world cup \n" );
    printf("\t0 : quit \n");

    printf(">> Enter a number : ");
    scanf("%d", &num);

    return num;

}

void randomPick(food *f[], int count){
     //SelectFoodType 통해서 종류 정하기
     //type 일치, delete 안된 메뉴 중 random으로 나온 값 print

    int type;
    int num;
    int judge = 0;

    if (count == 0){
        printf("There is no Data :(");
        return;
    }

    srand(time(NULL));

    printf("\n\n\tWhy bother choose menu? We will choose for you!\n");
    printf("\t-----------------------------------------------\n");

    while(judge==0){
        int randomNumber = rand() % count;

        type = selectFoodType();

        if(f[randomNumber]->type==type && f[randomNumber]->del!=0){
            judge = 1;
            num = randomNumber;
        }
        
    }
    
    printf("we recommend you a %s \n", f[num]->name);

}

void worldCupPick(food *f[], int count){//현준
     //SelectFoodType 통해서 종류 정하기
     //type 일치, delete 안된 메뉴 중 월드컵 실시
     //최종 메뉴 print
    printf("\n\n\tWelcome to food worldcup!\n");
    printf("\t-------------------------\n\n");
    printf("\tDo you want to start your favourite food world cup?\n");
    printf("\tYou can keep choosing a menu that seizes your mind,\n");
    printf("\tuntil there are only one menu left.\n");
    printf("\tFirst, you have to choose what type of food you perfer.\n\n");
    
    int countavailable =0;
    int type;
    int j = 0 ; 
    type = selectFoodType();

    for(int i = 0 ; i <count ; i++){
        if(f[i]->del==1 && f[i]->type == type){
            countavailable ++;
        }
    }

    food * temp[countavailable];

    for(int i = 0 ; i <count ; i++){
        if(f[i]->del==1 && f[i]->type == type){
            temp[j] = f[i];
            temp[j]->round = 1;
            j++;
        }
    }

    worldCupHelper(temp , countavailable , 1);
}

void worldCupHelper(food * f[] , int countavailable, int a){
    int select;
    int temp = countavailable;
    

    if(countavailable == 1){
        printf("\tWorldCup finished!\n");
        printf("\t------------------\n");
        printf("\tYour best pick is %s!\n\n", f[0]->name);
    }else{
        for(int a = 0 ; a < countavailable ; a= a+2){
            if(a==countavailable-1){
                f[a]->round++;
            }else{
                printf("\n\t1 : %s | 2 : %s\n\n", f[a]->name, f[a+1]->name);
                printf(" >> Enter the number : ");
                scanf("%d", &select);

                if (select == 1) {
                    f[a]->round++;
                    temp --;
                }
                else {
                    f[a+1]->round++;
                    temp--;
                }
            }
        }

        food* winners[temp];
        int b=0;
        
        for(int i = 0 ; i <temp ; i++){
            if(f[i]->round==2){
                winners[b] = f[i];
                b++;
            }
        }
        a++;

        worldCupHelper(winners , temp , a);
        
    }
}