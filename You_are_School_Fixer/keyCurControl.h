/*	Name : keyCurControl.h    ver 1.0
	Content : 커서, 키보드 컨트롤 함수들의 선언
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