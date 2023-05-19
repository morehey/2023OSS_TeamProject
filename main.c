#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include "whyb.h"

int main(){

    int mode;
    int t;      
    int index; //menu index
    int myIndex = 0;  //menu in my cart index 
    int memIndex;  //member index
    int menu;  
    int count;  //menu count which include deleted
    int myCnt;   //menu in cart count which include deleted 
    int buyCnt;   //menu count which except deleted
    int memberCnt; //member count
    int memberIs;  //whether member is existed.

    food *fo[SIZE];
    food *myFo[SIZE];
    member *mem[MSIZE];
    
    count = loadData(fo);
    index = count;
    mode = selectMode(); 

    while(1){

        if (mode == 1){     //�޴��� CRUD

            while(1){
                menu = selectMenuOne();

                if (menu == 0) break;
                else if (menu == 1){
                    if (count > 0 ) listFood(fo, index);
                    else printf("No data found.\n");
                }
                else if (menu == 2){
                    fo[index] = (food *)malloc(sizeof(food));
                    count += addFood(fo[index++]);
                }
                else if (menu == 3){
                    int no = selectFoodNo(fo, index);
                    if (no == 0){
                        printf("=> Canceled\n");
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
                    printf("Are you sure you want to delete (delete 1)");
                    scanf("%d", &deleteOk);
                    if (deleteOk == 1){
                        deleteFood(fo[no-1]);
                        count--;
                        printf("=> Deleted\n");
                    }
                    else printf("=> Canceled");
                }
                else if (menu == 5){
                    searchName(fo, index);
                }
                else if (menu == 6){
                    saveData(fo, index);
                }
            }
        

        }
        
        if (mode == 2){
            while(1){
                menu = selectMenuTwo();
                if (menu == 0) break;
                else if (menu == 1){
                    randomPick(fo, index);
                }
                else if (menu == 2){
                    worldCupPick(fo, index);
                }
            }

        }

        if (mode == 3){
            menu = selectMenuThree();
            myCnt = loadMyFood(myFo);
            memberCnt = loadMemberData(mem);
            memIndex = memberCnt;

            if (menu == 0) break;
            else if (menu == 1){
                if (count > 0 ) listFood(fo, index);
                else printf("�����Ͱ� �����ϴ�.\n");
            }
            else if (menu == 2){
                if (myCnt > 0 ) listFood(myFo, myIndex);
                else printf("��ٱ��Ͽ� ��� �޴��� �����ϴ�.\n");

            }
            else if (menu == 3){
                myFo[myIndex] = (food *)malloc(sizeof(food));
                myCnt += addFood(myFo[myIndex++]);
            }
            else if (menu == 4){
                int no = selectFoodNo(myFo, myIndex);
                    if (no == 0){
                        printf("=> ��ҵ�\n");
                        continue;
                    }
                    updateFood(myFo[no-1]);
            }
            else if (menu == 5){
                int no = selectFoodNo(myFo, myIndex);
                    if (no == 0){
                        printf("=> ��ҵ�!\n");
                        continue;
                    }

                    int deleteOk;
                    printf("������ �����Ͻðڽ��ϱ�?(���� 1)");
                    scanf("%d", &deleteOk);
                    if (deleteOk == 1){
                        deleteFood(myFo[no-1]);
                        myCnt--;
                        printf("=> ������\n");
                    }
                    else printf("=> ��ҵ�");
            }
            else if (menu == 6){
                searchName(myFo, myIndex);
            }
            else if (menu == 7){
                saveMyFood(myFo, myIndex);
            }
            else if (menu == 8){
                buyCnt = Buy(myFo, myCnt);
                memberIs = searchMember(mem, memberCnt, buyCnt);
                if (memberIs = 1 ){
                    mem[memIndex] = (member *)malloc (sizeof(member));
                    memberCnt += addMember(mem[memIndex++], buyCnt);
                }
                saveMemberData(mem, memberCnt);
            }

        }
        
        if (mode == 4){
            break;
        }

    }

    printf("���α׷��� ����Ǿ����ϴ�.\n");

    
    return 0;
}
