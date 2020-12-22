#include <iostream>
#include "player.h"
#include "config.h"
#include "game.h"

Player::Player(const Game& mygame)
	:GameObject(mygame)
{
}

void Player::update()
{
	
	if (graphics::getKeyState(graphics::SCANCODE_W))
	{
		player_y -= speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_A))
	{
		player_x -= speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_S))
	{
		player_y += speed * graphics::getDeltaTime() / 10.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_D))
	{
		player_x += speed * graphics::getDeltaTime() / 10.0f;
	}
	
	//if (mouse.button_left_released)
	//{
	//	bullets.push_back((*new Bullet(, player_x, player_y)));
	//	
	//}
	//if (!bullets.empty())
	//{
	//	std::list<Bullet>::iterator i = bullets.begin();
	//	while (i != bullets.end())
	//	{
	//		
	//		if (i->im_a_valid_bullet())
	//		{
	//			bullets.erase(i++);  // alternatively, i = items.erase(i);
	//		}
	//		else
	//		{
	//			i->update();
	//			++i;
	//		}
	//	}
	//}
	
	
	
	

	if (player_x < 0)
	{
		player_x = 0;
	}
	if (player_x > CANVAS_WIDTH)
	{
		player_x = CANVAS_WIDTH;
	}
	if (player_y < 0)
	{
		player_y = 0;
	}
	if (player_y > CANVAS_HEIGHT)
	{
		player_y = CANVAS_HEIGHT;
	}

}

void Player::draw()
{
	graphics::Brush br;
	br.outline_opacity = 0.0f;
	br.texture = std::string(ASSETS_PATH) + "airplane.png";
	graphics::drawRect(player_x, player_y, 80, 55, br);


	/*if (!bullets.empty())
	{
		for (std::list<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it)
		{
			it->draw();
			
		}
	}*/
	graphics::Brush brush;
	brush.fill_color[0] = 0.3f;
	brush.fill_color[1] = 1.0f;
	brush.fill_color[2] = 0.3f;
	brush.fill_opacity = 0.5f;
	graphics::drawDisk(player_x, player_y, 30.0f, brush);
	
}

void Player::init()
{
}

float Player::getPlayer_x()
{
	return player_x;
}

float Player::getPlayer_y()
{
	return player_y;
}

Player::~Player()
{
}

Disk Player::getCollisionHull() const
{
	Disk disk;
	disk.dx = player_x;
	disk.dy = player_y;
	disk.radius = 30.0f;
	return disk;
}
