/*	Name : menuControl.c    ver 1.0
	Content : �޴� ȭ�� ��Ʈ�� �Լ����� ����
	Implementation : YSW

	Last modified 2019/05/10
*/

#include "common.h"
#include <Windows.h>
#include <mmsystem.h>
#include "stageControl.h"
#include "menuControl.h"

/*	��	��: void startMenu(void)
	��	��: �޴� ȭ���� ���� �� ��� ����
	��	ȯ: void
*/
void startMenu(void) {
	setGameOption();

	mainMenu();

	switch (menuKeyInput()) {
	case 1: system("cls"); 
			return;
	default: exit(0);
	}
}

/*	��	��: void drawMenuScreen(void)
	��	��: �޴� ȭ�� ���
	��	ȯ: void
*/
void mainMenu(void) {
	GOLD
	puts("����������������������������������������������������������������");
	puts("��      *����� �б�fixer*      ��");
	puts("��                              ��");
	puts("��        1. ���� ����          ��");
	puts("��                              ��");
	puts("��        0. ��     ��          ��");
	puts("��                              ��");
	puts("����������������������������������������������������������������");
	printf(" Select > ");
	WHITE
}

/*	��	��: void setGameOption(void)
	��	��: �ܼ� ����, ũ�� ����
	��	ȯ: void
*/
void setGameOption(void) {
	system("title You're_School_Fixer");
	system("mode con: cols=140 lines=47");
}

/*	��	��: int menuKeyInput(void)
	��	��: �޴�ȭ�鿡�� ���� �Է¹ޱ�
	��	ȯ: int
*/
int menuKeyInput(void) {
	int Number;
	scanf_s("%d", &Number);
	return Number;
}

