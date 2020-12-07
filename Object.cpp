#include <graphics.h>
#include <scancodes.h>
#include "Object.h"


Object::Object()
{
	
}

void Object::update()
{
	this->center_x++;
}	

Object::~Object()
{
	
}

void Object::draw(float center_x, float center_y)
{
	graphics::Brush br;
	br.fill_color[0] = 1.f;
	br.fill_color[1] = 0.5f;
	br.fill_color[2] = 0.3f;
	br.texture = "assets\\BlackShip.png";
	br.outline_opacity = 0.0f;
	graphics:drawDisk(center_x, center_y, 5.f, br);
}

void Object::collision(float radius)
{

}

int Object::getCenter_x()
{
	return center_x;
}

int Object::getCenter_y()
{
	return center_y;
}

void Object::setCenter_x(int center_x)
{
	this->center_x;
}

void Object::setCenter_y(int center_y)
{
	this->center_y;
}



