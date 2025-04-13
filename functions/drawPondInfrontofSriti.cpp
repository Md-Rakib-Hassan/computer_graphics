#include <GL/glut.h>
#include <math.h>


void drawPondInfrontOfSriti(){
    // Filled pond
    glColor3f(0.2f, 0.6f, 0.9f);
    glBegin(GL_POLYGON);
        glVertex2f(425,150);
        glVertex2f(475,125);
        glVertex2f(525,0);
        glVertex2f(325,0);
        glVertex2f(375,125);
    glEnd();

    // Border around pond
    glColor3f(0.0f, 0.0f, 0.0f); // Black border
    glLineWidth(1.0f);
    glBegin(GL_LINE_LOOP);
        glVertex2f(425,150);
        glVertex2f(475,125);
        glVertex2f(525,0);
        glVertex2f(325,0);
        glVertex2f(375,125);
    glEnd();
}
