#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "glCubeView.h"

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);

    connect(ui->toCubeBtn, &QPushButton::clicked, [=]() {
        ui->openGLWidget->changeView(glCubeView::ObjectState::Cube);
    });

    connect(ui->toTetraBtn, &QPushButton::clicked, [=]() {
        ui->openGLWidget->changeView(glCubeView::ObjectState::Tetra);
    });

    connect(ui->toCircleBtn, &QPushButton::clicked, [=]() {
        ui->openGLWidget->changeView(glCubeView::ObjectState::Circle);
    });

    connect(ui->toCylinderBtn, &QPushButton::clicked, [=]() {
        ui->openGLWidget->changeView(glCubeView::ObjectState::Cylinder);
    });

    connect(ui->frustumBtn, &QPushButton::clicked, [=]() {
        ui->openGLWidget->changeProjectionState(glCubeView::ProjectionState::Frustum);
    });

    connect(ui->orthoBtn, &QPushButton::clicked, [=]() {
        ui->openGLWidget->changeProjectionState(glCubeView::ProjectionState::Ortho);
    });
}

mainWidget::~mainWidget()
{
    delete ui;
}

