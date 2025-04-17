
#include <GL/glut.h>


float blockX = 0.0f;          // X position of the block
float blockSpeed = 1;      // Speed of movement

void drawMetro(int offsetX = 0, int offsetY = 0, float scaleX = 5.0f, float scaleY = 5.0f) {
    auto vx = [&](float x, float y) {
        glVertex2f(offsetX + blockX + x * scaleX, offsetY + y * scaleY);
    };

    glBegin(GL_QUADS);
    glColor3ub(43, 50, 54);
    vx(-0.70,-0.60);
    vx(-0.80,-0.78);
    vx(-0.80,-0.80);
    vx(-0.70,-0.80);
    glEnd();
//train compartment
    glBegin(GL_QUADS);
    glColor3ub(43, 50, 54);
    vx(-0.70,-0.60);
    vx(-0.70,-0.62);
    vx(0.10,-0.62);
    vx(0.10,-0.60);
    glEnd();
//train compartment 1st up gray part
    glBegin(GL_QUADS);
    glColor3ub(65, 90, 173);
    vx(-0.70,-0.62);
    vx(-0.70,-0.64);
    vx(0.10,-0.64);
    vx(0.10,-0.62);
    glEnd();
//train compartment 1st up gray part
    glBegin(GL_QUADS);
    glColor3ub(65, 90, 173);
    vx(-0.70,-0.64);
    vx(-0.70,-0.65);
    vx(0.10,-0.65);
    vx(0.10,-0.64);
    glEnd();

    glBegin(GL_QUADS); //train compartment
    glColor3ub(43, 50, 54);
    vx(-0.70,-0.78);
    vx(-0.70,-0.80);
    vx(0.10,-0.80);
    vx(0.10,-0.78);
    glEnd();

//train compartment 1st black part
    glBegin(GL_QUADS);
    glColor3ub(43, 50, 54);
    vx(-0.7,-0.65);
    vx(-0.7,-0.73);
    vx(0.10,-0.73);
    vx(0.10,-0.65);
    glEnd();
//train white part
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    vx(-0.7,-0.73);
    vx(-0.7,-0.78);
    vx(0.10,-0.78);
    vx(0.10,-0.73);
    glEnd();
//train compartment 1st down gray part
    glBegin(GL_QUADS);
    glColor3ub(65, 90, 173);
    vx(-0.66,-0.75);
    vx(-0.69,-0.78);
    vx(0.10,-0.78);
    vx(0.10,-0.75);
    glEnd();

//train compartment 1st joint
    glBegin(GL_QUADS);
    glColor3ub(43, 50, 54);
    vx(0.10,-0.60);
    vx(0.10,-0.80);
    vx(0.12,-0.80);
    vx(0.12,-0.64);
    glEnd();
//train compartment 2nd white part
    glBegin(GL_QUADS);
    glColor3ub(255,255,255);
    vx(0.14,-0.78);
    vx(0.14,-0.62);
    vx(0.95,-0.62);
    vx(0.95,-0.78);
    glEnd();

    glBegin(GL_QUADS); //train compartment
    glColor3ub(43, 50, 54);
    vx(0.17,-0.60);
    vx(0.14,-0.62);
    vx(0.95,-0.62);
    vx(0.95,-0.60);
    glEnd();
//train compartment 2nd black part
    glBegin(GL_QUADS);
    glColor3ub(43, 50, 54);
    vx(0.22,-0.62);
    vx(0.22,-0.73);
    vx(0.95,-0.73);
    vx(0.95,-0.62);
    glEnd();
//train compartment 2nd up gray part
    glBegin(GL_QUADS);
    glColor3ub(65, 90, 173);
    vx(0.14,-0.62);
    vx(0.14,-0.65);
    vx(0.95,-0.65);
    vx(0.95,-0.62);
    glEnd();
//train compartment 2nd down gray part
    glBegin(GL_QUADS);
    glColor3ub(65, 90, 173);
    vx(0.22,-0.75);
    vx(0.19,-0.78);
    vx(0.95,-0.78);
    vx(0.95,-0.75);
    glEnd();
//train compartment
    glBegin(GL_QUADS);
    glColor3ub(43, 50, 54);
    vx(0.14,-0.78);
    vx(0.17,-0.80);
    vx(0.95,-0.80);
    vx(0.95,-0.78);
    glEnd();
//train compartment 2nd front gray part
    glBegin(GL_QUADS);
    glColor3ub(43, 50, 54);
    vx(0.14,-0.62);
    vx(0.14,-0.78);
    vx(0.17,-0.78);
    vx(0.17,-0.62);
    glEnd();
//train compartment 2nd back gray part
    glBegin(GL_QUADS);
    glColor3ub(43, 50, 54);
    vx(0.95,-0.60);
    vx(0.95,-0.80);
    vx(0.98,-0.80);
    vx(0.98,-0.63);
    glEnd();

//train compartment 2nd joint
    glBegin(GL_QUADS);
    glColor3ub(27, 33, 36);
    vx(0.12,-0.75);
    vx(0.12,-0.78);
    vx(0.14,-0.78);
    vx(0.14,-0.75);
    glEnd();
//train compartment 1st joint
    glBegin(GL_QUADS);
    glColor3ub(43, 50, 54);
    vx(0.98,-0.75);
    vx(0.98,-0.78);
    vx(1.0,-0.78);
    vx(1.0,-0.75);
    glEnd();

//window engine
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(-0.727,-0.65);
    vx(-0.76,-0.71);
    vx(-0.76,-0.73);
    vx(-0.72,-0.70);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(-0.65,-0.66);
    vx(-0.65,-0.72);
    vx(-0.60,-0.72);
    vx(-0.60,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(-0.57,-0.66);
    vx(-0.57,-0.72);
    vx(-0.52,-0.72);
    vx(-0.52,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(-0.49,-0.66);
    vx(-0.49,-0.72);
    vx(-0.44,-0.72);
    vx(-0.44,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(-0.41,-0.66);
    vx(-0.41,-0.72);
    vx(-0.36,-0.72);
    vx(-0.36,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(-0.33,-0.66);
    vx(-0.33,-0.72);
    vx(-0.27,-0.72);
    vx(-0.27,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(-0.24,-0.66);
    vx(-0.24,-0.72);
    vx(-0.19,-0.72);
    vx(-0.19,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(-0.16,-0.66);
    vx(-0.16,-0.72);
    vx(-0.11,-0.72);
    vx(-0.11,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(-0.08,-0.66);
    vx(-0.08,-0.72);
    vx(-0.03,-0.72);
    vx(-0.03,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(-0.00,-0.66);
    vx(-0.00,-0.72);
    vx(0.05,-0.72);
    vx(0.05,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(0.25,-0.66);
    vx(0.25,-0.72);
    vx(0.30,-0.72);
    vx(0.30,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(0.25,-0.66);
    vx(0.25,-0.72);
    vx(0.30,-0.72);
    vx(0.30,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(0.33,-0.66);
    vx(0.33,-0.72);
    vx(0.38,-0.72);
    vx(0.38,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(0.41,-0.66);
    vx(0.41,-0.72);
    vx(0.46,-0.72);
    vx(0.46,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(0.49,-0.66);
    vx(0.49,-0.72);
    vx(0.54,-0.72);
    vx(0.54,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(0.57,-0.66);
    vx(0.57,-0.72);
    vx(0.62,-0.72);
    vx(0.62,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(0.65,-0.66);
    vx(0.65,-0.72);
    vx(0.70,-0.72);
    vx(0.70,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(0.73,-0.66);
    vx(0.73,-0.72);
    vx(0.78,-0.72);
    vx(0.78,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(0.81,-0.66);
    vx(0.81,-0.72);
    vx(0.86,-0.72);
    vx(0.86,-0.66);
    glEnd();
//window
    glBegin(GL_QUADS);
    glColor3ub(160, 212, 235);
    vx(0.89,-0.66);
    vx(0.89,-0.72);
    vx(0.94,-0.72);
    vx(0.94,-0.66);
    glEnd();
}

void updateTrain(int value) {
    blockX -= blockSpeed;
    if (blockX < -250)  // adjust threshold based on scaling (e.g. screenWidth / scaleX)
        blockX = 1000.0f;        // restart off-screen

    glutPostRedisplay();
    glutTimerFunc(10, updateTrain, 0);
}
