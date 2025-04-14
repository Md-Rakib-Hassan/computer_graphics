#include <GL/glut.h>
#include <math.h>
#include "..\include\draw.h"

void drawFlower(float cx, float cy)
{
    // Center of flower — soft pink (white originally)
    drawCircle(cx, cy, 12, 255, 255, 255);

    // Petal colors in 0–255 RGB
    unsigned char petalColors[5][3] = {
        {230, 77, 102},    // Rose red
        {255, 153, 51},    // Warm orange
        {255, 217, 77},    // Soft yellow
        {102, 204, 102},   // Light green
        {153, 102, 255}    // Lavender
    };

    // Draw 5 petals
    for (int i = 0; i < 5; ++i)
    {
        float angle = i * 2 * M_PI / 5;
        float px = cx + cos(angle) * 6;
        float py = cy + sin(angle) * 6;

        unsigned char r = petalColors[i][0];
        unsigned char g = petalColors[i][1];
        unsigned char b = petalColors[i][2];

        float radius = 3.0f + (i % 2);  // Alternates between 3 and 4

        float offsetX = (i % 2 == 0) ? -1.5f : 1.5f;
        float offsetY = (i % 2 == 0) ? 1.5f : -1.5f;

        drawCircle(px + offsetX, py + offsetY, radius, r, g, b);
    }
}
