#pragma once
#include <iostream>
#include <string>
#include <scancodes.h>
#include <graphics.h>

class Map {
	//int width;
	//int height;
	//graphics::Brush br;

public:
	Map();//default constructor
	//Map(int width, int height,graphics::Brush br);//constructor
	~Map();//destructor
	void draw();//function draw
	void update();

};
	