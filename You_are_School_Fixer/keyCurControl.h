/*	Name : keyCurControl.h    ver 1.0
	Content : Ŀ��, Ű���� ��Ʈ�� �Լ����� ����
	Implementation : YSW

	Last modified 2019/05/10
*/

#ifndef __KEY_CURSOR_H_
#define __KEY_CURSOR_H_

#include "point.h"

point GetCurrentCursorPos(void);
void SetCurrentCursorPos(int x, int y);
void CursorLeft(void);
void CursorRight(void);
void CursorUp(void);
void CursorDown(void);
int ProcessKeyInput(void);

#endif