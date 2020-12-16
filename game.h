#pragma once
#include "graphics.h"
#include "player.h"
#include "bullet.h"
#include <list>
#include "enemy.h"



class Game 
{
	float speed = 10.f;
	Player* player = nullptr;
	Enemy* enemy = nullptr;
	bool initializePlayer = true;
	bool initializeEnemy = true;
	std::list<Bullet> bullets;
	
public:
	void draw();
	void update();
	void init();
	Game();
	~Game();
	
};
