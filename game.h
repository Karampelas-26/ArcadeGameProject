#pragma once
#include "graphics.h"
#include "player.h"
#include "bullet.h"
#include <list>
#include "enemy.h"
#include "effects.h"
#include "background.h"
#include "powerups.h"


class Game 
{
	
	typedef enum {STATUS_START, STATUS_PLAYING, STATUS_END} status_t;
	status_t status;
	void updateStartScreen();
	void updateLevelScreen();
	void updateEndScreen();
	void drawStartScreen();
	void drawLevelScreen();
	void drawEndScreen();
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
	PowerUps* powerUp = nullptr;
	bool initializePowerUp = true;
	void deleteEnemy();
	bool powerUpActive = false;
	

public:
	void draw();
	void update();
	void init();
	Game();
	~Game();
	
};
