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

    int menu;
    
    printf("\n메뉴판  -  메뉴 선택\n");
    printf("---------------------\n\n");
    printf("1 : 메뉴 조회\n");
    printf("2 : 메뉴 추가\n");
    printf("3 : 메뉴 수정\n");
    printf("4 : 메뉴 삭제\n");
    printf("5 : 메뉴 찾기\n");
    printf("6 : 메뉴 저장\n");
    printf("0 : 종료\n\n");
    printf("메뉴 입력 : ");
    scanf("%d", &menu);
    
    return menu;
}

int addFood(food *f){   //정환

    char buf[SIZE];

    printf("Enter the menu name: ");
    fgets(f->name, SIZE, stdin);
    f->name[strlen(f->name)-1] = '\0';
    
    printf("\nEnter the menu type (1 for meal, 2 for beverage, 3 for side): ");
    fgets(buf, SIZE, stdin);
    f->type = atoi(buf);
    
    printf("\nEnter the menu price: ");
    fgets(buf, SIZE, stdin);
    f->price = atoi(buf);
    
    f->cnt = 0;
    f->del = 0;
    f->get = 0;
    
    printf("Menu added successfully!\n");
    
    return 1;

    //메뉴 (이름, 가격, 타입) 추가
    //1 리턴
}

void readFood(food f){//정환
    //해당 메뉴의 이름, 가격 print
}


void listFood(food *f[], int count){//정환
    //selectFoodType으로 type 입력받기
    //삭제되지 않은 번호이고, type이 일치하면 해당 번호 print
    //readFood함수에서 menu 읽기
}

int selectFoodNo(food *f[], int count){//정환
    //listFood로 번호와 메뉴들 보여주기
    //메뉴 번호 리턴(취소 : 0)
}

void updateFood(food *f){//정환
    //메뉴 이름, 가격, 타입 업데이트하기
    //1 리턴하기
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