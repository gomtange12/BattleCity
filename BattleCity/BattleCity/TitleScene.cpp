#include "stdafx.h"
#include "TitleScene.h"
#include "BitMap.h"
#include "ResManager.h"
#include "InputManager.h"
#include "SceneManager.h"
void TitleScene::initScene()
{
	bitMap = ResManager::getInstance()->getBitMap(RES_ID_TITLEUI);
	selectBitMap = ResManager::getInstance()->getBitMap(RES_PLAYER_RIGHT0);
	selectPosY = 445;
}

void TitleScene::updateScene()
{
	if (InputManager::getInstance()->checkUpKey()) {
		if (selectPosY > 445)
			selectPosY -= 60;
	}
	else if (InputManager::getInstance()->checkDownKey()) {
		if (selectPosY < 505)
			selectPosY += 60;
	}
	if(InputManager::getInstance()->checkShootKey())
		SceneManager::getInstance()->nextScene(SCENE_GAME);
}

void TitleScene::renderScene(HDC hdc)
{
	bitMap->render(hdc, 0, 0);
	selectBitMap->render(hdc, (float)180, (float)selectPosY);
}

void TitleScene::releaseScene()
{
}
