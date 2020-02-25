#pragma once
#include "Singleton.h"
class Effect;
class EffectManager :public Singleton<EffectManager>
{
private:
	vector<Effect*> effect;
public:
	void initEffect(int res, int x, int y, int endRes);
	void renderEffect(HDC hdc);
	void updateEffect();
	void deleteEffect();
	void releaseEffect();
};

