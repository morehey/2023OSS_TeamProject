#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "whyb.h"


int selectMode(){

    int menu;

    printf("\n\tWhy Bother Choose Menu? Use whyb instead!\n");
    printf("\t-----------------------------------------\n");
    printf("\tChoose mode\n\n");
    printf("\t0 : Exit\n");
    printf("\t1 : Menu CRUD\n");
    printf("\t2 : Help your choice\n");
    printf("\t3 : Menu order\n\n");
    printf(">> which mode do you want to start? ");

    scanf("%d", &menu);
    
    return menu;
}
