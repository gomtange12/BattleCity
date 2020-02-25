#include "stdafx.h"
#include "PlayerManager.h"
#include "Player.h"

void PlayerManager::initPlayer()
{
	player = new Player();
	player->init();
}

void PlayerManager::updatePlayer()
{
	if (player->update())
		this->releasePlayer();
}

void PlayerManager::renderPlayer(HDC hdc)
{
	player->render(hdc);
}

void PlayerManager::releasePlayer()
{
	delete player;
}


