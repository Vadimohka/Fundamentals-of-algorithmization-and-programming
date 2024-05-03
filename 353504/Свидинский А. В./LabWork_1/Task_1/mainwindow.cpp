#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPainter>
#include <QPropertyAnimation>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setMinimumWidth(700);
    this->setMinimumHeight(500);

    flag = new Flag(this);
    flag->move(395, 220);
    isFlagUp = false;

    flagUpPosition = QPoint(flag->x(), 120);
    flagDownPosition = QPoint(flag->x(), 220);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QBrush(QColorConstants::Svg::turquoise, Qt::SolidPattern));
    painter.drawRect(this->rect());

    QRectF rectangle(190.0, 220.0, 380.0, 200.0);
    int startAngle = 180 * 16;
    int spanAngle = 180 * 16;

    painter.setBrush(QBrush(QColorConstants::Svg::brown, Qt::SolidPattern));
    painter.drawPie(rectangle, startAngle, spanAngle);

    QPen pen(Qt::black, 10);
    painter.setPen(pen);
    painter.drawLine(390, 315, 390, 120);

    painter.end();
}

void MainWindow::on_pushButton_clicked()
{
    if (!isFlagUp) {
        flag->raiseFlag();
        isFlagUp = true;
    } else {
        flag->lowerFlag();
        isFlagUp = false;
    }
}
