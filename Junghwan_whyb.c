#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "whyb.h"


int selectFoodType(){//정환
    
    int type;

    printf("\tWhat type of food would you like to eat?");
    printf("\n\n\tType 1 : Meal\n");
    printf("\tType 2 : Drink\n");
    printf("\tType 3 : Side\n\n");
    printf(">> Enter the food type number : ");
    scanf("%d", &type);

    return type;
}

int selectMenuOne() {

    int menu;
    
    printf("\t\t\nMenu  -  Select Menu\n");
    printf("\t----------------------\n\n");
    printf("\t0 : Return to main menu\n");
    printf("\t1 : Read menu\n");
    printf("\t2 : Add menu\n");
    printf("\t3 : Fix menu\n");
    printf("\t4 : Delete menu\n");
    printf("\t5 : Search menu\n");
    printf("\t6 : Save menu\n\n");
    printf(">> Enter a number : ");

    scanf("%d", &menu);

    return menu;
}

int addFood(food *f){   //정환

    printf("\n>> Enter the name of the menu: ");
    scanf("\n");
    scanf("%[^\n]s", f->name );
    
    printf(">> Menu type? (Meal : 1, Drink : 2, Side : 3): ");
    scanf("%d", &f->type);
    
    printf(">> Price?: ");
    scanf("%d", &f->price);

    f->cnt = 0;

    f->del = 1;

    f->get = 0;
    
    printf(">> Menu has been successfully added! <<\n");
    
    return 1;

}

void readFood(food f){//정환
    if (f.del == 0) {
        return;
    }
    else {
        printf("| %-14s   | %-4d | %d won\t | %d\n", f.name, f.type, f.price, f.cnt);
    }
    //해당 메뉴의 이름, 가격 print
}


void listFood(food *f[], int count){//정환

    printf("\nnumber\t| Name\t\t   | Type | Price\t | Quantity\n");
    printf("------------------------------------------------------------------\n");
    for(int i = 0; i < count; i++){
        if(f[i]->del == 0) continue;
        else{
            printf("%d \t", i+1);
            readFood(*f[i]);
        }
       
    }
    printf("\n");

}

int selectFoodNo(food *f[], int count){//정환
    int num;
    listFood(f, count);
    printf(">> What is the menu number? (Cancle :0) : ");
    scanf("%d", &num);
    return num;
}

void updateFood(food *f){//정환

    printf("\nMenu  -  Fix Menu\n");
    printf("-------------------\n\n");

    printf("\n>> Enter the name of the menu : ");
    scanf("\n");
    scanf("%[^\n]s", f->name );
    
    printf(">> Menu type? (Meal : 1, Dring : 2, Side : 3): ");
    scanf("%d", &f->type);
    
    printf(">> Price? : ");
    scanf("%d", &f->price);

    f->cnt = 0;
    f->del = 1;
    f->get = 0;
    
    printf(">> Menu has been successfully fixed! <<\n");
}

void deleteFood(food *f){//정환
    f->name[0] = '\0';
    f->type = -1;
    f->price = -1;
    f->cnt = -1;
    f->del = 0;
}

void searchName(food *f[], int count){//정환

    char menuName[SIZE];
    bool found = false;

    printf("\nMenu  -  Search Menu\n");
    printf("----------------------\n\n");

    printf(">> Enter the name of the menu: ");
    scanf("\n");
    scanf("%[^\n]s", menuName);
    printf("\n");

    for(int i = 0; i < count; i++) {

        if (f[i]->del == 0) continue;
        else if (strcmp(f[i]->name, menuName) == 0) {
            printf("%d \t", i+1);
            readFood(*f[i]);
            found = true;
        }
    }

    if (!found) printf(">> Menu not found <<\n");
}

void saveData(food *f[], int count){//정환

    FILE *file;

    file = fopen("saved_menu_data.txt", "w");

    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }

    for (int i = 0; i < count; i++) {
        if (f[i]->del == 0) continue;
        fprintf(file, "%d %d %d %d %d %s\n", 
        f[i]->type, f[i]->price, f[i]->cnt, f[i]->del, f[i]->get, f[i]->name);
    }

    fclose(file);

    printf("\n>> Food data saved to file successfully <<\n");
}