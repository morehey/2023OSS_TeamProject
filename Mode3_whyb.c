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
