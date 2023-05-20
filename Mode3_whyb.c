#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "whyb.h"


int selectMenuThree(){

    char buf[SIZE];
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

    fgets(buf, SIZE, stdin);   
    menu = atoi(buf);

    return menu;
}

int loadMyFood(food *mf[]){
    const char* filename = "myFood_data.txt";
    FILE* file = fopen(filename, "r");

    if (file != NULL) {

        int myFoodCount = 0;
        char line[256];
        while (fgets(line, sizeof(line), file) != NULL) {
            scanf(line, "9s %d %d %d", 
                   mf[myFoodCount]->name,
                   &mf[myFoodCount]->type,
                   &mf[myFoodCount]->price,
                   &mf[myFoodCount]->cnt
                   );

            myFoodCount++;
        }

        fclose(file);

        printf("data loaded\n");
        return myFoodCount;
    } else {
        printf("there is no data\n");
        return 0;
    }
    return 0;
}

void saveMyFood(food *f[], int myCnt){

    FILE *file;

    file = fopen("myFood_data.txt", "w");

    if (file == NULL) {
        printf("Failed to open the file for writing.\n");
        return;
    }

    for (int i = 0; i < myCnt; i++) {
        fprintf(file, "%s %d %d %d\n", 
        f[i]->name, f[i]->type, f[i]->price, f[i]->cnt);
    }

    fclose(file);

    printf("\n>> MyFood data saved to file successfully <<\n");
}

int loadMemberData(member *m[]){
    const char* filename = "Member_data.txt";
    FILE* file = fopen(filename, "r");

    if (file != NULL) {

        int MemberCount = 0;
        char line[256];
        while (fgets(line, sizeof(line), file) != NULL) {
            scanf(line, "9s %d %d %d", 
                   m[MemberCount]->userID,
                   &m[MemberCount]->point
                   );

            MemberCount++;
        }

        fclose(file);

        printf("data loaded\n");
        return MemberCount;
    } else {
        printf("there is no data\n");
        return 0;
    }
    return 0;
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

    return totalPrice;
  
}

void readMember(member m){
    printf("%s %d", m.userID, m.point);
}

int searchMember(member *m[], int count, int buyCnt){
    int scnt = 0;
    char search[20];

    printf("what is the name of the member? ");
    scanf("%s", search);

    printf("\nNo UserId Point\n");
    printf("===============================\n");
    for (int i = 0 ; i < count ; i ++){
        if (strstr(m[i]->userID, search)){
            printf("%2d", i+1);
            readMember(*m[i]);
            break;
        }
    }
    if (scnt == 0 ) printf("=> Not a valid user!");
    printf("\n");
}



int addMember(member *m, int buyCnt){
    printf("What is you UserID? ");
    scanf("%s", m->userID);
    m->point = 0;
    return 1;
    //I want to add the service which makes member doesn't duplicate. If time is possible, I will try it.
}

void saveMemberData(member *m[], int memberCnt){
    FILE *file;

    file = fopen("myFood_data.txt", "w");

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
