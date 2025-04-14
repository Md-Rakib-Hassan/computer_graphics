
#include <GL/glut.h>


void drawWindow(int offsetX = 0, int offsetY = 0, float scaleX = 1.0f, float scaleY = 1.0f) {
    auto vx = [&](int x, int y) {
        glVertex2i(offsetX + x * scaleX, offsetY + y * scaleY);
    };


     glBegin(GL_POLYGON);  // Lower part 1 window side
        glColor3ub(192, 219, 220);
        vx(31,55);vx(55,51);vx(56,95);vx(31,98);
    glEnd();


     glBegin(GL_POLYGON);  // Lower part 1 window side
        glColor3ub(192, 219, 220);
        vx(67,95);vx(66,49);vx(96,46);vx(96,93);
    glEnd();

}

void drawWindowFront(int offsetX = 0, int offsetY = 0, float scaleX = 1.0f, float scaleY = 1.0f) {
    auto vx = [&](int x, int y) {
        glVertex2i(offsetX + x * scaleX, offsetY + y * scaleY);
    };


     glBegin(GL_POLYGON);  // Lower part 1 window side
        glColor3ub(192, 219, 220);
        vx(186,98);vx(186,56);vx(218,59);vx(219,100);
    glEnd();



}

void drawMainBuilding(int offsetX = 0, int offsetY = 0, float scaleX = 1.0f, float scaleY = 1.0f) {
    auto vx = [&](float x, float y) {
        glVertex2f(offsetX + x * scaleX, offsetY + y * scaleY);
    };

    // --- Building Base Structure ---
    glBegin(GL_POLYGON);  // Left side of the building
        glColor3ub(120, 120, 122);
        vx(19, 264); vx(21, 45); vx(109, 32); vx(111, 277);
    glEnd();

    glBegin(GL_POLYGON);  // Right side of the building
        glColor3ub(157, 159, 161);
        vx(109, 32); vx(111, 277); vx(281, 54); vx(281, 257); vx(111, 276);
    glEnd();

    // --- Windows ---
    drawWindow(offsetX + 10 * scaleX, offsetY + 10 * scaleY, 0.8f * scaleX, 0.8f * scaleY);
    drawWindow(offsetX + 10 * scaleX, offsetY + 60 * scaleY, 0.8f * scaleX, 0.8f * scaleY);
    drawWindow(offsetX + 10 * scaleX, offsetY + 110 * scaleY, 0.8f * scaleX, 0.8f * scaleY);
    drawWindow(offsetX + 10 * scaleX, offsetY + 160 * scaleY, 0.8f * scaleX, 0.8f * scaleY);

    drawWindowFront(offsetX - 20 * scaleX, offsetY + 10 * scaleY, 0.8f * scaleX, 0.8f * scaleY);
    drawWindowFront(offsetX + 40 * scaleX, offsetY + 20 * scaleY, 0.7f * scaleX, 0.7f * scaleY);
    drawWindowFront(offsetX + 100 * scaleX, offsetY + 30 * scaleY, 0.6f * scaleX, 0.6f * scaleY);
    drawWindowFront(offsetX + 140 * scaleX, offsetY + 35 * scaleY, 0.55f * scaleX, 0.55f * scaleY);

    drawWindowFront(offsetX - 20 * scaleX, offsetY + 60 * scaleY, 0.8f * scaleX, 0.8f * scaleY);
    drawWindowFront(offsetX + 40 * scaleX, offsetY + 70 * scaleY, 0.7f * scaleX, 0.7f * scaleY);
    drawWindowFront(offsetX + 100 * scaleX, offsetY + 80 * scaleY, 0.6f * scaleX, 0.6f * scaleY);
    drawWindowFront(offsetX + 140 * scaleX, offsetY + 85 * scaleY, 0.55f * scaleX, 0.55f * scaleY);

    drawWindowFront(offsetX - 20 * scaleX, offsetY + 110 * scaleY, 0.8f * scaleX, 0.8f * scaleY);
    drawWindowFront(offsetX + 40 * scaleX, offsetY + 120 * scaleY, 0.7f * scaleX, 0.7f * scaleY);
    drawWindowFront(offsetX + 100 * scaleX, offsetY + 130 * scaleY, 0.6f * scaleX, 0.6f * scaleY);
    drawWindowFront(offsetX + 140 * scaleX, offsetY + 135 * scaleY, 0.55f * scaleX, 0.55f * scaleY);

    drawWindowFront(offsetX - 20 * scaleX, offsetY + 160 * scaleY, 0.8f * scaleX, 0.8f * scaleY);
    drawWindowFront(offsetX + 40 * scaleX, offsetY + 170 * scaleY, 0.7f * scaleX, 0.7f * scaleY);
    drawWindowFront(offsetX + 100 * scaleX, offsetY + 180 * scaleY, 0.6f * scaleX, 0.6f * scaleY);
    drawWindowFront(offsetX + 140 * scaleX, offsetY + 185 * scaleY, 0.55f * scaleX, 0.55f * scaleY);
}


