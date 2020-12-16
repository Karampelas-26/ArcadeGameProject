#pragma once
#include "graphics.h"
#include "config.h"
#include "gameobject.h"
//#include "enemy_bullet.h"
//#include <list>

class Enemy : public GameObject
{
	float speed = 17.0;
	float enemy_x;
	float enemy_y = 0.0f;
	//std::list<Enemybullet> enemybullets;
	//bool initializeBullet = true;
	
public:
	bool enemyisActive();
	void draw() override;
	void update() override;
	void init() override;
	float getEnemy_x();
	float getEnemy_y();
	Enemy(const class Game& mygame);
	~Enemy();
};