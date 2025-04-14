#include <GL/glut.h>
#include <cmath>




// Draw a scalable circle
void drawCircle(float x, float y, float radius, float scale = 1.0f) {
    glBegin(GL_POLYGON);
    for (int i = 0; i < 100; ++i) {
        float angle = 2.0f * 3.1416f * i / 100;
        glVertex2f(x + cos(angle) * radius * scale, y + sin(angle) * radius * scale);
    }
    glEnd();
}

// Scalable Cloud 1 - Small Cloud
void drawCloudSmall(float x, float y, float scale = 1.0f) {
    glColor3ub(255, 255, 255);
    drawCircle(x, y, 10, scale);
    drawCircle(x + 10 * scale, y + 5 * scale, 12, scale);
    drawCircle(x + 20 * scale, y, 10, scale);
}

// Scalable Cloud 2 - Medium Cloud
void drawCloudMedium(float x, float y, float scale = 1.0f) {
    glColor3ub(242, 242, 242);
    drawCircle(x, y, 15, scale);
    drawCircle(x + 15 * scale, y + 8 * scale, 18, scale);
    drawCircle(x + 30 * scale, y, 15, scale);
    drawCircle(x + 15 * scale, y - 5 * scale, 13, scale);
}

// Scalable Cloud 3 - Large Cloud
void drawCloudLarge(float x, float y, float scale = 1.0f) {
    glColor3ub(230, 230, 230);
    drawCircle(x, y, 18, scale);
    drawCircle(x + 15 * scale, y + 10 * scale, 22, scale);
    drawCircle(x + 35 * scale, y + 8 * scale, 20, scale);
    drawCircle(x + 50 * scale, y, 18, scale);
    drawCircle(x + 25 * scale, y - 10 * scale, 15, scale);
}
