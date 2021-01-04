﻿#include "game.h"
#include "config.h"
#include "utils.h"
#include <iostream>



void Game::update()
{
	if (status == STATUS_START)
	{

		updateStartScreen();
	}
	else if (status == STATUS_PLAYING)
	{
		updateLevelScreen();
	}
	else if (status == STATUS_END)
	{
		updateEndScreen();
	}
}




void Game::updateStartScreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		status = STATUS_PLAYING;
	}
}

void Game::updateLevelScreen()
{
	graphics::MouseState mouse;
	graphics::getMouseState(mouse);

	//initialize player if not exist
	if (initializePlayer)
	{
		player = new Player(*this);
		initializePlayer = false;
	}
	if (player)
	{
		player->update();

		//adding a bullet on list with click of mouse
		if (mouse.button_left_released)
		{
			bullets.push_back((*new Bullet(*this, player->getPlayer_x(), player->getPlayer_y(), powerUpActive)));
		}

		//update bullet or remove it if is not valid
		if (!bullets.empty())
		{
			std::list<Bullet>::iterator i = bullets.begin();
			while (i != bullets.end())
			{

				if (i->im_a_valid_bullet())
				{
					bullets.erase(i++);
				}
				else
				{
					i->update();
					++i;
				}
			}
		}
	}
	
	//initialiaze enemy if not exist
	if (initializeEnemy) 
	{
		enemy = new Enemy((*this));
		initializeEnemy = false;
	}

	//if enemy exist shoot once and add bullet on list
	if (enemy)
	{
		enemy->update();
		if (enemy->enemyisActive()) 
		{
			deleteEnemy();
		}

		//initialize enemy bullte if not exist
		if (initializeEnemyBullet) 
		{
			//check if enemy time initialize is able to shoot
			if (enemy->enableEnemy())
			{
				enemybullets.push_back((*new Enemybullet(*this, enemy->getEnemy_x(), enemy->getEnemy_y())));
				initializeEnemyBullet = false;
			}
		}

		//update the situation of bullet or remove it if is not valid
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
					i->update();
					++i;
				}
			}
		}
	}

	//check collisions enemy with player
	if (player && enemy) 
	{
		if (checkCollision(player->getCollisionHull(), enemy->getCollisionHull())) 
		{
			graphics::playSound(std::string(ASSETS_PATH) + "explosion.wav", 0.7f, false);
			effect = new Effects(*this, enemy->getEnemy_x(), enemy->getEnemy_y());
			ableEffect = true;
			timeEffect = graphics::getGlobalTime();
			deleteEnemy();

			//if player has no life delete him and update screen else decrease life 
			if (player->isAlive())
			{
				delete player;
				player = nullptr;
				status = STATUS_END;
			}
			else
			{
				player->decreaseLife();
				player->increaseScore();
			}
		}
	}

	//check collision each bullet with enemy
	if (enemy && !bullets.empty()) 
	{
		std::list<Bullet>::iterator i = bullets.begin();
		while (i != bullets.end())
		{
			if (enemy && checkCollision(enemy->getCollisionHull(), i->getCollisionHull()))
			{
				graphics::playSound(std::string(ASSETS_PATH) + "explosion.wav", 0.2f, false);
				effect = new Effects(*this, enemy->getEnemy_x(), enemy->getEnemy_y());
				ableEffect = true;
				timeEffect = graphics::getGlobalTime();
				deleteEnemy();
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
					effect = new Effects(*this, player->getPlayer_x(), player->getPlayer_y());
					ableEffect = true;
					timeEffect = graphics::getGlobalTime();
					delete player;
					player = nullptr;
					status = STATUS_END;

				}
				else
				{
					player->decreaseLife();
				}
				enemybullets.erase(i++); 
			}
			else
			{
				++i;
			}
		}
	}
	//collision enemy bullet with player bullet
	if (!bullets.empty() && !enemybullets.empty())
	{
		std::list<Bullet>::iterator j = bullets.begin();
		std::list<Enemybullet>::iterator i = enemybullets.begin();
		bool ereaser = false;
		while (i != enemybullets.end())
		{
			while (j != bullets.end())
			{
				if (checkCollision(j->getCollisionHull(), i->getCollisionHull()))
				{
					graphics::playSound(std::string(ASSETS_PATH) + "explosion.wav", 0.2f, false);
					bullets.erase(j++);
					ereaser = true;
					break;
				}
				else
				{
					++j;
					ereaser = false;
				}
			}
			if (ereaser)
			{
				enemybullets.erase(i++);
			}
			else
			{
				++i;
			}
		}
	}

	//upadate power up
	if (powerUp)
	{
		powerUp->update();

		if (player)
		{
			if (!powerUp->i_am_not_valid_power_up() && checkCollision(player->getCollisionHull(), powerUp->getCollisionHull()))
			{
				powerUpActive = true;
				delete powerUp;
				powerUp = nullptr;
				initializePowerUp = true;
			}
		}
	}
}

