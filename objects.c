#include <math.h>
#include <GL/glut.h>

#include "glut.h"
#include "camera.h"
#include "objects.h"

void drawAxes(float length)
{
    glBegin(GL_LINES);
    // red abscissa
    glColor3f(1, 0, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(length, 0, 0);
    // green ordinate
    glColor3f(0, 1, 0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, length, 0);
    // blue applicate
    glColor3f(0, 0, 1);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, length);
    glEnd();
    // set white color
    glColor3f(1, 1, 1);
}

sphere sun = { { 30, 0 , 0 }, 20 };
void drawSun(void)
{
    glPushMatrix();
    glTranslatef(sun.position.x, sun.position.y, sun.position.z);
    glColor3f(1, 1, 0);
    glutSolidSphere(sun.radius, SPHERE_QUALITY, SPHERE_QUALITY);
    glColor3f(1, 1, 1);
    glPopMatrix();
}

static float angle = 0;
sphere earth = { { 0, 0, 0 }, 5 };
static ellipseBorders earthBorders = { 100, 0, 80 };
void computeEarthPosition(void)
{
    angle += ANGLE_DELTA;
    if (angle > 360)
        angle = 0;

    earth.position.x = earthBorders.x * cos(angle);
    // earth.position.y is always 0
    earth.position.z = earthBorders.z * sin(angle);
}

void drawEarth(void)
{
    computeEarthPosition();

    glPushMatrix();
    glTranslatef(earth.position.x, earth.position.y, earth.position.z);
    glColor3f(0, 0.5, 0.8);
    glutSolidSphere(earth.radius, SPHERE_QUALITY, SPHERE_QUALITY);
    glColor3f(1, 1, 1);
    glPopMatrix();
}
