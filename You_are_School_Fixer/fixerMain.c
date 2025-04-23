/*	Name : fixerMain.c    ver 1.0
	Content : main �Լ��� ����

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
	int blockDelay = MAX_DELAY;	// RED��� ���� ��Ÿ��
	startMenu();				// �޴�ȭ���� ����
	AddBlockInfoToBoard();
	DrawGameBoard();
	ShowCurrentScore();			// ���� ���� ǥ��
	SetCurrentCursorPos(START_CURSOR_X, START_CURSOR_Y); //Ŀ���� ����� �ű��

	while (1) /*�ݺ������� RED��� ���� �� Ŀ�� �̵�*/
	{

		if (blockDelay == MAX_DELAY) { /* �� ����� ���� ��ġ ����*/
			DestroyTheBlock();  /* RED��� ���� */
			blockDelay = 0;
		}

		if (ProcessKeyInput()) {	/*SPACE�� �ԷµǸ� if�� ����*/
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
