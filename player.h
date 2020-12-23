#pragma once
#include "graphics.h"
#include "config.h"
#include "gameobject.h"
#include "bullet.h"
#include <list>




class Player : public GameObject , public Collidable
{
	int life = 10;
	int score = 0;
	float speed = 5.0f;
	float player_x = CANVAS_WIDTH / 2;
	float player_y = CANVAS_HEIGHT / 2;
	bool initializeEnemy = true;
	
	
	
public:
	Player(const class Game& mygame);
	void update() override;
	void draw() override;
	void init() override;
	float getPlayer_x();
	float getPlayer_y();
	~Player();
	Disk getCollisionHull() const override;
	void decreaseLife();
	void increaseScore();
	int getScore();
	bool isAlive();
};