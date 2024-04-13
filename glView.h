#ifndef GLVIEW_H
#define GLVIEW_H
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QtMath>

class glView : public QOpenGLWidget
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
    glView(QWidget *parent = nullptr);
    ~glView();
    void drawCube(float);
};
#endif // GLVIEW_H
