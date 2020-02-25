#include "stdafx.h"
#include "EffectManager.h"
#include "Effect.h"

void EffectManager::initEffect(int res, int x, int y, int endRes)
{
	Effect* newEffet = new Effect();
	newEffet->init(res, x, y, endRes);
	effect.push_back(newEffet);
}

void EffectManager::renderEffect(HDC hdc)
{
	for (auto iter = effect.begin(); iter != effect.end(); ++iter) {
		(*iter)->render(hdc);
	}
}

void EffectManager::updateEffect()
{
	for (auto iter = effect.begin(); iter != effect.end(); ++iter) {
		(*iter)->update();
	}
	deleteEffect();
}

void EffectManager::deleteEffect()
{
	for (auto iter = effect.begin(); iter != effect.end(); ){
		if ((*iter)->deleteEffect()) {
			delete *iter;
			iter = effect.erase(iter);
		}
		else
			++iter;
	}
}
void EffectManager::releaseEffect()
{
	for (auto iter = effect.begin(); iter != effect.end(); ++iter) {
			delete *iter;
	}
	effect.clear();
}
