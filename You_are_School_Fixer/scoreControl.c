/*	Name : scoreControl.c    ver 1.0
	Content : 게임 스코어 관리 함수들의 정의
	Implementation : YSW

	Last modified 2019/05/10
*/

#include "common.h"
#include "keyCurControl.h"

static int curGameScore = 0;

/*	함	수: void ShowCurrentScore(void)
	기	능: 점수 정보 출력
	반	환: void
*/

void ShowCurrentScore(void)
{
	SetCurrentCursorPos(115, 7);
	printf("§ 현재 점수 : %d  §", curGameScore);
}

/*	함	수: void AddGameScore(int score)
	기	능: 게임 점수 추가
	반	환: void
*/

void AddGameScore(int score)
{
	if (score < 1)
		return;
	curGameScore += score;
}

/*	함	수: int ReachMaxScore(void)
	기	능: 게임 최대 점수 도달 여부 확인
	반	환: int
*/

int ReachMaxScore(void)
{
	if (curGameScore > 20)
		return 1;
	else
		return 0;
}
