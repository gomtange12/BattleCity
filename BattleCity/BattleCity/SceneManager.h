#pragma once
#include "Singleton.h"

class Scene;
class SceneManager: public Singleton<SceneManager>
{
private:
	SCENE_NUM sceneNum;
	vector<Scene*> scene;
public:
	void initScene();
	void updateScene();
	void renderScene(HDC hdc);
	void releaseScene();
	void nextScene(SCENE_NUM sn);
};

