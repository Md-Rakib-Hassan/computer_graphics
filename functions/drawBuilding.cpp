#include <GL/glut.h>
#include <math.h>

void drawBuilding(float x, float width, float height)
{
    float baseY = 400;

    glColor3f(0.4f, 0.4f, 0.4f);
    glBegin(GL_POLYGON);
        glVertex2f(x, baseY);
        glVertex2f(x + width, baseY);
        glVertex2f(x + width, baseY + height);
        glVertex2f(x, baseY + height);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(x, baseY);
        glVertex2f(x + width, baseY);
        glVertex2f(x + width, baseY + height);
        glVertex2f(x, baseY + height);
    glEnd();

    for (float wx = x + 5; wx < x + width - 5; wx += 10)
    {
        for (float wy = baseY + 10; wy < baseY + height - 10; wy += 15)
        {
            glColor3f(1.0f, 1.0f, 0.0f);
            glBegin(GL_POLYGON);
                glVertex2f(wx, wy);
                glVertex2f(wx + 5, wy);
                glVertex2f(wx + 5, wy + 8);
                glVertex2f(wx, wy + 8);
            glEnd();
        }
    }
}
