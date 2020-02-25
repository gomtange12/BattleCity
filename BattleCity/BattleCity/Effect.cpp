#include "stdafx.h"
#include "Effect.h"
#include "BitMap.h"
#include "ResManager.h"

void Effect::init(int res, int x, int y, int endRes)
{
	pos.x = x;
	pos.y = y;
	resId = 0;
	
	for (int i = 0; i < endRes; ++i) {
		bitMap.push_back(ResManager::getInstance()->getBitMap(res + i));
	}

	aniCount = 0;
	endEffect = false;
	endResId = endRes-1;
}

void Effect::render(HDC hdc)
{
	if (bitMap.size() == 0)
		return;
	
	bitMap[resId]->render(hdc, (float)pos.x, (float)pos.y);
}

void Effect::update()
{
	if (bitMap.size() == 0)
		return;

	aniCount++;
	updateAnimation();
}


void Effect::updateAnimation()
{
	if (aniCount % 20 == 0)
	{
		if (resId == endResId)
			endEffect = true;
		else
			resId++;
	}
}

bool Effect::deleteEffect()
{
	return endEffect;
}

