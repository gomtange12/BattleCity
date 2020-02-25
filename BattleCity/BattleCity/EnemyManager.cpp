#include "stdafx.h"
#include "EnemyManager.h"
#include "Enemy.h"
#include "UIManager.h"
#include "SceneManager.h"
void EnemyManager::initEnemy()
{
	enemyNum = 6;
	int j = 0;
	for (int i = 0; i < enemyNum; ++i) {
		if (i == 3)
			j = 1;
		Enemy* newEnemy = new Enemy();
		newEnemy->init((149*(i % 3))+100,120+(j*300));
		enemy.push_back(newEnemy);
	}
	responFlag = false;
	responCount = 0;
	UIManager::getInstance()->setEnemyNum(enemyNum);
}

void EnemyManager::updateEnemy()
{
	for (auto iter = enemy.begin(); iter != enemy.end(); ) {
		if ((*iter)->update()) {
			delete *iter;
			iter = enemy.erase(iter);
			responFlag = true;
			--enemyNum;
			UIManager::getInstance()->setEnemyNum(enemyNum);
		}
		else
			iter++;
	}
	if (enemyNum < 0) {
		SceneManager::getInstance()->nextScene(SCENE_ENDING);
	}
	else
		responEnemy();
}
void EnemyManager::responEnemy() {
	if (responFlag == false) {
		return;
	}
	responCount++;
	if (responCount > 300) {
		responCount = 0;
		Enemy* newEnemy = new Enemy();
		int num=rand() % 10;
		newEnemy->init(80 + (num*30), 150);
		enemy.push_back(newEnemy);
		responFlag = false;
	}

}
void EnemyManager::renderEnemy(HDC hdc)
{
	for (auto iter = enemy.begin(); iter != enemy.end(); iter++) 
		(*iter)->render(hdc);
	
}

void EnemyManager::releaseEnemy()
{
	for (auto iter = enemy.begin(); iter != enemy.end(); ++iter) {
		delete *iter;
	}
	enemy.clear();
}

bool EnemyManager::checkCollisionEnemy(RECT missileRt)
{
	for (auto iter = enemy.begin(); iter != enemy.end(); iter++)
		if ((*iter)->checkCollisionByMissile(missileRt))
			return true;

	return false;
}
