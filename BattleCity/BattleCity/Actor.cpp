#include "stdafx.h"
#include "Actor.h"
#include "InputManager.h"
#include "TimerManager.h"
#include "BitMap.h"
#include "MapManager.h"
#include "MissileManager.h"
void Actor::init()
{
	resIndex = 0;
	speed = 0;
}

void Actor::moveByState() {
	if (state == STOP )
		return;

	float x = posX;
	float y = posY;
	if (state== LEFT)
		x -= speed * TimerManager::getInstance()->getElapseTime();
	else if (state == RIGHT)
		x += speed * TimerManager::getInstance()->getElapseTime();
	else if (state == UP)
		y -= speed * TimerManager::getInstance()->getElapseTime();
	else if (state == DOWN)
		y += speed * TimerManager::getInstance()->getElapseTime();

	if (x > 0 && y > 0 && x < SCREENWIDTH - 140 && y < SCREENHIGHT - 60) 
		checkCollisionByBlock(x, y);
	

}


void Actor::checkCollisionByBlock(float x, float y) 
{
	rect = { (LONG)x+1   ,  (LONG)y+2 , (LONG)x + 29, (LONG)y + 23 };
	if (!MapManager::getInstance()->checkCollisionByPlayer(rect)) {
		if (MapManager::getInstance()->checkCollisionSlowBlockByPlayer(rect)) {
			if (state == LEFT)
				posX -= (speed - 70) * TimerManager::getInstance()->getElapseTime();
			else if (state == RIGHT)
				posX += (speed - 70) * TimerManager::getInstance()->getElapseTime();
			else if (state == UP)
				posY -= (speed - 70) * TimerManager::getInstance()->getElapseTime();
			else if (state == DOWN)
				posY += (speed - 70) * TimerManager::getInstance()->getElapseTime();
			rect = { (LONG)posX + 1   ,  (LONG)posY + 2 , (LONG)posX + 29, (LONG)posY + 23 };
		}
		else {
			posX = x;
			posY = y;
			rect = { (LONG)posX + 1   ,  (LONG)posY + 2 , (LONG)posX + 29, (LONG)posY + 23 };
		}
	}
}
void Actor::render(HDC hdc)
{
	
	MissileManager::getInstance()->renderMissile(hdc);
	bitMap[resIndex]->render(hdc, posX, posY);
	
}

bool Actor::updateMissile()
{
	MissileManager::getInstance()->updateMissile();
	if (MissileManager::getInstance()->checkCollisionTank(rect, tankId)) {
		return true;
	}

	return false;
}

bool Actor::checkCollisionByMissile(RECT missileRt) {
	return false;
}