#include <iostream>
#include "player.h"
#include "config.h"


void Player::update()
{
	graphics::MouseState mouse;
	graphics::getMouseState(mouse);
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
	
	if (mouse.button_left_released)
	{
		bullets.push_back((*new Bullet(player_x, player_y)));
		
	}
	if (!bullets.empty())
	{
		/*for (std::list<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it)
		{
			it->update();
			if(it->im_a_valid_bullet())
				it = bullets.erase(it);
			
		}*/

		std::list<Bullet>::iterator i = bullets.begin();
		while (i != bullets.end())
		{
			
			if (i->im_a_valid_bullet())
			{
				bullets.erase(i++);  // alternatively, i = items.erase(i);
			}
			else
			{
				i->update();
				++i;
			}
		}

	}
	
	
	
	

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
	graphics::drawRect(player_x, player_y, 160, 110, br);

	if (!bullets.empty())
	{
		for (std::list<Bullet>::iterator it = bullets.begin(); it != bullets.end(); ++it)
		{
			it->draw();
			
		}
	}
	
}

void Player::init()
{
}

Player::Player()
{
}

Player::~Player()
{
}
