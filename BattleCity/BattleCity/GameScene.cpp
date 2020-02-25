#include "stdafx.h"
#include "GameScene.h"
#include "PlayerManager.h"
#include "MapManager.h"
#include "EffectManager.h"
#include "EnemyManager.h"
void GameScene::initScene()
{
	MapManager::getInstance()->initMap();

	playerManager = new PlayerManager();
	playerManager->initPlayer();
	
	enemyManager = new EnemyManager();
	enemyManager->initEnemy();

}

void GameScene::updateScene()
{
	playerManager->updatePlayer();
	enemyManager->updateEnemy();

	EffectManager::getInstance()->updateEffect();
	MapManager::getInstance()->updateMap();
}

void GameScene::renderScene(HDC hdc)
{
	MapManager::getInstance()->renderMap(hdc);

	playerManager->renderPlayer(hdc);
	enemyManager->renderEnemy(hdc);

	MapManager::getInstance()->renderBush(hdc);

	EffectManager::getInstance()->renderEffect(hdc);
}

void GameScene::releaseScene()
{
	playerManager->releasePlayer();
	delete playerManager;

	enemyManager->releaseEnemy();
	delete enemyManager;

	MapManager::getInstance()->releaseMap();

	MapManager::getInstance()->releaseInstance();

	EffectManager::getInstance()->releaseEffect();
	EffectManager::getInstance()->releaseInstance();
}


