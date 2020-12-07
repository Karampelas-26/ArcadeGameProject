#pragma once
#include <iostream>
#include <string>
#include <graphics.h>
#include <scancodes.h>

class Object {
	float radius;
	int center_x;
	int center_y;
	graphics::Brush br;
public:
	Object();//default constructor 
	void update();//function update
	~Object();//destructor
	void draw(float center_x, float center_y);
	void collision(float radius);
	int getCenter_x();
	int getCenter_y();
	void setCenter_x(int center_x);
	void setCenter_y(int center_y);
};
