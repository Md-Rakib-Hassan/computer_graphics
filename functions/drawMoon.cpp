#include <GL/glut.h>
#include <math.h>

// Utility: draw a filled circle
void drawCircle(float cx, float cy, float r, float red, float green, float blue, float alpha = 1.0f) 
{
    glColor4f(red, green, blue, alpha);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(cx, cy);
    for (int i = 0; i <= 100; i++) {
        float angle = 2.0f * M_PI * i / 100;
        float x = cx + cos(angle) * r;
        float y = cy + sin(angle) * r;
        glVertex2f(x, y);
    }
    glEnd();
}

// Moon with glow
void drawMoon(float cx, float cy, float radius) {
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Outer soft glow layers
    drawCircle(cx, cy, radius * 2.0f, 1.0f, 1.0f, 0.9f, 0.05f);
    drawCircle(cx, cy, radius * 1.5f, 1.0f, 1.0f, 0.9f, 0.08f);
    drawCircle(cx, cy, radius * 1.2f, 1.0f, 1.0f, 0.9f, 0.15f);

    // Core moon (white-gray)
    drawCircle(cx, cy, radius, 0.9f, 0.9f, 0.95f, 1.0f);

    glDisable(GL_BLEND);
}
