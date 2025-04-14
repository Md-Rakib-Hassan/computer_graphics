#ifndef DRAW_H
#define DRAW_H

void drawHouse(int offsetX = 0, int offsetY = 0, float scaleX = 1.0f, float scaleY = 1.0f);
void drawBuilding(float x, float width, float height);
void drawPondInfrontOfSriti();
void drawStepsInFrontOfSritiShoudho();
void drawRiverAndLake();
void drawSun(float cx, float cy, float radius, int segments = 100);
void drawStalls(float offsetX, float offsetY);
void drawMoon(float cx, float cy, float radius);
void drawBoat(int offsetX, int offsetY, float scaleX, float scaleY, bool motion, bool sail = true);
void drawStreetLamp(float x1, float y1, float height);
void drawLine(float x1, float y1, float x2, float y2);
void drawFilledTriangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b);
void drawCircle(float cx, float cy, float r, float red, float green, float blue);
void drawMetroPillars();
void drawMemorial(int offsetX = 0, int offsetY = 0, float scaleX = 1.0f, float scaleY = 1.0f);
void drawFlower(float cx, float cy);
void drawSritiShoudho();
void drawTree(float x, float y);
void drawCar(float x, float y);
void drawMountain(float x, float baseY, float width, float height, float r, float g, float b);
void drawFlag(float offsetX, float offsetY, float scale);

#endif
