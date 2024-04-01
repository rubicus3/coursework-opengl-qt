#include "glView.h"

glView::glView(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

glView::~glView()
{
}


void glView::initializeGL()
{

}


void glView::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
//    glMatrixMode(GL_PROJECTION);

}

void glView::paintGL()
{
    glClearColor(0.25, 0.1, 0.5, 0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(90, 0, 0, 1);

    glBegin(GL_TRIANGLES);
    glColor3d(1, 0, 0);
    glVertex2d(0, 0);
    glVertex2d(1, 0);
    glVertex2d(0, 1);

    glEnd();
}

