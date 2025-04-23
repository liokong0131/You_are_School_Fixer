/*	Name : menuControl.c    ver 1.0
	Content : 메뉴 화면 컨트롤 함수들의 정의
	Implementation : YSW

	Last modified 2019/05/10
*/

#include "common.h"
#include <Windows.h>
#include <mmsystem.h>
#include "stageControl.h"
#include "menuControl.h"

/*	함	수: void startMenu(void)
	기	능: 메뉴 화면의 시작 및 기능 실행
	반	환: void
*/
void startMenu(void) {
	setGameOption();

	mainMenu();

	switch (menuKeyInput()) {
	case 1: system("cls"); 
			return;
	default: exit(0);
	}
}

/*	함	수: void drawMenuScreen(void)
	기	능: 메뉴 화면 출력
	반	환: void
*/
void mainMenu(void) {
	GOLD
	puts("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓");
	puts("┃      *당신은 학교fixer*      ┃");
	puts("┃                              ┃");
	puts("┃        1. 게임 시작          ┃");
	puts("┃                              ┃");
	puts("┃        0. 종     료          ┃");
	puts("┃                              ┃");
	puts("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛");
	printf(" Select > ");
	WHITE
}

/*	함	수: void setGameOption(void)
	기	능: 콘솔 제목, 크기 설정
	반	환: void
*/
void setGameOption(void) {
	system("title You're_School_Fixer");
	system("mode con: cols=140 lines=47");
}

/*	함	수: int menuKeyInput(void)
	기	능: 메뉴화면에서 목차 입력받기
	반	환: int
*/
int menuKeyInput(void) {
	int Number;
	scanf_s("%d", &Number);
	return Number;
}

