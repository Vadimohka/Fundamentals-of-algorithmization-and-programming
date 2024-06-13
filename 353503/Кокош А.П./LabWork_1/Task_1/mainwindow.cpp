#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , scene(new QGraphicsScene())

{
    ui->setupUi(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    Shar *shar = new Shar();
    const int x_pos = -30;
    const int y_pos = -30;
    shar->setPos(x_pos, y_pos);
    itemsId.push_back(shar->getId());
    scene->addItem(shar);
}

void MainWindow::on_deletebutton_clicked()
{
    if (!itemsId.isEmpty()) {
        Shar *deletedShar = nullptr;
        foreach (QGraphicsItem *item, scene->items()) {
            Shar *shar = static_cast<Shar *>(item);
            if (itemsId.back() == shar->getId()) {
                deletedShar = shar;
            }
        }
        itemsId.pop_back();

        scene->removeItem(deletedShar);
    }
}
