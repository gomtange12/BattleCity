#pragma once

class BitMap;
class Effect
{
private:
	vector<BitMap*> bitMap;
	POINT pos;
	int resId;
	int endResId;
	int aniCount;
	bool endEffect;
public:

	void init(int res,int x, int y, int endRes);
	void render(HDC hdc);
	void update();
	void updateAnimation();
	bool deleteEffect();
};

