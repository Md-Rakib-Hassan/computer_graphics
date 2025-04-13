#include <GL/glut.h>
#include <math.h>

void drawStalls(float offsetX, float offsetY) {
    auto vx = [&](float x, float y) { glVertex2f(offsetX + x, offsetY + y); };

    // Roof shape
    glColor3f(0.2f, 0.6f, 0.9f);
    glBegin(GL_POLYGON);
    vx(-50, 50);
    vx(0, 0);
    vx(275, 200);
    vx(200, 200);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Border
    glBegin(GL_LINE_LOOP);
    vx(-50, 50);
    vx(0, 0);
    vx(275, 200);
    vx(200, 200);
    glEnd();

    // Main front face
    glColor3f(0.75f, 0.72f, 0.04f);
    glBegin(GL_POLYGON);
    vx(0, 0);
    vx(275, 200);
    vx(270, 150);
    vx(70, 0);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Border
    glBegin(GL_LINE_LOOP);
    vx(0, 0);
    vx(275, 200);
    vx(270, 150);
    vx(70, 0);
    glEnd();

    // Main front counter
    glColor3f(1.0f, 0.0f, 0.04f);
    glBegin(GL_POLYGON);
    vx(30, 0);
    vx(275, 175);
    vx(270, 150);
    vx(70, 0);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Border
    glBegin(GL_LINE_LOOP);
    vx(30, 0);
    vx(275, 175);
    vx(270, 150);
    vx(70, 0);
    glEnd();

    // Door or small window
    glColor3f(0.78f, 0.25f, 0.02f);
    glBegin(GL_POLYGON);
    vx(90, 60);
    vx(110, 70);
    vx(115, 30);
    vx(95, 20);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f); // Border
    glBegin(GL_LINE_LOOP);
    vx(90, 60);
    vx(110, 70);
    vx(115, 30);
    vx(95, 20);
    glEnd();
}
