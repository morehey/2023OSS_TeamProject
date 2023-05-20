#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "whyb.h"


int selectFoodType(){//정환
    
    //Type 1 : ~
    //Type 2 : ~
    //return Type 번호
}

int selectMenuOne() {

    char buf[SIZE];
    int menu;
    
    printf("\t\t\nMenu  -  Select Menu\n");
    printf("\t----------------------\n\n");
    printf("\t1 : Read Menu\n");
    printf("\t2 : Add Menu\n");
    printf("\t3 : Fix Menu\n");
    printf("\t4 : Delete Menu\n");
    printf("\t5 : Search Menu\n");
    printf("\t6 : Save Menu\n");
    printf("\t0 : EXit\n\n");
    printf("Enter a number : ");

    fgets(buf, SIZE, stdin);   
    menu = atoi(buf);

    return menu;
}

int addFood(food *f){   //정환

    char buf[SIZE];

    printf("\nEnter the name of the menu: ");
    fgets(f->name, SIZE, stdin);
    f->name[strlen(f->name)-1] = '\0';
    
    printf("Menu type? (Meal : 1, Dring : 2, Side : 3): ");
    fgets(buf, SIZE, stdin);
    f->type = atoi(buf);
    
    printf("Price?: ");
    fgets(buf, SIZE, stdin);
    f->price = atoi(buf);
    
    printf("Quantity?: ");
    fgets(buf, SIZE, stdin);
    f->cnt = atoi(buf);

    f->del = 1;
    
    printf("Menu has been successfully added!\n");
    
    return 1;

}

void readFood(food f){//정환
    if (f.del == 0) {
        printf("No data.");
        return;
    }
    else {
        printf("| %s\t   | %d\t\t | %d won\t | %d\n", f.name, f.type, f.price, f.cnt);
    }
    //해당 메뉴의 이름, 가격 print
}


void listFood(food *f[], int count){//정환

    printf("\nnumber\t| Name\t\t   | Type\t | Price\t | Quantity\n");
    printf("------------------------------------------------------------------\n");
    for(int i = 0; i < count; i++){
        if(f[i] == NULL) continue;
        printf("%d \t", i+1);
        readFood(*f[i]);
    }
    printf("\n");

}

int selectFoodNo(food *f[], int count){//정환
    int num;
    listFood(f, count);
    printf("What is the menu number? (Cancle :0) : ");
    scanf("%d", &num);
    return num;
}

void updateFood(food *f){//정환

    char buf[SIZE];

    printf("\nMenu  -  Fix Menu\n");
    printf("-------------------\n\n");

    printf("\nEnter the name of the menu: ");
    fgets(f->name, SIZE, stdin);
    f->name[strlen(f->name)-1] = '\0';
    
    printf("Menu type? (Meal : 1, Dring : 2, Side : 3): ");
    fgets(buf, SIZE, stdin);
    f->type = atoi(buf);
    
    printf("Price?: ");
    fgets(buf, SIZE, stdin);
    f->price = atoi(buf);
    
    printf("Quantity?: ");
    fgets(buf, SIZE, stdin);
    f->cnt = atoi(buf);
    
    printf("Menu has been successfully fixed!\n");
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

    printf("Enter the name of the menu: ");
    fgets(menuName, SIZE, stdin);
    menuName[strlen(menuName)-1] = '\0';
    printf("\n");

    for(int i = 0; i < count; i++) {

        if (f[i] == NULL) continue;
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
        fprintf(file, "%s %d %d %d\n", 
        f[i]->name, f[i]->type, f[i]->price, f[i]->cnt);
    }

    fclose(file);

    printf("\n>> Food data saved to file successfully <<\n");
}