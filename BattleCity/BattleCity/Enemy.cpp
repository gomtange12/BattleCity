#include "stdafx.h"
#include "Enemy.h"
#include "ResManager.h"
#include "BitMap.h"
#include "MissileManager.h"

void Enemy::init(int x, int y)
{
	for (int i = 0; i < RES_ID_ENEMY_END; ++i) {
		bitMap.push_back(ResManager::getInstance()->getEnemyBitMap(RES_ENEMY_DOWN0 + i));
	}
	posX = (float)x;
	posY = (float)y;
	resIndex = 0;
	updateCount = 0;
	speed = 110;
	tankId = ENEMY;
}

bool Enemy::update()
{
	updateCount++;

	updateState();
	applyToResIndexByState();
	moveByState();
	shootMissile();
	if (updateMissile()) {
		
		return true;
	}

	return false;

}

void Enemy::shootMissile()
{
	if (updateCount == 50) {
		MissileManager::getInstance()->initMissile(dir, posX, posY, ENEMY);
	}


}

void Enemy::updateState()
{	
	if (updateCount == 60) {
		randNum = rand();
		updateCount = 0;
		randNum = randNum % 4;
	}

	switch (randNum)
	{
	case 0:
		state = UP;
		dir = UP;
		break;
	case 1:
		state = DOWN;
		dir = DOWN;
		break;
	case 2:
		state = LEFT;
		dir = LEFT;
		break;
	case 3:
		state = RIGHT;
		dir = RIGHT;
		break;
	}

}


void Enemy::applyToResIndexByState()
{
	if (state == UP) {
		if (resIndex == RES_ENEMY_UP0)
			resIndex = RES_ENEMY_UP1;
		else
			resIndex = RES_ENEMY_UP0;
	}
	else if (state == DOWN) {
		if (resIndex == RES_ENEMY_DOWN0)
			resIndex = RES_ENEMY_DOWN1;
		else
			resIndex = RES_ENEMY_DOWN0;
	}
	else if (state == RIGHT) {
		if (resIndex == RES_ENEMY_RIGHT0)
			resIndex = RES_ENEMY_RIGHT1;
		else
			resIndex = RES_ENEMY_RIGHT0;
	}
	else if (state == LEFT) {
		if (resIndex == RES_ENEMY_LEFT0)
			resIndex = RES_ENEMY_LEFT1;
		else
			resIndex = RES_ENEMY_LEFT0;
	}
}
