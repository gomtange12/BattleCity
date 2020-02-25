#pragma once
#include "Scene.h"
class BitMap;
class TitleScene : public Scene
{
private:
	BitMap* bitMap;
	BitMap* selectBitMap;
	int selectPosY;
public:
	void initScene();
	void updateScene();
	void renderScene(HDC hdc);
	void releaseScene();
};

