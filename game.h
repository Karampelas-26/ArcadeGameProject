#pragma once
#include "graphics.h"
#include "player.h"
<<<<<<< HEAD

class Game
{
	
	Player* player = nullptr;
	bool initializePlayer = true;
=======
#include "enemy.h"

class Game
{
	float speed = 10.f;
	Player* player = nullptr;
	Enemy* enemy = nullptr;
	bool initializePlayer = true;
	bool initializeEnemy = true;
>>>>>>> remotes/origin/development
public:
	void draw();
	void update();
	void init();
	Game();
	~Game();
	
};
