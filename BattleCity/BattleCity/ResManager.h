#pragma once
#include "Singleton.h"

class BitMap;
class ResManager:public Singleton<ResManager>
{
private:
	vector<std::string> resId;
	vector<BitMap*> bitMap;
	vector<BitMap*> blockBitMap;
	vector<BitMap*> EnemyBitMap;
public:
	void initRes(HDC hdc);
	void initResId();
	BitMap* getBitMap(int index);

	void release();

	void initBlockRes(HDC hdc);
	void initBlockResId();
	BitMap * getBlockBitMap(int index);

	void initEnemyRes(HDC hdc);
	void initEnemyResId();
	BitMap* getEnemyBitMap(int index);


};

