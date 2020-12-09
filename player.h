#pragma once
#include "graphics.h"
#include "config.h"
#include "gameobject.h"
#include "bullet.h"
#include <vector>

class Player : public GameObject
{

	float speed = 10.0f;
	float player_x = CANVAS_WIDTH / 2;
	float player_y = CANVAS_HEIGHT / 2;
	std::vector<Bullet> bullets;
	
	
public:
	void update() override;
	void draw() override;
	void init() override;
	Player();
	~Player();
};