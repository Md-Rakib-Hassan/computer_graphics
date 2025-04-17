#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>

#define WINDOW_WIDTH 850
#define WINDOW_HEIGHT 600
#define MAX_RAINDROPS 500




typedef struct
{
    float x, y;
    float speed;
} Raindrop;


Raindrop raindrops[MAX_RAINDROPS];


void initRain(bool &rainActive)
{
    for (int i = 0; i < MAX_RAINDROPS; i++)
    {
        raindrops[i].x = rand() % WINDOW_WIDTH;
        raindrops[i].y = rand() % WINDOW_HEIGHT;
        raindrops[i].speed = 1 + rand() % 4; // Random speed between 1 and 4
    }
    rainActive = true; // Start the rain
}

void updateRain()
{
    for (int i = 0; i < MAX_RAINDROPS; i++)
    {
        raindrops[i].y -= raindrops[i].speed; // Move raindrop down
        if (raindrops[i].y < 0)
        {
            raindrops[i].x = rand() % WINDOW_WIDTH;
            raindrops[i].y = WINDOW_HEIGHT + rand() % 100;
            raindrops[i].speed = 1 + rand() % 4; // New random speed
        }
    }
}

void drawRain(bool &rainActive)
{
    if (rainActive)
    {
        glColor3f(0.0f, 0.0f, 1.0f); // Blue color for raindrops
        for (int i = 0; i < MAX_RAINDROPS; i++)
        {
            glBegin(GL_LINES);
            glVertex2f(raindrops[i].x, raindrops[i].y);
            glVertex2f(raindrops[i].x, raindrops[i].y - 10); // Line for raindrop
            glEnd();
        }
    }
}