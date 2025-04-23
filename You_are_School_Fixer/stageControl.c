/*	Name : blockControl.c    ver 1.0
	Content : 블록, 게임화면 컨트롤 함수들의 정의
	Implementation : YSW

	Last modified 2019/05/10
*/

#include <Windows.h>
#include <time.h>
#include "common.h"
#include "point.h"
#include "blockInfo.h"
#include "keyCurControl.h"
#include "stageControl.h"
#include "scoreControl.h"


#define GBOARD_ORIGIN_X	0
#define GBOARD_ORIGIN_Y	0

static int gameBoardInfo[GBOARD_HEIGHT][GBOARD_WIDTH/2] = { 0, };

static int currentBlockHeight;
static int currentBlockWidth;

static int redBlock;

/*	함	수: void AddCurrentBlockInfoToBoard(void)
	기	능: 배열에 학교, UFO 블록의 정보를 추가한다.
	반	환: void
*/
void AddBlockInfoToBoard(void)
{
	int x, y;
	for (y = 0; y < HEIGHT_OF_UFO_MODEL; y++) {
		for(x = 2; x < GBOARD_WIDTH/2; x++)
			gameBoardInfo[y][x] = ufoModel[y][x - 2];
	}
	for (y = 7; y < GBOARD_HEIGHT; y++) {
		for (x = 5; x < GBOARD_WIDTH/2 -5; x++) {
			gameBoardInfo[y][x] = schoolModel[y-7][x-5];
		}
	}
}

void DrawGameBoard(void)
{
	int x, y;

	for (y = 0; y < GBOARD_HEIGHT; y++)
	{
		for (x = 0; x < GBOARD_WIDTH/2; x++)
		{
			SetCurrentCursorPos(x * 2, y);

			switch (gameBoardInfo[y][x]) {
			case 0: printf("  "); break;
			case 1: WHITE printf("■"); break;
			case 2:	YELLOW printf("■"); break;
			case 3:	GRAY printf("■"); break;
			case 4: SKY_BLUE printf("■"); break;
			default: PLUM printf("■"); break;
			}
		}
	}
	GOLD
	for (y = 0; y <= GBOARD_HEIGHT + 1; y++)
	{
		SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);
		if (y == GBOARD_HEIGHT + 1)
			printf("┗");
		else
			printf("┃");
	}
	for (x = 1; x <= GBOARD_WIDTH; x++)
	{
		SetCurrentCursorPos(GBOARD_ORIGIN_X + x, GBOARD_HEIGHT + 1);
		if (x == GBOARD_WIDTH)
			printf("┛");
		else
			printf("━");
	}
	for (y = 0; y <= GBOARD_HEIGHT + 1; y++)
	{
		SetCurrentCursorPos(GBOARD_WIDTH, GBOARD_ORIGIN_Y + y);

		if (y == GBOARD_HEIGHT + 1)
			printf("┛");
		else
			printf("┃");
	}
	WHITE
	SetCurrentCursorPos(0, 0);
}



/*	함	수: void ChooseBlock(void)
	기	능: RED블록으로 바꿀 블록을 무작위 선택
	반	환: void
*/
void ChooseBlock(void)
{
	srand((unsigned int)time(NULL));
	currentBlockHeight = (rand() % HEIGHT_OF_SCHOOL_MODEL)+7;
	currentBlockWidth = (rand() % WIDTH_OF_SCHOOL_MODEL)+5;
}

void ChangeToRedBlock(void)
{
	point Pos = GetCurrentCursorPos();
	/*시각적 처리*/
	SetCurrentCursorPos(currentBlockWidth * 2, currentBlockHeight);
	RED printf("■"); WHITE

	/*데이터 처리*/
	gameBoardInfo[currentBlockHeight][currentBlockWidth] = 5;

	SetCurrentCursorPos(Pos.x, Pos.y);

	redBlock++;
}

void DestroyTheBlock(void) {
	ChooseBlock();
	ChangeToRedBlock();
}

int IsRedBlockChosen(void)
{
	point Pos = GetCurrentCursorPos();
	if (gameBoardInfo[Pos.y][Pos.x / 2] == 5)
		return 1;
	else
		return 0;
}

void ChangeToNormalBlock(void)
{
	point Pos = GetCurrentCursorPos();

	switch (schoolModel[Pos.y-7][Pos.x/2-5]) {
	case 1: WHITE printf("■"); break;
	case 2: YELLOW printf("■"); break;
	case 4: SKY_BLUE printf("■"); break;
	case 6: PLUM printf("■"); break;
	}

	WHITE
	redBlock--;
	AddGameScore(1);
	ShowCurrentScore();
	gameBoardInfo[Pos.y][Pos.x/2] = schoolModel[Pos.y-7][Pos.x/2 - 5];

	SetCurrentCursorPos(Pos.x, Pos.y);

	Beep(490, 100);
}

/*	함	수: int IsGameOver(void)
	기	능: 게임이 종료되었는지 확인하는 함수
	반	환: 게임 종료 시 1 반환
*/

int IsGameOver(void)
{
	if (redBlock > 30)
		return 1;
	else
		return 0;
}
