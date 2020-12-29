#pragma once
#include "graphics.h"
#include "player.h"
#include "bullet.h"
#include <list>
#include "enemy.h"
#include "effects.h"



class Game 
{
	
	float speed = 10.f;
	Player* player = nullptr;
	Enemy* enemy = nullptr;
	bool initializePlayer = true;
	bool initializeEnemy = true;
	std::list<Bullet> bullets;
	bool checkCollision(Disk disk1, Disk disk2);
	std::list<Enemybullet> enemybullets;
	bool initializeBullet = true;
	bool initializeEnemyBullet = true;
	Effects* effect = nullptr;
	bool ableEffect = false;
	float timeEffect;

public:
	void draw();
	void update();
	void init();
	Game();
	~Game();
	
};
