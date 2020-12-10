#pragma once
#include "graphics.h"
#include "config.h"
#include "gameobject.h"

class Enemybullet : public GameObject
{

	float speed = 5.0f;
	float enemy_bullet_start_x;
	float enemy_bullet_start_y;
public:
	void draw() override;
	void update() override;
	void init() override;
	Enemybullet(float enemy_bullet_start_x, float enemy_bullet_start_y);
	~Enemybullet();
	float getEnemybullet_start_y();
};