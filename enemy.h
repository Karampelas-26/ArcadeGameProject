#pragma once
#include "graphics.h"
#include "config.h"
#include "gameobject.h"
#include "enemy_bullet.h"
#include <list>

class Enemy : public GameObject
{
	float speed = 10.0f;
	float enemy_x = CANVAS_WIDTH/2;
	float enemy_y = 0;
	std::list<Enemybullet> enemybullets;
	bool initializeBullet = true;
	
public:
	
	void draw() override;
	void update() override;
	void init() override;
	Enemy();
	~Enemy();
};