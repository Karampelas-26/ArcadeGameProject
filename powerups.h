#pragma once
#include "graphics.h"
#include "config.h"
#include "gameobject.h"
<<<<<<< HEAD
#include "player.h"
=======
>>>>>>> development

class PowerUps : public GameObject, public Collidable
{
	float speed = 10.0f;
	float position_x;
	float position_y;
	float timer;

public:
	void draw() override;
	void update() override;
	void init() override;
	PowerUps(const class Game& mygame, float position_x, float position_y);
	~PowerUps();
	bool i_am_not_valid_power_up();
<<<<<<< HEAD
	//bool extraPowerUp();
=======
>>>>>>> development
	Disk getCollisionHull() const override;
};