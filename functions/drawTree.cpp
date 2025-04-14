#include <GL/glut.h>
#include <math.h>
#include "..\include\draw.h"

void drawTree(float x, float y)
{
    // Draw trunk
    glColor3f(0.55f, 0.27f, 0.07f); // brown
    glBegin(GL_POLYGON);
    glVertex2f(x - 2, y);
    glVertex2f(x + 2, y);
    glVertex2f(x + 2, y + 20);
    glVertex2f(x - 2, y + 20);
    glEnd();

    // Draw leaves (three overlapping green circles)
    drawCircle(x, y + 25, 7, 0, 128, 0);     // 0.0f, 0.5f, 0.0f
    drawCircle(x - 5, y + 20, 6, 0, 153, 0); // 0.0f, 0.6f, 0.0f
    drawCircle(x + 5, y + 20, 6, 0, 153, 0); // 0.0f, 0.6f, 0.0f
}