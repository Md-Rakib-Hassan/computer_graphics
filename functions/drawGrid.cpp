#include <GL/glut.h>
#include <math.h>

void drawGrid(float spacing, int width, int height)
{
    glColor3f(0.8f, 0.8f, 0.8f); // Light gray grid

    glLineWidth(1.0f);
    glBegin(GL_LINES);

    // Vertical lines
    for (float x = 0; x <= width; x += spacing)
    {
        glVertex2f(x, 0);
        glVertex2f(x, height);
    }

    // Horizontal lines
    for (float y = 0; y <= height; y += spacing)
    {
        glVertex2f(0, y);
        glVertex2f(width, y);
    }

    glEnd();
}
