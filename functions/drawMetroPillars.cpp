#include <GL/glut.h>

void drawMetroPillar(float x, float y, float height) {
    // Draw vertical pillar
    glColor3f(0.4f, 0.4f, 0.4f); // concrete gray
    glBegin(GL_POLYGON);
    glVertex2f(x - 2, y);
    glVertex2f(x + 2, y);
    glVertex2f(x + 2, y + height);
    glVertex2f(x - 2, y + height);
    glEnd();

    // Top slab (track platform)
    glColor3f(0.1f, 0.1f, 0.1f); // darker slab
    glBegin(GL_POLYGON);
    glVertex2f(x - 10, y + height);
    glVertex2f(x + 10, y + height);
    glVertex2f(x + 10, y + height + 3);
    glVertex2f(x - 10, y + height + 3);
    glEnd();
}

void drawMetroPillars()
{
    float topRightX = 425, topRightY = 350;
    float bottomRightX = 0, bottomRightY = 230;

    bottomRightX = topRightX - 425;  // Assuming -150 + 75

    for (float i = 0; i <= 1.0f; i += 0.1f)
    {
        float x = topRightX * (1 - i) + bottomRightX * i;
        float y = topRightY * (1 - i) + bottomRightY * i;
        drawMetroPillar(x + 25, y, 40); // offset to the right
    }
}