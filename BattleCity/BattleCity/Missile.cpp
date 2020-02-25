#include "stdafx.h"
#include "Missile.h"
#include "ResManager.h"
#include "TimerManager.h"
#include "MapManager.h"
#include "EffectManager.h"
#include "BitMap.h"
void Missile::initMissile(int _dir, float x, float y, ACTOR_ID id)
{
	posX = x;
	posY = y;
	dir = _dir;
	for (int i = 0; i < 4; ++i)
		bitMap.push_back(ResManager::getInstance()->getBitMap(RES_MISSILE_UP + i));

	applyToResIndexByState();
	speed = 80;

	aid = id;
}

void Missile::updateMissile()
{
	moveBydir();
}

void Missile::moveBydir()
{
	if (dir == LEFT)
		posX -= speed * TimerManager::getInstance()->getElapseTime();
	else if (dir == RIGHT)
		posX += speed * TimerManager::getInstance()->getElapseTime();
	else if (dir == UP)
		posY -= speed * TimerManager::getInstance()->getElapseTime();
	else if (dir == DOWN)
		posY += speed * TimerManager::getInstance()->getElapseTime();
}
bool Missile::checkCollisionByTank(RECT tank, ACTOR_ID tankId)
{
	if (aid == tankId)
		return false;

	rect = { (LONG)posX  ,  (LONG)posY , (LONG)posX + 7, (LONG)posY + 7 };

	RECT temp;
	if (IntersectRect(&temp, &rect, &tank)) {
		EffectManager::getInstance()->initEffect(RES_ID_EFFECT0, posX - 10, posY - 10, 5);
		return true;
	}

	return false;
}
bool Missile::checkCollisionByBlock()
{
	rect = { (LONG)posX    ,  (LONG)posY , (LONG)posX + 7, (LONG)posY + 7 };

	if (MapManager::getInstance()->checkCollisionByMissile(rect)) {
		MapManager::getInstance()->releaseBlankBlock();
		EffectManager::getInstance()->initEffect(RES_ID_EFFECT0, posX-10, posY-10, 2);
		return true;
	}
	return false;
}
bool Missile::deleteOutOfRange()
{
	if (posX <= 0 || posX > SCREENWIDTH-100 || posY <= 0 || posY > SCREENHIGHT)
		return true;

	return false;
}

void Missile::applyToResIndexByState()
{
	if (dir == UP)
		resIndex = 0;
	else if (dir == DOWN)
		resIndex = 1;
	else if (dir == RIGHT)
		resIndex = 2;
	else if (dir == LEFT)
		resIndex = 3;

}

void Missile::renderMissile(HDC hdc)
{
	
	bitMap[resIndex]->render(hdc, posX, posY);
}




