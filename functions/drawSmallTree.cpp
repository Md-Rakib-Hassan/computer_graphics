#include <GL/glut.h>
#include <math.h>


void circle(GLfloat rx, GLfloat ry, GLfloat cx, GLfloat cy)
{
    glBegin(GL_POLYGON);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 3.1416 / 180;
        float x = rx * cos(angle);
        float y = ry * sin(angle);
        glVertex2f((x + cx), (y + cy));
    }
    glEnd();
}

void drawSmallTree1(float cx, float cy, float r, float g, float b, float sizeX, float sizeY) {
    glColor3f(r, g, b);

    circle(sizeX, sizeY, cx, cy);


    circle(sizeX * 0.8, sizeY * 0.8, cx - sizeX * 0.6, cy - sizeY * 0.2);


    circle(sizeX * 0.8, sizeY * 0.8, cx + sizeX * 0.6, cy - sizeY * 0.2);
}