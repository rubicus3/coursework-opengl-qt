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
    glFrustum(-1, 1, -1, 1, 1, 3);
}

void glView::paintGL()
{
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.25, 0.1, 0.5, 0);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glTranslatef(0, 0, -2);

    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);

    drawCube(0.5);
}

void glView::mousePressEvent(QMouseEvent* mo) {
    mPos = mo->pos();
}

void glView::mouseMoveEvent(QMouseEvent* mo) {
    xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
    yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
    update();
}




void glView::drawCube(float a)
{

    float ver_cub[] = {
        -a, -a,  a,   a, -a,  a,    a,  a,  a,    -a,  a,  a,
         a, -a, -a,  -a, -a, -a,   -a,  a, -a,     a,  a, -a,
        -a, -a, -a,  -a, -a,  a,   -a,  a,  a,    -a,  a, -a,
         a, -a,  a,   a, -a, -a,    a,  a,- a,     a,  a,  a,
        -a, -a,  a,   a, -a,  a,    a, -a, -a,    -a, -a, -a,
        -a,  a,  a,   a,  a,  a,    a,  a, -a,    -a,  a, -a,
    };

    float color_arr[] = {
        1, 0, 0,   1, 0, 0,   1, 0, 0,   1, 0, 0,
        0, 0, 1,   0, 0, 1,   0, 0, 1,   0, 0, 1,
        1, 1, 0,   1, 1, 0,   1, 1, 0,   1, 1, 0,
        0, 1, 1,   0, 1, 1,   0, 1, 1,   0, 1, 1,
        1, 0, 1,   1, 0, 1,   1, 0, 1,   1, 0, 1,
        1, 0.5, 0.5, 1, 0.5, 0.5, 1, 0.5, 0.5, 1, 0.5, 0.5,
    };

    glVertexPointer(3, GL_FLOAT, 0, &ver_cub);
    glColorPointer(3, GL_FLOAT, 0, &color_arr);

    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    glDrawArrays(GL_QUADS, 0, 24);

    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}












