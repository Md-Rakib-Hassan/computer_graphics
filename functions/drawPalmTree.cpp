#include <GL/glut.h>
#include <math.h>
#include "../include/draw.h"

// Draw a beautiful palm tree with curved, lush fronds
void drawPalmTree(float x, float y, float scale)
{
    // --- Trunk ---
    glColor3f(139 / 255.0f, 69 / 255.0f, 19 / 255.0f); // Brown
    glBegin(GL_POLYGON);
    glVertex2f(x - 5 * scale, y);
    glVertex2f(x + 5 * scale, y);
    glVertex2f(x + 6 * scale, y + 100 * scale);
    glVertex2f(x - 6 * scale, y + 100 * scale);
    glEnd();

    float leafCenterX = x;
    float leafCenterY = y + 100 * scale;

    // --- Fronds (many curved leaves) ---
    int leafCount = 10;
    float radius = 55 * scale;
    for (int i = 0; i < leafCount; ++i)
    {
        float angle = (2 * M_PI / leafCount) * i - M_PI / 2; // spread evenly

        float midX = cos(angle) * radius;
        float midY = sin(angle) * (radius * 0.6); // shorter height for arc effect

        float controlX1 = leafCenterX + midX * 0.6f + 8 * scale;
        float controlY1 = leafCenterY + midY * 0.6f;

        float controlX2 = leafCenterX + midX * 0.6f - 8 * scale;
        float controlY2 = leafCenterY + midY * 0.6f;

        glColor3f(34 / 255.0f, 139 / 255.0f, 34 / 255.0f); // Green
        glBegin(GL_TRIANGLES);
        glVertex2f(leafCenterX, leafCenterY);
        glVertex2f(controlX1, controlY1);
        glVertex2f(controlX2, controlY2);
        glEnd();
    }

    // --- Coconuts ---
    drawCircle(leafCenterX - 4 * scale, leafCenterY - 2 * scale, 3 * scale, 101, 67, 33);
    drawCircle(leafCenterX + 4 * scale, leafCenterY - 2 * scale, 3 * scale, 101, 67, 33);
    drawCircle(leafCenterX, leafCenterY - 4 * scale, 3 * scale, 101, 67, 33);
}