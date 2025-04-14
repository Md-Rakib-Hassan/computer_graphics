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

float cloud1X = 0.0f, cloud2X = -100.0f, cloud3X = 200.0f;
float cloudSpeed = 0.5f; // Speed of cloud motion

typedef struct {
	float x, y;
	float speed;
}Raindrop;

Raindrop raindrops[MAX_RAINDROPS];
int rainActive = 0;

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


void drawRoadWithLamps()
{
    // Road edge points (top and bottom for perspective)
    float topLeftX = 350, topLeftY = 350;
    float topRightX = topLeftX + 75;
    float bottomLeftX = -150, bottomLeftY = 230;
    float bottomRightX = bottomLeftX + 150;

    // ----- Draw road polygon -----
    glColor3f(0.2f, 0.2f, 0.2f); // dark gray road
    glBegin(GL_POLYGON);
    glVertex2f(topLeftX, topLeftY);
    glVertex2f(topRightX, topLeftY);
    glVertex2f(bottomRightX, bottomLeftY);
    glVertex2f(bottomLeftX, bottomLeftY);
    glEnd();


    // ----- Draw street lamps -----
    for (float i = 0; i <= 1.0f; i += 0.1f)
    {
        float x = topLeftX * (1 - i) + bottomLeftX * i;
        float y = topLeftY * (1 - i) + bottomLeftY * i;
        drawStreetLamp(x + 5, y, 30);
    }
    glEnd();

}


void drawMetroTrack()
{
    float topRightX = 425, topRightY = 350;
    float bottomRightX = 0, bottomRightY = 230;

    bottomRightX = topRightX - 425; // reuse logic

    glColor3f(0.3f, 0.3f, 0.3f); // rail color
    glBegin(GL_LINES);
    for (float i = 0; i <= 1.0f; i += 0.05f)
    {
        float x = topRightX * (1 - i) + bottomRightX * i;
        float y = topRightY * (1 - i) + bottomRightY * i;
        glVertex2f(x + 15, y + 43); // left rail
        glVertex2f(x + 35, y + 43); // right rail
    }
    glEnd();
}



void initRain() {
    for (int i = 0; i < MAX_RAINDROPS; i++) {
        raindrops[i].x = rand() % WINDOW_WIDTH;
        raindrops[i].y = rand() % WINDOW_HEIGHT;
        raindrops[i].speed = 1 + rand() % 4;  // Random speed between 1 and 4
    }
    rainActive = 1;  // Start the rain
}

void updateRain() {
    for (int i = 0; i < MAX_RAINDROPS; i++) {
        raindrops[i].y -= raindrops[i].speed;  // Move raindrop down
        if (raindrops[i].y < 0) {
            // Reset raindrop to the top of the screen with a new random x position
            raindrops[i].x = rand() % WINDOW_WIDTH;
            raindrops[i].y = WINDOW_HEIGHT + rand() % 100;
            raindrops[i].speed = 1 + rand() % 4;  // New random speed
        }
    }
}

void drawRain() {
    if (rainActive) {
        glColor3f(0.0f, 0.0f, 1.0f);  // Blue color for raindrops
        for (int i = 0; i < MAX_RAINDROPS; i++) {
            glBegin(GL_LINES);
                glVertex2f(raindrops[i].x, raindrops[i].y);
                glVertex2f(raindrops[i].x, raindrops[i].y - 10);  // Line for raindrop
            glEnd();
        }
    }
}


