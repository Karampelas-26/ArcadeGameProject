#include "game.h"
#include "config.h"
#include "player.h"
#include "utils.h"
#include <iostream>


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
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSETS_PATH) + "water.png";
	
	float offset = 10.0f + 0.5f * sinf(graphics::getGlobalTime() / 10000.0f);
	//std::cout << offset << std::endl;
	/*float height = offset;
	if(height > CANVAS_HEIGHT)
	{
		height = 0;
	}
	height -= 0;*/
	/*if (CANVAS_HEIGHT / 2 + offset() > CANVAS_HEIGHT)
	{
		height = CANVAS_HEIGHT / 2;
		//std::cout << "if" << height << std::endl;
	}
	else {
		height = CANVAS_HEIGHT / 2 + offset();
		//std::cout << "else" << height << std::endl;
	}*/
	graphics::drawRect(CANVAS_WIDTH / 2,CANVAS_HEIGHT / 2 + offset, CANVAS_WIDTH,CANVAS_HEIGHT, br);
	
	if (player)
	{
		player->draw();
	}
	if (enemy) 
	{
		enemy->draw();
	}
}

void Game::init()
{
	//graphics::playMusic(std::string(ASSETS_PATH) + "music.mp3", 0.5f, true, 4000);
	
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
