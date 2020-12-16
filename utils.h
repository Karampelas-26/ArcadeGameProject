#pragma once

struct Disk{
	float dx;
	float dy;
	float radius;
	bool collission(Disk &disk);
public:
	Disk(float dx,float dy,float radius);
};
		
