/*	Name : stageControl.h    ver 1.0
	Content : 블록, 게임화면 컨트롤 함수들의 선언
	Implementation : YSW

	Last modified 2019/05/10
*/

#ifndef __BLOCK_STAGE_H_
#define __BLOCK_STAGE_H_

#define GBOARD_WIDTH	110
#define GBOARD_HEIGHT	45

#define COL GetStdHandle(STD_OUTPUT_HANDLE) // 콘솔창의 핸들정보 받기

#define GOLD SetConsoleTextAttribute(COL, 0x0006); // 금색
#define GRAY SetConsoleTextAttribute(COL, 0x0008); // 회색
#define SKY_BLUE SetConsoleTextAttribute(COL, 0x000b); // 하늘색
#define RED SetConsoleTextAttribute(COL, 0x000c); // 빨간색
#define PLUM SetConsoleTextAttribute(COL, 0x000d); // 자주색
#define YELLOW SetConsoleTextAttribute(COL, 0x000e); // 노란색
#define WHITE SetConsoleTextAttribute(COL, 0x000f); // 흰색

void AddBlockInfoToBoard(void);
void ChangeToNormalBlock(void);
void ChangeToRedBlock(void);
void ChooseBlock(void);
void DestroyTheBlock(void);
void DrawGameBoard(void);
int IsGameOver(void);
int IsRedBlockChosen(void);

#endif
