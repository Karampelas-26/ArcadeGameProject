#pragma once
#include "graphics.h"
#include "config.h"
#include "gameobject.h"
#include "player.h"

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
	//bool extraPowerUp();
	Disk getCollisionHull() const override;
};