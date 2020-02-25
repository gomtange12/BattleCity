#pragma once
#include "Singleton.h"
class BitMap;
class UIManager:public Singleton< UIManager>
{
private:
	vector<BitMap*> playerIcon;
	vector<BitMap*> enemyIcon;
	int enemyNum;
	int life;
public:

	void init();

	void render(HDC hdc);

	inline void setLife(int lf) { life = lf; };
	inline void setEnemyNum(int eN) { enemyNum = eN; };

};

