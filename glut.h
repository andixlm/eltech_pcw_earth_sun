#ifndef GLUTHANDLERS_INCLUDED
#define GLUTHANDLERS_INCLUDED

#define WIDTH 640
#define HEIGHT 480

void reshapeScene(int, int);
void renderScene(void);
void idleScene(void);
void visibleScene(int);
void mousePressed(int, int, int, int);
void mouseMotion(int, int);
void mousePassiveMotion(int, int);
void normalKeys(unsigned char, int, int);
void specialKeys(int, int, int);

extern int currentWindow;

#endif // GLUTHANDLERS_INCLUDED
