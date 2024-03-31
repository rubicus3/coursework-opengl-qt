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
}

void glView::paintGL()
{
    glClearColor(0.25, 0.1, 0.5, 0);
    glClear(GL_COLOR_BUFFER_BIT);
}

