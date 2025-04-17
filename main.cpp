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



void display(){

    glClear(GL_COLOR_BUFFER_BIT);
    int groundTopY = GROUND_TOP_Y;
    drawBackground(groundTopY, isNight,cloud1X,cloud2X,cloud3X);


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
