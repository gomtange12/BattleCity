#include "stdafx.h"
#include "MissileManager.h"
#include "Missile.h"

void MissileManager::initMissile(int _dir, float x, float y, ACTOR_ID id)
{
	Missile* newMissile = new Missile();
	newMissile->initMissile(_dir, x + 13, y + 10, id);
	missile.push_back(newMissile);
}

void MissileManager::updateMissile()
{
	for (auto iter = missile.begin(); iter != missile.end(); ) {
		(*iter)->updateMissile();
		if (checkDeleteMissile(iter))
			iter = missile.erase(iter);
		else
			++iter;
	}
}
bool MissileManager::checkDeleteMissile(vector<Missile*>::iterator iter)
{
	if ((*iter)->checkCollisionByBlock() || (*iter)->deleteOutOfRange()) {
		delete *iter;
		return true;
	}
	else {
		return false;
	}

}
bool MissileManager::checkCollisionTank(RECT tank, ACTOR_ID tankId)
{
	bool flag = false;
	for (auto iter = missile.begin(); iter != missile.end(); ) {
		if ((*iter)->checkCollisionByTank(tank, tankId)) {
			delete *iter;
			iter = missile.erase(iter);
			flag = true;
		}
		else {
			++iter;
			
		}
	}
	return flag;
}
void MissileManager::renderMissile(HDC hdc)
{
	for (auto iter = missile.begin(); iter != missile.end(); ++iter)
		(*iter)->renderMissile(hdc);
}
