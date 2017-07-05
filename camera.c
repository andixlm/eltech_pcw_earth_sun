#include <math.h>
#include <GL/glut.h>

#include "glut.h"
#include "camera.h"

cameraArgs camera;
mousePosition mouse = { 0, 0 };

float velocity = 0;
float alpha = 0, beta = 270;
int directMovement = 0, backMovement = 0;

void computeCameraViewAndPosition(void)
{
    if (alpha > 360)
        alpha = 0;

    if (beta > 360 - 10)
        beta = 360 - 10;
    else if (beta < 180 + 10)
        beta = 180 + 10;

    camera.lookAt.x = sin(alpha * DEGREE);
    camera.lookAt.y = cos(beta * DEGREE);
    camera.lookAt.z = cos(alpha * DEGREE) * sin(beta * DEGREE);

    camera.position.x += velocity * camera.lookAt.x;
    camera.position.y += velocity * camera.lookAt.y;
    camera.position.z += velocity * camera.lookAt.z;

    camera.lookAt.x += camera.position.x;
    camera.lookAt.y += camera.position.y;
    camera.lookAt.z += camera.position.z;
}

static struct distance distanceToS1 = { 0, 0, 0, 0 };
static struct distance distanceToS2 = { 0, 0, 0, 0 };

int closerToCamera(sphere* sphere_1, sphere* sphere_2)
{
    distanceToS1.x = camera.position.x - sphere_1 -> position.x;
    distanceToS1.z = camera.position.z - sphere_1 -> position.z;
    distanceToS1.dist = sqrt(distanceToS1.x * distanceToS1.x + distanceToS1.z * distanceToS1.z);

    distanceToS2.x = camera.position.x - sphere_2 -> position.x;
    distanceToS2.z = camera.position.z - sphere_2 -> position.z;
    distanceToS2.dist = sqrt(distanceToS2.x * distanceToS2.x + distanceToS2.z * distanceToS2.z);

    if (distanceToS1.dist < distanceToS2.dist)
        return 1;
    else
        return 0;
}

void centerCursor(void)
{
    if (mouse.x != WIDTH / 2)
    {
        mouse.x = WIDTH / 2;
        glutWarpPointer(mouse.x, mouse.y);
    }

    if (mouse.y != HEIGHT / 2)
    {
        mouse.y = HEIGHT / 2;
        glutWarpPointer(mouse.x, mouse.y);
    }
}
