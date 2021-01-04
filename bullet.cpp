#include "bullet.h"

bool Bullet::im_a_valid_bullet()
{
	
	return bullet_start_y < -50; 
}

void Bullet::draw()
{
	if (!powerUpMode)
	{
		graphics::Brush br;
		br.texture = std::string(ASSETS_PATH) + "bullet.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(bullet_start_x, bullet_start_y , 20, 25, br);
	}
	else
	{
		graphics::Brush br1;
		br1.texture = std::string(ASSETS_PATH) + "bullet.png";
		br1.outline_opacity = 0.0f;
		graphics::drawRect(bullet_start_x-5, bullet_start_y , 20, 25, br1);

		graphics::Brush br;
		br.texture = std::string(ASSETS_PATH) + "bullet.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(bullet_start_x + 5, bullet_start_y, 20, 25, br);
	}
}

void Bullet::update()
{
	bullet_start_y -= speed * graphics::getDeltaTime() / 100.0f;	
}

void Bullet::init()
{
}


Bullet::Bullet(const Game& mygame, float bullet_start_x, float bullet_start_y,bool powerUpMode)
	:GameObject(mygame)
{
	this->bullet_start_x = bullet_start_x;
	this->bullet_start_y = bullet_start_y;
	this->powerUpMode = powerUpMode;
}

Bullet::~Bullet()
{
}

float Bullet::getBullet_start_y()
{
	return bullet_start_y;
}

Disk Bullet::getCollisionHull() const
{
	if (!powerUpMode) 
	{
		Disk disk;
		disk.dx = bullet_start_x;
		disk.dy = bullet_start_y;
		disk.radius = 10.0f;
		return disk;
	}
	else 
	{
		Disk disk;
		disk.dx = bullet_start_x;
		disk.dy = bullet_start_y;
		disk.radius = 13.0f;
		return disk;
	}
}

void Bullet::enablePowerUp()
{
	powerUpMode = true;
}
