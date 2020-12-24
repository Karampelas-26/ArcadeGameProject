#include "effects.h"
#include "graphics.h"
#include "config.h"

void Effects::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.4f;
	br.texture = std::string(ASSETS_PATH) + "explosion.png";
	graphics::drawRect(cordinates_x, cordinates_y, 30.0f, 30.0f, br);
}

void Effects::update()
{
}

void Effects::init()
{
}

Effects::Effects(const class Game& mygame, float cordinates_x, float cordinates_y)
	:GameObject(mygame)
{
	this->cordinates_x = cordinates_x;
	this->cordinates_y = cordinates_y;
}

Effects::~Effects()
{
}
