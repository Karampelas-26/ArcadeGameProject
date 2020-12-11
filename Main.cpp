#include <iostream>
#include "graphics.h"
#include "game.h"
#include "config.h"


void update(float ms)
{
    Game* game = (Game*)graphics::getUserData();
    game->update();
}

void draw()
{
    Game* game = (Game*)graphics::getUserData();
    game->draw();
}   
int main() {
    Game game;

    graphics::createWindow(WINDOWS_WIDTH, WINDOWS_HEIGHT, "1942");

    graphics::setUserData(&game);
    graphics::setDrawFunction(draw);
    graphics::setUpdateFunction(update);
    //graphics::setFullScreen(true);

    graphics::setCanvasSize(CANVAS_WIDTH,CANVAS_HEIGHT);
    graphics::setCanvasScaleMode(graphics::CANVAS_SCALE_FIT);
    game.init();
    graphics::startMessageLoop();
    game.~Game();
	return 0;
}