#include "enemy_bullet.h"

void Enemybullet::draw()
{

	graphics::Brush br;
	br.texture = std::string(ASSETS_PATH) + "enemy_bullet.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(enemy_bullet_start_x, enemy_bullet_start_y, 40, 50, br);
}

void Enemybullet::update()
{
	enemy_bullet_start_y += speed * graphics::getDeltaTime() / 1.0f;

}

void Enemybullet::init()
{
}

Enemybullet::Enemybullet(float enemy_bullet_start_x, float enemy_bullet_start_y)
{
	this->enemy_bullet_start_x = enemy_bullet_start_x;
	this->enemy_bullet_start_y = enemy_bullet_start_y;
}

Enemybullet::~Enemybullet()
{
}

float Enemybullet::getEnemybullet_start_y()
{
	return enemy_bullet_start_y;
}
