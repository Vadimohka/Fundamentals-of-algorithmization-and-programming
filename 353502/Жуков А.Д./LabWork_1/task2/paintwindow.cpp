 #include "paintwindow.h"
#include "ui_paintwindow.h"

paintWindow::paintWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paintWindow),
    scene(new Canvas(this))
{
    ui->setupUi(this);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

paintWindow::~paintWindow()
{
    delete ui;
}

void paintWindow::getSize(int w, int h)
{
    ui->graphicsView->setFixedSize(w, h);
    scene->setSceneRect(0, 0, w, h);
    ui->graphicsView->setScene(scene);
}
