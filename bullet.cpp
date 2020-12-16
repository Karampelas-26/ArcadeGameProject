#include "bullet.h"

bool Bullet::im_a_valid_bullet()
{
	
	return bullet_start_y < -50; //legit it is working
}

void Bullet::draw()
{

	graphics::Brush br;
	br.texture = std::string(ASSETS_PATH) + "bullet.png";
	br.outline_opacity = 0.0f;
	graphics::drawRect(bullet_start_x, bullet_start_y - 40, 20, 25, br);
}

void Bullet::update()
{
	bullet_start_y -= speed * graphics::getDeltaTime() / 10.0f;
	
}

void Bullet::init()
{
}

//Bullet::Bullet(float bullet_start_x, float bullet_start_y)
//{
//	this->bullet_start_x = bullet_start_x;
//	this->bullet_start_y = bullet_start_y;
//}

Bullet::Bullet(const Game& mygame, float bullet_start_x, float bullet_start_y)
	:GameObject(mygame)
{
	this->bullet_start_x = bullet_start_x;
	this->bullet_start_y = bullet_start_y;
}

Bullet::~Bullet()
{
}

float Bullet::getBullet_start_y()
{
	return bullet_start_y;
}
