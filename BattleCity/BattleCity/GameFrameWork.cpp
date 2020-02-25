#include "stdafx.h"
#include "GameFrameWork.h"
#include "RenderManager.h"
#include "InputManager.h"
#include "SceneManager.h"
#include "TimerManager.h"
#include "ResManager.h"
void GameFrameWork::init(HWND _hWnd)
{
	hWnd = _hWnd;

	srand(GetTickCount());
	
	TimerManager::getInstance()->initTime();

	RenderManager::getInstance()->init(hWnd);

	SceneManager::getInstance()->initScene();

	InputManager::getInstance()->initInput(hWnd);
}
void GameFrameWork::release()
{
	InputManager::getInstance()->releaseInstance();

	SceneManager::getInstance()->releaseScene();
	SceneManager::getInstance()->releaseInstance();

	RenderManager::getInstance()->release();
	RenderManager::getInstance()->releaseInstance();

	TimerManager::getInstance()->releaseInstance();
}

void GameFrameWork::update()
{
	if (TimerManager::getInstance()->updateTime())
		return;

	InputManager::getInstance()->inputKeyState();

	SceneManager::getInstance()->updateScene();

	RenderManager::getInstance()->render();
}

