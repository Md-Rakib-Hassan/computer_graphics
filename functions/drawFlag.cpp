#include <GL/glut.h>
#include <math.h>

void drawFlag(float offsetX, float offsetY, float scale) {
    auto vx = [&](float x, float y) {
        glVertex2f(offsetX + x * scale, offsetY + y * scale);
    };

    // --- Thicker & Taller Pole
    glColor3f(0.3f, 0.3f, 0.3f); // Dark gray
    glBegin(GL_POLYGON);
        vx(-0.4f, 0.0f);     // base bottom-left
        vx(0.4f, 0.0f);      // base bottom-right
        vx(0.4f, 15.0f);     // top-right
        vx(-0.4f, 15.0f);    // top-left
    glEnd();

    // --- Thicker Base
    glColor3f(0.2f, 0.2f, 0.2f); // Darker
    glBegin(GL_POLYGON);
        vx(-2.0f, 0.0f);
        vx(2.0f, 0.0f);
        vx(2.5f, -1.0f);
        vx(-2.5f, -1.0f);
    glEnd();

    // --- Green Flag Body (Tall version)
    glColor3f(0.0f, 0.42f, 0.24f); // Official green
    glBegin(GL_POLYGON);
        vx(0.4f, 8.0f);        // flag starts higher up
        vx(10.4f, 8.0f);
        vx(10.4f, 14.0f);      // top of flag
        vx(0.4f, 14.0f);
    glEnd();

    // --- Red Circle (Centered slightly toward hoist)
    glColor3f(0.83f, 0.1f, 0.1f); // Official red
    float cx = 5.4f, cy = 11.0f, r = 2.0f;  // Higher center
    int triangleAmount = 100;
    float twicePi = 2.0f * M_PI;

    glBegin(GL_TRIANGLE_FAN);
        vx(cx, cy);
        for (int i = 0; i <= triangleAmount; ++i) {
            float angle = i * twicePi / triangleAmount;
            vx(cx + r * cos(angle), cy + r * sin(angle));
        }
    glEnd();
}
