#pragma once
#include "graphics.h"

class Background
{	
	float position_x;
	float position_y;
	float dimension_x;
	float dimension_y;
	float offset;
	graphics::Brush brush;
	

public:
	void draw(float offset);
	Background(float position_x, float position_y, float dimension_x, float dimension_y, graphics::Brush brush);
	~Background();



};

