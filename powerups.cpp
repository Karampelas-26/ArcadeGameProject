#include "powerups.h"
#include "player.h"

void PowerUps::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSETS_PATH) + "powerup.png";
	graphics::drawRect(position_x, position_y, 40.0f, 40.0f, br);
}

void PowerUps::update()
{
	position_y += speed * graphics::getDeltaTime() / 100.0f;
}

void PowerUps::init()
{
}

PowerUps::PowerUps(const class Game& mygame, float position_x, float position_y)
	:GameObject(mygame)
{
	this->position_x = position_x; 
	this->position_y = position_y;
	this->timer = graphics::getGlobalTime();
}

PowerUps::~PowerUps()
{
}

bool PowerUps::i_am_not_valid_power_up()
{
	return position_y > CANVAS_HEIGHT + 50.0f; // || graphics::getGlobalTime() - timer < 2000.0f;
}


Disk PowerUps::getCollisionHull() const
{
	Disk disk;
	disk.dx = position_x;
	disk.dy = position_y;
	disk.radius = 20.0f;
	return disk;
}
