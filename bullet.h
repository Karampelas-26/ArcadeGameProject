#pragma once
#include "graphics.h"
#include "config.h"
#include "gameobject.h"

class Bullet : public GameObject
{

	float speed = 10;
	float bullet_start_x;
	float bullet_start_y;
public:
<<<<<<< HEAD
=======
	bool im_a_valid_bullet();
>>>>>>> remotes/origin/development
	void draw() override;
	void update() override;
	void init() override;
	Bullet(float bullet_start_x, float bullet_start_y);
	~Bullet();
	float getBullet_start_y();
};