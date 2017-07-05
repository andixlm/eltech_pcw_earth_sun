#ifndef OBJECTS_INCLUDED
#define OBJECTS_INCLUDED

#define ANGLE_DELTA 0.0001
#define SPHERE_QUALITY 20

void drawAxes(float);
void drawSun(void);
void computeEarthPosition(void);
void drawEarth(void);

typedef struct
{
    struct
    {
        float x;
        float y;
        float z;
    } position;

    float radius;
} sphere;

typedef struct
{
    float x;
    float y;
    float z;
} ellipseBorders;

extern sphere sun, earth;

#endif // OBJECTS_INCLUDED
