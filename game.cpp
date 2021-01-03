#include "game.h"
#include "config.h"
#include "utils.h"
#include <iostream>



void Game::update()
{
	if (status == STATUS_START) {

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
			bullets.push_back((*new Bullet(*this, player->getPlayer_x(), player->getPlayer_y(), powerUpActive)));
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
}

void Game::draw()
{
	//float offset = CANVAS_HEIGHT * sinf(graphics::getDeltaTime() / 1000.0f) / 4;
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSETS_PATH) + "water.png";
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT /2 , CANVAS_WIDTH, CANVAS_HEIGHT, br);

	if (initializeEnemy && graphics::getGlobalTime() > 2000) {
		enemy = new Enemy((*this));
		initializeEnemy = false;

	}
	if (enemy) {
		enemy->update();
		if (enemy->enemyisActive()) {
			deleteEnemy();
		}
		//enemy bullet
		if (initializeEnemyBullet) {
			if (enemy->Foo()) {
				enemybullets.push_back((*new Enemybullet(*this, enemy->getEnemy_x(), enemy->getEnemy_y())));
				initializeEnemyBullet = false;
			}
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
			effect = new Effects(*this, enemy->getEnemy_x(), enemy->getEnemy_y());
			ableEffect = true;
			timeEffect = graphics::getGlobalTime();
			deleteEnemy();
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
	if (enemy && !bullets.empty()) {
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
				enemybullets.erase(i++);  // alternatively, i = items.erase(i);
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
					//enemybullets.erase(i++);
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
		//std::cout << "power up is here\n";
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


<<<<<<< HEAD
=======
	/*if (bgList.empty())
	{
		bgList.push_back(*(new Background(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT,br)));
		bgList.push_back(*(new Background(CANVAS_WIDTH / 2, -CANVAS_HEIGHT / 2, CANVAS_WIDTH, CANVAS_HEIGHT,br)));
	}
	if (!bgList.empty()) 
	{
		std::list<Background>::iterator i = bgList.begin();
		while (i != bgList.end())
		{
			i->draw(offset);
			++i;
		}
	}*/
	
	/*if (background)
		background->draw(offset);*/
>>>>>>> d9df9bcefec80105228c248bbf09f84d2d3d0fed
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
<<<<<<< HEAD

	if (enemy)
=======
	if (enemy) 
>>>>>>> d9df9bcefec80105228c248bbf09f84d2d3d0fed
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


bool Game::checkCollision(Disk disk1,Disk disk2)
{	
	float dx = pow(disk1.dx - disk2.dx, 2);
	float dy = pow(disk1.dy - disk2.dy, 2);

	if (sqrt(dx + dy) < disk1.radius + disk2.radius)
		return true;
	else
		return false;
}



void Game::deleteEnemy()
{
	if (player && player->getScore() == 10) {
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
	//graphics::playMusic(std::string(ASSETS_PATH) + "music.mp3", 0.05f, true, 4000);
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
<<<<<<< HEAD
	delete powerUp;
	powerUp = nullptr;
	delete effect;
	effect = nullptr;
=======
>>>>>>> d9df9bcefec80105228c248bbf09f84d2d3d0fed
}
