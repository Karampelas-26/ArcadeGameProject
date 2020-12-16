#pragma once
#include "graphics.h"
#include "config.h"
#include "gameobject.h"
#include "bullet.h"
#include <list>




class Player : public GameObject
{

	float speed = 5.0f;
	float player_x = CANVAS_WIDTH / 2;
	float player_y = CANVAS_HEIGHT / 2;
	/*std::list<Bullet> bullets;*/
	bool initializeEnemy = true;
	/*Enemy* enemy = nullptr;*/
	
	
public:
	Player(const class Game& mygame);
	void update() override;
	void draw() override;
	void init() override;
	float getPlayer_x();
	float getPlayer_y();
	~Player();
};