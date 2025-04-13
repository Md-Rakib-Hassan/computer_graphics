#ifndef DRAW_H
#define DRAW_H

void drawHouse(int offsetX = 0, int offsetY = 0, float scaleX = 1.0f, float scaleY = 1.0f);
void drawBuilding(float x, float width, float height);
void drawPondInfrontOfSriti();
void drawStepsInFrontOfSritiShoudho();
void drawRiverAndLake();
void drawSun(float cx, float cy, float radius, int segments = 100);

#endif