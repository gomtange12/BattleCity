#pragma once
#include "Actor.h"
#define DIE 8
class BitMap;
class Player:public Actor
{
private :
	BitMap* diebitMap;
	int hp;
	int shootCount;
	int responCount;
public:
	virtual ~Player() {};

	void init();
	bool update();
	void respon();
	void shootMissile();
	void checkKey();
	void applyToResIndexByState();

};

