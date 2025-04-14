#include <GL/glut.h>
#include <math.h>

void drawRectangle(float x, float y, float width, float height, float r, float g, float b)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void drawCar(float x, float y, float scale)
{
    // Body
    drawRectangle(x, y, scale * 60, scale * 20, 0.2f, 0.2f, 0.8f);
    drawRectangle(x + scale * 10, y + scale * 20, scale * 40, scale * 15, 0.1f, 0.1f, 0.6f);

    // Wheels
    glColor3f(0, 0, 0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float angle = i * M_PI / 180.0f;
        glVertex2f(x + scale * 15 + cos(angle) * scale * 5, y + sin(angle) * scale * 5);
    }
    glEnd();
    glBegin(GL_POLYGON);
    for (int i = 0; i < 360; i++)
    {
        float angle = i * M_PI / 180.0f;
        glVertex2f(x + scale * 45 + cos(angle) * scale * 5, y + sin(angle) * scale * 5);
    }
    glEnd();
}

void drawParkingLot(float offsetX, float offsetY)
{
    auto vx = [&](float x, float y)
    { glVertex2f(offsetX + x, offsetY + y); };

    glColor3f(0.7f, 0.7f, 0.71f);
    glBegin(GL_QUADS);
    vx(340, 190);
    vx(200, 200);
    vx(-60, 0);
    vx(200, 0);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    vx(340, 190);
    vx(200, 200);
    vx(-60, 0);
    vx(200, 0);
    glEnd();

    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    vx(170, 160);
    vx(290, 150);
    glEnd();
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    vx(120, 110);
    vx(240, 100);
    glEnd();
    
    glColor3f(1.0f, 1.0f, 1.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    vx(70, 60);
    vx(190, 50);
    glEnd();

    // Cars
    drawCar(offsetX + 70, offsetY + 20, 1.5f);
}
