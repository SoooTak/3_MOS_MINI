/*
	미니 프로젝트 [대학생 성적관리 프로그램]
	개발자 : 김민상
	개발 기간 : 2023.12 ~ 2024.2

    1. 메인화면
    2. 로그인
    3. 회원가입
    4. (학생) 성적열람
    5. (학생) 세부정보 관리
    6. (교수) 학생관리
    7. (교수) 성적부여
*/
#define _CRT_SECURE_NO_WARNINGS
#define MAX_MEMBER 100
#define MAX_ID 50
#define MAX_PW 50

#include <stdio.h>
#include <time.h>       // 현재 날짜 확인
#include <windows.h>    // 콘솔창 크기 설정, 화면 클리어
#include <conio.h>      // _getch() 함수 사용 (엔터키 입력 없이 문자 입력)
#include <stdlib.h>
#include <string.h>

// 텍스트 색상 종류 열거체
typedef enum ColorType {
    None = -1,
    BLACK,  	// 0
    darkBLUE,	// 1
    DarkGreen,	// 2
    darkSkyBlue,// 3
    DarkRed,  	// 4
    DarkPurple,	// 5
    DarkYellow,	// 6
    GRAY,		// 7
    DarkGray,	// 8
    BLUE,		// 9
    GREEN,		// 10
    SkyBlue,	// 11
    RED,		// 12
    PURPLE,		// 13
    YELLOW,		// 14
    WHITE		// 15
} COLOR;

// tui 그리는 함수들
void printMain(void);       // 1. 메인화면 tui 그리는 함수
void printLogin(void);      // 2. 로그인 tui 그리는 함수
void printSignup(void);     // 3. 회원가입 tui 그리는 함수
void printScore(void);      // 4. 성적열람 tui 그리는 함수
void printStudent(void);    // 6. 학생관리 tui 그리는 함수

// 기능 함수들
int Login(void);    // 2. 로그인
int Signup(void);   // 3. 회원가입

// 디자인 관련 함수들
void textcolor(int colorNum);           // 텍스트 색상 변경 함수
void gotoxy(int x, int y);              // 커서 이동 함수
void cursor(int n);                     // 커서 감추는 함수 

// 1. 메인화면
int main(void)
{
    system("mode con:cols=100 lines=30");
    char choice;
    while(1)
    {
        printStudent();
        choice = _getch();
        printMain();
        choice = _getch();
        if (choice == 'A' || choice == 'a')
            Login();
        else if (choice == 'B' || choice == 'b')
        {
            printSignup();
            Signup();
        }
        else if (choice == 'X' || choice == 'x')
            return 0;
    }
}

// 2. 로그인 (미완)
int Login(void)
{
    char inputID[MAX_ID];
    char inputPW[MAX_PW];
    while (1)
    {
        printLogin();

        gotoxy(45, 11);
        scanf("%s", inputID);

        if (strcmp("!!", inputID) == 0)
            return 0;

        gotoxy(45, 15);
        scanf("%s", inputPW);

        if (strcmp("!!", inputPW) == 0)
            return 0;

        /*
            1. 입력한 ID와 PW를 회원정보파일과 비교
            1-1. 일치하면 교수자 여부에 따라 4. 성적열람 또는 6. 학생관리 로 이동
            1-2. 불일치하면 로그인 처음으로 이동
        */
    }
    return 0;
}

// 3. 회원가입 (미완)
int Signup(void)
{
    cursor(1);
    int y = 9;
    gotoxy(42, y);

    /*
        1. ID 입력
        1-1. ID 중복검사
        2. PW 입력
        3. 이름 입력
        4. 소속 입력
        5. 재학중인 학기 입력
        6. 졸업학점 입력
        7. 교수자 여부 입력
        8. 회원정보파일에 고유ID|이름|ID|PW|소속|학기|졸업학점|교수자여부 형식으로 저장
    */

    char c[MAX_ID];
    scanf("%s", c);
    if (strcmp("!!", c) == 0)
        return 0;
}

// (TUI) 1. 메인화면 tui 그리는 함수
void printMain(void) {
    system("cls");
    int i, x = 25, y = 4;
    gotoxy(x, y);
    printf("┌────────────────────────────────────────────────┐");
    for (i = 1; i <= 9; i++)
    {
        gotoxy(x, ++y);
        printf("│%48s│", " ");
    }
    gotoxy(x, ++y);
    printf("└────────────────────────────────────────────────┘");

    x = 36;
    y = 15;
    gotoxy(x, y);
    printf("┌──────────────────────────┐");
    gotoxy(x, ++y);
    printf("│%26s│", " ");
    gotoxy(x, ++y);
    printf("└──────────────────────────┘");

    y++;
    gotoxy(x, y);
    printf("┌──────────────────────────┐");
    gotoxy(x, ++y);
    printf("│%26s│", " ");
    gotoxy(x, ++y);
    printf("└──────────────────────────┘");

    y++;
    gotoxy(x, y);
    printf("┌──────────────────────────┐");
    gotoxy(x, ++y);
    printf("│%26s│", " ");
    gotoxy(x, ++y);
    printf("└──────────────────────────┘");

    gotoxy(38, 9);
    printf("대학생 성적관리 프로그램");

    y = 16;
    gotoxy(47, y);
    printf("로그인     :  A");
    y += 3;
    gotoxy(46, y);
    printf("회원가입    :  B");
    y += 3;
    gotoxy(48, y);
    printf("종료      :  X\n");
    cursor(0);
}

