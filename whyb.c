#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include "whyb.h"


int loadData(food *f[]){
   const char* filename = "menu_data.txt";
    FILE* file = fopen(filename, "r");

    if (file != NULL) {

        int dataCount = 0;
        char line[256];
        while (fgets(line, sizeof(line), file) != NULL) {
            scanf(line, "9s %d %d %d %d %d", 
                   f[dataCount]->name,
                   &f[dataCount]->type,
                   &f[dataCount]->price,
                   &f[dataCount]->cnt,
                   &f[dataCount]->del,
                   &f[dataCount]->get
                   );

            dataCount++;
        }

        fclose(file);

        printf("data loaded\n");

        // return data count
        return dataCount;
    } else {
        printf("there is no data\n");

        // return 0 because there is nodata
        return 0;
    }

}


int selectMode(){
    int menu;
    printf("\nWhy Bother Choose Menu? Use whyb instead!\n");
    printf("-----------------------------------------\n");
    printf("choose mode\n\n");
    printf("1 : menu CRUD\n");
    printf("2 : help your choice\n");
    printf("3 : menu order\n");
    printf("4 : quit\n\n");
    printf("=> which mode do you want to start? ");
    scanf("%d", &menu);
    return menu;
}

int selectMenuTwo(){//����
    //menu 1 : �������� ������
    //menu 2 : ���������� ������
    //menu 0 : ����
}

void randomPick(food *f[], int count){//����
    //SelectFoodType ���ؼ� ���� ���ϱ�
    //type ��ġ, delete �ȵ� �޴� �� random���� ���� �� print
}

void worldCupPick(food *f[], int count){//����
    //SelectFoodType ���ؼ� ���� ���ϱ�
    //type ��ġ, delete �ȵ� �޴� �� ������ �ǽ�
    //���� �޴� print
}

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
    printf("=> which mode do you want to start?");

    scanf("%d", &menu);

    return menu;
}

int loadMyFood(food *mf[]){//����
    //��ġ�ϴ� ��ٱ��� ������ �ҷ�����
    //.txt������ ã�Ƽ� �ҷ����� "���� ��ٱ��� �ҷ���"
    //.txt������ �� ã���� "���� ��ٱ��� ����"
    //return ���� .txt���� �ȿ� �־��� ������ ���� (�������� 0 ����)
    return 0;
}

void saveMyFood(food *f[], int myCnt){//����
    //���ݱ��� �߰�, ����, ���� �� ���� .txt���Ͽ� �����ϱ�
    //loadMyFood������ .txt���ϸ��� ������ txt�����̿��� ��
}

int loadMemberData(member *m[]){//����
    //MemberData�� �ؽ�Ʈ ���Ͽ��� �ҷ�����
    //�� member �� ����
}


int Buy(food *mf[], int myCnt){//����
    //��ٱ��� �ȿ� �ִ� �޴� ���
    //��ٱ��� �ȿ� �ִ� �޴� ���� ���� ���
    //�����ϴ� �κ� ����
    //��ٱ��� �ȿ� �ִ� �޴� ��ü ����
    //saveMyFood �̿��� ��ٱ��� �� ���� �����
    //�����ߴ� �޴��� ���� ����
}


int searchMember(member *m[], int count, int buyCnt){//����
    //�˻��� ID�� �Է¹ް� 
    //ID�� �����ϸ� ���� ����Ʈ�� buyCnt �߰� 
    //���� ����Ʈ ���
    //ID�� �������� ������ 1 ����
}


int addMember(member *m, int buyCnt){//����
    //�޴� (�̸�, point) �߰�
    //�����ϴٸ� �ߺ��� ID�� �Է����� ���ϰ� 
    //1 ����
}

void saveMemberData(member *m[], int memberCnt){//����
    //���ݱ��� �ɹ� ���� .txt���Ͽ� �����ϱ�
    //loadMemberData������ .txt���ϸ��� ������ txt�����̿��� ��
}
