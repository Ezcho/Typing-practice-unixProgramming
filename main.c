#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

char name[] = "default";
int score = 0;

void Menu();

void longWriting();
void shortWriting();
void TypingPractice();

void TypingGame();


void readScore();
void appendScore(char name[], int score);


int main() {
    Menu();
    return 0;
}

void Menu(){
    int c;
    FILE *fp;
    int menu;
    if((fp = fopen("Resource/Menu.txt", "r"))==NULL)
        printf("FILE OPEN FAIL!");
    while((c = fgetc(fp)) != EOF){
        putchar(c);
    }
    fclose(fp);

    printf("Enter your Menu: ");
    scanf("%d", menu);

    switch(menu){
        case 1 :
            TypingPractice();
            appendScore(name, score);
            break;
        case 2 :
            TypingGame();
            break;
        case 3 :
            readScore();
            break;
        case 4 :
            printf("Undeveloped Content");
            break;
        case 5 :
            printf("게임을 종료 합니다.");
            break;
        default :
            printf("올바른 값을 입력 하세요");
            Menu();
    }

}
void readScore(){
    char name[100];
    FILE *fp;
    char buf[255];
    char *str;

    if((fp = fopen("dat/rank.dat", "r"))==NULL)
        printf("FILE OPEN FAIL...");
    while(!feof(fp)){
        *str = fgets(str, sizeof(str), fp);
        if(str == name){
            printf(str);
            fgets(str, sizeof(str), fp);
            printf(str);
            fgets(str, sizeof(str), fp);
            printf(str);
            fgets(str, sizeof(str), fp);
            printf(str);
            fgets(str, sizeof(str), fp);
            printf(str);
            break;
        }
    }
}
void appendScore(char name[], int score){
    int fd;
    while((fd=open("dat/rank.dat", O_WRONLY | O_CREAT  | O_EXCL, 0644))< 0){
        if (errno != EEXIST){
            perror("open");
        }
    }
    lseek(fd, 0, SEEK_END);
    write(fd, "\n\n", 2);
    write(fd, name, sizeof(name));
    write(fd, "\n", 2);
    write(fd, score, sizeof(score));
    close (fd);
}

void longWriting(){
    printf("longWriting실행");
}
void shortWriting() {
    printf("shortWriting실행");
}

void TypingPractice(){
    longWriting();
    shortWriting();
    printf("TypingPractice 실행");
}

void TypingGame(){
    printf("TypingGame 실행");
}