// (TUI) 2. 로그인 tui 그리는 함수 
void printLogin(void)
{
    system("cls");
    cursor(1);
    int x = 40, y = 4;
    gotoxy(x, y);
    printf("┌─────────────┐");
    gotoxy(x, ++y);
    printf("│%13s│", " ");
    gotoxy(x, ++y);
    printf("└─────────────┘");

    gotoxy(45, 5);
    printf("로그인");

    x = 31;
    y = 10;
    gotoxy(x, y);
    printf("┌───────────────────────────────┐");
    gotoxy(x, ++y);
    printf("│%31s│", " ");
    gotoxy(x, ++y);
    printf("└───────────────────────────────┘");

    y = 14;
    gotoxy(x, y);
    printf("┌───────────────────────────────┐");
    gotoxy(x, ++y);
    printf("│%31s│", " ");
    gotoxy(x, ++y);
    printf("└───────────────────────────────┘");

    gotoxy(34, 11);
    printf("아이디  : ");
    gotoxy(33, 15);
    printf("비밀번호 : ");
    gotoxy(23, 20);
    printf("메인화면으로 돌아가기 : ID 또는 PW에 !! 입력 후 엔터");
}

// (TUI) 3. 회원가입 tui 그리는 함수
void printSignup(void)
{
    system("cls");
    cursor(1);
    int x = 41, y = 3;
    gotoxy(x, y);
    printf("┌───────────────┐");
    gotoxy(x, ++y);
    printf("│%15s│", " ");
    gotoxy(x, ++y);
    printf("└───────────────┘");

    gotoxy(46, 4);
    printf("회원가입");

    x = 21;
    y = 7;
    gotoxy(x, y);
    printf("┌────────────────────────────────────────────────────────┐");
    for (int i = 1; i <= 16; i++)
    {
        gotoxy(x, ++y);
        printf("│%56s│", " ");
    }
    gotoxy(x, ++y);
    printf("└────────────────────────────────────────────────────────┘");

    y = 9;
    gotoxy(30, y);
    printf("ID       : ");
    gotoxy(30, y += 2);
    printf("PW       : ");
    gotoxy(29, y += 2);
    printf("이름      : ");
    gotoxy(29, y += 2);
    printf("소속      : ");
    gotoxy(25, y += 2);
    printf("재학중인 학기 : ");
    gotoxy(27, y += 2);
    printf("졸업학점    : ");
    gotoxy(26, y += 2);
    printf("교수자 여부  : ");
    gotoxy(23, y += 2);
    printf("(교수자 : 1, 학생 : 2)");

    gotoxy(25, 26);
    printf("메인화면으로 돌아가기 : 아무 칸이나 !! 입력 후 엔터");
}

// (TUI) 4. 성적열람 tui 그리는 함수
void printScore(void)
{
    cursor(0);
    int x = 14, y = 2;
    gotoxy(x, y);
    printf("┌──────────────────────────────────────────────────────────────────────┐");
    for (int i = 1; i <= 20; i++)
    {
        gotoxy(x, ++y);
        printf("│%70s│", " ");
    }
    gotoxy(x, ++y);
    printf("└──────────────────────────────────────────────────────────────────────┘");
}

// (TUI) 6. 학생관리 tui 그리는 함수
void printStudent(void)
{
    cursor(0);
    int x = 14, y = 2;
    gotoxy(x, y);
    printf("┌──────────────────────────────────────────────────────────────────────┐");
    for (int i = 1; i <= 20; i++)
    {
        gotoxy(x, ++y);
        printf("│%70s│", " ");
    }
    gotoxy(x, ++y);
    printf("└──────────────────────────────────────────────────────────────────────┘");

    gotoxy(20, 1);
    printf("교수명 : ");

    gotoxy(24, 5);
    printf("이름         학년                   이름         학년");

    gotoxy(19, 7);
    printf("1.                                  6.");
    gotoxy(19, 9);
    printf("2.                                  7.");
    gotoxy(19, 11);
    printf("3.                                  8.");
    gotoxy(19, 13);
    printf("4.                                  9.");
    gotoxy(19, 15);
    printf("5.                                 10.");

    gotoxy(19, 21);
    printf("< 이전 페이지 : A                             다음 페이지 : D >");
}

// (보조) 좌표 이동 함수
void gotoxy(int x, int y) {
    COORD pos = { x,y };
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

// (보조) 텍스트 색 변경 함수
void textcolor(int colorNum) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), colorNum);
}

// (보조) 콘솔창 커서 안 보이게 하는 함수 0 -> 숨김,  1 -> 보임
void cursor(int n)
{
    HANDLE hConsole;
    CONSOLE_CURSOR_INFO ConsoleCursor;

    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    ConsoleCursor.bVisible = n;
    ConsoleCursor.dwSize = 1;

    SetConsoleCursorInfo(hConsole, &ConsoleCursor);
}