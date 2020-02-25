#include "stdafx.h"
#include "Player.h"
#include "ResManager.h"
#include "InputManager.h"
#include "TimerManager.h"
#include "MissileManager.h"
#include "BitMap.h"
#include "UIManager.h"
#include "EffectManager.h"
#include "SceneManager.h"
void Player::init()
{
	for (int i = 0; i < 8; ++i) {
		bitMap.push_back(ResManager::getInstance()->getBitMap(i));
	}
	diebitMap = ResManager::getInstance()->getBlockBitMap(RES_ID_BLOCK15);
	bitMap.push_back(diebitMap);
	hp = 3;
	respon();

}
bool Player::update()
{
	if (resIndex == DIE) {
		if (responCount >= 300) {
			if (hp < 0) {
				SceneManager::getInstance()->nextScene(SCENE_ENDING);
			}
			else
				respon();
		}
		
		responCount++;
		return false;
	}

	checkKey();
	moveByState();
	applyToResIndexByState();
	shootMissile();

	if (updateMissile()) {
		--hp;
		resIndex = DIE;
	}
	
	return false;
}
void Player::respon() 
{
	UIManager::getInstance()->setLife(hp);
	posX = 380.0f;
	posY = 655.0f;
	speed = 120;
	shootCount = 0;
	responCount = 0;
	dir = UP;
	state = STOP;
	tankId = PLAYER;
	resIndex = RES_PLAYER_UP0;
	rect = { (LONG)posX + 1   ,  (LONG)posY + 2 , (LONG)posX + 29, (LONG)posY + 23 };
	EffectManager::getInstance()->initEffect(RES_ID_SHIELD0, posX, posY+5, 2);
}
void Player::shootMissile() 
{
	if (InputManager::getInstance()->checkShootKey()) {
		shootCount--;
		if (shootCount <= 0) {
			MissileManager::getInstance()->initMissile(dir, posX, posY, PLAYER);
			shootCount = 120;
		}
	}
	else {
		shootCount = 0;
	}

}

void Player::checkKey()
{
	if (InputManager::getInstance()->checkLeftKey()) {
		state = LEFT;
		dir = LEFT;
	}
	else if (InputManager::getInstance()->checkRightKey()) {
		state = RIGHT;
		dir = RIGHT;
	}
	else if (InputManager::getInstance()->checkUpKey()) {
		state = UP;
		dir = UP;
	}
	else if (InputManager::getInstance()->checkDownKey()) {
		state = DOWN;
		dir = DOWN;
	}
	else
		state = STOP;

}

void Player::applyToResIndexByState()
{
	if (state == UP) {
		if (resIndex == RES_PLAYER_UP0)
			resIndex = RES_PLAYER_UP1;
		else
			resIndex = RES_PLAYER_UP0;
	}
	else if (state == DOWN) {
		if (resIndex == RES_PLAYER_DOWN0)
			resIndex = RES_PLAYER_DOWN1;
		else
			resIndex = RES_PLAYER_DOWN0;
	}
	else if (state == RIGHT) {
		if (resIndex == RES_PLAYER_RIGHT0)
			resIndex = RES_PLAYER_RIGHT1;
		else
			resIndex = RES_PLAYER_RIGHT0;
	}
	else if (state == LEFT) {
		if (resIndex == RES_PLAYER_LEFT0)
			resIndex = RES_PLAYER_LEFT1;
		else
			resIndex = RES_PLAYER_LEFT0;
	}
}