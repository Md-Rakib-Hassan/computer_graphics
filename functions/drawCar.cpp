#include <GL/glut.h>
#include <math.h>
#include "../include/draw.h"

void drawCar(float x, float y)
{
    // Body
    glColor3f(0.9f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + 40, y);
    glVertex2f(x + 40, y + 15);
    glVertex2f(x, y + 15);
    glEnd();

    // Top
    glColor3f(0.6f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(x + 5, y + 15);
    glVertex2f(x + 35, y + 15);
    glVertex2f(x + 30, y + 25);
    glVertex2f(x + 10, y + 25);
    glEnd();

    // Wheels
    drawCircle(x + 8,  y - 2, 4, 26, 26, 26);   // 0.1f * 255 ≈ 25.5
    drawCircle(x + 32, y - 2, 4, 26, 26, 26);
    
}