#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include "score.h"

int loadData (score *s[]){
    int count = 0, i;
    FILE *fp;
    if (access ("score.txt", F_OK ) != -1){
        fp = fopen("score.txt", "rt");
        for (i = 0 ; i < 100 ; i++){
            fscanf(fp, "%s", s[i]->name);
            if (feof(fp)) break;
            fscanf(fp, "%d", &s[i]->kor);
            fscanf(fp, "%d", &s[i]->eng);
            fscanf(fp, "%d", &s[i]->math);
        }
        fclose(fp);
        printf("=> 로딩 성공!\n");
        return i ; 
    }
    else{
        printf("=> 파일 없음\n");
        return 0;
    }
}
int selectMenu() {
    int menu;
    printf("\n*** 점수계산기 ***\n");
    printf("1. 조회\n");
    printf("2. 추가\n");
    printf("3. 수정\n");
    printf("4. 삭제\n");
    printf("5. 파일저장\n");
    printf("6. 이름 검색\n");
    printf("0. 종료\n\n");
    printf("=> 원하는 메뉴는? ");
    scanf("%d", &menu);
    return menu;
}

int addScore(score *s) {
    printf("이름은? ");
    scanf("%s", s->name);
    printf("국어는? ");
    scanf("%d", &s->kor);
    printf("영어는? ");
    scanf("%d", &s->eng);
    printf("수학은? ");
    scanf("%d", &s->math);
    printf("=> 추가됨!\n\n");
    return 1;
}
void readScore(score s) {
    int sum = s.kor + s.eng + s.math;
    double avg = sum / 3.0;
    printf("%8s %4d %4d %4d %5d %5.1f\n", s.name, s.kor, s.eng,
    s.math,sum, avg);
}

int updateScore(score *s) {
    printf("이름은? ");
    scanf("%s", s->name);
    printf("국어는? ");
    scanf("%d", &s->kor);
    printf("영어는? ");
    scanf("%d", &s->eng);
    printf("수학은? ");
    scanf("%d", &s->math);
    printf("=> 수정됨!\n");
    return 1;
}
void listScore(score *s[], int count) {
    printf("\nNo Name\tKor Eng Math Sum Avg\n");
    printf("================================\n");
    for (int i = 0; i < count; i++) {
        if (s[i]->kor == -1) continue;
        printf("%-2d ", i + 1);
        readScore(*s[i]);
    }
    printf("\n");
}
int selectDataNo(score *s[], int count) {
    int no;
    listScore(s, count);
    printf("번호는 (취소 :0)? ");
    scanf("%d", &no);
    return no;
}
int deleteScore(score *s) {
    s->kor = -1;
    s->eng = -1;
    s->math = -1;
    return 1;
}

void saveData(score *s[], int count){
    FILE *fp;
    fp = fopen("score.txt", "wt");

    for (int i = 0 ; i < count ; i++){
        if (s[i]->kor == -1) continue;
        fprintf(fp, "%s %d %d %d\n", s[i]->name, s[i]->kor, s[i]->eng, s[i]->math);
    }
    fclose(fp);
    printf("=>저장됨\n");
}

void searchName(score *s[], int count){
    int scnt = 0;
    char search[20];

    printf("검색할 이름은? ");
    scanf("%s", search);

    printf("\nNo Name Kor Eng Math Sum Avg\n");
    printf("===============================\n");
    for (int i = 0 ; i < count ; i ++){
        if (s[i]->kor == -1) continue;
        if (strstr(s[i]->name, search)){
            printf("%2d", i+1);
            readScore(*s[i]);
            scnt++;
        }
    }
    if (scnt == 0 ) printf("=> 검색된 데이터 없음!");
    printf("\n");
}
