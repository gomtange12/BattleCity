#pragma once
#include "Scene.h"
class BitMap;
class EndingScene :public Scene
{
private:
	BitMap* bitMap;
	int count;
public:
	void initScene();
	void updateScene();
	void renderScene(HDC hdc);
	void releaseScene();
};

