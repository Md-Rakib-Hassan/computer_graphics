#include <GL/glut.h>

void drawHouse(int offsetX = 0, int offsetY = 0, float scaleX = 1.0f, float scaleY = 1.0f) {
    auto vx = [&](int x, int y) {
        glVertex2i(offsetX + x * scaleX, offsetY + y * scaleY);
    };

    glBegin(GL_POLYGON);  // Shadow
        glColor3ub(85, 3, 3);
        vx(15, 120);
        vx(0, 70);
        vx(10, 70);
        vx(22, 107);
        vx(15, 120);
    glEnd();

    glBegin(GL_POLYGON);  // front with window
        glColor3ub(46, 139, 87);
        vx(22, 107);
        vx(10, 70);
        vx(10, 15);
        vx(40, 10);
        vx(40, 70);
        vx(22, 107);
    glEnd();

    glBegin(GL_POLYGON);  // side with door
        glColor3ub(143, 188, 143);
        vx(40, 10);
        vx(100, 15);
        vx(100, 70);
        vx(40, 70);
    glEnd();

    glBegin(GL_POLYGON);  // tin roof
        glColor3ub(128, 0, 0);
        vx(105, 60);
        vx(80, 115);
        vx(15, 120);
        vx(40, 60);
    glEnd();

    // Doors
    glColor3ub(120, 0, 0);
    glRecti(
        offsetX + 55 * scaleX, offsetY + 50 * scaleY,
        offsetX + 45 * scaleX, offsetY + 10 * scaleY
    );

    glColor3ub(120, 0, 0);
    glRecti(
        offsetX + 20 * scaleX, offsetY + 60 * scaleY,
        offsetX + 30 * scaleX, offsetY + 40 * scaleY
    );

    glBegin(GL_POLYGON);  // Lower part 1 window side
        glColor3ub(0, 0, 0);
        vx(40, 10);
        vx(7, 17);
        vx(7, 7);
        vx(40, 0);
    glEnd();

    glBegin(GL_POLYGON);  // Lower part 2 door side
        glColor3ub(0, 0, 0);
        vx(40, 10);
        vx(102, 15);
        vx(102, 5);
        vx(40, 0);
    glEnd();
}
