#include "stdafx.h"
#include "MapManager.h"
#include "Block.h"
#include "ResManager.h"
#include "SceneManager.h"

void MapManager::initMap()
{
	for (int i = 0; i < HIGHT; ++i) {
		for (int j = 0; j < WIDTH; ++j) {
			Block* newblock = new Block();
			newblock->initBlock(ResManager::getInstance()->getBlockBitMap(RES_ID_BLOCK16), j * 33, i * 25, RES_ID_BLOCK16);
			block.push_back(newblock);
		}
	}
	loadMap();
}

void MapManager::updateMap()
{
	count = 0;
	for (auto iter = block.begin(); iter != block.end(); ++iter) {
		if ((*iter)->checkCommandCenterBlock())
			count++;	
	}
	if (count == 0)
		SceneManager::getInstance()->nextScene(SCENE_ENDING);
}

void MapManager::releaseMap()
{
	for (auto iter = block.begin(); iter != block.end(); ++iter)
		delete *iter;
	block.clear();
}

void MapManager::loadMap()
{
	ifstream in("map.txt", ios::in);
	for (auto iter = block.begin(); iter != block.end(); ++iter)
		(*iter)->loadBlockFile(in);

	releaseBlankBlock();
}

void MapManager::renderMap(HDC hdc)
{
	for (auto iter = block.begin(); iter != block.end(); ++iter)
		(*iter)->renderBlock(hdc);
}
void MapManager::renderBush(HDC hdc)
{
	for (auto iter = block.begin(); iter != block.end(); ++iter)
		(*iter)->renderBush(hdc);
}
bool MapManager::checkCollisionSlowBlockByPlayer(RECT playerRect)
{
	for (auto iter = block.begin(); iter != block.end(); ++iter) {
		if ((*iter)->checkCollisionSlowBlockByPlayer(playerRect)) {
			return true;
		}
	}
	return false;
}
bool MapManager::checkCollisionByPlayer(RECT playerRect)
{
	for (auto iter = block.begin(); iter != block.end(); ++iter) {
		if ((*iter)->checkCollisionByPlayer(playerRect)) {
			return true;
		}
	}
	return false;
}
bool MapManager::checkCollisionByMissile(RECT missileRect)
{
	for (auto iter = block.begin(); iter != block.end(); ++iter) {
		if ((*iter)->checkCollisionByMissile(missileRect)) {
			(*iter)->updateByState();
			return true;
		}
	}
	return false;
}
void MapManager::releaseBlankBlock()
{
	for (auto iter = block.begin(); iter != block.end();) {
		if ((*iter)->checkBlankBlock()) {
			delete *iter;
			iter = block.erase(iter);
		}
		else
			++iter;
	}
}