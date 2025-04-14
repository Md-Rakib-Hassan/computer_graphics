#include <GL/glut.h>
#include <math.h>
#include "C:\Users\Ridwan Sharif\Documents\University_space\L4T2\Computer Graphics\computer_graphics\include\draw.h"

void drawSritiShoudho()
{
    int cx = 425;
    int cy = 250;
    int base = 100;
    int height = 350;

    drawFilledTriangle(cx - 20, cy, cx + 20, cy, cx, cy + height, 0.6f, 0.6f, 0.6f);

    for (int i = 1; i <= 3; ++i)
    {
        float offset = i * 40;
        float h = height * (1.0f - i * 0.1f);
        float thickness = 20;

        drawFilledTriangle(cx - offset - thickness, cy, cx - offset + thickness, cy, cx, cy + h, 0.7f - 0.1f * i, 0.7f - 0.1f * i, 0.7f - 0.1f * i);
        drawFilledTriangle(cx + offset - thickness, cy, cx + offset + thickness, cy, cx, cy + h, 0.7f - 0.1f * i, 0.7f - 0.1f * i, 0.7f - 0.1f * i);
    }

    drawFilledTriangle(cx - 30, cy, cx + 30, cy, cx, cy + height * 0.5f, 0.3f, 0.3f, 0.3f);

}