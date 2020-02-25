#include "stdafx.h"
#include "Block.h"
#include "BitMap.h"
#include "ResManager.h"

void Block::initBlock(BitMap* bMap, int x, int y, int rid)
{
	bitMap = bMap;
	pos.x = (long)x;
	pos.y = (long)y;
	resId = rid;
		
	state = NONE_BLOCK;
}
void Block::renderBlock(HDC hdc)
{
	if (resId != RES_ID_BLOCK6)
		bitMap->render(hdc, (float)pos.x, (float)pos.y);
}
void Block::renderBush(HDC hdc)
{
	if (resId == RES_ID_BLOCK6)
		bitMap->render(hdc, (float)pos.x, (float)pos.y);
}
void Block::updateByState()
{
	if (resId == RES_ID_BLOCK14) {
		bitMap = ResManager::getInstance()->getBlockBitMap(resId);
		return;
	}

	if (resId >= RES_ID_BLOCK5)
		return;

	if (state == BLANK) {
		resId = RES_ID_BLOCK15;
		bitMap = ResManager::getInstance()->getBlockBitMap(resId);
		return;
	}

	resId += state;
	bitMap = ResManager::getInstance()->getBlockBitMap(resId);
}
void Block::loadBlockFile(ifstream & infile)
{
	infile >> resId;
	bitMap = ResManager::getInstance()->getBlockBitMap(resId);
	infile >> pos.x;
	infile >> pos.y;

	if(resId != RES_ID_BLOCK6 )
		rect = { pos.x - 1  ,  pos.y - 1 , pos.x + 34, pos.y + 26 };
}
bool Block::checkCollisionSlowBlockByPlayer(RECT otherRect)
{
	
	if (resId != RES_ID_BLOCK5)
		return false;

	RECT temp;
	if (IntersectRect(&temp, &rect, &otherRect))
		return true;

	return false;
}
bool Block::checkCollisionByPlayer(RECT otherRect)
{

	if (resId == RES_ID_BLOCK5) {
		return false;
	}

	RECT temp;
	if (IntersectRect(&temp, &rect, &otherRect))
		return true;
	
	return false;
}
bool Block::checkCollisionByMissile(RECT otherRect)
{
	if (resId == RES_ID_BLOCK7 || resId == RES_ID_BLOCK5)
		return false;

	RECT temp;
	if (IntersectRect(&temp, &rect, &otherRect)) {
		if (resId == RES_ID_BLOCK13)
			resId = RES_ID_BLOCK14;
		if (state == NONE_BLOCK) {
			if (rect.left == otherRect.right - 1) {
				state = RIGHT_BLOCK;
				rect = { pos.x + 18  ,  pos.y - 1 , pos.x + 34, pos.y + 26 };
				return true;
			}
			if (rect.top == otherRect.bottom - 1) {
				state = BOTTOM_BLOCK;
				rect = { pos.x -1  ,  pos.y + 13 , pos.x + 34, pos.y + 26 };
				return true;
			}
			if (rect.right == otherRect.left + 1) {
				state = LEFT_BLOCK;
				rect = { pos.x - 1  ,  pos.y - 1 , pos.x + 17, pos.y + 26 };
				return true;
			}
			if (rect.bottom == otherRect.top + 1) {
				state = TOP_BLOCK;
				rect = { pos.x - 1  ,  pos.y - 1 , pos.x + 34, pos.y + 13 };
				return true;
			}
		}
		else {
			state = BLANK;
			return true;
		}
		
	}
	
	return false;
}
bool Block::checkBlankBlock()
{
	if (resId == RES_ID_BLOCK16 || resId == RES_ID_BLOCK15)
		return true;
	return false;
}

bool Block::checkCommandCenterBlock()
{
	if (resId == RES_ID_BLOCK13)
		return true;
	return false;
}
