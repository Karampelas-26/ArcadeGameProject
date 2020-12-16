//#include <iostream>
//#include "enemy.h"
//#include "config.h"
//#include "math.h"
//	
//
//
//void Enemy::update()
//{
//		enemy_x += speed * graphics::getDeltaTime() / 1000.0f;
//		int time = (int) graphics::getGlobalTime();
//		int fireRate = time % 500;
//		float offset = 0.5f + 0.5f * sinf(graphics::getGlobalTime() / 10);
//		if (fireRate == 0)
//			enemybullets.push_back((*new Enemybullet(enemy_x, enemy_y)));
//
//		if (!enemybullets.empty())
//		{
//			std::list<Enemybullet>::iterator i = enemybullets.begin();
//			while (i != enemybullets.end())
//			{
//
//				if (i->im_a_valid_bullet())
//				{
//					enemybullets.erase(i++);  // alternatively, i = items.erase(i);
//				}
//				else
//				{
//					i->update();
//					++i;
//				}
//			}
//		}
//		if (enemy_x > CANVAS_WIDTH) {
//			enemy_x = 0.0f;
//		}
//}
//
//bool Enemy::enemyisActive()
//{
//	return true;
//}
//
//void Enemy::draw()
//{
//	graphics::Brush br;
//	br.texture = std::string(ASSETS_PATH) + "enemy.png";
//	br.outline_opacity = 0.0f;
//	graphics::drawRect(enemy_x, enemy_y, 50, 60, br);
//	if (!enemybullets.empty())
//	{
//		std::list<Enemybullet>::iterator i = enemybullets.begin();
//		while (i != enemybullets.end())
//		{
//
//			if (i->im_a_valid_bullet())
//			{
//				enemybullets.erase(i++); 
//			}
//			else
//			{
//				i->draw();
//				++i;
//			}
//		}
//
//	}
//}
//
//void Enemy::init()
//{
//	
//}
//
//float Enemy::getEnemy_x()
//{
//	return enemy_x;
//}
//
//float Enemy::getEnemy_y()
//{
//	return enemy_y;
//}
//
//Enemy::Enemy()
//{
//	init();
//}
//
//Enemy::~Enemy()
//{
//	//delete[] & enemybullets;
//}
