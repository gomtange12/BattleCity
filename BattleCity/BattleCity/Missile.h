#pragma once

class BitMap;
class Missile 
{
private:
	vector<BitMap*> bitMap;
	float posX;
	float posY;

	RECT rect;

	int dir;
	int resIndex;
	float speed;

	ACTOR_ID aid;
public:
	void initMissile(int dir, float x, float y, ACTOR_ID id);
	void updateMissile();
	void moveBydir();
	bool checkCollisionByTank(RECT tank, ACTOR_ID tankId);
	bool checkCollisionByBlock();
	bool deleteOutOfRange();
	void applyToResIndexByState();
	void renderMissile(HDC hdc);
};

