#include "mainwidget.h"
#include "ui_mainwidget.h"
#include "glCubeView.h"

mainWidget::mainWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::mainWidget)
{
    ui->setupUi(this);

    connect(ui->changeToCube, &QPushButton::clicked, [=]() {
        ui->openGLWidget->changeState(glCubeView::State::Cube);
    });

    connect(ui->changeToTetra, &QPushButton::clicked, [=]() {
        ui->openGLWidget->changeState(glCubeView::State::Tetra);
    });
}

mainWidget::~mainWidget()
{
    delete ui;
}

