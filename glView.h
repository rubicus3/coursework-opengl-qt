#ifndef GLVIEW_H
#define GLVIEW_H
#include <QOpenGLWidget>

class glView : public QOpenGLWidget
{
    Q_OBJECT

public:
    glView(QWidget *parent = nullptr);
    ~glView();
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

};
#endif // GLVIEW_H