void Game::updateEndScreen()
{
	if (graphics::getKeyState(graphics::SCANCODE_RETURN))
	{
		status = STATUS_PLAYING;
	}
	else if (graphics::getKeyState(graphics::SCANCODE_ESCAPE))
	{
		exit(0);
	}
	if (!initializePlayer)
	{
		initializePlayer = true;
	}
	if (powerUpActive)
	{
		powerUpActive = false;
	}
	if (powerUp)
	{
		delete powerUp;
		powerUp = nullptr;
		initializePowerUp = true;
	}
	if (!bullets.empty())
	{
		bullets.clear();
	}
	if (!enemybullets.empty())
	{
		enemybullets.clear();
		initializeEnemyBullet = true;
	}
}

void Game::drawStartScreen()
{
	graphics::Brush br;
	br.fill_color[0] = 1.0f;
	char start_info[60];
	sprintf_s(start_info, "Press enter to start");
	graphics::drawText(70.0f, CANVAS_HEIGHT/2, 25.0f,start_info, br);
}

void Game::drawLevelScreen()
{
	//backgorund layer
	float offset = CANVAS_HEIGHT * fmodf(graphics::getGlobalTime() / 1000.0f, 10.0f) / 10.0f;

	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSETS_PATH) + "water.png";

	graphics::Brush br1;
	br1.outline_opacity = 1.0f;
	br1.fill_opacity = 0.5f;
	br1.texture = std::string(ASSETS_PATH) + "water.png";

	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2 + offset, CANVAS_WIDTH, CANVAS_HEIGHT, br);
	graphics::drawRect(CANVAS_WIDTH / 2, -CANVAS_HEIGHT / 2 + offset, CANVAS_WIDTH, CANVAS_HEIGHT, br);

	//player layer
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

	//enemy layer
	if (enemy)
	{
		enemy->draw();
	}

	//enemy bullet layer
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

	if (player) {
		//draw life points
		char score_info[40];
		sprintf_s(score_info, "Score: %d", player->getScore());

		graphics::Brush brush;
		brush.fill_color[0] = 1.0f;
		brush.fill_color[1] = 0.2f;
		brush.fill_color[2] = 0.2f;

		graphics::drawText(250.0f, 750.0f, 25.0f, score_info, brush);
		//draw life
		char life_info[40];
		sprintf_s(life_info, "Life points: %d", player->getLife());

		graphics::drawText(30.0f, 750.0f, 25.0f, life_info, brush);
	}
	//effect layer
	if (effect && ableEffect && graphics::getGlobalTime() - timeEffect < 250)
		effect->draw();
	else if (effect)
	{
		ableEffect = false;
		delete effect;
		effect = nullptr;
	}
	//power up layer
	if (powerUp || !initializePowerUp)
	{
		powerUp->draw();
	}
}

void Game::drawEndScreen()
{
	graphics::Brush br;
	br.fill_color[0] = 1.0f;
	char end_info1[60];
	sprintf_s(end_info1, "Press Enter to play again ");
	graphics::drawText(10.0f, CANVAS_HEIGHT / 2, 25.0f, end_info1, br); 
	char end_info2[60];
	sprintf_s(end_info2, "Or Esc to exit the game");
	graphics::drawText(20.0f, CANVAS_HEIGHT / 2 + 27.5f , 25.0f, end_info2, br);
}

//checking if two disk have collision
bool Game::checkCollision(Disk disk1,Disk disk2)
{	
	float dx = pow(disk1.dx - disk2.dx, 2);
	float dy = pow(disk1.dy - disk2.dy, 2);

	if (sqrt(dx + dy) < disk1.radius + disk2.radius)
		return true;
	else
		return false;
}


//delete enemy player and check if it can enable powerup
void Game::deleteEnemy()
{
	if (player && player->getScore() == 100) 
	{
		powerUp = new PowerUps(*this, enemy->getEnemy_x(), enemy->getEnemy_y());
		initializePowerUp = false;
	}
	delete enemy;
	enemy = nullptr;
	initializeEnemy = true;
}

void Game::draw()
{
	if (status == STATUS_START) {

		drawStartScreen();
	}
	else if (status == STATUS_PLAYING)
	{
		drawLevelScreen();
	}
	else
		drawEndScreen();
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
	delete powerUp;
	powerUp = nullptr;
	delete effect;
	effect = nullptr;
}