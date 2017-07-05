#ifndef CAMERA_INCLUDED
#define CAMERA_INCLUDED

#define PI 3.1415926
#define DEGREE PI / 180.0

#include "objects.h"

#define VELOCITY_VALUE 0.1

void computeCameraViewAndPosition(void);
void centerCursor(void);

int closerToCamera(sphere*, sphere*);

typedef struct
{
    int x;
    int y;
} mousePosition;

typedef struct
{
    struct
    {
        float x;
        float y;
        float z;
    } position;

    struct
    {
        float x;
        float y;
        float z;
    } lookAt;
} cameraArgs;

struct distance
{
        float x;
        float y;
        float z;
        float dist;
};

extern cameraArgs camera;
extern mousePosition mouse;

extern float velocity;
extern float alpha, beta;
extern int directMovement, backMovement;

#endif // CAMERA_INCLUDED
