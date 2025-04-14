#include <GL/glut.h>
#include <math.h>

// Mountain Variant 1: Tall & jagged peak
void drawMountain1(float x, float baseY, float width, float height, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x, baseY);
    glVertex2f(x + width * 0.1, baseY + height * 0.4);
    glVertex2f(x + width * 0.2, baseY + height * 0.55);
    glVertex2f(x + width * 0.3, baseY + height * 0.75);
    glVertex2f(x + width * 0.5, baseY + height);  // Sharp peak
    glVertex2f(x + width * 0.7, baseY + height * 0.7);
    glVertex2f(x + width * 0.8, baseY + height * 0.45);
    glVertex2f(x + width * 0.9, baseY + height * 0.2);
    glVertex2f(x + width, baseY);
    glEnd();
}

// Mountain Variant 2: Wide with a soft round peak
void drawMountain2(float x, float baseY, float width, float height, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x, baseY);
    glVertex2f(x + width * 0.2, baseY + height * 0.5);
    glVertex2f(x + width * 0.35, baseY + height * 0.75);
    glVertex2f(x + width * 0.5, baseY + height * 0.85);  // Round peak
    glVertex2f(x + width * 0.65, baseY + height * 0.75);
    glVertex2f(x + width * 0.8, baseY + height * 0.5);
    glVertex2f(x + width, baseY);
    glEnd();
}

// Mountain Variant 3: Small & craggy
void drawMountain3(float x, float baseY, float width, float height, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x, baseY);
    glVertex2f(x + width * 0.1, baseY + height * 0.2);
    glVertex2f(x + width * 0.2, baseY + height * 0.5);
    glVertex2f(x + width * 0.3, baseY + height * 0.3);
    glVertex2f(x + width * 0.4, baseY + height * 0.7);
    glVertex2f(x + width * 0.5, baseY + height * 0.6);  // Craggy, irregular peak
    glVertex2f(x + width * 0.6, baseY + height * 0.3);
    glVertex2f(x + width * 0.7, baseY + height * 0.55);
    glVertex2f(x + width * 0.9, baseY + height * 0.15);
    glVertex2f(x + width, baseY);
    glEnd();
}
