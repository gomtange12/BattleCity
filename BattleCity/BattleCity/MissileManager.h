#pragma once
#include "Singleton.h"
class Missile;
class MissileManager : public Singleton<MissileManager>
{
private:
	vector<Missile*> missile;

public:
	void initMissile(int _dir, float x, float y, ACTOR_ID id);
	void updateMissile();
	bool checkDeleteMissile(vector<Missile*>::iterator iter);
	bool checkCollisionTank(RECT tank, ACTOR_ID tankId);

	void renderMissile(HDC hdc);
};

