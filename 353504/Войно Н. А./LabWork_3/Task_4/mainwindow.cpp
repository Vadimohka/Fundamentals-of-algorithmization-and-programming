#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    if (ui->spinBox->value() != 0) {
        count = 0;
        //ui->count->setText("0");
        ui->pushButton->setEnabled(false);
        ui->spinBox->setEnabled(false);
        hanoi(towerSizes[0], towers[0], towers[2], towers[1], towerSizes[0], towerSizes[2], towerSizes[1], 310, 1010, 660);
    }
    else
    {
        QMessageBox::critical(0, "Ошибка", "Количество колец должно быть больше нуля");
    }
}


void MainWindow::on_spinBox_valueChanged(int n)
{
    ui->pushButton->setEnabled(true);
    ui->spinBox->setEnabled(true);
    // Удаляем старые диски
    for (int i = 0; i < towerSizes[0]; i++) {
        towers[0][i]->hide();
        towers[0][i]->deleteLater();
    }
    delete[] towers[0];
    towers[0] = new Ring*[n];
    towerSizes[0] = n;

    QCoreApplication::processEvents(); // Обрабатываем все ожидающие события удаления

    // Создаем новые диски
    for (int i = 0; i < n; i++) {
        Ring *ring = new Ring(n-i, this);
        ring->setPosition(300 - (n-i)*5, 500 - (i+1)*30);
        ring->show();
        towers[0][i] = ring;
    }
}

void MainWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    QBrush brush(Qt::black);

    //painter.drawRect(20, 20, 1880, 780);

    painter.setBrush(brush);
    painter.drawRect(310, 140, 10, 350); // столб 1
    painter.drawRect(660, 140, 10, 350); // столб 2
    painter.drawRect(1010, 140, 10, 350); // столб 3

}


void MainWindow::moveRing(Ring* ring, int x, int y) {
    int halfWidth = 5; // половина ширины столба

    // Поднимаем прямоугольник вверх
    animationUp = new QPropertyAnimation(ring, "geometry");
    animationUp->setDuration(500/speed); // продолжительность анимации в миллисекундах
    animationUp->setStartValue(ring->geometry()); // начальное положение - текущее положение прямоугольника
    animationUp->setEndValue(QRect(ring->x(), 40, ring->width(), ring->height())); // конечное положение - прямоугольник поднят вверх
    animationUp->start(QAbstractAnimation::DeleteWhenStopped); // начинаем анимацию и удаляем ее, когда она закончится

    QEventLoop loop;
    QObject::connect(animationUp, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    // Перемещаем прямоугольник влево или вправо
    animationLeftOrRight = new QPropertyAnimation(ring, "geometry");
    animationLeftOrRight->setDuration(500/speed);
    animationLeftOrRight->setStartValue(QRect(ring->x(), 40, ring->width(), ring->height()));
    animationLeftOrRight->setEndValue(QRect(x - ring->width()/2 + halfWidth, 40, ring->width(), ring->height()));
    animationLeftOrRight->start(QAbstractAnimation::DeleteWhenStopped);

    QObject::connect(animationLeftOrRight, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    animationDown = new QPropertyAnimation(ring, "geometry");
    animationDown->setDuration(500/speed); // продолжительность анимации в миллисекундах
    animationDown->setStartValue(QRect(x - ring->width()/2 + halfWidth, 40, ring->width(), ring->height()));
    animationDown->setEndValue(QRect(x - ring->width()/2 + halfWidth, y, ring->width(), ring->height()));
    animationDown->start(QAbstractAnimation::DeleteWhenStopped);

    QObject::connect(animationDown, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
}


void MainWindow::hanoi(int n, Ring**& from, Ring**& to, Ring**& aux, int& sizeFrom, int& sizeTo, int& sizeAux, int x1, int x2, int x3) {

    if (n == 1) {
        count++;
        ui->label_2->setText(QString::number(count));

        Ring* ring = from[sizeFrom-1];
        Ring** newFrom = new Ring*[sizeFrom - 1];
        for(int i = 0; i < sizeFrom - 1; i++) {
            newFrom[i] = from[i];
        }
        delete[] from;
        from = newFrom;
        sizeFrom--;
        moveRing(ring, x2, 500 - (sizeTo+1)*30);
        Ring** newTo = new Ring*[sizeTo + 1];
        for(int i = 0; i < sizeTo; i++) {
            newTo[i] = to[i];
        }
        newTo[sizeTo] = ring;
        to = newTo;
        sizeTo++;
        return;
    }
    hanoi(n - 1, from, aux, to, sizeFrom, sizeAux, sizeTo, x1, x3, x2);
    hanoi(1, from, to, aux, sizeFrom, sizeTo, sizeAux, x1, x2, x3);
    hanoi(n - 1, aux, to, from, sizeAux, sizeTo, sizeFrom, x3, x2, x1);
}


void MainWindow::on_doubleSpinBox_valueChanged(double n)
{
    speed = n;
}

