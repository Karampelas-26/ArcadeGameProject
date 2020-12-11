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
	if (initializeEnemy && graphics::getGlobalTime() > 2000) {
		enemy = new Enemy();
		initializeEnemy = false;
		
	}
	if (enemy) {
		enemy->update();
	}
}


void Game::draw()
{
	//float offset = CANVAS_HEIGHT * fmodf((graphics::getDeltaTime() / 1000.0f),100)/2 ;
	//float offset = speed * graphics::getDeltaTime() / 180.0f;
	//float offset = graphics::getDeltaTime();
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSETS_PATH) + "water.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT /2, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	
	if (player)
	{
		player->draw();
	}
	if (enemy) 
	{
		enemy->draw();
	}
	//enemy->~Enemy();
}

void Game::init()
{
	//graphics::playMusic(std::string(ASSETS_PATH) + "music.mp3", 0.5f, true, 4000);
	//enemy->init();
}

Game::Game()
{
}

Game::~Game()
{
	delete player;
	delete enemy;
	//enemy->~Enemy();
}
