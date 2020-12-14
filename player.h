#pragma once
#include "graphics.h"
#include "config.h"
#include "gameobject.h"
#include "bullet.h"
<<<<<<< HEAD
#include <vector>
=======
#include <list>
#include "enemy.h"
>>>>>>> remotes/origin/development

class Player : public GameObject
{

	float speed = 10.0f;
	float player_x = CANVAS_WIDTH / 2;
	float player_y = CANVAS_HEIGHT / 2;
<<<<<<< HEAD
	std::vector<Bullet> bullets;
=======
	std::list<Bullet> bullets;
	bool initializeEnemy = true;
	Enemy* enemy = nullptr;
>>>>>>> remotes/origin/development
	
	
public:
	void update() override;
	void draw() override;
	void init() override;
	Player();
	~Player();
};