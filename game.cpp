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

		//enemy bullet
		if (initializeEnemyBullet) {
			enemybullets.push_back((*new Enemybullet(*this, enemy->getEnemy_x(), enemy->getEnemy_y())));
			initializeEnemyBullet = false;
		}
		if (!enemybullets.empty())
		{
			std::list<Enemybullet>::iterator i = enemybullets.begin();
			while (i != enemybullets.end())
			{

				if (i->im_a_valid_bullet())
				{
					enemybullets.erase(i++);  // alternatively, i = items.erase(i);
				}
				else
				{
					i->update();
					++i;
				}
			}
		}
	}
	//check collisions enemy with player
	if (player && enemy) {
		if (checkCollision(player->getCollisionHull(), enemy->getCollisionHull())) {
			graphics::playSound(std::string(ASSETS_PATH) + "explosion.wav", 0.7f, false);
			Effects* effect = new Effects(*this,enemy->getEnemy_x(), enemy->getEnemy_y());
			delete enemy;
			enemy = nullptr;
			initializeEnemy = true;
			if (player->isAlive())
			{
				delete player;
				player = nullptr;
				initializePlayer = true;

			}
			else
			{
				player->decreaseLife();
			}
		}
	}
	//check collision each bullet with enemy
	if (enemy && !bullets.empty()) {
		std::list<Bullet>::iterator i = bullets.begin();
		while (i != bullets.end())
		{

			if (enemy && checkCollision(enemy->getCollisionHull(), i->getCollisionHull()))
			{
				graphics::playSound(std::string(ASSETS_PATH) + "explosion.wav", 0.2f, false);
				delete enemy;
				enemy = nullptr;
				initializeEnemy = true;
				initializeEnemyBullet = true;
				player->increaseScore();
				bullets.erase(i++);
			}
			else {
				++i;
			}
		}
	}
	//check enemy bullet collision wit player
	if (player && !enemybullets.empty()) {
		std::list<Enemybullet>::iterator i = enemybullets.begin();
		while (i != enemybullets.end())
		{

			if (player && checkCollision(player->getCollisionHull(), i->getCollisionHull()))
			{
				graphics::playSound(std::string(ASSETS_PATH) + "explosion.wav", 0.2f, false);
				if (player->isAlive()) 
				{
					delete player;
					player = nullptr;
					initializePlayer = true;
					
				}
				else
				{
					player->decreaseLife();
				}
				enemybullets.erase(i++);  // alternatively, i = items.erase(i);
			}
			else
			{
				++i;
			}
		}
	}
}	


bool Game::checkCollision(Disk disk1,Disk disk2)
{	
	float dx = pow(disk1.dx - disk2.dx, 2);
	float dy = pow(disk1.dy - disk2.dy, 2);

	if (sqrt(dx + dy) < disk1.radius + disk2.radius)
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
	//enemy bullet
	if (!enemybullets.empty())
	{
		std::list<Enemybullet>::iterator i = enemybullets.begin();
		while (i != enemybullets.end())
		{
			if (i->im_a_valid_bullet())
			{
				enemybullets.erase(i++);
			}
			else
			{
				i->draw();
				++i;
			}
		}
	}
	//draw life points
	if (player) {
		char str[40];
		sprintf_s(str, "Score: %d", player->getScore());

		graphics::Brush brush;
		brush.fill_color[0] = 1.0f;
		brush.fill_color[1] = 0.2f;
		brush.fill_color[2] = 0.2f;

		graphics::drawText(250.0f, 750.0f, 25.0f, str, brush);
	}

	if (effect) {
	
		effect->draw();
	}
}

void Game::init()
{
	graphics::playMusic(std::string(ASSETS_PATH) + "music.mp3", 0.05f, true, 4000);
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
