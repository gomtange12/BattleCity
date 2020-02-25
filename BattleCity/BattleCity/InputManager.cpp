#include "stdafx.h"
#include "InputManager.h"


void InputManager::initInput(HWND _hWnd)
{
	hWnd = _hWnd;

	leftKey  = false;
	rightKey = false;
	upKey    = false;
	downKey  = false;
	shootKey = false;
}

void InputManager::inputKeyState()
{
	if (GetKeyState(VK_LEFT) & 0x8000)
		leftKey = true;
	else
		leftKey = false;
	if (GetKeyState(VK_RIGHT) & 0x8000)
		rightKey = true;
	else
		rightKey = false;
	if (GetKeyState(VK_UP) & 0x8000)
		upKey = true;
	else
		upKey = false;
	if (GetKeyState(VK_DOWN) & 0x8000)
		downKey = true;
	else
		downKey = false;

	if (GetKeyState(VK_SPACE) & 0x8000)
	{
		if (shootKey == false)
			shootKey = true;
	}
	else
	{
		if (shootKey)//Å° ¾÷
			shootKey = false;
	}

	if (GetKeyState(VK_LBUTTON) & 0x8000)
	{
		GetCursorPos(&pt);
		ScreenToClient(hWnd, &pt);
	}
}
