#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define WINDOW_WIDTH 850
#define WINDOW_HEIGHT 600
#define MAX_FIRE_PARTICLES 800

struct FireParticle
{
    float x, y;
    float speed;
    float r, g, b;
};

FireParticle fireParticles[MAX_FIRE_PARTICLES];



void initFireParticles()
{
    for (int i = 0; i < MAX_FIRE_PARTICLES; i++)
    {
        fireParticles[i].x = rand() % WINDOW_WIDTH;
        fireParticles[i].y = rand() % WINDOW_HEIGHT + WINDOW_HEIGHT;
        fireParticles[i].speed = (rand() % 30 + 20) / 10.0f; // speed 2.0 to 5.0
        // Set fire color: red-orange-yellow tones
        fireParticles[i].r = 1.0f;
        fireParticles[i].g = (rand() % 50) / 100.0f; // 0.0 to 0.5
        fireParticles[i].b = 0.0f;
    }
}

void updateFireParticles(bool &fireActive)
{
    if (!fireActive)
        return;
    for (int i = 0; i < MAX_FIRE_PARTICLES; i++)
    {
        fireParticles[i].y -= fireParticles[i].speed;
        if (fireParticles[i].y < 0)
        {
            fireParticles[i].x = rand() % WINDOW_WIDTH;
            fireParticles[i].y = WINDOW_HEIGHT + rand() % 100;
        }
    }
}

void drawFireParticles(bool &fireActive)
{
    if (!fireActive)
        return;
    for (int i = 0; i < MAX_FIRE_PARTICLES; i++)
    {
        glColor3f(fireParticles[i].r, fireParticles[i].g, fireParticles[i].b);
        glBegin(GL_POLYGON);
        float radius = 2.0f;
        for (int j = 0; j < 360; j += 45)
        {
            float angle = j * M_PI / 180.0f;
            float x = fireParticles[i].x + cos(angle) * radius;
            float y = fireParticles[i].y + sin(angle) * radius;
            glVertex2f(x, y);
        }
        glEnd();
    }
}