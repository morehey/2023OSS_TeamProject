#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "whyb.h"
#define SIZE 100
#define MSIZE 100

int main(){

    int mode;
    int index;      //메뉴판 인덱스
    int myIndex = 0;    //장바구니 인덱스
    int memIndex;   //회원 인덱스
    int menu;
    int count;      //메뉴판 메뉴 개수 (삭제 된 것까지 합해서)
    int myCnt;      //장바구니 메뉴 개수 (삭제 된 것까지 합해서)
    int buyCnt;     //장바구니 메뉴 개수 (삭제 된 것 제외)
    int memberCnt;  //회원들 수
    int memberIs;   //기존 회원인지 여부
    char search[30];

    food *fo[SIZE];
    food *myFo[SIZE];
    member *mem[MSIZE];

    count = loadData(fo);
    index = count;

    while(1){

        mode = selectMode(); 

        if (mode == 1){     //메뉴판 CRUD

            bool repeat = true;

            while(repeat){
                menu = selectMenuOne();

                if (menu == 0) repeat = false;
                else if (menu == 1){
                    if (count > 0 ) listFood(fo, index);
                    else printf(">> No data <<\n");
                }
                else if (menu == 2){
                    fo[count] = (food *)malloc(sizeof(food));
                    count += addFood(fo[index++]);
                }
                else if (menu == 3){
                    int no = selectFoodNo(fo, index);
                    if (no == 0){
                        printf("=> Cancled!\n");
                        continue;
                    }
                    updateFood(fo[no-1]);
                }
                else if (menu == 4){
                    int no = selectFoodNo(fo, index);
                    if (no == 0){
                        printf("=> Canceled!\n");
                        continue;
                    }

                    int deleteOk;
                    printf(">> Are you sure you want to delete? (confirm : 1) <<");
                    scanf("%d", &deleteOk);
                    if (deleteOk == 1){
                        deleteFood(fo[no-1]);
                        count--;
                        printf("=> Deleted!\n");
                    }
                    else printf("=> Canceled!");
                }
                else if (menu == 5){
                    searchName(fo, index);
                }
                else if (menu == 6){
                    saveData(fo, index);
                }
            }
        }
        
        else if (mode == 2){
            bool repeat = true;
            while(repeat){
                menu = selectMenuTwo();
                if (menu == 0) repeat = false;
                else if (menu == 1){
                    randomPick(fo, index);
                }
                else if (menu == 2){
                    worldCupPick(fo, index);
                }
            }
        }

        else if (mode == 3) {

            bool repeat = true;
            
            // myCnt = loadMyFood(myFo);
            // memberCnt = loadMemberData(mem);
            // memIndex = memberCnt;

                        
            myCnt = 0;
            


            while (repeat) {
                menu = selectMenuThree();

                if (menu == 0) repeat = false;
                else if (menu == 1){
                    if (count > 0 ) listFood(fo, index);
                    else printf(">> No data <<\n");
                }
                else if (menu == 2){
                    if (myCnt > 0 ) listFood(myFo, myIndex);
                    else printf("There are no menu in the cart\n");

                }
                else if (menu == 3){
                    myFo[myIndex] = (food *)malloc(sizeof(food));
                    myCnt += addFood(myFo[myIndex++]);
                }
                else if (menu == 4){
                    int no = selectFoodNo(myFo, myIndex);
                        if (no == 0){
                            printf("=> Cancled!\n");
                            continue;
                        }
                        updateFood(myFo[no-1]);
                }
                else if (menu == 5){
                    int no = selectFoodNo(myFo, myIndex);
                        if (no == 0){
                            printf("=> Canceled!\n");
                            continue;
                        }

                        int deleteOk;
                        printf(">> Are you sure you want to delete? (confirm : 1) <<");
                        scanf("%d", &deleteOk);
                        if (deleteOk == 1){
                            deleteFood(myFo[no-1]);
                            myCnt--;
                            printf("=> Deleted!\n");
                        }
                        else printf("=> Cancled!");
                }
                else if (menu == 6){
                    searchName(myFo, myIndex);
                }
                else if (menu == 7){
                    saveMyFood(myFo, myIndex);
                }
                else if (menu == 8){
                    memberCnt = loadMember(mem);
                    memIndex = memberCnt;
                    if (myCnt == 0){
                        printf("There is no Data\n");
                        printf("You should take one more menu\n");
                        continue;
                    }
                    buyCnt = Buy(myFo, myCnt);
                    buyCnt = countBuy(myFo, myCnt);
                    printf(">> what is the userID of for the point? ");
                    scanf("%s", search);
                    memberIs = searchMember(search, mem, memberCnt, buyCnt);
                    if (memberIs == 1){
                        mem[memIndex] = (member *)malloc (sizeof(member));
                        memberCnt += addMember(search, mem[memIndex++], buyCnt);
                    }
                    saveMemberData(mem, memIndex);
                }
            }
        }
        
        else if (mode == 0){
            break;
        }

    }

    printf(">> Good Bye~ <<\n");
    
    return 0;
}
