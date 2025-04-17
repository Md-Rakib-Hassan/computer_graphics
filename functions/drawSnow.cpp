#include <stdlib.h>
#include <time.h>
#include <GL/glut.h>
#include <math.h>
#define WINDOW_WIDTH 850
#define WINDOW_HEIGHT 600
#define MAX_SNOWFLAKES 1000



struct Snowflake
{
    float x, y;
    float speed;
    float radius;
};
Snowflake snowflakes[MAX_SNOWFLAKES];

void drawCircleSnow(float cx, float cy, float r)
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


void initSnowflakes()
{
    for (int i = 0; i < MAX_SNOWFLAKES; i++)
    {
        snowflakes[i].x = rand() % WINDOW_WIDTH;
        snowflakes[i].y = rand() % WINDOW_HEIGHT;
        snowflakes[i].speed = (rand() % 50 + 50) / 100.0f; // 0.5 to 1.0
        snowflakes[i].radius = (rand() % 4 + 1);           // 1 to 4
    }
}

void updateSnowflakes()
{
    for (int i = 0; i < MAX_SNOWFLAKES; i++)
    {
        snowflakes[i].y -= snowflakes[i].speed;
        if (snowflakes[i].y < 0)
        {
            snowflakes[i].y = WINDOW_HEIGHT + rand() % 100;
            snowflakes[i].x = rand() % WINDOW_WIDTH;
        }
    }
    glutPostRedisplay();
}


void drawSnow(bool &snowActive)
{
    if (snowActive)
    {
        glColor3f(1.0f, 1.0f, 1.0f); // Snow color
        for (int i = 0; i < MAX_SNOWFLAKES; i++)
        {
            drawCircleSnow(snowflakes[i].x, snowflakes[i].y, snowflakes[i].radius);
        }
    }
}