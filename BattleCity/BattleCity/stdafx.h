// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 또는 프로젝트 특정 포함 파일이 들어 있는
// 포함 파일입니다.
//

#pragma once

#include "targetver.h"
#pragma comment(lib, "msimg32.lib")
#pragma comment (lib, "ws2_32.lib")
#define _CRT_SECURE_NO_WARNINGS
#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용을 Windows 헤더에서 제외합니다.
#include <windows.h>

// C 런타임 헤더 파일입니다.
#include <iostream>
#include <crtdbg.h>
#include <vector>
#include <tchar.h>
#include <list>
#include <string>
#include <math.h>
#include <stdio.h>
#include <chrono>
#include <fstream>

// 여기서 프로그램에 필요한 추가 헤더를 참조합니다.
using namespace std;

//#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")

#define SCREENWIDTH 640
#define SCREENHIGHT 790

#define WIDTH 16
#define HIGHT 30

enum SCENE_NUM {
	SCENE_MENU,
	SCENE_GAME,
	SCENE_ENDING,
	SCENE_END
};

enum RES_ID
{
	RES_PLAYER_UP0,
	RES_PLAYER_UP1,
	RES_PLAYER_DOWN0,
	RES_PLAYER_DOWN1,
	RES_PLAYER_RIGHT0,
	RES_PLAYER_RIGHT1,
	RES_PLAYER_LEFT0,
	RES_PLAYER_LEFT1,
	RES_MISSILE_UP,
	RES_MISSILE_DOWN,
	RES_MISSILE_RIGHT,
	RES_MISSILE_LEFT,
	RES_PLAYER_END
};

enum RES_ID_BLOCK {
	RES_ID_BLOCK0,
	RES_ID_BLOCK1,
	RES_ID_BLOCK2,
	RES_ID_BLOCK3,
	RES_ID_BLOCK4,
	RES_ID_BLOCK5,
	RES_ID_BLOCK6,
	RES_ID_BLOCK7,
	RES_ID_BLOCK8,
	RES_ID_BLOCK9,
	RES_ID_BLOCK10,
	RES_ID_BLOCK11,
	RES_ID_BLOCK12,
	RES_ID_BLOCK13,
	RES_ID_BLOCK14,
	RES_ID_BLOCK15,
	RES_ID_BLOCK16,
	RES_ID_BACKGROUND,
	RES_BLOCK_END
};
enum RES_ID_EFFECT {
	RES_ID_EFFECT0 = 12,
	RES_ID_EFFECT1,
	RES_ID_EFFECT2,
	RES_ID_EFFECT3,
	RES_ID_EFFECT4,
	RES_ID_SHIELD0,
	RES_ID_SHIELD1,
	RES_ID_EFFECT_END
};
enum RES_ID_UI {
	RES_ID_PLAYERICON = 19,
	RES_ID_ENEMYICON,
	RES_ID_ENDINGUI,
	RES_ID_TITLEUI,
	RES_ID_UI_END
};
enum RES_ID_ENEMY {
	RES_ENEMY_DOWN0,
	RES_ENEMY_DOWN1,
	RES_ENEMY_DOWN2,
	RES_ENEMY_LEFT0,
	RES_ENEMY_LEFT1,
	RES_ENEMY_LEFT2,
	RES_ENEMY_RIGHT0,
	RES_ENEMY_RIGHT1,
	RES_ENEMY_RIGHT2,
	RES_ENEMY_UP0,
	RES_ENEMY_UP1,
	RES_ENEMY_UP2,
	RES_ID_ENEMY_END
};

enum STATE_ACTOR
{
	UP,
	DOWN,
	RIGHT,
	LEFT,
	STOP
};

enum ACTOR_ID {
	PLAYER,
	ENEMY
};