#include <GL/glut.h>

float boatWave = 0.0f;
bool boatWaveUp = true;

void drawBoat(int offsetX, int offsetY, float scaleX, float scaleY, bool motion, bool sail = true) {
    if (motion) {
        // Wave effect only (up and down)
        if (boatWaveUp) boatWave += 0.008f;
        else boatWave -= 0.008f;

        if (boatWave > 2.0f) boatWaveUp = false;
        if (boatWave < -2.0f) boatWaveUp = true;
    }

    float by = boatWave; // Only Y-axis movement

    auto vx = [&](int x, int y) {
        glVertex2i(offsetX + (x+by) * scaleX, offsetY + (y + by) * scaleY);
    };

    glPushMatrix();
    glColor3ub(0, 0, 0); // Black

    // Boat body
    glBegin(GL_POLYGON);
        vx(0, 50); vx(15, 20); vx(30, 0);
        vx(30, 20); vx(0, 50);
        glEnd();

        glBegin(GL_POLYGON);
        vx(30, 20); vx(30, 0); vx(60, -5);
        vx(90, 0); vx(95, 20); vx(30, 20);
        glEnd();

        glBegin(GL_POLYGON);
        vx(95, 20); vx(90, 0); vx(105, 15);
        vx(120, 50); vx(95, 20);
        glEnd();

        if(sail){

            // sail
            glColor3ub(173,216,230);
            glBegin(GL_POLYGON);
            vx(123, 80); vx(130, 110); vx(131, 130); vx(130, 150);
            vx(125, 165); vx(117, 177); vx(107, 188); vx(75, 165); vx(130, 110);
            glEnd();

            glBegin(GL_POLYGON);
            vx(112, 50); vx(123, 80); vx(95, 130); vx(112, 50);
            glEnd();

            glBegin(GL_POLYGON);
            vx(95, 20); vx(112, 50); vx(100, 110); vx(95, 20);
            glEnd();



                // Boat wood
     glColor3ub(139, 69, 19);
     glRecti(offsetX+by + 92 * scaleX, offsetY+by + 20 * scaleY,
         offsetX +by+ 94 * scaleX, offsetY+by + 200 * scaleY);






            // Lines
            glColor3ub(0, 0, 0);
            glBegin(GL_LINE_STRIP);
            vx(38, 58); vx(107, 188); vx(107, 183); vx(38, 58); vx(75, 165);
            glEnd();




        }







//chauni
        glColor3ub(140, 100, 40);
        glBegin(GL_POLYGON);
        vx(95, 20); vx(93, 40); vx(87, 58); vx(83, 65);
        vx(75, 70); vx(60, 72); vx(60, 20); vx(95, 20);
        glEnd();

        glBegin(GL_POLYGON);
        vx(30, 20); vx(32, 40); vx(38, 58); vx(42, 65);
        vx(50, 70); vx(65, 72); vx(65, 20); vx(30, 20);
        glEnd();

        // Lines
        glColor3ub(0, 0, 0);
        glBegin(GL_LINE_STRIP); vx(32, 40); vx(93, 40); glEnd();
        glBegin(GL_LINE_STRIP); vx(38, 58); vx(87, 58); glEnd();
        glBegin(GL_LINE_STRIP); vx(65, 72); vx(65, 20); glEnd();
        glBegin(GL_LINE_STRIP); vx(50, 70); vx(50, 20); glEnd();
        glBegin(GL_LINE_STRIP); vx(80, 68); vx(80, 20); glEnd();



    glPopMatrix();
}
