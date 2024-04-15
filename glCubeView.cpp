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
    // Включаем буфер глубины, для корректной проекции объекта
    glEnable(GL_DEPTH_TEST);
}


void glView::resizeGL(int w, int h)
{
    // Устанавливаем размер области просмотра как размер окна
    glViewport(0, 0, w, h);

    // Устанавливаем режим работы с буфером в режим проекции
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Устанавливаем проекцию в режим перспективной проекции
    glFrustum(-1, 1, -1, 1, 1, 3);
}

void glView::paintGL()
{
    // Включаем буфер глубины, для корректной проекции объекта
    glEnable(GL_DEPTH_TEST);

    // Задаём цвет фона
    glClearColor(0.25, 0.1, 0.5, 0);

    // Очищаем буфера цвета и глубины
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);

    // Заменяем текущую матрицу новой
    glLoadIdentity();

    // Перемещаем камеру на -2 по оси z
    glTranslatef(0, 0, -2);

    // Поворачиваем камеру вокруг оси x и y на xRot и yRot градусов
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);

    // Вызываем функцию отрисовки куба
    drawCube(0.5);
}

// Обрабатываем нажатие мышкой и запоминаем позицию нажатия
void glView::mousePressEvent(QMouseEvent* mo) {
    mPos = mo->pos();
}

// Обрабатываем нажатие мышкой и получаем углы вращения в зависимости от перемещения мышкой от изначальной позиции
void glView::mouseMoveEvent(QMouseEvent* mo) {
    xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
    yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
    update();
}


// Функция отрисовки куба
void glView::drawCube(float a)
{
    // Задаём вектор вершин куба
    float ver_cub[] = {
        -a, -a,  a,   a, -a,  a,    a,  a,  a,    -a,  a,  a,
         a, -a, -a,  -a, -a, -a,   -a,  a, -a,     a,  a, -a,
        -a, -a, -a,  -a, -a,  a,   -a,  a,  a,    -a,  a, -a,
         a, -a,  a,   a, -a, -a,    a,  a,- a,     a,  a,  a,
        -a, -a,  a,   a, -a,  a,    a, -a, -a,    -a, -a, -a,
        -a,  a,  a,   a,  a,  a,    a,  a, -a,    -a,  a, -a,
    };

    // Задаём цвета граней куба
    float color_arr[] = {
        1, 0, 0,   1, 0, 0,   1, 0, 0,   1, 0, 0,
        0, 0, 1,   0, 0, 1,   0, 0, 1,   0, 0, 1,
        1, 1, 0,   1, 1, 0,   1, 1, 0,   1, 1, 0,
        0, 1, 1,   0, 1, 1,   0, 1, 1,   0, 1, 1,
        1, 0, 1,   1, 0, 1,   1, 0, 1,   1, 0, 1,
        1, 0.5, 0.5, 1, 0.5, 0.5, 1, 0.5, 0.5, 1, 0.5, 0.5,
    };

    // Задаём матрицы вершин и цветов
    glVertexPointer(3, GL_FLOAT, 0, &ver_cub);
    glColorPointer(3, GL_FLOAT, 0, &color_arr);

    // Включаем клиенту обработку массивов вершин и цветов
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Отрисуем куб квадратными полигонами
    glDrawArrays(GL_QUADS, 0, 24);

    // Выключаем клиенту обработку массивов вершин и цветов
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}












