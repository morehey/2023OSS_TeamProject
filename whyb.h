#define SIZE 100
#define MSIZE 100

typedef struct {
    char name[40];  //메뉴 이름, 공백 포함
    int type;       //메뉴의 종류(ex. 식사류 - 1, 음료류 - 2, 사이드류 - 3 등등)
    int price;      //메뉴의 가격
    int cnt;        //메뉴의 수량
    int del;        //메뉴의 삭제 여부
    int get;        //메뉴가 장바구니에 담겼는지 여부
    int judge; //월드컵을 위한 판단 변수 (1 : 생존, 2 : )
}food;

typedef struct {
    char userID[40];
    int point;
}member;

int loadData(food *f[]);    //기존 메뉴판 불러오기
int selectMode();           //메뉴판 변경 모드, 주문 모드, 메뉴 고르기 모드를 선택할 수 있음
int selectMenuOne();        
int selectMenuTwo();
int selectMenuThree();
int selectFoodType();
int addFood(food *f);
void readFood(food f);
void updateFood(food *f);
void deleteFood(food *f);
void listFood(food *f[], int count);
int selectFoodNo(food *f[], int count);
void saveData(food *f[], int count);
void searchName(food *f[], int count);
void randomPick(food *f[], int count);
void worldCupPick(food *f[], int count);
int loadMyFood(food *mf[]);
void saveMyFood(food *mf[], int myCnt);
int loadMemberData(member *m[]);
int addMember(member *m, int buyCnt);
int countBuy(food *mf[], int myCnt);
int Buy(food *mf[], int myCnt);
void readMember(member m);
int searchMember(member *f[], int memberCnt, int buyCnt);
void saveMemberData(member *m[], int memberCnt);



