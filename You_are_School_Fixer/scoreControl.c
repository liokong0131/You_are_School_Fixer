/*	Name : scoreControl.c    ver 1.0
	Content : ���� ���ھ� ���� �Լ����� ����
	Implementation : YSW

	Last modified 2019/05/10
*/

#include "common.h"
#include "keyCurControl.h"

static int curGameScore = 0;

/*	��	��: void ShowCurrentScore(void)
	��	��: ���� ���� ���
	��	ȯ: void
*/

void ShowCurrentScore(void)
{
	SetCurrentCursorPos(115, 7);
	printf("�� ���� ���� : %d  ��", curGameScore);
}

/*	��	��: void AddGameScore(int score)
	��	��: ���� ���� �߰�
	��	ȯ: void
*/

void AddGameScore(int score)
{
	if (score < 1)
		return;
	curGameScore += score;
}

/*	��	��: int ReachMaxScore(void)
	��	��: ���� �ִ� ���� ���� ���� Ȯ��
	��	ȯ: int
*/

int ReachMaxScore(void)
{
	if (curGameScore > 20)
		return 1;
	else
		return 0;
}
