#include <iostream>
#include "enemy.h"
#include "config.h"
#include "math.h"


void Enemy::update()
{
		enemy_y += 2 *speed * graphics::getDeltaTime() / 1000.0f;	
}

bool Enemy::enemyisActive()
{
	return enemy_y > CANVAS_HEIGHT + 50.0f;
}

float Enemy::getFireRate()
{
	return  fmodf(graphics::getGlobalTime() / 1000.0f, 3.0f) ;
}

void Enemy::draw()
{
		graphics::Brush br;
		br.texture = std::string(ASSETS_PATH) + "enemy.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(enemy_x, enemy_y, 50, 60, br);

		//draw disk of collision
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
	timer = graphics::getGlobalTime();
}

bool Enemy::Foo() 
{
	return graphics::getGlobalTime() - timer > 2000;
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


