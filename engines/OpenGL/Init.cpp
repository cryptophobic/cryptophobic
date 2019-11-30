#include <GL/freeglut.h>
#include <GL/gl.h>
#include <functional>
#include "controller/Controller.h"

#include "Init.h"

void Init::renderSceneCB()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glutSwapBuffers();
}

void Init::initializeGlutCallbacks()
{
    glutDisplayFunc(Init::renderSceneCB);
}

void Init::start(int argc, char* argv[])
{
    Controller cnt;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGBA);
    glutInitWindowSize(1024, 768);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Tutorial 01");

    Init::initializeGlutCallbacks();

    // http://www.alecjacobson.com/weblog/?p=3779
    static std::function<void(int, int, int)> control_bounce = [&cnt] (int key, int x, int y) {return cnt.control(key, x, y);};
    auto control = [] (int key, int x, int y) {control_bounce(key, x, y);};
    //glutKeyboardFunc(control);
    glutSpecialFunc(control);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glutMainLoop();
}
