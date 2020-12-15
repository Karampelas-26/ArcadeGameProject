#include "utils.h"
#include "config.h"
#include "graphics.h"


float offset()
{
    float height = CANVAS_HEIGHT / 2 + CANVAS_HEIGHT * 0.5f * fmodf(graphics::getGlobalTime() / 10000.0f, 1000.0f);
    /*if (height > 1000.0f ) {
        height = 0;
    }
    */
    return height;
}
