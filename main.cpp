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

typedef struct {
	float x, y;
	float speed;
}Raindrop;

Raindrop raindrops[MAX_RAINDROPS];
int rainActive = 0;

void init()
{
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
    srand(time(0));
}















void drawTree(float x, float y)
{
    // Draw trunk
    glColor3f(0.55f, 0.27f, 0.07f); // brown
    glBegin(GL_POLYGON);
    glVertex2f(x - 2, y);
    glVertex2f(x + 2, y);
    glVertex2f(x + 2, y + 20);
    glVertex2f(x - 2, y + 20);
    glEnd();

    // Draw leaves (three overlapping green circles)
    drawCircle(x, y + 25, 7, 0.0f, 0.5f, 0.0f);
    drawCircle(x - 5, y + 20, 6, 0.0f, 0.6f, 0.0f);
    drawCircle(x + 5, y + 20, 6, 0.0f, 0.6f, 0.0f);
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


void drawFlower(float cx, float cy)
{
    drawCircle(cx, cy, 10, 1.0f, 0.0f, 0.0f);
    for (int i = 0; i < 5; ++i)
    {
        float angle = i * 2 * M_PI / 5;
        float px = cx + cos(angle) * 6;
        float py = cy + sin(angle) * 6;
        float r = (rand() % 100) / 100.0f;
        float g = (rand() % 100) / 100.0f;
        float b = (rand() % 100) / 100.0f;
        drawCircle(px + (rand()%5 - 2), py + (rand()%5 - 2), 3 + rand()%2, r, g, b);
    }
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
    glColor3f(0.0f, 0.6f, 0.0f);
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

    drawRoadWithLamps();
    drawMetroPillars();
    drawMetroTrack();
    drawRiverAndLake();
    drawStalls(0, 0);
    drawHouse(750, 300, 0.75, 0.5);
    drawSun(550, 550, 30);
	drawMoon(400, 550, 30);

}


void drawCar(float x, float y)
{
    // Body
    glColor3f(0.9f, 0.1f, 0.1f);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + 40, y);
    glVertex2f(x + 40, y + 15);
    glVertex2f(x, y + 15);
    glEnd();

    // Top
    glColor3f(0.6f, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glVertex2f(x + 5, y + 15);
    glVertex2f(x + 35, y + 15);
    glVertex2f(x + 30, y + 25);
    glVertex2f(x + 10, y + 25);
    glEnd();

    // Wheels
    drawCircle(x + 8, y - 2, 4, 0.1f, 0.1f, 0.1f);
    drawCircle(x + 32, y - 2, 4, 0.1f, 0.1f, 0.1f);
}



void drawSritiShoudhoWithFilledShapes()
{
    int cx = 425;
    int cy = 250;
    int base = 100;
    int height = 350;

    drawFilledTriangle(cx - 20, cy, cx + 20, cy, cx, cy + height, 0.6f, 0.6f, 0.6f);

    for (int i = 1; i <= 3; ++i)
    {
        float offset = i * 40;
        float h = height * (1.0f - i * 0.1f);
        float thickness = 20;

        drawFilledTriangle(cx - offset - thickness, cy, cx - offset + thickness, cy, cx, cy + h, 0.7f - 0.1f * i, 0.7f - 0.1f * i, 0.7f - 0.1f * i);
        drawFilledTriangle(cx + offset - thickness, cy, cx + offset + thickness, cy, cx, cy + h, 0.7f - 0.1f * i, 0.7f - 0.1f * i, 0.7f - 0.1f * i);
    }

    drawFilledTriangle(cx - 30, cy, cx + 30, cy, cx, cy + height * 0.5f, 0.3f, 0.3f, 0.3f);

    drawStepsInFrontOfSritiShoudho();
    drawPondInfrontOfSriti();

    for (int i = 0; i < 20; ++i)
    {
        float fx = cx - 70 + (float)(rand() % 140);
        float fy = cy - 20 - (float)(rand() % 25);
        drawFlower(fx, fy);
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    drawBackground();
    drawSritiShoudhoWithFilledShapes();
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

	updateRain();
	drawRain();

    drawBoat(640, 200, 0.7, 0.7, true);  // motion = true

    glutPostRedisplay();

    glFlush();
}

void keyboard(unsigned char key, int x, int y)
{
    if (key == 'r' || key == 'R')  // Toggle rain when "R" is pressed
    {
        if (rainActive)
            rainActive = 0;  // Stop rain
        else
            initRain();  // Start rain
    }
}

void update(int value) {
    updateRain();
    glutPostRedisplay();  // Trigger redraw
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
