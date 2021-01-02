#include "enemy_bullet.h"

void Enemybullet::draw()
{

	graphics::Brush br;
	br.texture = std::string(ASSETS_PATH) + "enemy_bullet.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(enemy_bullet_start_x, enemy_bullet_start_y, 20, 25, br);

	//draw disk of collision
	graphics::Brush brush;
	brush.fill_color[0] = 0.3f;
	brush.fill_color[1] = 0.3f;
	brush.fill_color[2] = 1.0f;
	brush.fill_opacity = 0.5f;
	graphics::drawDisk(enemy_bullet_start_x, enemy_bullet_start_y, 10.0f, brush);
}

void Enemybullet::update()
{
	enemy_bullet_start_y += 2 *speed * graphics::getDeltaTime() / 100.0f;

}

void Enemybullet::init()
{
}

bool Enemybullet::im_a_valid_bullet()
{
	return enemy_bullet_start_y > CANVAS_HEIGHT - 50;
}

Enemybullet::Enemybullet(const class Game& mygame, float enemy_bullet_start_x, float enemy_bullet_start_y)
	:GameObject(mygame) 
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

Disk Enemybullet::getCollisionHull() const
{
	Disk disk;
	disk.dx = enemy_bullet_start_x;
	disk.dy = enemy_bullet_start_y;
	disk.radius = 10.0f;
	return disk;
}