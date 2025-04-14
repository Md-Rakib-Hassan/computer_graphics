#include <GL/glut.h>
#include <math.h>

void drawMountain(float x, float baseY, float width, float height, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);

    // Start at bottom-left
    glVertex2f(x, baseY);

    // Jagged path up the left side
    glVertex2f(x + width * 0.1, baseY + height * 0.3);
    glVertex2f(x + width * 0.2, baseY + height * 0.45);
    glVertex2f(x + width * 0.3, baseY + height * 0.6);

    // Rounded peak (top middle)
    glVertex2f(x + width * 0.5, baseY + height);

    // Jagged path down right side
    glVertex2f(x + width * 0.7, baseY + height * 0.6);
    glVertex2f(x + width * 0.8, baseY + height * 0.4);
    glVertex2f(x + width * 0.9, baseY + height * 0.2);

    // End at bottom-right
    glVertex2f(x + width, baseY);

    glEnd();
}
