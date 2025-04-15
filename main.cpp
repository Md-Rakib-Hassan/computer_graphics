#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "include/draw.h"

#define WINDOW_WIDTH 850
#define WINDOW_HEIGHT 600
#define SKY_START_Y 350
#define GROUND_TOP_Y SKY_START_Y
#define MAX_RAINDROPS 500
#define MAX_SNOWFLAKES 1000
#define MAX_FIRE_PARTICLES 800

struct FireParticle
{
    float x, y;
    float speed;
    float r, g, b;
};

FireParticle fireParticles[MAX_FIRE_PARTICLES];
int fireActive = 0;

float cloud1X = 0.0f, cloud2X = -100.0f, cloud3X = 200.0f;
float cloudSpeed = 0.5f;

float planeX = 150.0f;
float planeY = 100.0f;
int planeFacingLeft = 1;


typedef struct
{
    float x, y;
    float speed;
} Raindrop;

struct Snowflake
{
    float x, y;
    float speed;
    float radius;
};

Snowflake snowflakes[MAX_SNOWFLAKES];

Raindrop raindrops[MAX_RAINDROPS];
int rainActive = 0;
int snowActive = 0;

bool showMemorial = true;
bool isNight = false;

void init()
{
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
    srand(time(0));
}


void initRain()
{
    for (int i = 0; i < MAX_RAINDROPS; i++)
    {
        raindrops[i].x = rand() % WINDOW_WIDTH;
        raindrops[i].y = rand() % WINDOW_HEIGHT;
        raindrops[i].speed = 1 + rand() % 4; // Random speed between 1 and 4
    }
    rainActive = 1; // Start the rain
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

void drawRain()
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

void updateFireParticles()
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

void drawFireParticles()
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

    drawRoadWithLamps();

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

    if (isNight)
    {
        drawMoon(550, 550, 30); // Show moon
    }
    else
    {
        drawSun(550, 550, 30); // Show sun
    }

    drawCloudSmall(cloud1X, 550, 1.0f); // Cloud 1
    drawCar(150, 350);
    drawConcreteFloor();
    drawMainBuilding(0,278,.6,.8);
    //drawMetroPillars();
    //drawMetroTrack();
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

    drawMetro(60,430,200,120);

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
    drawRain();

    drawFireParticles();

    if (snowActive)
    {
        glColor3f(1.0f, 1.0f, 1.0f); // Snow color
        for (int i = 0; i < MAX_SNOWFLAKES; i++)
        {
            drawCircleSnow(snowflakes[i].x, snowflakes[i].y, snowflakes[i].radius);
        }
    }




    glutSwapBuffers();

    // drawGrid(10.0f, WINDOW_WIDTH, WINDOW_HEIGHT);

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'r' || key == 'R')
    {
        if (rainActive)
            rainActive = 0;
        else
            initRain();
    }

    if (key == 'm' || key == 'M')
    {
        showMemorial = !showMemorial;
    }

    if (key == 'n' || key == 'N')
    {
        isNight = !isNight;
    }

    if (key == 's' || key == 'S')
    {
        snowActive = !snowActive;
    }

    if (key == 'f' || key == 'F')
    {
        fireActive = !fireActive;
        if (fireActive)
            initFireParticles();
    }
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
    updateFireParticles();


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