void drawBackground()
{
    if (isNight) {
        glClearColor(0.02f, 0.09f, 0.27f, 1.0f);  // Dark blueish night sky
    } else {
        glClearColor(0.53f, 0.81f, 0.98f, 1.0f);  // Daytime sky blue
    }

    glClear(GL_COLOR_BUFFER_BIT);

    //Ground
    glColor3f(0.0f, isNight ? 0.3f: 0.6f, 0.0f);
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

    drawCircle(100, SKY_START_Y + 70, 20, 1.0f, 1.0f, 1.0f);
    drawCircle(130, SKY_START_Y + 90, 25, 1.0f, 1.0f, 1.0f);
    drawCircle(170, SKY_START_Y + 70, 20, 1.0f, 1.0f, 1.0f);

    drawCircle(600, SKY_START_Y + 100, 18, 1.0f, 1.0f, 1.0f);
    drawCircle(630, SKY_START_Y + 120, 23, 1.0f, 1.0f, 1.0f);
    drawCircle(670, SKY_START_Y + 100, 18, 1.0f, 1.0f, 1.0f);

    drawCloudSmall(cloud1X, 550, 1.0f);   // Cloud 1
    drawCloudMedium(cloud2X, 500, 0.8f);  // Cloud 2
    drawCloudLarge(cloud3X, 450, 1.2f);   // Cloud 3

    //drawCircle(760, SKY_START_Y + 90, 30, 1.0f, 1.0f, 0.0f);

    drawFilledTriangle(690, 350, 770, 510, 850, 350, 0.4f, 0.3f, 0.2f);
    drawFilledTriangle(640, 350, 715, 460, 790, 350, 0.5f, 0.4f, 0.3f);

    float bx = 75;
    for (int i = 0; i < 6; ++i)
    {
        float bw = 30 + rand() % 20;
        float bh = 60 + rand() % 100;
        drawBuilding(bx, bw, bh);
        bx += bw - 10 + rand() % 10;
    }

    // Mountains
    drawMountain(600, GROUND_TOP_Y, 200, 160, 0.4f, 0.3f, 0.2f);  // Big brown mountain
    drawMountain(680, GROUND_TOP_Y, 170, 140, 0.5f, 0.4f, 0.3f);  // Slightly smaller
    drawMountain(740, GROUND_TOP_Y, 130, 100, 0.3f, 0.2f, 0.1f);  // Smallest, dark


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


    drawRoadWithLamps();
    drawMetroPillars();
    drawMetroTrack();
    drawRiverAndLake();
    drawStepsInFrontOfSritiShoudho();
    drawPondInfrontOfSriti();
    drawStalls(0, 0);
    drawHouse(750, 300, 0.75, 0.5);
    if (isNight) {
        drawMoon(550, 550, 30);  // Show moon
    } else {
        drawSun(550, 550, 30);   // Show sun
    }

}


void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawBackground();
    drawCar(150, 350);
    drawCar(100, 280);

    for (int i = 0; i < 20; i++)
    {
        drawTree(580 + i * 10, 220 - i * 10);
    }
    for (int i = 0; i < 20; i++)
    {
        drawTree(600 + i * 10, 220 - i * 10);
    }

    drawBoat(640, 200, 0.7, 0.7, true);

    glutPostRedisplay();



    drawMemorial(250,262,1,1.6);

    if(showMemorial) {
        drawMemorial(260,262,1,1.8);
    } 
    else {
        drawSritiShoudho();
    }

    drawStepsInFrontOfSritiShoudho();
    drawPondInfrontOfSriti();

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
        {450, 230}
    };
    
    for (int i = 0; i < 10; ++i)
    {
        drawFlower(flowerPositions[i][0]+20, flowerPositions[i][1]+25);
    }
    drawFlag(425, 160, 3);

	updateRain();
	drawRain();



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

    if(key == 'm' || key == 'M')
    {
        showMemorial = !showMemorial;
    }

    if(key == 'n' || key == 'N')
    {
        isNight = !isNight;
    }


void update(int value) {
    updateRain();
     cloud1X += cloudSpeed;
    cloud2X += cloudSpeed * 0.7f;
    cloud3X += cloudSpeed * 0.4f;

    // Reset position if off screen
    if (cloud1X > WINDOW_WIDTH+100) cloud1X = -100;
    if (cloud2X > WINDOW_WIDTH+100) cloud2X = -150;
    if (cloud3X > WINDOW_WIDTH+100) cloud3X = -200;

    glutPostRedisplay();
   glutTimerFunc(16, update, 0);  // 16 ms -> roughly 60 FPS

}



int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sriti Shoudho");
    init();
	glutKeyboardFunc(keyboard);
    glutDisplayFunc(display);

	glutTimerFunc(25, update, 0);
    glutMainLoop();
    return 0;
}

