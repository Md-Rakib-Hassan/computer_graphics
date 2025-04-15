#include <GL/glut.h>
#include "../include/draw.h"
void drawRoadWithLamps()
{

    float topLeftX = 350, topLeftY = 350;
    float topRightX = topLeftX + 75;
    float bottomLeftX = -150, bottomLeftY = 230;
    float bottomRightX = bottomLeftX + 150;

    glColor3f(0.2f, 0.2f, 0.2f); // dark gray road
    glBegin(GL_POLYGON);
    glVertex2f(topLeftX, topLeftY);
    glVertex2f(topRightX, topLeftY);
    glVertex2f(bottomRightX, bottomLeftY);
    glVertex2f(bottomLeftX, bottomLeftY);
    glEnd();

    glEnd();
}