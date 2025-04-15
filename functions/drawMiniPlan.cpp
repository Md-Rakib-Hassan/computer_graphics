#include <GL/glut.h>

void drawMiniPlan(float offsetX=0.0f, float offsetY=0.0f, float scaleX = 1.0f, float scaleY = 1.0f) {
    
    auto vx = [&](int x, int y) {
        glVertex2f(offsetX + x * scaleX, offsetY + y * scaleY);
    };
glBegin(GL_POLYGON);
glColor3ub(35, 50, 64);
vx(70, 440);
vx(100, 440);
vx(100, 460);
vx(90, 450);
vx(80, 450);
vx(80, 450);
glEnd();
// body
glBegin(GL_POLYGON);
glColor3ub(255, 86, 111);
vx(80, 420);
vx(80, 420);
vx(100, 440);
vx(30, 440);
vx(30, 430);
vx(10, 430);
glEnd();
// cokepit
glBegin(GL_POLYGON);
glColor3ub(220, 241, 255);
vx(20, 430);
vx(30, 430);
vx(30, 440);
glEnd();
// fan
glBegin(GL_POLYGON);
glColor3ub(35, 50, 64);
vx(40, 410);
vx(60, 410);
vx(70, 420);
vx(60, 430);
vx(40, 430);
glEnd();
}
