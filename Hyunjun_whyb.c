#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "whyb.h"
#include <time.h>

int loadData(food *f[]){
   const char* filename = "menu_data.txt";
    FILE* file = fopen(filename, "r");

    if (file != NULL) {

        int dataCount = 0;
        char line[256];
        while (fgets(line, sizeof(line), file) != NULL) {
            scanf(line, "9s %d %d %d %d %d", 
                   f[dataCount]->name,
                   &f[dataCount]->type,
                   &f[dataCount]->price,
                   &f[dataCount]->cnt,
                   &f[dataCount]->del,
                   &f[dataCount]->get
                   );

            dataCount++;
        }

        fclose(file);

        printf("data loaded\n");

        // return data count
        return dataCount;
    } else {
        printf("there is no data\n");

        // return 0 because there is nodata
        return 0;
    }
}


int selectMenuTwo(){
     //menu 1 : random pick
     //menu 2 : worldcuup pick
     //menu 0 : quit
    int num;

    printf("\t1 : totaly random pick \n");
    printf("\t2 : pick by world cup \n" );
    printf("\t0 : quit ");

    scanf("%d", &num);

    return num;

}

void randomPick(food *f[], int count){
     //SelectFoodType 통해서 종류 정하기
     //type 일치, delete 안된 메뉴 중 random으로 나온 값 print

    int type;
    int num;
    int judge = 0;
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
    printf("\tyou can keep choosing a menu that seizes your mind,\n");
    printf("\tuntil there are only one menu left.\n");
    printf("\tFirst, you have to choose what type of food you perfer.\n\n");

    int type = selectFoodType();
    int countMenu = 0;
    food *temp[SIZE];

// Copy datas in original food menu with chosen menu type, excluding the deleted ones.
    for (int i = 0; i < count; i++)
        if (f[i]->del == 1 && f[i]->type == type) {
            temp[i] = f[i];
            countMenu++;
        }

    foodPicker(temp, countMenu);
}

void foodPicker(food *temp[], int countMenu) {

    int i = 0;
    int add = 0;
    int select;

    printf("\n\twhich one do you prefer?\n");
    printf("\t------------------------\n");

    if (temp[i]->del == 0) {
        printf("No data");
        return;
    }

    while (countMenu > 1) {

        printf("1 : %s | 2 : %s\n\n", temp[i]->name, temp[i+add+1]->name);
        printf(" >> Enter the number : ");
        scanf("%d", &select);

        if (select == 1) {
            temp[i]->del = 0;
            add++;
        }
        else {
            temp[i+1]->del = 0;
            i++;
        }
        countMenu--;

    }

    printf("WorldCup finished!\n");
    printf("------------------\n");
    printf("Your best pick is %s!\n\n", temp[i]->name);

}