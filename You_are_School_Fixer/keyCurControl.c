/*	Name : keyCurControl.c    ver 1.0
	Content : 커서, 키보드 컨트롤 함수들의 정의

	Last modified 2019/05/10
*/

#include "common.h"
#include <Windows.h>
#include "point.h"
#include "stageControl.h"
#include <conio.h>

#define KEY_SENSITIVE		100

#define LEFT 75
#define RIGHT 77
#define UP 72
#define DOWN 80
#define SPACE 32

/*	함	수: point GetCurrentCursorPos(void)
	기	능: 현재 커서 위치 정보를 담은 구조체 변수 반환
	반	환: point
*/

point GetCurrentCursorPos(void)
{
	point curPoint;
	CONSOLE_SCREEN_BUFFER_INFO curInfo;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curPoint.x = curInfo.dwCursorPosition.X;
	curPoint.y = curInfo.dwCursorPosition.Y;
	return curPoint;
}

/*	함	수: void SetCurrentCuresorPos(int x, int y)
	기	능: 커서 위치를 설정
	반	환: void
*/

void SetCurrentCursorPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/*	함	수: void CursortLeft(void)
	기	능: 커서를 왼쪽으로 한 칸 이동
	반	환: void
*/

void CursorLeft(void)
{
	point Pos = GetCurrentCursorPos();
	if (Pos.x > 2)
		SetCurrentCursorPos(Pos.x - 2, Pos.y);
}

/*	함	수: void CursorRight(void)
	기	능: 커서를 오른쪽으로 한 칸 이동
	반	환: void
*/

void CursorRight(void)
{
	point Pos = GetCurrentCursorPos();
	if (Pos.x < GBOARD_WIDTH)
		SetCurrentCursorPos(Pos.x + 2, Pos.y);
}

/*	함	수: void CursorUp(void)
	기	능: 커서를 위쪽으로 한 칸 이동
	반	환: void
*/

void CursorUp(void)
{
	point Pos = GetCurrentCursorPos();
	if (Pos.y > 0)
		SetCurrentCursorPos(Pos.x, Pos.y - 1);
}

/*	함	수: void CursorDown(void)
	기	능: 커서를 아래쪽으로 한 칸 이동
	반	환: void
*/

void CursorDown(void)
{
	point Pos = GetCurrentCursorPos();
	if (Pos.y < GBOARD_HEIGHT)
		SetCurrentCursorPos(Pos.x, Pos.y + 1);
}

/*	함	수: int ProcessKeyInput(void)
	기	능: 키 입력을 처리
	반	환: SPACE 선택 시 1
*/

int ProcessKeyInput(void)
{
	int i;
	int key;
	for (i = 0; i < KEY_SENSITIVE; i++)
	{
		if (_kbhit() != 0)
		{
			key = _getch();
			switch (key)
			{
			case LEFT:
				CursorLeft();
				break;
			case RIGHT:
				CursorRight();
				break;
			case UP:
				CursorUp();
				break;
			case DOWN:
				CursorDown();
				break;
			case SPACE:
				return 1;
			}
		}
	}
	return 0;
}