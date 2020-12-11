#pragma once
#include "graphics.h"
#include "config.h"
#include "gameobject.h"
#include "enemy_bullet.h"
#include <list>

class Enemy : public GameObject
{
	float speed = 10.0f;
	float enemy_x = 0.0f;
	float enemy_y = 200.f;
	std::list<Enemybullet> enemybullets;
	bool initializeBullet = true;
	
public:
	
	void draw() override;
	void update() override;
	void init() override;
	float getEnemy_x();
	float getEnemy_y();
	Enemy();
	~Enemy();
};