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

    fgets(buf, SIZE, stdin);   
    menu = atoi(buf);

    return menu;
}

int addFood(food *f){   //정환

    char buf[SIZE];

    printf("\n메뉴 이름을 입력하세요: ");
    fgets(f->name, SIZE, stdin);
    f->name[strlen(f->name)-1] = '\0';
    
    printf("메뉴의 종류는? (식사 : 1, 음료 : 2, 사이드 : 3): ");
    fgets(buf, SIZE, stdin);
    f->type = atoi(buf);
    
    printf("가격은?: ");
    fgets(buf, SIZE, stdin);
    f->price = atoi(buf);
    
    printf("수량은?: ");
    fgets(buf, SIZE, stdin);
    f->cnt = atoi(buf);

    f->del = 1;
    
    printf("메뉴가 성공적으로 추가되었습니다!\n");
    
    return 1;

    //메뉴 (이름, 가격, 타입) 추가
    //1 리턴
}

void readFood(food f){//정환
    if (f.del == 0) {
        printf("정보가 없습니다.");
        return;
    }
    else {
        printf("| %s\t   | %d\t\t | %d원\t | %d개\n", f.name, f.type, f.price, f.cnt);
    }
    //해당 메뉴의 이름, 가격 print
}


void listFood(food *f[], int count){//정환

    printf("번호\t| 메뉴이름\t   | 종류\t | 가격\t\t | 수량\n");
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
    printf("번호는? (취소 :0) : ");
    scanf("%d", &num);
    return num;
}

void updateFood(food *f){//정환

    char buf[SIZE];

    printf("\n메뉴판  -  메뉴 수정\n");
    printf("---------------------\n\n");

    printf("\n메뉴 이름을 입력하세요: ");
    fgets(f->name, SIZE, stdin);
    f->name[strlen(f->name)-1] = '\0';
    
    printf("메뉴의 종류는? (식사 : 1, 음료 : 2, 사이드 : 3): ");
    fgets(buf, SIZE, stdin);
    f->type = atoi(buf);
    
    printf("가격은?: ");
    fgets(buf, SIZE, stdin);
    f->price = atoi(buf);
    
    printf("수량은?: ");
    fgets(buf, SIZE, stdin);
    f->cnt = atoi(buf);
    
    printf("메뉴가 성공적으로 수정되었습니다!\n");
    
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