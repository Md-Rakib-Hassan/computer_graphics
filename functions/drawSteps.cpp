#include <GL/glut.h>
#include <math.h>

void drawStepsInFrontOfSritiShoudho()
{
    int startX = 350;
    int startY = 220;
    int stepWidth = 150;
    int stepHeight = 10;
    int numberOfSteps = 5;

    // Base platform
    glColor3f(0.5f, 0.3f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(240, 250);
    glVertex2f(350, 220);
    glVertex2f(500, 220);
    glVertex2f(610, 250);
    glEnd();

    // Border for base platform
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(240, 250);
    glVertex2f(350, 220);
    glVertex2f(500, 220);
    glVertex2f(610, 250);
    glEnd();

    // Front-facing steps (shrinking and centered)
    for (int i = 0; i < numberOfSteps; ++i)
    {
        int shrink = i * 5;
        float yTop = startY - i * stepHeight;
        float yBottom = startY - (i + 1) * stepHeight;
        float xLeft = startX + shrink;
        float xRight = startX + stepWidth - shrink;

        glColor3f(0.5f, 0.3f, 0.2f);
        glBegin(GL_POLYGON);
        glVertex2f(xLeft, yTop);
        glVertex2f(xRight, yTop);
        glVertex2f(xRight, yBottom);
        glVertex2f(xLeft, yBottom);
        glEnd();

        // Border for each step
        glColor3f(0.0f, 0.0f, 0.0f);
        glLineWidth(1.0f);
        glBegin(GL_LINE_LOOP);
        glVertex2f(xLeft, yTop);
        glVertex2f(xRight, yTop);
        glVertex2f(xRight, yBottom);
        glVertex2f(xLeft, yBottom);
        glEnd();
    }

    // Bottom platform
    glColor3f(0.5f, 0.3f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(370, 170);
    glVertex2f(480, 170);
    glVertex2f(625, 0);
    glVertex2f(225, 0);
    glEnd();

    // Border for bottom platform
    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(370, 170);
    glVertex2f(480, 170);
    glVertex2f(625, 0);
    glVertex2f(225, 0);
    glEnd();
}
