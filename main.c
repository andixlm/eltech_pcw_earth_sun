#include <GL/glut.h>

#include "glut.h"
#include "camera.h"
#include "objects.h"
#include "keyboardKeys.h"

int currentWindow;

int main (int argc, char *argv[])
{
    // GLUT initialization
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(WIDTH, HEIGHT);
    currentWindow = glutCreateWindow("Sun and Earth");
    // properties
    glutSetCursor(GLUT_CURSOR_NONE);
    // GLUT handlers
    glutReshapeFunc(reshapeScene);
    glutDisplayFunc(renderScene);
    glutVisibilityFunc(visibleScene);
    glutMouseFunc(mousePressed);
    glutMotionFunc(mouseMotion);
    glutPassiveMotionFunc(mousePassiveMotion);
    glutKeyboardFunc(normalKeys);
    glutSpecialFunc(specialKeys);

    glutMainLoop();

    return 0;
}
