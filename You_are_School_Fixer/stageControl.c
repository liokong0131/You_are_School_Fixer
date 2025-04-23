/*	Name : blockControl.c    ver 1.0
	Content : ���, ����ȭ�� ��Ʈ�� �Լ����� ����
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

/*	��	��: void AddCurrentBlockInfoToBoard(void)
	��	��: �迭�� �б�, UFO ����� ������ �߰��Ѵ�.
	��	ȯ: void
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
			case 1: WHITE printf("��"); break;
			case 2:	YELLOW printf("��"); break;
			case 3:	GRAY printf("��"); break;
			case 4: SKY_BLUE printf("��"); break;
			default: PLUM printf("��"); break;
			}
		}
	}
	GOLD
	for (y = 0; y <= GBOARD_HEIGHT + 1; y++)
	{
		SetCurrentCursorPos(GBOARD_ORIGIN_X, GBOARD_ORIGIN_Y + y);
		if (y == GBOARD_HEIGHT + 1)
			printf("��");
		else
			printf("��");
	}
	for (x = 1; x <= GBOARD_WIDTH; x++)
	{
		SetCurrentCursorPos(GBOARD_ORIGIN_X + x, GBOARD_HEIGHT + 1);
		if (x == GBOARD_WIDTH)
			printf("��");
		else
			printf("��");
	}
	for (y = 0; y <= GBOARD_HEIGHT + 1; y++)
	{
		SetCurrentCursorPos(GBOARD_WIDTH, GBOARD_ORIGIN_Y + y);

		if (y == GBOARD_HEIGHT + 1)
			printf("��");
		else
			printf("��");
	}
	WHITE
	SetCurrentCursorPos(0, 0);
}



/*	��	��: void ChooseBlock(void)
	��	��: RED������� �ٲ� ����� ������ ����
	��	ȯ: void
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
	/*�ð��� ó��*/
	SetCurrentCursorPos(currentBlockWidth * 2, currentBlockHeight);
	RED printf("��"); WHITE

	/*������ ó��*/
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
	case 1: WHITE printf("��"); break;
	case 2: YELLOW printf("��"); break;
	case 4: SKY_BLUE printf("��"); break;
	case 6: PLUM printf("��"); break;
	}

	WHITE
	redBlock--;
	AddGameScore(1);
	ShowCurrentScore();
	gameBoardInfo[Pos.y][Pos.x/2] = schoolModel[Pos.y-7][Pos.x/2 - 5];

	SetCurrentCursorPos(Pos.x, Pos.y);

	Beep(490, 100);
}

/*	��	��: int IsGameOver(void)
	��	��: ������ ����Ǿ����� Ȯ���ϴ� �Լ�
	��	ȯ: ���� ���� �� 1 ��ȯ
*/

int IsGameOver(void)
{
	if (redBlock > 30)
		return 1;
	else
		return 0;
}
