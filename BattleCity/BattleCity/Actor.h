#pragma once

class BitMap;
class Missile;
class Actor
{
protected:
	ACTOR_ID tankId;
	vector<BitMap*> bitMap;
	
	float posX;
	float posY;

	STATE_ACTOR state;
	RECT rect;

	int dir;
	float speed;
	int resIndex;
	
public:
	virtual ~Actor() {};

	virtual void init();
	virtual bool update()=0;
	virtual void moveByState();
	virtual void checkCollisionByBlock(float x, float y);
	virtual void render(HDC hdc);
	virtual bool updateMissile();
	virtual bool checkCollisionByMissile(RECT otherRt);

	virtual void applyToResIndexByState()=0;
	inline RECT getRect() const { return rect; };
};

