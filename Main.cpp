#include <iostream>
#include "include/graphics.h"
#include "include/scancodes.h"
#include "Map.h"
#include "Object.h"

static const std::string assets_path = "assets/";
struct Game
{
    int window_width = 1024;
    int window_height = 768;
    
    float canvas_width = 100.f;
    float canvas_height = 100.f;

    float airplane_center_x = 50.0f;
    float airplane_center_y = 50.0f;


    float airplane_speed = 0.5f;

    float spinner_angle = 0.0f;

    void init()
    {
        graphics::Brush br;
        br.fill_color[0] = 0.1;
        br.fill_color[1] = 0.1;
        br.fill_color[2] = 0.1;
        graphics::setWindowBackground(br);
        graphics::setFont(assets_path + "MontserratAlternates-Bold.otf");

        
    }
};

void update(float ms)
{

    Game* game = (Game*)graphics::getUserData(); 

    graphics::MouseState mouse;
    graphics::getMouseState(mouse);
    if (mouse.button_left_released)
    {
        graphics::playSound("assets\\EXPLOSION_Short_Messy_stereo.wav", 1.0f, false);
    }
    if (graphics::getKeyState(graphics::SCANCODE_W))
    {
        game->airplane_center_y -= 0.5f;
    }
    if (graphics::getKeyState(graphics::SCANCODE_S))
    {
        game->airplane_center_y += 0.5f;
    }
    if (graphics::getKeyState(graphics::SCANCODE_A))
    {
        game->airplane_center_x -= 0.5f;
    }
    if (graphics::getKeyState(graphics::SCANCODE_D))
    {
        game->airplane_center_x += 0.5f;
    }
    
}


void drawPlane()
{
    Game* game = (Game*)graphics::getUserData();

    graphics::Brush br;
    br.fill_color[0] = 1.0f; 
    br.fill_color[0] = 0.0f;
    br.fill_color[0] = 02.0f;
    br.fill_opacity = 0.5f;
    br.outline_opacity = 0.0f;
    br.texture = assets_path + "BlackShip.png";
    graphics::drawRect(game->airplane_center_x, game->airplane_center_y, 1, 2, br);
}

void draw()
{
    drawPlane();
}

int main() {
    Game game;

    graphics::createWindow(game.window_height, game.window_height, "1942 Arcade Game");

    graphics::setUserData(&game);
    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(game.canvas_width, game.canvas_height);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);

    graphics::startMessageLoop();
	return 0;
}