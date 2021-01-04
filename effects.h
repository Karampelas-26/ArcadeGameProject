#pragma once
#include "gameobject.h"

class Effects : public GameObject
{
	float cordinates_x, cordinates_y;

public:
	void draw() override;
	void update() override;
	void init() override;
	Effects(const class Game& mygame, float cordinates_x,float cordinates_y);
	~Effects();
};
