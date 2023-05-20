#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "whyb.h"


int selectMode(){

    char buf[SIZE];
    int menu;

    printf("\n\tWhy Bother Choose Menu? Use whyb instead!\n");
    printf("\t-----------------------------------------\n");
    printf("\tchoose mode\n\n");
    printf("\t1 : menu CRUD\n");
    printf("\t2 : help your choice\n");
    printf("\t3 : menu order\n");
    printf("\t4 : quit\n\n");
    printf("=> which mode do you want to start? ");

    fgets(buf, SIZE, stdin);   
    menu = atoi(buf);

    return menu;
}
