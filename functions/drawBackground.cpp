#include "../include/draw.h"
#include <GL/glut.h>
#define WINDOW_WIDTH 850
#define WINDOW_HEIGHT 600




void drawBackground(int &GROUND_TOP_Y, bool &isNight, float &cloud1X, float &cloud2X, float &cloud3X)
{
    if (isNight)
    {
        glClearColor(0.02f, 0.09f, 0.27f, 1.0f); // Dark blueish night sky
    }
    else
    {
        glClearColor(0.53f, 0.81f, 0.98f, 1.0f); // Daytime sky blue
    }

    glClear(GL_COLOR_BUFFER_BIT);

    // Ground
    glColor3f(0.0f, isNight ? 0.3f : 0.6f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(WINDOW_WIDTH, 0);
    glVertex2f(WINDOW_WIDTH, 0);
    glVertex2f(WINDOW_WIDTH, GROUND_TOP_Y);
    glVertex2f(0, GROUND_TOP_Y);
    glEnd();

    glColor3f(0.2f, 0.2f, 0.2f);
    glBegin(GL_POLYGON);
    glVertex2f(0, GROUND_TOP_Y - 20);
    glVertex2f(WINDOW_WIDTH, GROUND_TOP_Y - 20);
    glVertex2f(WINDOW_WIDTH, GROUND_TOP_Y);
    glVertex2f(0, GROUND_TOP_Y);
    glEnd();

    drawCloudMedium(cloud2X, 500, 0.8f); // Cloud 2

    // Mountains
    drawMountain1(600, GROUND_TOP_Y, 200, 160, 0.4f, 0.3f, 0.2f); // Big brown mountain
    drawCloudLarge(cloud3X, 450, 1.2f);                           // Cloud 3
    drawMountain2(680, GROUND_TOP_Y, 170, 140, 0.5f, 0.4f, 0.3f); // Slightly smaller
    drawMountain3(740, GROUND_TOP_Y, 130, 100, 0.3f, 0.2f, 0.1f); // Smallest, dark

    float bx = 190;

    // Building 1
    float bw1 = 30;
    float bh1 = 70;
    drawBuilding(bx, bw1, bh1);
    bx += bw1;

    // Building 2
    float bw2 = 40;
    float bh2 = 90;
    drawBuilding(bx, bw2, bh2);
    bx += bw2;

    // Building 3
    float bw3 = 25;
    float bh3 = 50;
    drawBuilding(bx, bw3, bh3);
    bx += bw3;

    // Building 4
    float bw4 = 35;
    float bh4 = 100;
    drawBuilding(bx, bw4, bh4);
    bx += bw4;

    drawCar(150, 350);

    drawConcreteFloor();

    drawRoadWithLamps();

    drawMetro(60,430,200,120);

    drawMainBuilding(0,278,.6,.8);

    for (float i = 0; i <= 1.0f; i += 0.1f)
    {
        float x = 350 * (1 - i) + -150 * i;
        float y = 350 * (1 - i) + 230 * i;
        drawStreetLamp(x + 5, y, 30);
    }

    if (isNight)
    {
        drawMoon(550, 550, 30); // Show moon
    }
    else
    {
        drawSun(550, 550, 30); // Show sun
    }

    drawCloudSmall(cloud1X, 550, 1.0f); // Cloud 1
    drawRiverAndLake();
    drawStepsInFrontOfSritiShoudho();
    drawPondInfrontOfSriti();
    drawStalls(-75, 50);
    drawHouse(750, 300, 0.75, 0.5);
    drawParkingLot(0, 0);
    drawBus(200, 180, 0.7f, -6.0f);
}

