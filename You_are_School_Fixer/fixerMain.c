/*	Name : fixerMain.c    ver 1.0
	Content : main 함수의 정의

	Last modified 2019/05/10
*/

#include <Windows.h>
#include "common.h"
#include "keyCurControl.h"
#include "stageControl.h"
#include "menuControl.h"
#include "scoreControl.h"

#define START_CURSOR_X		50
#define START_CURSOR_Y		20
#define MAX_DELAY  600

int main(void)
{
	int blockDelay = MAX_DELAY;	// RED블록 생성 쿨타임
	startMenu();				// 메뉴화면의 시작
	AddBlockInfoToBoard();
	DrawGameBoard();
	ShowCurrentScore();			// 현재 점수 표시
	SetCurrentCursorPos(START_CURSOR_X, START_CURSOR_Y); //커서를 가운데로 옮기기

	while (1) /*반복적으로 RED블록 생성 및 커서 이동*/
	{

		if (blockDelay == MAX_DELAY) { /* 새 블록의 등장 위치 설정*/
			DestroyTheBlock();  /* RED블록 생성 */
			blockDelay = 0;
		}

		if (ProcessKeyInput()) {	/*SPACE가 입력되면 if문 실행*/
			if (IsRedBlockChosen()) {
				ChangeToNormalBlock();
			}
		}

		if (IsGameOver()) {
			SetCurrentCursorPos(115, 20);
			puts("GAME OVER ^^");
			break;
		}
		if (ReachMaxScore()) {
			SetCurrentCursorPos(115, 20);
			puts("YOU WIN!!");
			break;
		}

		blockDelay++;
	}

	SetCurrentCursorPos(5, 5);
	system("pause");
	return 0;
}
