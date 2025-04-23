/*	Name : scoreControl.h    ver 1.0
	Content : 게임 스코어 관리 및 레벨 관리 함수들의 선언
	Implementation : YSW

	Last modified 2019/05/10
*/

#ifndef __SCORE_H_
#define __SCORE_H_

void ShowCurrentScore(void);
void AddGameScore(int score);
int ReachMaxScore(void);

#endif