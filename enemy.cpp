#include <iostream>
#include "enemy.h"
#include "config.h"
#include "math.h"

	


void Enemy::update()
{
		enemy_y += speed * graphics::getDeltaTime() / 1000.0f;
		//int time = (int) graphics::getGlobalTime();
		//int fireRate = time % 500;
		//float offset = 0.5f + 0.5f * sinf(graphics::getGlobalTime() / 10);
		//if (fireRate == 0)
		//	enemybullets.push_back((*new Enemybullet(enemy_x, enemy_y)));

		//if (!enemybullets.empty())
		//{
		//	std::list<Enemybullet>::iterator i = enemybullets.begin();
		//	while (i != enemybullets.end())
		//	{

		//		if (i->im_a_valid_bullet())
		//		{
		//			enemybullets.erase(i++);  // alternatively, i = items.erase(i);
		//		}
		//		else
		//		{
		//			i->update();
		//			++i;
		//		}
		//	}
		//}
		
}

bool Enemy::enemyisActive()
{
	return enemy_y < 0;
}

void Enemy::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSETS_PATH) + "enemy.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(enemy_x, enemy_y, 50, 60, br);
	/*if (!enemybullets.empty())
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

	}*/

	graphics::Brush brush;
	brush.fill_color[0] = 1.0f;
	brush.fill_color[1] = 0.3f;
	brush.fill_color[2] = 0.3f;
	brush.fill_opacity = 0.5f;
	graphics::drawDisk(enemy_x, enemy_y, 30.0f, brush);
}

void Enemy::init()
{
	enemy_x = float(rand() % CANVAS_WIDTH);
}

float Enemy::getEnemy_x()
{
	return enemy_x;
}

float Enemy::getEnemy_y()
{
	return enemy_y;
}

Enemy::Enemy(const  Game& mygame)
	:GameObject(mygame)
{
	init();
}

Enemy::~Enemy()
{
}

Disk Enemy::getCollisionHull() const
{
	Disk disk;
	disk.dx = enemy_x;
	disk.dy = enemy_y;
	disk.radius = 30.0f;
	return disk;
}
