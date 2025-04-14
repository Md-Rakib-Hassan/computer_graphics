#include <GL/glut.h>


void drawMetroTrack()
{
    float topRightX = 425, topRightY = 350;
    float bottomRightX = 0, bottomRightY = 230;

    bottomRightX = topRightX - 425; // reuse logic

    glColor3f(0.3f, 0.3f, 0.3f); // rail color
    glBegin(GL_LINES);
    for (float i = 0; i <= 1.0f; i += 0.05f)
    {
        float x = topRightX * (1 - i) + bottomRightX * i;
        float y = topRightY * (1 - i) + bottomRightY * i;
        glVertex2f(x + 15, y + 43); // left rail
        glVertex2f(x + 35, y + 43); // right rail
    }
    glEnd();
}