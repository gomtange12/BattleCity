#include "stdafx.h"
#include "UIManager.h"
#include "BitMap.h"
#include "ResManager.h"

void UIManager::init()
{
	life = 3;
	for (int i = 0; i < life; ++i)
		playerIcon.push_back(ResManager::getInstance()->getBitMap(RES_ID_PLAYERICON));
	enemyNum = 6;
	for (int i = 0; i < enemyNum; ++i)
		enemyIcon.push_back(ResManager::getInstance()->getBitMap(RES_ID_ENEMYICON));
}

void UIManager::render(HDC hdc)
{
	for (int i = 0; i < life; ++i) 
		playerIcon[i]->render(hdc, (float)550 + (i * 20), (float)500);
	
	int j = 0;
	for (int i = 0; i < enemyNum; ++i) {
		if (i == 3)
			j = 1;
		enemyIcon[i]->render(hdc, (float)550 + ((i %3)* 20), (float)300 + (15 * j));
	}
	
}
