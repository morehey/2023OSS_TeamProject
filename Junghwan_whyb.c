#include <stdio.h>
#include <stdlib.h>
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
    
    printf("\nMenu  -  Select Menu\n");
    printf("---------------------\n\n");
    printf("1 : Read Menu\n");
    printf("2 : Add Menu\n");
    printf("3 : Fix Menu\n");
    printf("4 : Delete Menu\n");
    printf("5 : Search Menu\n");
    printf("6 : Save Menu\n");
    printf("0 : EXit\n\n");
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
        printf("| %s\t   | %d\t\t | %dwon\t | %d\n", f.name, f.type, f.price, f.cnt);
    }
    //해당 메뉴의 이름, 가격 print
}


void listFood(food *f[], int count){//정환

    printf("number\t| Name\t   | Type\t | Price\t\t | Quantity\n");
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
    printf("---------------------\n\n");

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
    
    return 1;
}

void deleteFood(food *f){//정환
    //del를 0으로 변경
}

void searchName(food *f[], int count){//정환
    //검색할 이름을 입력받고 
    //삭제되지 않고, 이름이 같으면 readFood함수에서 menu 읽기
}

void saveData(food *f[], int count){//정환
    //지금까지 추가, 수정, 삭제 한 내용 .txt파일에 저장하기
    //loadData에서의 .txt파일명과 동일한 txt파일이여야 함
}