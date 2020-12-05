#include <iostream>
#include "include/graphics.h"
#include "include/scancodes.h"

void update(float ms)
{
    graphics::MouseState mouse;
    graphics::getMouseState(mouse);
    if (mouse.button_left_released)
    {
        graphics::playSound("assets\\EXPLOSION_Short_Messy_stereo.wav", 1.0f, false);
    }
}

void drawWater()
{
    graphics::Brush br;
    br.texture = "assets\\waterr.png";
    br.outline_opacity = 0.0f;

    graphics::drawRect(750, 425, 1500, 850, br);

}


void drawPlane()
{
    graphics::Brush br;

    graphics::setOrientation(180);

    br.texture = "assets\\BlackShip.png";
    br.outline_opacity = 0.0f;

    graphics::drawRect(500, 250, 200, 200, br);

    br.fill_color[0] = 0.5f;
    br.fill_color[1] = 0.0f;
    br.fill_color[2] = 0.0f;

    graphics::resetPose();
    drawText(300, 440, 70, "Hello RAF!", br);
}

void draw()
{
    drawWater();
    drawPlane();
}

int main() {

    graphics::createWindow(1500, 850, "Hello World");

    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);

    graphics::setCanvasSize(1000, 500);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_WINDOW);
    //graphics::setFullScreen(true);
    
    graphics::Brush br;
    br.fill_color[0] = 0.5f;
    br.fill_color[1] = 0.7f;
    br.fill_color[2] = 0.9f;
    graphics::setWindowBackground(br);

    graphics::setFont("assets\\MontserratAlternates-Bold.otf");

    graphics::startMessageLoop();
	return 0;
}