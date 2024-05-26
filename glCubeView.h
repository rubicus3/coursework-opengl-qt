#ifndef GLCUBEVIEW_H
#define GLCUBEVIEW_H
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QtMath>
#include <vector>



class glCubeView : public QOpenGLWidget
{
    Q_OBJECT
public:
    enum ObjectState {Cube, Tetra, Circle, Cylinder};
    enum ProjectionState {Frustum, Ortho};
private:
    ObjectState objectState = ObjectState::Cube;
    ProjectionState projectionState = ProjectionState::Frustum;
    QPoint mPos;
    float xRot, yRot, zRot;

    void initializeGL() override;
    void resizeGL(int w, int h) override;
    void paintGL() override;

    void mousePressEvent(QMouseEvent*) override;
    void mouseMoveEvent(QMouseEvent*) override;

    void drawCube(float radius);
    void drawTetra(float radius);
    void drawCircle(float radius);
    void drawCylinder(float radius);
    void changeProjection();

    std::vector<double> getCircleArray(int n, double radius,  double x, double y, double z);
public:
    glCubeView(QWidget *parent = nullptr);
    ~glCubeView();

public slots:
    void changeView(ObjectState state);
    void changeProjectionState(ProjectionState state);
};
#endif // GLCUBEVIEW_H
