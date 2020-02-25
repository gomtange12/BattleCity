#pragma once
enum STATE_BLOCK
{
	NONE_BLOCK,
	TOP_BLOCK,
	LEFT_BLOCK,
	BOTTOM_BLOCK,
	RIGHT_BLOCK,
	BLANK
};
class BitMap;
class Block
{
private:
	BitMap* bitMap;
	POINT pos;
	int resId;
	RECT rect;
	STATE_BLOCK state;

	
public:
	void initBlock(BitMap* bMap, int x, int y, int rid);
	void renderBlock(HDC hdc);
	void renderBush(HDC hdc);
	void updateByState();
	void loadBlockFile(ifstream& infile);

	bool checkCollisionSlowBlockByPlayer(RECT otherRect);
	
	bool checkCollisionByPlayer(RECT otherRect);
	bool checkCollisionByMissile(RECT otherRect);
	bool checkBlankBlock();

	bool checkCommandCenterBlock();
};

