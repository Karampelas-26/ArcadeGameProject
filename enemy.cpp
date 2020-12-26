#include <iostream>
#include "enemy.h"
#include "config.h"
#include "math.h"
<<<<<<< HEAD
=======

>>>>>>> b76f72d6cadc3bf44460268df4724c264e934c84
	


void Enemy::update()
{
<<<<<<< HEAD
		enemy_x += speed * graphics::getDeltaTime() / 1000.0f;
		int time = (int) graphics::getGlobalTime();
		int fireRate = time % 500;
		float offset = 0.5f + 0.5f * sinf(graphics::getGlobalTime() / 10);
		if (fireRate == 0)
			enemybullets.push_back((*new Enemybullet(enemy_x, enemy_y)));

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
		if (enemy_x > CANVAS_WIDTH) {
			enemy_x = 0.0f;
		}
=======
		enemy_y += speed * graphics::getDeltaTime() / 1000.0f;	
>>>>>>> b76f72d6cadc3bf44460268df4724c264e934c84
}

bool Enemy::enemyisActive()
{
<<<<<<< HEAD
	return true;
=======
	return enemy_y < 0;
}

float Enemy::getFireRate()
{
	return  fmodf(graphics::getGlobalTime() / 1000.0f, 3.0f) ;
>>>>>>> b76f72d6cadc3bf44460268df4724c264e934c84
}

void Enemy::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSETS_PATH) + "enemy.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(enemy_x, enemy_y, 50, 60, br);
<<<<<<< HEAD
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
=======
	
	//draw disk of collision
	graphics::Brush brush;
	brush.fill_color[0] = 1.0f;
	brush.fill_color[1] = 0.3f;
	brush.fill_color[2] = 0.3f;
	brush.fill_opacity = 0.5f;
	graphics::drawDisk(enemy_x, enemy_y, 30.0f, brush);
>>>>>>> b76f72d6cadc3bf44460268df4724c264e934c84
}

void Enemy::init()
{
<<<<<<< HEAD
	
=======
	enemy_x = float(rand() % CANVAS_WIDTH);
>>>>>>> b76f72d6cadc3bf44460268df4724c264e934c84
}

float Enemy::getEnemy_x()
{
	return enemy_x;
}

float Enemy::getEnemy_y()
{
	return enemy_y;
}

<<<<<<< HEAD
Enemy::Enemy()
=======
Enemy::Enemy(const  Game& mygame)
	:GameObject(mygame)
>>>>>>> b76f72d6cadc3bf44460268df4724c264e934c84
{
	init();
}

Enemy::~Enemy()
{
<<<<<<< HEAD
	//delete[] & enemybullets;
}
=======
}

Disk Enemy::getCollisionHull() const
{
	Disk disk;
	disk.dx = enemy_x;
	disk.dy = enemy_y;
	disk.radius = 30.0f;
	return disk;
}


>>>>>>> b76f72d6cadc3bf44460268df4724c264e934c84
