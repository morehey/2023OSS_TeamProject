#include <stdio.h>
#include "whyb.h"

/*
일단, 구현에 앞서 드리고 싶은 말은! 
이전 교수님께서 CRUD 구현하셨을 때 한 내용을 바탕으로 함수와 코드를 만들었고요
제가 사실 어느정도까지 틀을 잡아야할지 모르겠어서 
일단 최대한 자세하게 적어놓긴 했습니다.
최대한 충돌을 피하게 하기 위해서 그랬는데,
어떤 분에게는 너무 자율성을 침해한다고 느낄수도 있을 것 같아 조심스럽네요..
한번 코드 읽어보시고, 충돌이 일어나지 않는다 싶으면 얼마든지 마음대로 바꾸셔도 됩니다!
의견, 질문하셔도 완전 좋습니다:)
*/

int loadData(food *f[]){
    //일치하는 메뉴판 데이터 불러오기
    //.txt파일을 찾아서 불러오면 "데이터 불러옴"
    //.txt파일을 못 찾으면 "데이터 없음"
    //return 값은 .txt파일 안에 있었던 데이터 개수 (없었으면 0 리턴)
}


int selectMode(){
    //mode 1 : 메뉴판 수정 (메뉴판 CRUD)
    //mode 2 : 메뉴 고르기 도우미
    //mode 3 : 메뉴 주문하기
    //mode 4 : 키오스크 종료
    //return mode 번호
}

int selectFoodType(){
    //Type 1 : ~
    //Type 2 : ~
    //return Type 번호
}


int selectMenuOne(){//메뉴판 CRUD에서 메뉴 고르기
    //menu 1 : 메뉴 조회
    //menu 2 : 메뉴 추가
    //menu 3 : 메뉴 수정
    //menu 4 : 메뉴 삭제
    //menu 5 : 메뉴 찾기
    //menu 6 : 메뉴 저장
    //menu 0 : 종료
    //return 메뉴 번호
}

int addFood(food *f){
    //메뉴 (이름, 가격, 타입) 추가
    //1 리턴
}
void readFood(food f){
    //해당 메뉴의 이름, 가격 print
}


void listFood(food *f[], int count){
    //selectFoodType으로 type 입력받기
    //삭제되지 않은 번호이고, type이 일치하면 해당 번호 print
    //readFood함수에서 menu 읽기
}

int selectFoodNo(food *f[], int count){
    //listFood로 번호와 메뉴들 보여주기
    //메뉴 번호 리턴(취소 : 0)
}

void updateFood(food *f){
    //메뉴 이름, 가격, 타입 업데이트하기
    //1 리턴하기
}

void deleteFood(food *f){
    //del를 0으로 변경
}

void searchName(food *f[], int count){
    //검색할 이름을 입력받고 
    //삭제되지 않고, 이름이 같으면 readFood함수에서 menu 읽기
}

void saveData(food *f[], int count){
    //지금까지 추가, 수정, 삭제 한 내용 .txt파일에 저장하기
    //loadData에서의 .txt파일명과 동일한 txt파일이여야 함
}

int selectMenuTwo(){
    //menu 1 : 랜덤으로 고르기
    //menu 2 : 월드컵으로 고르기
    //menu 0 : 종료
}

void randomPick(food *f[], int count){
    //SelectFoodType 통해서 종류 정하기
    //type 일치, delete 안된 메뉴 중 random으로 나온 값 print
}

void worldCupPick(food *f[], int count){
    //SelectFoodType 통해서 종류 정하기
    //type 일치, delete 안된 메뉴 중 월드컵 실시
    //최종 메뉴 print
}

int selectMenuThree(){
    //menu 1 : 메뉴 조회
    //menu 2 : 장바구니 조회
    //menu 3 : 장바구니 메뉴 추가
    //menu 4 : 장바구니 메뉴 수정
    //menu 5 : 장바구니 메뉴 삭제
    //menu 6 : 장바구니 메뉴 검색
    //menu 7 : 장바구니 메뉴 저장
    //menu 8 : 걀제 및 적립
    //menu 0 : 종료
}

int loadMyFood(food *mf[]){
    //일치하는 장바구니 데이터 불러오기
    //.txt파일을 찾아서 불러오면 "기존 장바구니 불러옴"
    //.txt파일을 못 찾으면 "기존 장바구니 없음"
    //return 값은 .txt파일 안에 있었던 데이터 개수 (없었으면 0 리턴)
}

void saveMyFood(food *f[], int myCnt){
    //지금까지 추가, 수정, 삭제 한 내용 .txt파일에 저장하기
    //loadMyFood에서의 .txt파일명과 동일한 txt파일이여야 함
}

int loadMemberData(member *m[]){
    //MemberData를 텍스트 파일에서 불러오기
    //총 member 수 리턴
}


int Buy(food *mf[], int myCnt){
    //장바구니 안에 있는 메뉴 출력
    //장바구니 안에 있는 메뉴 가격 총합 출력
    //결제하는 부분 구현
    //장바구니 안에 있는 메뉴 전체 삭제
    //saveMyFood 이용해 장바구니 안 내용 지우기
    //결제했던 메뉴의 개수 리턴
}


int searchMember(member *m[], int count, int buyCnt){
    //검색할 ID를 입력받고 
    //ID가 존재하면 기존 포인트에 buyCnt 추가 
    //현재 포인트 출력
    //ID가 존재하지 않으면 1 리턴
}


int addMember(member *m, int buyCnt){
    //메뉴 (이름, point) 추가
    //가능하다면 중복된 ID은 입력하지 못하게 
    //1 리턴
}

void saveMemberData(member *m[], int memberCnt){
    //지금까지 맴버 내용 .txt파일에 저장하기
    //loadMemberData에서의 .txt파일명과 동일한 txt파일이여야 함
}
