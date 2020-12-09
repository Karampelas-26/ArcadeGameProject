#pragma once
#include "graphics.h"
#include "player.h"

class Game
{
	
	Player* player = nullptr;
	bool initializePlayer = true;
public:
	void draw();
	void update();
	void init();
	Game();
	~Game();
	
};
