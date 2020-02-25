#include "stdafx.h"
#include "EndingScene.h"
#include "BitMap.h"
#include "ResManager.h"
#include "SceneManager.h"
void EndingScene::initScene()
{
	bitMap = ResManager::getInstance()->getBitMap(RES_ID_ENDINGUI);
	count = 0;
}

void EndingScene::updateScene()
{
	count++;
	if (count >= 600) {
		SceneManager::getInstance()->nextScene(SCENE_MENU);
		count = 0;
	}
}

void EndingScene::renderScene(HDC hdc)
{
	bitMap->render(hdc, 0, 0);
}

void EndingScene::releaseScene()
{
}
