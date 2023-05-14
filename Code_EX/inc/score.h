typedef struct {
    char name[20];
    int kor;
    int eng;
    int math;
} score ;

int loadData (score *s[]);
int selectMenu();
int addScore(score *s);
void readScore(score s);
int updateScore(score *s);
void listScore(score *s[], int count);
int selectDataNo(score *s[], int count);
int deleteScore(score *s);
void saveData(score *s[], int count);
void searchName(score *s[], int count);
