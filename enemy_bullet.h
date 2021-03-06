#pragma once
#include "graphics.h"
#include "config.h"
#include "gameobject.h"

class Enemybullet : public GameObject,public Collidable
{

	float speed = 5.0f;
	float enemy_bullet_start_x;
	float enemy_bullet_start_y;
public:
	bool im_a_valid_bullet();
	void draw() override;
	void update() override;
	void init() override;
	Enemybullet(const class Game& mygame, float enemy_bullet_start_x, float enemy_bullet_start_y);
	~Enemybullet();
	float getEnemybullet_start_y();
	Disk getCollisionHull() const override;
};