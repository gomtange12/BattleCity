#pragma once

class Enemy;
class EnemyManager
{
private:
	vector<Enemy*> enemy;
	bool responFlag;
	int responCount;
	int enemyNum;
public:
	void initEnemy();
	void updateEnemy();
	void responEnemy();
	void renderEnemy(HDC hdc);
	void releaseEnemy();
	bool checkCollisionEnemy(RECT missileRt);
};

