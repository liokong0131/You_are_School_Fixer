/*	Name : keyCurControl.c    ver 1.0
	Content : Ŀ��, Ű���� ��Ʈ�� �Լ����� ����

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

/*	��	��: point GetCurrentCursorPos(void)
	��	��: ���� Ŀ�� ��ġ ������ ���� ����ü ���� ��ȯ
	��	ȯ: point
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

/*	��	��: void SetCurrentCuresorPos(int x, int y)
	��	��: Ŀ�� ��ġ�� ����
	��	ȯ: void
*/

void SetCurrentCursorPos(int x, int y)
{
	COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

/*	��	��: void CursortLeft(void)
	��	��: Ŀ���� �������� �� ĭ �̵�
	��	ȯ: void
*/

void CursorLeft(void)
{
	point Pos = GetCurrentCursorPos();
	if (Pos.x > 2)
		SetCurrentCursorPos(Pos.x - 2, Pos.y);
}

/*	��	��: void CursorRight(void)
	��	��: Ŀ���� ���������� �� ĭ �̵�
	��	ȯ: void
*/

void CursorRight(void)
{
	point Pos = GetCurrentCursorPos();
	if (Pos.x < GBOARD_WIDTH)
		SetCurrentCursorPos(Pos.x + 2, Pos.y);
}

/*	��	��: void CursorUp(void)
	��	��: Ŀ���� �������� �� ĭ �̵�
	��	ȯ: void
*/

void CursorUp(void)
{
	point Pos = GetCurrentCursorPos();
	if (Pos.y > 0)
		SetCurrentCursorPos(Pos.x, Pos.y - 1);
}

/*	��	��: void CursorDown(void)
	��	��: Ŀ���� �Ʒ������� �� ĭ �̵�
	��	ȯ: void
*/

void CursorDown(void)
{
	point Pos = GetCurrentCursorPos();
	if (Pos.y < GBOARD_HEIGHT)
		SetCurrentCursorPos(Pos.x, Pos.y + 1);
}

/*	��	��: int ProcessKeyInput(void)
	��	��: Ű �Է��� ó��
	��	ȯ: SPACE ���� �� 1
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