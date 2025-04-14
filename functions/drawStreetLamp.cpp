#include <GL/glut.h>
#include <math.h>
#include "../include/draw.h"

void drawStreetLamp(float x1, float y1, float height)
{
    drawLine(x1, y1, x1, y1 + height);
    drawCircle(x1, y1 + height + 3, 4, 255, 255, 128);  // 1.0f = 255, 0.5f × 255 ≈ 128
}