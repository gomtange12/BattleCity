#pragma once
#include "Scene.h"

class PlayerManager;
class EnemyManager;
class GameScene : public Scene
{
private:
	PlayerManager* playerManager;
	EnemyManager* enemyManager;
public:

	void initScene();
	void updateScene();
	void renderScene(HDC hdc);
	void releaseScene();
};

