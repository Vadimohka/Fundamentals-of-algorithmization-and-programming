#include "mainwindow.h"
#include "ui_mainwindow.h"

constexpr int DELAY = 10;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QTimer *timer = new QTimer();
    connect(timer, SIGNAL(timeout()), this, SLOT(repaint()));
    timer->start(DELAY);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter canv;

    canv.begin(this);
    canv.setBrush(QBrush(Qt::yellow, Qt::SolidPattern));
    canv.drawRect(shape->paint());
    canv.end();

    if (ui->rb1->isChecked())
    {
        canv.begin(this);
        canv.setBrush(QBrush(Qt::white, Qt::SolidPattern));
        canv.drawPolygon(shape2->paint());
        canv.end();

        shape->move_shape(width());
        shape2->move_shape(width());
    }

    Q_UNUSED(event);
}
