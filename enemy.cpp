#include <iostream>
#include "enemy.h"
#include "config.h"



void Enemy::update()
{
		enemy_y += speed * graphics::getDeltaTime() / 1000.0f;

		enemybullets.push_back((*new Enemybullet(enemy_x, enemy_y)));

		if (!enemybullets.empty())
		{
			for (std::vector<Enemybullet>::iterator it = enemybullets.begin(); it != enemybullets.end(); ++it)
			{
				//enemybullets.erase(enemybullets.begin());

				(*it).update();
			}
			
		}
		
}
void Enemy::draw()
{
	graphics::Brush br;
	br.texture = std::string(ASSETS_PATH) + "enemy.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(enemy_x, enemy_y, 50, 60, br);
	if (!enemybullets.empty())
	{
		for (std::vector<Enemybullet>::iterator it = enemybullets.begin(); it != enemybullets.end(); ++it)
		{
			(*it).draw();
			
		}
		//enemybullets.erase(enemybullets.begin());
	}
	//enemybullets.erase(enemybullets.begin());
}

void Enemy::init()
{
}

Enemy::Enemy()
{
	
}

Enemy::~Enemy()
{
	//delete[] & enemybullets;
}
