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
    glEnable(GL_DEPTH_TEST);
}


void glView::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
//    glOrtho(-1, 1, -1, 1, -1, 2);
    glFrustum(-1, 1, -1, 1, 1, 2);
}

float arr[] = {0, 0, -1.5, 1, 0, -1.5, 0, 1, -1.5};

void glView::paintGL()
{
    glClearColor(0.25, 0.1, 0.5, 0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glRotatef(90, 0, 0, 1);


    glVertexPointer(3, GL_FLOAT, 0, &arr);

    glEnableClientState(GL_VERTEX_ARRAY);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    glColor3d(1, 0, 0);
    glDisableClientState(GL_VERTEX_ARRAY);

//    glBegin(GL_TRIANGLES);
//    glColor3d(1, 0, 0);
//    glVertex3d(0, 0, -1.5);
//    glVertex3d(1, 0, -1.5);
//    glVertex3d(0, 1, -1.5);
//    glEnd();

}

