#pragma once
#include "Singleton.h"
class InputManager :public Singleton<InputManager>
{
private:
	HWND hWnd;

	bool leftKey;
	bool rightKey;
	bool upKey;
	bool downKey;
	bool shootKey;

	POINT pt;
public:
	void initInput(HWND _hWnd);
	void inputKeyState();

	inline bool checkLeftKey()  const { return leftKey; };
	inline bool checkRightKey() const { return rightKey; };
	inline bool checkUpKey()    const { return upKey; };
	inline bool checkDownKey()  const { return downKey; };
	inline bool checkShootKey() const { return shootKey; };

};

