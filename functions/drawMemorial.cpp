#include <GL/gl.h>
#include <GL/glut.h>


void drawMemorial(int offsetX = 0, int offsetY = 0, float scaleX = 1.0f, float scaleY = 1.0f)
{

	auto vx = [&](float x, float y) {
        glVertex2f(offsetX+164 + x*200 * scaleX, offsetY+20 + y*200 * scaleY);
    };

    glBegin(GL_TRIANGLES);  //top tri
    glColor3ub(166, 166, 166);
    vx(-0.01f, 0.7f);
    vx(0.01f, 0.7f);
    vx(0.0f, 0.75f);
    glEnd();

    //main base
    glBegin(GL_TRIANGLES);  //front tri 1st tall
    glColor3ub(204, 204, 204);
    vx(-0.2f, -0.1f);
    vx(0.2f, -0.1f);
    vx(0.0f, 0.7f);
    glEnd();

    glBegin(GL_TRIANGLES);  // bottom gap tri
    glColor3ub(107, 62, 17);
    vx(-0.2f, -0.1f);
    vx(0.2f, -0.1f);
    vx(0.0f, 0.0f);
    glEnd();

    glBegin(GL_QUADS);  //middle 2 tri with a quads
    glColor3ub(128, 128, 128);
    vx(0.0f, 0.0f);
    vx(0.125f, 0.2f);
    vx(0.0f, 0.4f);
    vx(-0.125f, 0.2f);
    glEnd();

    glBegin(GL_POLYGON);  //middle divider
    glColor3ub(166, 166, 166);
    vx(-0.115f, 0.215f);
    vx(-0.125f, 0.2f);
    vx(-0.115f, 0.185f);
    vx(0.115f, 0.185f);
    vx(0.125f, 0.2f);
    vx(0.115f, 0.215f);
    glEnd();

    //main base border
    glBegin(GL_QUADS);  //right first border
    glColor3ub(230, 230, 230);
    vx(0.2f, -0.1f);
    vx(0.21f, -0.1f);
    vx(0.01f, 0.7f);
    vx(0.00f, 0.7f);
    glEnd();

    glBegin(GL_QUADS); //left first border
    glColor3ub(230, 230, 230);
    vx(-0.2f, -0.1f);
    vx(-0.21f, -0.1f);
    vx(-0.01f, 0.7f);
    vx(-0.00f, 0.7f);
    glEnd();

    glBegin(GL_TRIANGLES); //right first piller
    glColor3ub(204, 204, 204);
    vx(0.21f, -0.1f);
    vx(0.3f, -0.1f);
    vx(0.06f, 0.5f);
    glEnd();

    glBegin(GL_TRIANGLES); //left first piller
    glColor3ub(204, 204, 204);
    vx(-0.21f, -0.1f);
    vx(-0.3f, -0.1f);
    vx(-0.06f, 0.5f);
    glEnd();

    glBegin(GL_QUADS);// right second border
    glColor3ub(230, 230, 230);
    vx(0.3f, -0.1f);
    vx(0.31f, -0.1f);
    vx(0.055f, 0.52f);
    vx(0.054f, 0.5f);
    glEnd();

    glBegin(GL_QUADS); //left second border
    glColor3ub(230, 230, 230);
    vx(-0.3f, -0.1f);
    vx(-0.31f, -0.1f);
    vx(-0.055f, 0.52f);
    vx(-0.054f, 0.5f);
    glEnd();

    glBegin(GL_TRIANGLES); //right second piller
    glColor3ub(204, 204, 204);
    vx(0.31f, -0.1f);
    vx(0.4f, -0.1f);
    vx(0.1f, 0.4f);
    glEnd();

    glBegin(GL_TRIANGLES); //left second piller
    glColor3ub(204, 204, 204);
    vx(-0.31f, -0.1f);
    vx(-0.4f, -0.1f);
    vx(-0.1f, 0.4f);
    glEnd();

    glBegin(GL_QUADS); // right third border
    glColor3ub(230, 230, 230);
    vx(0.4f, -0.1f);
    vx(0.41f, -0.1f);
    vx(0.095f, 0.42f);
    vx(0.1f, 0.4f);
    glEnd();

    glBegin(GL_QUADS); //left third border
    glColor3ub(230, 230, 230);
    vx(-0.4f, -0.1f);
    vx(-0.41f, -0.1f);
    vx(-0.095f, 0.42f);
    vx(-0.1f, 0.4f);
    glEnd();

    glBegin(GL_TRIANGLES); //right third piller
    glColor3ub(204, 204, 204);
    vx(0.41f, -0.1f);
    vx(0.5f, -0.1f);
    vx(0.167f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES); //left third piller
    glColor3ub(204, 204, 204);
    vx(-0.41f, -0.1f);
    vx(-0.5f, -0.1f);
    vx(-0.167f, 0.3f);
    glEnd();

    glBegin(GL_QUADS); // right fourth border
    glColor3ub(230, 230, 230);
    vx(0.5f, -0.1f);
    vx(0.51f, -0.1f);
    vx(0.1568f, 0.316f);
    vx(0.16f, 0.3f);
    glEnd();

    glBegin(GL_QUADS); //left fourth border
    glColor3ub(230, 230, 230);
    vx(-0.5f, -0.1f);
    vx(-0.51f, -0.1f);
    vx(-0.1568f, 0.316f);
    vx(-0.16f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES); //right fourth piller
    glColor3ub(204, 204, 204);
    vx(0.51f, -0.1f);
    vx(0.6f, -0.1f);
    vx(0.17f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES); //left fourth piller
    glColor3ub(204, 204, 204);
    vx(-0.51f, -0.1f);
    vx(-0.6f, -0.1f);
    vx(-0.17f, 0.3f);
    glEnd();

    glBegin(GL_QUADS); // right fifth border
    glColor3ub(230, 230, 230);
    vx(0.6f, -0.1f);
    vx(0.615f, -0.1f);
    vx(0.15f, 0.33f);
    vx(0.167f, 0.3f);
    glEnd();

    glBegin(GL_QUADS); //left fifth border
    glColor3ub(230, 230, 230);
    vx(-0.6f, -0.1f);
    vx(-0.615f, -0.1f);
    vx(-0.15f, 0.33f);
    vx(-0.167f, 0.3f);
    glEnd();

    glBegin(GL_TRIANGLES); //right fifth piller
    glColor3ub(204, 204, 204);
    vx(0.61f, -0.1f);
    vx(0.7f, -0.1f);
    vx(0.29f, 0.2f);
    glEnd();

    glBegin(GL_TRIANGLES); //left fifth piller
    glColor3ub(204, 204, 204);
    vx(-0.61f, -0.1f);
    vx(-0.7f, -0.1f);
    vx(-0.29f, 0.2f);
    glEnd();

    glBegin(GL_QUADS); // right sixth border
    glColor3ub(230, 230, 230);
    vx(0.7f, -0.1f);
    vx(0.718f, -0.1f);
    vx(0.25f, 0.24f);
    vx(0.275f, 0.21f);
    glEnd();

    glBegin(GL_QUADS); //left sixth border
    glColor3ub(230, 230, 230);
    vx(-0.7f, -0.1f);
    vx(-0.718f, -0.1f);
    vx(-0.25f, 0.24f);
    vx(-0.275f, 0.21f);
    glEnd();

    glBegin(GL_TRIANGLES); 	//right sixth piller
    glColor3ub(204, 204, 204);
    vx(0.71f, -0.1f);
    vx(0.8f, -0.1f);
    vx(0.3f, 0.2f);
    glEnd();

    glBegin(GL_TRIANGLES); //left sixth piller
    glColor3ub(204, 204, 204);
    vx(-0.71f, -0.1f);
    vx(-0.8f, -0.1f);
    vx(-0.3f, 0.2f);
    glEnd();

    glBegin(GL_QUADS); // right seventh border
    glColor3ub(230, 230, 230);
    vx(0.8f, -0.1f);
    vx(0.82f, -0.1f);
    vx(0.25f, 0.241f);
    vx(0.265f, 0.221f);
    glEnd();

    glBegin(GL_QUADS); //left seventh border
    glColor3ub(230, 230, 230);
    vx(-0.8f, -0.1f);
    vx(-0.82f, -0.1f);
    vx(-0.25f, 0.241f);
    vx(-0.265f, 0.221f);
    glEnd();

}