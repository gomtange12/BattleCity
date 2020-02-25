#pragma once
#include "Singleton.h"
class Block;
class MapManager: public Singleton<MapManager>
{
private:
	vector<Block*> block;
	int count;
public:

	void initMap();
	void updateMap();
	void releaseMap();
	void loadMap();
	void renderMap(HDC hdc);
	void renderBush(HDC hdc);
	bool checkCollisionSlowBlockByPlayer(RECT playerRect);
	bool checkCollisionByPlayer(RECT playerRect);
	bool checkCollisionByMissile(RECT playerRect);
	void releaseBlankBlock();
};

