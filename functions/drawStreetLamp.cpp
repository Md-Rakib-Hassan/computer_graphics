#include "../include/draw.h"
void drawStreetLamp(float x1, float y1, float height)
{
    drawLine(x1, y1, x1, y1 + height);
    drawCircle(x1, y1 + height + 3, 4, 1.0f, 1.0f, 0.5f);
}