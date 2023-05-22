#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "whyb.h"


int selectMenuThree(){
    
    int menu;

    printf("\t0 : Return to main menu\n");
    printf("\t1 : Show Menu\n");
    printf("\t2 : Show My Cart\n");
    printf("\t3 : Add Menu To My Cart\n");
    printf("\t4 : Update Menu In My Cart\n");
    printf("\t5 : Delete Menu In My Cart\n");
    printf("\t6 : Search Menu In My Cart\n");
    printf("\t7 : Save My Cart\n");
    printf("\t8 : Order And Earn Point\n\n");
    
    printf(">> Enter a number : ");

    scanf("%d", &menu);
    printf("\n");

    return menu;
}

int loadMyFood(food *mf[]) {
    const char* filename = "myFood_data.txt";
    FILE* file = fopen(filename, "r");

    if (file != NULL) {
        int dataCount = 0;

        while (!feof(file)) {
            mf[dataCount] = malloc(sizeof(food)); // 메모리 할당

            fscanf(file, "%d %d %d %d %d %[^\n]s\n",  
                   &mf[dataCount]->type,
                   &mf[dataCount]->price,
                   &mf[dataCount]->cnt,
                   &mf[dataCount]->del,
                   &mf[dataCount]->get,
                   mf[dataCount]->name
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


void saveMyFood(food *mf[], int myCnt){

    FILE *file;

    file = fopen("myFood_data.txt", "w");

    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }

    for (int i = 0; i < myCnt; i++) {
        fprintf(file, "%d %d %d %d %d %s\n", 
        mf[i]->type, mf[i]->price, mf[i]->cnt, mf[i]->del, mf[i]->get, mf[i]->name);
    }

    fclose(file);

    printf("\n>> MyFood data saved to file successfully <<\n");
}

int loadMember(member *m[]) {
    const char* filename = "saved_member_data.txt";
    FILE* file = fopen(filename, "r");

    if (file != NULL) {
        int dataCount = 0;

        while (!feof(file)) {
            m[dataCount] = malloc(sizeof(member)); // 메모리 할당

            fscanf(file, "%s %d",  
                   m[dataCount]->userID,
                   &m[dataCount]->point
            );

            dataCount++;
        }

        fclose(file);


        // 반환: 데이터 개수
        return dataCount;
    } else {

        // 반환: 데이터가 없음
        return 0;
    }
}


int countBuy(food *mf[], int myCnt){
    int totalCnt = 0;
    for (int i = 0 ; i < myCnt ; i++){
        if (mf[i] -> del == 0 ) continue;
        else totalCnt++;
    }


    return totalCnt;
  
}



int Buy(food *mf[], int myCnt){
    int totalPrice = 0;
    for (int i = 0 ; i < myCnt ; i++){
        if (mf[i] -> del == 0 ) continue;
        else totalPrice+=mf[i]->price;
    }
        printf(">> Total checkout is %d won <<\n",totalPrice);


    return totalPrice;
  
}

void readMember(member m){
    printf("| %-14s   | %-4d", m.userID, m.point);
}

int searchMember(char search[30], member *m[], int count, int buyCnt){
    int scnt = 0;

    printf("\nNo -- UserId -- Point\n");
    printf("===============================\n");
    for (int i = 0 ; i < count ; i ++){
        if (strcmp(m[i]->userID, search)==0){
            printf("%d \t", i+1);
            readMember(*m[i]);
            scnt++;
            m[i]->point+=buyCnt;
            break;
        }
    }
    if (scnt == 0 ) {
        printf(">> Not a valid user!\n");
        printf("\n I will add this ID <<");
        printf("\n");
    }
    return scnt;
}



int addMember(char search[30], member *m, int buyCnt){
    strcpy(m->userID,search);
    m->point = 0;
    return 1;
}

void saveMemberData(member *m[], int memberCnt){
    FILE *file;

    file = fopen("saved_member_data.txt", "w");

    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }

    for (int i = 0; i < memberCnt; i++) {
        fprintf(file, "%s %d\n", m[i]->userID, m[i]->point);
    }

    fclose(file);

    printf("\n>> Member data saved to file successfully <<\n");

}
