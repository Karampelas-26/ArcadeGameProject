#pragma once
#include "graphics.h"
#include "config.h"
#include "gameobject.h"


class Bullet : public GameObject, public Collidable {

	float speed = 10.0f;
	float bullet_start_x;
	float bullet_start_y;
	bool powerUpMode;
public:
	bool im_a_valid_bullet();
	void draw() override;
	void update() override;
	void init() override;
	//Bullet(float bullet_start_x, float bullet_start_y);
	Bullet(const class Game& mygame, float bullet_start_x, float bullet_start_y, bool powerUpMode);
	~Bullet();
	float getBullet_start_y();
	Disk getCollisionHull() const override;
	void enablePowerUp();
};