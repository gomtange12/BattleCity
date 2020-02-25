#include "stdafx.h"
#include "ResManager.h"
#include "BitMap.h"


void ResManager::initRes(HDC hdc)
{
	bitMap.reserve(RES_ID_UI_END);
	blockBitMap.reserve(RES_BLOCK_END);
	EnemyBitMap.reserve(RES_ID_ENEMY_END);

	initResId();

	for (int i = 0; i < RES_ID_UI_END; i++)
	{
		BitMap* bMap = new BitMap();
		resId[i] = "res\\" + resId[i] + ".bmp";
		bMap->init(hdc, resId[i]);
		bitMap.emplace_back(bMap);
	}
	resId.clear();
	initBlockRes(hdc);
	initEnemyRes(hdc);
}
BitMap* ResManager::getBitMap(int index)
{
	return bitMap[index];
}

void ResManager::release()
{
	for (auto iter = bitMap.begin(); iter != bitMap.end(); ++iter) {
		(*iter)->release();
		delete *iter;
	}
	bitMap.clear();
	for (auto iter = blockBitMap.begin(); iter != blockBitMap.end(); ++iter) {
		(*iter)->release();
		delete *iter;
	}
	blockBitMap.clear();
	for (auto iter = EnemyBitMap.begin(); iter != EnemyBitMap.end(); ++iter) {
		(*iter)->release();
		delete *iter;
	}
	EnemyBitMap.clear();
		
}
void ResManager::initBlockRes(HDC hdc)
{
	initBlockResId();

	for (int i = 0; i < RES_BLOCK_END; i++)
	{
		BitMap* bMap = new BitMap();
		bMap->init(hdc, resId[i]);
		blockBitMap.emplace_back(bMap);
	}
	resId.clear();
}
void ResManager::initBlockResId()
{
	for (int i = 0; i < RES_BLOCK_END -1; ++i) {
		resId.push_back("res\\block");
		resId[i] += std::to_string(i);
		resId[i] += ".bmp";
	}
	resId.push_back("res\\backGround.bmp");
}
void ResManager::initResId()
{

	resId = { "tank_up_00","tank_up_01","tank_down_00","tank_down_01","tank_right_00","tank_right_01",
		"tank_left_00","tank_left_01","missile_00","missile_01","missile_02","missile_03",
		"explosion_00","explosion_01","explosion_02","explosion_03","explosion_04","shield_00",
		"shield_01","player_icon","enemy_icon","gameover","title"
	};

}
BitMap * ResManager::getBlockBitMap(int index)
{
	return blockBitMap[index];
}

void ResManager::initEnemyRes(HDC hdc)
{
	initEnemyResId();

	for (int i = 0; i < RES_ID_ENEMY_END; i++)
	{
		BitMap* bMap = new BitMap();
		resId[i] = "res\\" + resId[i] + ".bmp";
		bMap->init(hdc, resId[i]);
		EnemyBitMap.emplace_back(bMap);
	}
	resId.clear();
}
void ResManager::initEnemyResId()
{
	resId = { "e_down_00","e_down_01","e_down_02","e_left_00","e_left_01","e_left_02",
		"e_right_00","e_right_01","e_right_02","e_up_00","e_up_01","e_up_02",
	};
}
BitMap * ResManager::getEnemyBitMap(int index)
{
	return EnemyBitMap[index];
}
