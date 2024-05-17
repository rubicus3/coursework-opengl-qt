#include "glCubeView.h"
#include<QDebug>
#include <QVector3D>
#include<vector>


glCubeView::glCubeView(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

glCubeView::~glCubeView()
{
}


void glCubeView::initializeGL()
{
    // Включаем буфер глубины, для корректной проекции объекта
    glEnable(GL_DEPTH_TEST);
}


void glCubeView::resizeGL(int w, int h)
{
    // Устанавливаем размер области просмотра как размер окна
    glViewport(0, 0, w, h);

    // Устанавливаем режим работы с буфером в режим проекции
    glMatrixMode(GL_PROJECTION);

    // Загрузка единичной матрицы
    glLoadIdentity();

    // Устанавливаем проекцию в режим перспективной проекции
    glFrustum(-1, 1, -1, 1, 1, 3);
}

void glCubeView::paintGL()
{
    qInfo() << "PaintGL call";
    // Задаём цвет фона
    glClearColor(0.17, 0.49, 0.38, 1);

    // Очищаем буфера цвета и глубины
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    // Устанавливаем режим работы с буфером в режим модели/вида
    glMatrixMode(GL_MODELVIEW);

    // Загрузка единичной матрицы
    glLoadIdentity();

    // Перемещаем камеру на -2 по оси z
    glTranslatef(0, 0, -2);

    // Поворачиваем камеру вокруг оси x и y на xRot и yRot градусов
    glRotatef(xRot, 1, 0, 0);
    glRotatef(yRot, 0, 1, 0);

    // Вызываем функцию отрисовки в зависимости от состояния
    changeProjection();

    if(objectState == ObjectState::Cube) drawCube(0.5);
    else if(objectState == ObjectState::Tetra) drawTetra(0.5);
    else if(objectState == ObjectState::Circle)     drawCircle(1);
    else if(objectState == ObjectState::Cylinder) {}

}

// Обрабатываем нажатие мышкой и запоминаем позицию нажатия
void glCubeView::mousePressEvent(QMouseEvent* mo) {
    mPos = mo->pos();
}

// Обрабатываем нажатие мышкой и получаем углы вращения в зависимости от перемещения мышкой от изначальной позиции
void glCubeView::mouseMoveEvent(QMouseEvent* mo) {
    xRot = 1 / M_PI * (mo->pos().y() - mPos.y());
    yRot = 1 / M_PI * (mo->pos().x() - mPos.x());
    update();
}

void glCubeView::changeView(ObjectState state) {
    qInfo() << "Changing drawing state to: " << state;
    this->objectState = state;
    xRot = 0;
    yRot = 0;
    update();
}

void glCubeView::changeProjection(){
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if(projectionState == glCubeView::ProjectionState::Frustum) {
        glFrustum(-1, 1, -1, 1, 1, 3);
    }
    else if(projectionState == glCubeView::ProjectionState::Ortho) {
        glOrtho(-1, 1, -1, 1, 1, 3);
    }

}

void glCubeView::changeProjectionState(ProjectionState state){
    qInfo() << "Changing projection state to: " << state;
    projectionState = state;
    update();
}




// Функция отрисовки куба
void glCubeView::drawCube(float a)
{
    // Задаём вектор вершин куба
    float ver_cub[] = {
        -a, -a,  a,   a, -a,  a,    a,  a,  a,    -a,  a,  a,
         a, -a, -a,  -a, -a, -a,   -a,  a, -a,     a,  a, -a,
        -a, -a, -a,  -a, -a,  a,   -a,  a,  a,    -a,  a, -a,
         a, -a,  a,   a, -a, -a,    a,  a, -a,     a,  a,  a,
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
        0, 1, 0,   0, 1, 0,   0, 1, 0,   0, 1, 0,
    };

    // Задаём матрицы вершин и цветов
    glVertexPointer(3, GL_FLOAT, 0, &ver_cub);
    glColorPointer(3, GL_FLOAT, 0, &color_arr);

    // Включаем обработку массивов вершин и цветов
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Отрисуем куб квадратными полигонами
    glDrawArrays(GL_QUADS, 0, 24);

    // Выключаем обработку массивов вершин и цветов
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}


void glCubeView::drawTetra(float a) {
    // Задаём вектор вершин тетраэдра
    float ver_cub[] = {
        -a, 0, a,  a, 0, a,  0, 1.5f * a,  0,
        -a, 0, a,  a, 0, a,  0, 0, -a,
        -a, 0, a,  0, 1.5f * a, 0,  0, 0, -a,
         a, 0, a,  0, 1.5f * a, 0,  0, 0, -a,
    };

    // Задаём цвета граней тетраэдра
    float color_arr[] = {
        1, 0, 0,  1, 0, 0,  1, 0, 0,
        1, 1, 0,  1, 1, 0,  1, 1, 0,
        1, 0, 1,  1, 0, 1,  1, 0, 1,
        0, 0, 1,  0, 0, 1,  0, 0, 1,
    };

    // Задаём матрицы вершин и цветов
    glVertexPointer(3, GL_FLOAT, 0, &ver_cub);
    glColorPointer(3, GL_FLOAT, 0, &color_arr);

    // Включаем клиенту обработку массивов вершин и цветов
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Отрисуем тетраэдра треугольными полигонами
    glDrawArrays(GL_TRIANGLES, 0, 12);

    // Выключаем клиенту обработку массивов вершин и цветов
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}

void glCubeView::drawCircle(float radius) {
    int n = 16;

    double* ver = getCircleArray(n, radius, QVector3D(0, 0, 0));

    std::vector<double> verv(ver, ver + n * 3);

//    double ver[] = {
//        0, 0, 0,
//        0.5, 0, 0,
//        0, 0.5, 0,
//        -0.5, 0, 0,
//        0, -0.5, 0,
//        0.5, 0, 0
//    };

    std::vector<double> color_v;
    for(int i = 0; i < n + 2; i++) {
        color_v.push_back(1);
        color_v.push_back(0);
        color_v.push_back(0);
    }
    double* color_arr = color_v.data();


    // Задаём матрицы вершин и цветов
    glVertexPointer(3, GL_DOUBLE, 0, ver);
    glColorPointer(3, GL_DOUBLE, 0, color_arr);

    // Включаем клиенту обработку массивов вершин и цветов
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Отрисуем тетраэдра треугольными полигонами
    glDrawArrays(GL_TRIANGLE_FAN, 0, n + 2);

    // Выключаем клиенту обработку массивов вершин и цветов
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisableClientState(GL_COLOR_ARRAY);
}


double* glCubeView::getCircleArray(int n, double radius, QVector3D center) {

    std::vector<double> ver = { center.x(), center.y(), center.z()  };


    double astep = 2 * M_PI / n; // Шаг прохода угла в радианах


    for(int i = 0; i <= n; i++) {
        double angle = astep * i;
        ver.push_back(round(radius * cos(angle) * 10000000.0) / 10000000.0 + center.x()); // x
        ver.push_back(round(radius * sin(angle) * 10000000.0) / 10000000.0 + center.y()); // y
        ver.push_back(center.z());                   // z
    }
//    ver.push_back(radius); // x
//    ver.push_back(0);      // y
//    ver.push_back(0);      // z


    for(int i = 0; i < ver.size(); i+=3) {
        qInfo() << ver[i] << " " << ver[i + 1] << " " << ver[i + 2];
    }


    double* v = ver.data();

    return v;
}











