#include <GL/glut.h>
#include <math.h>

// Utility: draw a filled circle with alpha
void drawCircleSun(float cx, float cy, float r, float red, float green, float blue, float alpha = 1.0f)
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

// Sun with glow
void drawSun(float cx, float cy, float radius, int segments = 100)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    // Outer glow (soft orange)
    drawCircleSun(cx, cy, radius * 2.8f, 1.0f, 0.8f, 0.0f, 0.04f);
    drawCircleSun(cx, cy, radius * 2.2f, 1.0f, 0.85f, 0.0f, 0.06f);
    drawCircleSun(cx, cy, radius * 1.8f, 1.0f, 0.9f, 0.0f, 0.10f);
    drawCircleSun(cx, cy, radius * 1.4f, 1.0f, 0.95f, 0.1f, 0.12f);

    for (int i = 0; i < 10; ++i) {
        float innerR = (float)i / 10;
        float outerR = (float)(i + 1) / 10;

        float r = 1.0f;                       // Constant red
        float g = 1.0f - innerR * 0.3f;       // From 1.0 to 0.5 green
        float b = 0.0f;                       // No blue

        glColor4f(r, g, b, 1.0f);  // opaque inner intensity
        glBegin(GL_TRIANGLE_STRIP);
        for (int j = 0; j <= segments; ++j) {
            float angle = 2 * M_PI * j / segments;
            float x1 = cx + radius * innerR * cos(angle);
            float y1 = cy + radius * innerR * sin(angle);
            float x2 = cx + radius * outerR * cos(angle);
            float y2 = cy + radius * outerR * sin(angle);
            glVertex2f(x1, y1);
            glVertex2f(x2, y2);
        }
        glEnd();
    }

    glDisable(GL_BLEND);
}
