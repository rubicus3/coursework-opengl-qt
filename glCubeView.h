#ifndef GLCUBEVIEW_H
#define GLCUBEVIEW_H
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QtMath>



class glCubeView : public QOpenGLWidget
{
    Q_OBJECT
public:
    enum ObjectState {Cube, Tetra, Circle, Cylinder};
    enum ProjectionState {Frustum, Ortho};
private:
    ObjectState objectState = ObjectState::Cube;
    ProjectionState projectionState = ProjectionState::Frustum;
    float xRot, yRot, zRot;
    QPoint mPos;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;

    double* getCircleArray(int n, double radius, QVector3D center);

    void changeProjection();
public:
    glCubeView(QWidget *parent = nullptr);
    ~glCubeView();
    void drawCube(float);
    void drawTetra(float);
    void drawCircle(float radius);


public slots:
    void changeView(ObjectState state);
    void changeProjectionState(ProjectionState state);
};
#endif // GLCUBEVIEW_H
