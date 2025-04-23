/*	Name : stageControl.h    ver 1.0
	Content : ���, ����ȭ�� ��Ʈ�� �Լ����� ����
	Implementation : YSW

	Last modified 2019/05/10
*/

#ifndef __BLOCK_STAGE_H_
#define __BLOCK_STAGE_H_

#define GBOARD_WIDTH	110
#define GBOARD_HEIGHT	45

#define COL GetStdHandle(STD_OUTPUT_HANDLE) // �ܼ�â�� �ڵ����� �ޱ�

#define GOLD SetConsoleTextAttribute(COL, 0x0006); // �ݻ�
#define GRAY SetConsoleTextAttribute(COL, 0x0008); // ȸ��
#define SKY_BLUE SetConsoleTextAttribute(COL, 0x000b); // �ϴû�
#define RED SetConsoleTextAttribute(COL, 0x000c); // ������
#define PLUM SetConsoleTextAttribute(COL, 0x000d); // ���ֻ�
#define YELLOW SetConsoleTextAttribute(COL, 0x000e); // �����
#define WHITE SetConsoleTextAttribute(COL, 0x000f); // ���

void AddBlockInfoToBoard(void);
void ChangeToNormalBlock(void);
void ChangeToRedBlock(void);
void ChooseBlock(void);
void DestroyTheBlock(void);
void DrawGameBoard(void);
int IsGameOver(void);
int IsRedBlockChosen(void);

#endif
