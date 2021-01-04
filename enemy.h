#pragma once
#include "graphics.h"
#include "config.h"
#include "gameobject.h"
#include "enemy_bullet.h"
#include <list>

class Enemy : public GameObject , public Collidable
{
	float speed = 22.0f;
	float enemy_x;
	float enemy_y = 0.0f;
	float fireRate;
	float timer;

public:
	float getFireRate();
	bool enemyisActive();
	void draw() override;
	void update() override;
	void init() override;
	float getEnemy_x();
	float getEnemy_y();
	Enemy(const class Game& mygame);
	~Enemy();
	Disk getCollisionHull() const override;
	bool enableEnemy();
};