#include "game.h"
#include "config.h"
#include "utils.h"
#include <iostream>



void Game::update()
{
	graphics::MouseState mouse;
	graphics::getMouseState(mouse);

	if (initializePlayer)
	{
		player = new Player(*this);
		initializePlayer = false;
	}
	if (player)
	{
		player->update();

		if (mouse.button_left_released)
		{
			bullets.push_back((*new Bullet(*this, player->getPlayer_x(), player->getPlayer_y())));
		}
		if (!bullets.empty())
		{
			std::list<Bullet>::iterator i = bullets.begin();
			while (i != bullets.end())
			{

				if (i->im_a_valid_bullet())
				{
					bullets.erase(i++);  // alternatively, i = items.erase(i);
				}
				else
				{
					i->update();
					++i;
				}
			}
		}
	}


	if (initializeEnemy && graphics::getGlobalTime() > 2000) {
		enemy = new Enemy((*this));
		initializeEnemy = false;
		
	}
	if (enemy) {
		enemy->update();
	}

	if (checkCollision()) {
		delete enemy;
		enemy = nullptr;
		initializeEnemy = true;
	}

}	


bool Game::checkCollision()
{
	if (!player || !enemy) {
		return false;
	}
	Disk player_disk = player->getCollisionHull();
	Disk enemy_disk = enemy->getCollisionHull();
	
	float dx = pow(player_disk.dx - enemy_disk.dx, 2);
	float dy = pow(player_disk.dy - enemy_disk.dy, 2);

	if (sqrt(dx + dy) < player_disk.radius + enemy_disk.radius)
		return true;
	else
		return false;
}

void Game::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSETS_PATH) + "water.png";
	
	float offset = CANVAS_HEIGHT * fmodf(graphics::getGlobalTime()/100.0f,80.0f)/800.0f;
	
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2 + offset, CANVAS_HEIGHT, CANVAS_HEIGHT*2, br);
	
	if (player)
	{
		player->draw();

		if (!bullets.empty())
		{
			for (std::list<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it)
			{
				it->draw();

			}
		}
	}

	if (enemy) 
	{
		enemy->draw();
	}

	
}

void Game::init()
{
	//graphics::playMusic(std::string(ASSETS_PATH) + "music.mp3", 0.3f, true, 4000);
	graphics::setFont(std::string(ASSETS_PATH) + "font.ttf");
}

Game::Game()
{
}

Game::~Game()
{
	delete player;
	player = nullptr;
	delete enemy;
	enemy = nullptr;
	//enemy->~Enemy();
}
