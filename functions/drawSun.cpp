#include <GL/glut.h>
#include <math.h>

void drawSun(float cx, float cy, float radius, int segments = 100) {
    for (int i = 0; i < 10; ++i) {
        float innerR = (float)i / 10;
        float outerR = (float)(i + 1) / 10;

        float r = 1.0f;                       // Constant red
        float g = 1.0f - innerR * 0.5f;       // From 1.0 to 0.5
        float b = 0.0f;                       // No blue

        glColor3f(r, g, b);
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
}
