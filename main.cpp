#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "include/draw.h"

#define WINDOW_WIDTH 850
#define WINDOW_HEIGHT 600
#define SKY_START_Y 350
#define GROUND_TOP_Y SKY_START_Y




bool rainActive = false;
bool snowActive = false;
bool fireActive = false;
bool showMemorial = true;
bool isNight = false;

float cloud1X = 0.0f, cloud2X = -100.0f, cloud3X = 200.0f;
float cloudSpeed = 0.5f;

float planeX = 150.0f;
float planeY = 100.0f;
int planeFacingLeft = 1;



void init()
{
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
    srand(time(0));
}


void drawBackground()
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



void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    drawBackground();


    drawCar(100, 280);

    drawBoat(640, 250, 0.6, 0.5, true, false);
    drawBoat(690, 150, 0.8, 0.7, true);

    float scaleX = planeFacingLeft ? 1.0f : -1.0f;
    drawMiniPlan(planeX, planeY, scaleX, 1.0f);


    glutPostRedisplay();

    if (showMemorial)
    {
        drawMemorial(260, 262, 1, 1.8);
    }
    else
    {
        drawSritiShoudho();
    }

    drawStepsInFrontOfSritiShoudho();
    drawPondInfrontOfSriti();

    for (int i = 0; i < 8; i++)
    {
        drawTree(600 + i * 30, 180 - i * 30, 0.50f);
    }

    float flowerPositions[10][2] = {
        {360, 230},
        {370, 225},
        {380, 235},
        {390, 220},
        {400, 230},
        {410, 218},
        {420, 232},
        {430, 228},
        {440, 225},
        {450, 230}};

    for (int i = 0; i < 10; ++i)
    {
        drawFlower(flowerPositions[i][0] + 20, flowerPositions[i][1] + 25);
    }
    drawFlag(425, 160, 3);

    drawPalmTree(750, 300, 0.8f);

    updateRain();
    drawRain(rainActive);

    drawFireParticles(fireActive);

    drawSnow(snowActive);

    glutSwapBuffers();

    // drawGrid(10.0f, WINDOW_WIDTH, WINDOW_HEIGHT);

    glFlush();
}



void specialKeys(int key, int x, int y)
{
    float moveAmount = 5.0f;

    switch (key)
    {
    case GLUT_KEY_LEFT:
        planeX -= moveAmount;
        planeFacingLeft = 1;
        break;
    case GLUT_KEY_RIGHT:
        planeX += moveAmount;
        planeFacingLeft = 0;
        break;
    case GLUT_KEY_UP:
        planeY += moveAmount;
        break;
    case GLUT_KEY_DOWN:
        planeY -= moveAmount;
        break;
    }

    if (planeX < 0) planeX = 0;
    if (planeX > WINDOW_WIDTH) planeX = WINDOW_WIDTH;
    if (planeY < 0) planeY = 0;
    if (planeY > GROUND_TOP_Y) planeY = GROUND_TOP_Y;

    glutPostRedisplay(); // Redraw the scene
}


void update(int value)
{
    updateRain();
    updateSnowflakes();
    updateFireParticles(fireActive);


    cloud1X += cloudSpeed;
    cloud2X += cloudSpeed * 0.7f;
    cloud3X += cloudSpeed * 0.4f;

    // Reset position if off screen
    if (cloud1X > WINDOW_WIDTH + 100)
        cloud1X = -100;
    if (cloud2X > WINDOW_WIDTH + 100)
        cloud2X = -150;
    if (cloud3X > WINDOW_WIDTH + 100)
        cloud3X = -200;



    glutPostRedisplay();
    glutTimerFunc(16, update, 0); // 16 ms -> roughly 60 FPS
}

void keyboard(unsigned char key, int x, int y){
    controlKeyboard(key, rainActive, showMemorial, isNight, snowActive, fireActive);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sriti Shoudho");
    init();

    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);
    glutDisplayFunc(display);

    initSnowflakes();
    glutTimerFunc(0, updateTrain, 0);
    glutTimerFunc(25, update, 0);
    glutTimerFunc(1, updateTrain, 0);
    glutMainLoop();
    return 0;
}
