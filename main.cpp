#include <GL/glut.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "include/draw.h"

#define WINDOW_WIDTH 850
#define WINDOW_HEIGHT 600
#define SKY_START_Y 350
#define GROUND_TOP_Y SKY_START_Y

void init()
{
    glClearColor(0.53f, 0.81f, 0.98f, 1.0f);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
    srand(time(0));
}

void drawLine(float x1, float y1, float x2, float y2)
{
    glBegin(GL_LINES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glEnd();
}

void drawFilledTriangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b)
{
    // Filled triangle
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();

    // Border
    glColor3f(0.0f, 0.0f, 0.0f);  // Black border
    glLineWidth(1.0f);           // Thickness of the border
    glBegin(GL_LINE_LOOP);
        glVertex2f(x1, y1);
        glVertex2f(x2, y2);
        glVertex2f(x3, y3);
    glEnd();
}


void drawCircle(float cx, float cy, float r, float red, float green, float blue)
{
    glColor3f(red, green, blue);
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

void drawStreetLamp(float x1, float y1, float height)
{
    drawLine(x1, y1, x1, y1 + height);
    drawCircle(x1, y1 + height + 3, 4, 1.0f, 1.0f, 0.5f);
}


void drawMetroPillar(float x, float y, float height) {
    // Draw vertical pillar
    glColor3f(0.4f, 0.4f, 0.4f); // concrete gray
    glBegin(GL_POLYGON);
    glVertex2f(x - 2, y);
    glVertex2f(x + 2, y);
    glVertex2f(x + 2, y + height);
    glVertex2f(x - 2, y + height);
    glEnd();

    // Top slab (track platform)
    glColor3f(0.1f, 0.1f, 0.1f); // darker slab
    glBegin(GL_POLYGON);
    glVertex2f(x - 10, y + height);
    glVertex2f(x + 10, y + height);
    glVertex2f(x + 10, y + height + 3);
    glVertex2f(x - 10, y + height + 3);
    glEnd();
}

void drawMetroPillars()
{
    float topRightX = 425, topRightY = 350;
    float bottomRightX = 0, bottomRightY = 230;

    bottomRightX = topRightX - 425;  // Assuming -150 + 75

    for (float i = 0; i <= 1.0f; i += 0.1f)
    {
        float x = topRightX * (1 - i) + bottomRightX * i;
        float y = topRightY * (1 - i) + bottomRightY * i;
        drawMetroPillar(x + 25, y, 40); // offset to the right
    }
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

void drawStalls() {
    // First roof shape
    glColor3f(0.2f, 0.6f, 0.9f);
    glBegin(GL_POLYGON);
    glVertex2f(-50, 50);
    glVertex2f(0, -0);
    glVertex2f(200, 130);
    glVertex2f(130, 140);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);  // Border
    glBegin(GL_LINE_LOOP);
    glVertex2f(-50, 50);
    glVertex2f(0, -0);
    glVertex2f(200, 130);
    glVertex2f(130, 140);
    glEnd();

    // Second structure
    glColor3f(0.75f, 0.72f, 0.04f);
    glBegin(GL_POLYGON);
    glVertex2f(0, 0);
    glVertex2f(200, 130);
    glVertex2f(200, 90);
    glVertex2f(70, 0);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);  // Border
    glBegin(GL_LINE_LOOP);
    glVertex2f(0, 0);
    glVertex2f(200, 130);
    glVertex2f(200, 90);
    glVertex2f(70, 0);
    glEnd();

    // Door or window on stall
    glColor3f(0.78f, 0.25f, 0.02f);
    glBegin(GL_POLYGON);
    glVertex2f(90, 60);
    glVertex2f(110, 70);
    glVertex2f(115, 30);
    glVertex2f(95, 20);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);  // Border
    glBegin(GL_LINE_LOOP);
    glVertex2f(90, 60);
    glVertex2f(110, 70);
    glVertex2f(115, 30);
    glVertex2f(95, 20);
    glEnd();

    // Right-side extended box
    glColor3f(0.78f, 0.25f, 0.02f);
    glBegin(GL_QUADS);
    glVertex2f(200, 130);
    glVertex2f(230, 120);
    glVertex2f(260, 150);
    glVertex2f(250, 160);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);  // Border
    glBegin(GL_LINE_LOOP);
    glVertex2f(200, 130);
    glVertex2f(230, 120);
    glVertex2f(260, 150);
    glVertex2f(250, 160);
    glEnd();

    // Background banner or backdrop
    glColor3f(0.2f, 0.6f, 0.9f);
    glBegin(GL_QUADS);
    glVertex2f(190, 120);
    glVertex2f(120, 130);
    glVertex2f(300, 220);
    glVertex2f(280, 220);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);  // Border
    glBegin(GL_LINE_LOOP);
    glVertex2f(190, 120);
    glVertex2f(120, 130);
    glVertex2f(300, 220);
    glVertex2f(280, 220);
    glEnd();
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

    float bx = 20;
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
    drawStalls();
    drawHouse(750, 300, 0.75, 0.5);
    drawSun(550, 550, 30);

}

void drawSmallAirplane(float x, float y)
{
    // Body
    glColor3f(1.0f, 1.0f, 1.0f); // white
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + 50, y + 6);
    glVertex2f(x + 50, y - 6);
    glVertex2f(x, y - 6);
    glEnd();

    // Tail fin
    glColor3f(0.6f, 0.6f, 0.6f); // grey
    glBegin(GL_TRIANGLES);
    glVertex2f(x + 10, y);
    glVertex2f(x, y + 10);
    glVertex2f(x, y - 10);
    glEnd();

    // Top wing
    glColor3f(0.7f, 0.7f, 0.9f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x + 25, y);
    glVertex2f(x + 10, y + 20);
    glVertex2f(x + 35, y + 20);
    glEnd();

    // Bottom wing
    glColor3f(0.7f, 0.7f, 0.9f);
    glBegin(GL_TRIANGLES);
    glVertex2f(x + 25, y);
    glVertex2f(x + 10, y - 20);
    glVertex2f(x + 35, y - 20);
    glEnd();

    // Windows (cockpit style)
    glColor3f(0.2f, 0.6f, 1.0f); // blue
    for (int i = 0; i < 3; i++)
    {
        float winX = x + 15 + i * 8;
        float winY = y + 2;
        glBegin(GL_POLYGON);
        glVertex2f(winX, winY);
        glVertex2f(winX + 5, winY);
        glVertex2f(winX + 5, winY - 4);
        glVertex2f(winX, winY - 4);
        glEnd();
    }
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
    drawSmallAirplane(600, 500);
    drawCar(150, 350);
    drawCar(100, 280);
    //drawTrain(100, 200);

    for (int i = 0; i < 20; i++)
    {
        drawTree(580 + i * 10, 220 - i * 10);
    }
    for (int i = 0; i < 20; i++)
    {
        drawTree(600 + i * 10, 220 - i * 10);
    }
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Sriti Shoudho (Updated Buildings, Flowers, Road)");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
