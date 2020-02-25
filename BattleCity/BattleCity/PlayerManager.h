#pragma once
class Player;
class PlayerManager
{
private:
	Player* player;

public:
	void initPlayer();
	void updatePlayer();
	void renderPlayer(HDC hdc);
	void releasePlayer();
	
};

