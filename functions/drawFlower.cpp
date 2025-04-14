#include <GL/glut.h>
#include <math.h>
#include "..\include\draw.h"

void drawFlower(float cx, float cy)
{
    // Center of flower — soft pink
    drawCircle(cx, cy, 12, 1.0f, 1.0f, 1.0f);

    // Predefined colors for petals (aesthetic palette)
    float petalColors[5][3] = {
        {0.9f, 0.3f, 0.4f},   // Rose red
        {1.0f, 0.6f, 0.2f},   // Warm orange
        {1.0f, 0.85f, 0.3f},  // Soft yellow
        {0.4f, 0.8f, 0.4f},   // Light green
        {0.6f, 0.4f, 1.0f}    // Lavender
    };

    // Draw 5 petals
    for (int i = 0; i < 5; ++i)
    {
        float angle = i * 2 * M_PI / 5;
        float px = cx + cos(angle) * 6;
        float py = cy + sin(angle) * 6;

        float r = petalColors[i][0];
        float g = petalColors[i][1];
        float b = petalColors[i][2];

        // Petals have slight shape variety (size variation)
        float radius = 3.0f + (i % 2);  // Alternates between 3 and 4

        // Gentle offset for visual liveliness
        float offsetX = (i % 2 == 0) ? -1.5f : 1.5f;
        float offsetY = (i % 2 == 0) ? 1.5f : -1.5f;

        drawCircle(px + offsetX, py + offsetY, radius, r, g, b);
    }
}
