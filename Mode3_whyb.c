#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "whyb.h"


int selectMenuThree(){
    int menu;
    printf("1 : Show Menu\n");
    printf("2 : Show My Cart\n");
    printf("3 : Add Menu To My Cart\n");
    printf("4 : Update Menu In My Cart\n");
    printf("5 : Delete Menu In My Cart\n");
    printf("6 : Search Menu In My Cart\n");
    printf("7 : Sava My Cart\n");
    printf("8 : Order And Earn Point\n");
    printf("0 : Quit\n\n");
    printf("=> which menu do you want to start?");

    scanf("%d", &menu);

    return menu;
}

int loadMyFood(food *mf[]){
    return 0;
}

void saveMyFood(food *f[], int myCnt){
}

int loadMemberData(member *m[]){
}


int Buy(food *mf[], int myCnt){
  
}


int searchMember(member *m[], int count, int buyCnt){//����

}


int addMember(member *m, int buyCnt){//����

}

void saveMemberData(member *m[], int memberCnt){//����

}
