#include <GL/glut.h>
#include <math.h>

void drawBus(float x, float y, float scale, float angleDegrees)
{
    glPushMatrix();

    // Move to origin and rotate
    glTranslatef(x, y, 0);
    glRotatef(angleDegrees, 0, 0, 1);
    glScalef(scale, scale, 1);
    glTranslatef(-x, -y, 0); // Translate back

    auto vx = [&](float dx, float dy)
    {
        glVertex2f(x + dx, y + dy);
    };

    // --- Bus Body ---
    glColor3ub(128, 0, 128); // Purple
    glBegin(GL_POLYGON);
    vx(0, 0);
    vx(0, 50);
    vx(180, 50);
    vx(180, 0);
    glEnd();

    // --- Windows ---
    glColor3ub(200, 240, 255); // Light blue
    for (int i = 0; i < 4; i++)
    {
        float winX = 20 + i * 35;
        glBegin(GL_POLYGON);
        vx(winX, 20);
        vx(winX, 40);
        vx(winX + 25, 40);
        vx(winX + 25, 20);
        glEnd();
    }

    // --- Window Outlines ---
    glColor3f(0, 0, 0);
    for (int i = 0; i < 4; i++)
    {
        float winX = 20 + i * 35;
        glBegin(GL_LINE_LOOP);
        vx(winX, 20);
        vx(winX, 40);
        vx(winX + 25, 40);
        vx(winX + 25, 20);
        glEnd();
    }

    // --- Wheels ---
    glColor3ub(20, 20, 20);
    float wheelRadius = 12;
    for (int i = 0; i < 2; i++)
    {
        float cx = x + (30 + i * 120);
        float cy = y - 5;
        glBegin(GL_POLYGON);
        for (int j = 0; j < 360; j++)
        {
            float angle = j * M_PI / 180.0f;
            glVertex2f(cx + cos(angle) * wheelRadius, cy + sin(angle) * wheelRadius);
        }
        glEnd();
    }

    glPopMatrix();
}
