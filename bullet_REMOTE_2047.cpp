#include "bullet.h"

bool Bullet::im_a_valid_bullet()
{
	
	return bullet_start_y < -50; //legit it is working
}

void Bullet::draw()
{
	if (!powerUpMode)
	{
		graphics::Brush br;
		br.texture = std::string(ASSETS_PATH) + "bullet.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(bullet_start_x, bullet_start_y - 15, 20, 25, br);

		//draw disk of collision
		graphics::Brush brush;
		brush.fill_color[0] = 0.3f;
		brush.fill_color[1] = 0.3f;
		brush.fill_color[2] = 1.0f;
		brush.fill_opacity = 0.5f;
		graphics::drawDisk(bullet_start_x, bullet_start_y, 10.0f, brush);
	}
	else
	{
		graphics::Brush br1;
		br1.texture = std::string(ASSETS_PATH) + "bullet.png";
		br1.outline_opacity = 0.0f;
		graphics::drawRect(bullet_start_x-5, bullet_start_y - 15, 20, 25, br1);

		//draw disk of collision
		graphics::Brush brush;
		brush.fill_color[0] = 0.3f;
		brush.fill_color[1] = 0.3f;
		brush.fill_color[2] = 1.0f;
		brush.fill_opacity = 0.5f;
		graphics::drawDisk(bullet_start_x-5, bullet_start_y, 10.0f, brush);

		graphics::Brush br;
		br.texture = std::string(ASSETS_PATH) + "bullet.png";
		br.outline_opacity = 0.0f;
		graphics::drawRect(bullet_start_x+5, bullet_start_y - 15, 20, 25, br);

		//draw disk of collision
		/*graphics::Brush brush;
		brush.fill_color[0] = 0.3f;
		brush.fill_color[1] = 0.3f;
		brush.fill_color[2] = 1.0f;
		brush.fill_opacity = 0.5f;*/
		graphics::drawDisk(bullet_start_x+5, bullet_start_y, 10.0f, brush);
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
	Disk disk;
	disk.dx = bullet_start_x;
	disk.dy = bullet_start_y;
	disk.radius = 10.0f;
	return disk;
}

void Bullet::enablePowerUp()
{
	powerUpMode = true;
}
