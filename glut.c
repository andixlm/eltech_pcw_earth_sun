#include <time.h>
#include <stdlib.h>
#include <GL/glut.h>

#include "glut.h"
#include "camera.h"
#include "objects.h"
#include "keyboardKeys.h"

#define VISIBLE_MIN_DISTANCE 0.1
#define VISIBLE_MAX_DISTANCE 10000.0

static int showAxes = 0;
static int lockMovement = 0;

void reshapeScene(int width, int height)
{
    if (height == 0)
        height = 1;

    glViewport(0, 0, (GLsizei)width, (GLsizei)height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(45.0, width/(GLdouble)height, VISIBLE_MIN_DISTANCE, VISIBLE_MAX_DISTANCE);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glutPostRedisplay();
}

void renderScene(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    if (directMovement == 1) velocity = VELOCITY_VALUE;
    else if (backMovement == 1) velocity = -VELOCITY_VALUE;

    computeCameraViewAndPosition();
    gluLookAt(camera.position.x, camera.position.y, camera.position.z,
              camera.lookAt.x, camera.lookAt.y, camera.lookAt.z,
              0.0, 1.0, 0.0);

    if (showAxes == 1)
        drawAxes(VISIBLE_MAX_DISTANCE);

    if (closerToCamera(&earth, &sun))
    {
        drawSun();
        drawEarth();
    }
    else
    {
        drawEarth();
        drawSun();
    }

    glutSwapBuffers();
}

void visibleScene(int visible)
{
    if (visible)
        glutIdleFunc(idleScene);
}

void idleScene(void)
{
    glutPostWindowRedisplay(currentWindow);
}

void mousePressed(int button, int state, int x, int y)
{
    if (!lockMovement)
    {
        switch (button)
        {
            case GLUT_LEFT_BUTTON:
                backMovement = 0;
                directMovement = 1;
                break;

            case GLUT_RIGHT_BUTTON:
                directMovement = 0;
                backMovement = 1;
                break;
        }
    }
}

void mouseMotion(int x, int y)
{
    if (!lockMovement)
    {
        if (x - mouse.x > 0) alpha += abs(x - mouse.x);
        if (x - mouse.x < 0) alpha -= abs(x - mouse.x);
        if (y - mouse.y > 0) beta -= abs(y - mouse.y);
        if (y - mouse.y < 0) beta += abs(y - mouse.y);
    }

    mouse.x = x;
    mouse.y = y;

    centerCursor();
}

void mousePassiveMotion(int x, int y)
{
    velocity = 0;
    directMovement = 0; backMovement = 0;

    if (!lockMovement)
    {
        if (x - mouse.x > 0) alpha += abs(x - mouse.x);
        if (x - mouse.x < 0) alpha -= abs(x - mouse.x);
        if (y - mouse.y > 0) beta -= abs(y - mouse.y);
        if (y - mouse.y < 0) beta += abs(y - mouse.y);
    }

    mouse.x = x;
    mouse.y = y;

    centerCursor();
}

void normalKeys(unsigned char key, int x, int y)
{
    switch (key)
    {
        case KEY_ESC:
            exit(0);
            break;
    }
}

void specialKeys(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_F1:
            showAxes = showAxes ? 0 : 1;
            break;
        case GLUT_KEY_F2:
            lockMovement = lockMovement ? 0 : 1;
            break;
    }
}
