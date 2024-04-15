#ifndef GLCUBEVIEW_H
#define GLCUBEVIEW_H
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QtMath>

class glCubeView : public QOpenGLWidget
{
    Q_OBJECT
private:
    float xRot, yRot, zRot;
    QPoint mPos;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;
public:
    glCubeView(QWidget *parent = nullptr);
    ~glCubeView();
    void drawCube(float);
};
#endif // GLCUBEVIEW_H
