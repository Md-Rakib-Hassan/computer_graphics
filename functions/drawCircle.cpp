#include <GL/glut.h>
#include <math.h>

void drawCircle(float cx, float cy, float r, float red, float green, float blue)
{
    glColor3f(red, green, blue);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float angle = i * M_PI / 180.0f;
        float x = cx + cos(angle) * r;
        float y = cy + sin(angle) * r;
        glVertex2f(x, y);
    }
    glEnd();
}