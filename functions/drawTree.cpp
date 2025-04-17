#include <GL/glut.h>
#include <math.h>
#include "../include/draw.h"

// Scalable RGBA circle
void drawCircleRGBA(float cx, float cy, float r, GLubyte red, GLubyte green, GLubyte blue, GLubyte alpha)
{
    glColor4ub(red, green, blue, alpha);
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

// Scalable Tree
void drawTree(float x, float y, float scale)
{
    // Enable blending for soft leaf overlay
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Trunk (forked)
    glColor3ub(139, 69, 19); // SaddleBrown
    glBegin(GL_POLYGON);
    glVertex2f(x - 10 * scale, y);
    glVertex2f(x - 5 * scale, y + 40 * scale);
    glVertex2f(x - 15 * scale, y + 90 * scale);
    glVertex2f(x - 5 * scale, y + 90 * scale);
    glVertex2f(x + 5 * scale, y + 45 * scale);
    glVertex2f(x + 10 * scale, y + 90 * scale);
    glVertex2f(x + 20 * scale, y + 90 * scale);
    glVertex2f(x + 10 * scale, y + 40 * scale);
    glVertex2f(x + 15 * scale, y);
    glEnd();

    // Leafy crown (scaled positions and radii)
    drawCircleRGBA(x,                  y + 110 * scale, 40 * scale, 60, 160, 60, 255);  // Medium green
    drawCircleRGBA(x - 30 * scale,     y + 100 * scale, 35 * scale, 50, 150, 50, 255);  // Darker
    drawCircleRGBA(x + 30 * scale,     y + 100 * scale, 35 * scale, 50, 150, 50, 255);
    drawCircleRGBA(x - 25 * scale,     y + 130 * scale, 25 * scale, 70, 170, 70, 255);  // Lighter
    drawCircleRGBA(x + 25 * scale,     y + 130 * scale, 25 * scale, 70, 170, 70, 255);
    drawCircleRGBA(x,                  y + 150 * scale, 30 * scale, 80, 180, 80, 255);  // Lightest green
}

void drawCircle(float cx, float cy, float r)
{
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

void drawSmallTree2(float cx, float cy, float r, float g, float b, float scale)
{
    // Set solid leaf color
    glColor3f(r, g, b);

    // Leafy top — 5 overlapping circles
    drawCircle(cx, cy + scale * 2.0f, scale);               // Center
    drawCircle(cx - scale * 0.8f, cy + scale * 1.5f, scale * 0.9f);  // Left
    drawCircle(cx + scale * 0.8f, cy + scale * 1.5f, scale * 0.9f);  // Right
    drawCircle(cx - scale * 0.5f, cy + scale * 2.5f, scale * 0.7f);  // Top Left
    drawCircle(cx + scale * 0.5f, cy + scale * 2.5f, scale * 0.7f);  // Top Right

    // Trunk — scales with size
    glColor3ub(139, 69, 19); // SaddleBrown
    glBegin(GL_POLYGON);
    glVertex2f(cx - scale * 0.2f, cy - scale);
    glVertex2f(cx + scale * 0.2f, cy - scale);
    glVertex2f(cx + scale * 0.15f, cy + scale * 0.5f);
    glVertex2f(cx - scale * 0.15f, cy + scale * 0.5f);
    glEnd();
}


void drawTreesRightSide(){
    for (int i = 0; i < 8; i++)
    {
        drawTree(600 + i * 30, 180 - i * 30, 0.50f);
    }
}