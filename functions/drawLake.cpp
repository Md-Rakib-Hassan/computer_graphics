#include <GL/glut.h>
#include <math.h>


void drawRiverAndLake() {

    glColor3f(0.2f, 0.6f, 0.9f); 
    glBegin(GL_POLYGON);
    glVertex2f(500, 330); 
    glVertex2f(700, 320);
    glVertex2f(750, 320);
    glVertex2f(695, 250);
    glVertex2f(810, 240);
    glVertex2f(880, 0);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(500, 330);
    glVertex2f(700, 320);
    glVertex2f(750, 320);
    glVertex2f(705, 265);
    glVertex2f(810, 240);
    glVertex2f(880, 0);
    glEnd();
}

