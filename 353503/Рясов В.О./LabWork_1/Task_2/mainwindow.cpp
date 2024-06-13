#include "mainwindow.h"
#include "paintscene.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), scene(new PaintScene())
{
    ui->setupUi(this);

    ui->graphicsView->setScene(scene);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_figureChoise_currentIndexChanged(int index)
{
    switch (index) {
    case 0:
        scene->setTypeFigure(PaintScene::RectType);
        break;
    case 1:
        scene->setTypeFigure(PaintScene::RhombType);
        break;
    case 2:
        scene->setTypeFigure(PaintScene::TriangleType);
        break;
    case 3:
        scene->setTypeFigure(PaintScene::EllipseType);
        break;
    case 4:
        scene->setTypeFigure(PaintScene::StarType);
        break;
    case 5:
        scene->setTypeFigure(PaintScene::SixStarType);
        break;
    case 6:
        scene->setTypeFigure(PaintScene::EightStarType);
        break;
    case 7:
        scene->setTypeFigure(PaintScene::DeleteType);
        break;
    case 8:
        scene->setTypeFigure(PaintScene::MoveType);
        break;
    case 9:
        scene->setTypeFigure(PaintScene::RotateType);
        break;
    default:
        break;
    }
}

