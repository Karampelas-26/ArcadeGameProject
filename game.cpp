#include "game.h"
#include "config.h"
#include "player.h"


void Game::update()
{
	if (initializePlayer)
	{
		player = new Player();
		initializePlayer = false;
	}
	if (player)
	{
		player->update();
	}
	
	
}

void Game::draw()
{
	//float offset = CANVAS_HEIGHT * sinf(graphics::getDeltaTime() / 1000.0f) / 4;
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSETS_PATH) + "water.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT /2 , CANVAS_WIDTH, CANVAS_HEIGHT, br);

	if (player)
	{
		player->draw();
	}
	


}

void Game::init()
{
}

Game::Game()
{
}

Game::~Game()
{
	delete player;
}
