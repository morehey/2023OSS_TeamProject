#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "score.h"

int main(void) {
    int count = 0, menu, index = 0;
    int result = 0;
    char ld[20];
    score *sp[100];

    scanf("%s", ld);
    if (strcmp(ld, "./score4")==0){
        count = loadData(sp);
        index = count;
    }


    while(1) {

        menu = selectMenu();
        if (menu == 0) break;
        else if (menu == 2) {
            sp[index] = (score *)malloc(sizeof(score));
            count += addScore(sp[index++]);
        } else if (menu == 1) {
            if(count > 0) listScore(sp, index);
            else printf("데이터가 없습니다.\n");
        } else if (menu == 3) {
            int no = selectDataNo(sp, index);
            if (no == 0) {
                printf("=> 취소됨!\n");
                continue;
            }
            updateScore(sp[no - 1]);
        }
        else if (menu == 4) {
            int no = selectDataNo(sp, index);
            if (no == 0) {
                printf("=> 취소됨!\n");
                continue;
            }

            int deleteok;
            printf("정말로 삭제하시겠습니까?(삭제 :1)");
            scanf("%d", &deleteok);
            if (deleteok == 1) {
                    deleteScore(sp[no-1]);
                    count--;
                    printf("=> 삭제됨\n");
            } 
            else printf("=> 취소됨\n");
            }
        else if (menu == 5){
            saveData(sp, index);
        }
        else if (menu == 6){
            searchName(sp, index);
        }
    }
    printf("종료됨!\n");
    return 0;
}