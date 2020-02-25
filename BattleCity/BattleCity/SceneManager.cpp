#include "stdafx.h"
#include "SceneManager.h"
#include "GameScene.h"
#include "EndingScene.h"
#include "TitleScene.h"
#include "Scene.h"

void SceneManager::initScene()
{
	scene.reserve(SCENE_END);
	sceneNum = SCENE_MENU;

	scene.emplace_back(new TitleScene());
	//scene.emplace_back(new StageScene());
	scene.emplace_back(new GameScene());
	scene.emplace_back(new EndingScene());

	for (auto iter = scene.begin(); iter != scene.end(); iter++)
		(*iter)->initScene();
}
void SceneManager::updateScene()
{
	scene[sceneNum]->updateScene();
}
void SceneManager::renderScene(HDC hdc)
{
	scene[sceneNum]->renderScene(hdc);
}
void SceneManager::releaseScene()
{
	for (auto iter = scene.begin(); iter != scene.end(); ++iter) {
		(*iter)->releaseScene();
		delete *iter;

	}
	scene.clear();
}

void SceneManager::nextScene(SCENE_NUM sn)
{
	sceneNum = sn;
	if (sceneNum == SCENE_ENDING) {
		scene[SCENE_GAME]->releaseScene();
		scene[SCENE_GAME]->initScene();
	}
}
