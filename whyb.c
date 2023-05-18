#include <stdio.h>
#include "whyb.h"

int loadData(food *f[]){
   const char* filename = "menu_data.txt";
    FILE* file = fopen(filename, "r");

    if (file != NULL) {
        // 파일이 성공적으로 열렸을 때 실행되는 코드
        // 데이터를 파일로부터 읽어와서 f 배열에 저장하는 작업을 수행하면 됩니다.

        // 예시: 파일에서 데이터를 읽어와서 배열에 저장하는 과정
        int dataCount = 0;
        char line[256];
        while (fgets(line, sizeof(line), file) != NULL) {
            sscanf(line, "9s %d %d %d %d %d", 
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

        printf("데이터 불러옴\n");

        // 파일 안에 있던 데이터 개수 반환
        return dataCount;
    } else {
        printf("데이터 없음\n");

        // 데이터가 없으므로 0을 반환
        return 0;
    }

    //일치하는 메뉴판 데이터 불러오기
    //.txt파일을 찾아서 불러오면 "데이터 불러옴"
    //.txt파일을 못 찾으면 "데이터 없음"
    //return 값은 .txt파일 안에 있었던 데이터 개수 (없었으면 0 리턴)
}


int selectMode(){//승희
    int menu;
    printf("mode 선택\n\n\n");
    printf("1 : 메뉴판 CRUD\n");
    printf("2 : 메뉴 고르기 도우미\n");
    printf("3 : 메뉴 주문하기\n");
    printf("4 : 전체 프로그램 종료\n");
    scanf("%d", &menu);
    return menu;
}

int selectFoodType(){//정환
    //Type 1 : ~
    //Type 2 : ~
    //return Type 번호
}


int selectMenuOne(){//정환
    //메뉴판 CRUD에서 메뉴 고르기
    //menu 1 : 메뉴 조회
    //menu 2 : 메뉴 추가
    //menu 3 : 메뉴 수정
    //menu 4 : 메뉴 삭제
    //menu 5 : 메뉴 찾기
    //menu 6 : 메뉴 저장
    //menu 0 : 종료
    //return 메뉴 번호
}

int addFood(food *f){//정환
    //메뉴 (이름, 가격, 타입) 추가
    //1 리턴
}
void readFood(food f){//정환
    //해당 메뉴의 이름, 가격 print
}


void listFood(food *f[], int count){//정환
    //selectFoodType으로 type 입력받기
    //삭제되지 않은 번호이고, type이 일치하면 해당 번호 print
    //readFood함수에서 menu 읽기
}

int selectFoodNo(food *f[], int count){//정환
    //listFood로 번호와 메뉴들 보여주기
    //메뉴 번호 리턴(취소 : 0)
}

void updateFood(food *f){//정환
    //메뉴 이름, 가격, 타입 업데이트하기
    //1 리턴하기
}

void deleteFood(food *f){//정환
    //del를 0으로 변경
}

void searchName(food *f[], int count){//정환
    //검색할 이름을 입력받고 
    //삭제되지 않고, 이름이 같으면 readFood함수에서 menu 읽기
}

void saveData(food *f[], int count){//정환
    //지금까지 추가, 수정, 삭제 한 내용 .txt파일에 저장하기
    //loadData에서의 .txt파일명과 동일한 txt파일이여야 함
}

int selectMenuTwo(){//현준
    //menu 1 : 랜덤으로 고르기
    //menu 2 : 월드컵으로 고르기
    //menu 0 : 종료
}

void randomPick(food *f[], int count){//현준
    //SelectFoodType 통해서 종류 정하기
    //type 일치, delete 안된 메뉴 중 random으로 나온 값 print
}

void worldCupPick(food *f[], int count){//현준
    //SelectFoodType 통해서 종류 정하기
    //type 일치, delete 안된 메뉴 중 월드컵 실시
    //최종 메뉴 print
}

int selectMenuThree(){//승희

    int menu;
    printf("1 : 메뉴 조회\n");
    printf("2 : 장바구니 조회\n");
    printf("3 : 장바구니 메뉴 추가\n");
    printf("4 : 장바구니 메뉴 수정\n");
    printf("5 : 장바구니 메누 삭제\n");
    printf("6 : 장바구니 메뉴 검색\n");
    printf("7 : 장바구니 메뉴 저장\n");
    printf("8 : 결제 및 적립\n");
    printf("0 : 종료\n\n");
    printf("=> 선택하실 메뉴를 입력하세요 : ");

    scanf("%d", &menu);

    return menu;
}

int loadMyFood(food *mf[]){//승희
    //일치하는 장바구니 데이터 불러오기
    //.txt파일을 찾아서 불러오면 "기존 장바구니 불러옴"
    //.txt파일을 못 찾으면 "기존 장바구니 없음"
    //return 값은 .txt파일 안에 있었던 데이터 개수 (없었으면 0 리턴)
}

void saveMyFood(food *f[], int myCnt){//승희
    //지금까지 추가, 수정, 삭제 한 내용 .txt파일에 저장하기
    //loadMyFood에서의 .txt파일명과 동일한 txt파일이여야 함
}

int loadMemberData(member *m[]){//승희
    //MemberData를 텍스트 파일에서 불러오기
    //총 member 수 리턴
}


int Buy(food *mf[], int myCnt){//승희
    //장바구니 안에 있는 메뉴 출력
    //장바구니 안에 있는 메뉴 가격 총합 출력
    //결제하는 부분 구현
    //장바구니 안에 있는 메뉴 전체 삭제
    //saveMyFood 이용해 장바구니 안 내용 지우기
    //결제했던 메뉴의 개수 리턴
}


int searchMember(member *m[], int count, int buyCnt){//승희
    //검색할 ID를 입력받고 
    //ID가 존재하면 기존 포인트에 buyCnt 추가 
    //현재 포인트 출력
    //ID가 존재하지 않으면 1 리턴
}


int addMember(member *m, int buyCnt){//승희
    //메뉴 (이름, point) 추가
    //가능하다면 중복된 ID은 입력하지 못하게 
    //1 리턴
}

void saveMemberData(member *m[], int memberCnt){//승희
    //지금까지 맴버 내용 .txt파일에 저장하기
    //loadMemberData에서의 .txt파일명과 동일한 txt파일이여야 함
}
