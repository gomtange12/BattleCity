#pragma once
#include "Actor.h"
class Missile;
class Enemy : public Actor
{
private:
	int updateCount;
	int randNum;

public:
	virtual ~Enemy() {};

	void init(int x, int y);
	bool update();
	void shootMissile();
	void updateState();
	void applyToResIndexByState();
};

