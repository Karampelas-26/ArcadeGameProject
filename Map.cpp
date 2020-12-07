#include "Map.h"


Map::Map()
{
}

/*Map::Map(int width, int height, graphics::Brush br)
{
	this->width = width;
	this->height = height;
	this->br = br;
}*/

Map::~Map()
{
}

void Map::draw()
{
	graphics::Brush br;
	br.texture = "assets\\waterr.png";
	br.outline_opacity = 0.0f;

	graphics::drawRect(750, 425, 1500, 850, br);
}

void Map::update()
{
}
