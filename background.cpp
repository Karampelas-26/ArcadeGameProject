#include "background.h"
#include "config.h"

void Background::draw(float offset)
{
	/*graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSETS_PATH) + "water.png";*/

	
	graphics::drawRect(position_x, position_y + offset, dimension_x, dimension_y, brush);
}

Background::Background(float position_x, float position_y, float dimension_x, float dimension_y, graphics::Brush brush)
{
	this->position_x = position_x;
	this->position_y = position_y;
	this->dimension_x = dimension_x;
	this->dimension_y = dimension_y;
	this->brush = brush;
}	

Background::~Background()
{
}
