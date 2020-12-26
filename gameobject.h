#pragma once
#include "utils.h"

class Collidable
{
<<<<<<< HEAD
=======
public:
>>>>>>> b76f72d6cadc3bf44460268df4724c264e934c84
	virtual Disk getCollisionHull() const = 0;
};

class GameObject
{
protected:
	const class Game& game;
public:
	GameObject(const class Game& mygame);
	virtual void update() = 0;
	virtual void draw() = 0;
	virtual void init() = 0;
};
