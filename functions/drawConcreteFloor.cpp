#include <GL/glut.h>
#include <math.h>

void drawConcreteFloor(){

    glColor3f(0.7f, 0.7f, 0.71f);
    glBegin(GL_TRIANGLES);
    glVertex2f(0, 267);
    glVertex2f(265, 330);
    glVertex2f(0, 329);
    glEnd();

    glColor3f(0.0f, 0.0f, 0.0f);
    glLineWidth(2.0f);
    glBegin(GL_LINE_LOOP);
    glVertex2f(0, 267);
    glVertex2f(265, 330);
    glVertex2f(0, 329);
    glEnd();

}