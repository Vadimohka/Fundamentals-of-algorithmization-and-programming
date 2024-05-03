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

void MainWindow::paintEvent(QPaintEvent*) {
    QPainter painter(this);
    QBrush brush(Qt::black);

    painter.drawRect(20, 20, 1880, 780);

    painter.setBrush(brush);
    painter.drawRect(310, 140, 40, 660); // столб 1
    painter.drawRect(940, 140, 40, 660); // столб 2
    painter.drawRect(1570, 140, 40, 660); // столб 3

}


void MainWindow::moveRect(Rect* rect, int x, int y) {
    int halfWidth = 20; // половина ширины столба

    // Поднимаем прямоугольник вверх
    animation1 = new QPropertyAnimation(rect, "geometry");
    animation1->setDuration(500/speed); // продолжительность анимации в миллисекундах
    animation1->setStartValue(rect->geometry()); // начальное положение - текущее положение прямоугольника
    animation1->setEndValue(QRect(rect->x(), 40, rect->width(), rect->height())); // конечное положение - прямоугольник поднят вверх
    animation1->start(QAbstractAnimation::DeleteWhenStopped); // начинаем анимацию и удаляем ее, когда она закончится

    QEventLoop loop;
    QObject::connect(animation1, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    // Перемещаем прямоугольник влево или вправо
    animation2 = new QPropertyAnimation(rect, "geometry");
    animation2->setDuration(500/speed); // продолжительность анимации в миллисекундах
    animation2->setStartValue(QRect(rect->x(), 40, rect->width(), rect->height())); // начальное положение - прямоугольник находится наверху
    animation2->setEndValue(QRect(x - rect->width()/2 + halfWidth, 40, rect->width(), rect->height())); // конечное положение - прямоугольник перемещен влево или вправо
    animation2->start(QAbstractAnimation::DeleteWhenStopped); // начинаем анимацию и удаляем ее, когда она закончится

    QObject::connect(animation2, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();

    // Опускаем прямоугольник вниз
    animation3 = new QPropertyAnimation(rect, "geometry");
    animation3->setDuration(500/speed); // продолжительность анимации в миллисекундах
    animation3->setStartValue(QRect(x - rect->width()/2 + halfWidth, 40, rect->width(), rect->height())); // начальное положение - прямоугольник находится вверху
    animation3->setEndValue(QRect(x - rect->width()/2 + halfWidth, y, rect->width(), rect->height())); // конечное положение - новое положение прямоугольника
    animation3->start(QAbstractAnimation::DeleteWhenStopped); // начинаем анимацию и удаляем ее, когда она закончится

    QObject::connect(animation3, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
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
    towers[0] = new Rect*[n];
    towerSizes[0] = n;

    QCoreApplication::processEvents(); // Обрабатываем все ожидающие события удаления

    // Создаем новые диски
    for (int i = 0; i < n; i++) {
        Rect *rect = new Rect(n-i, this);
        rect->setPosition(310 - (n-i)*5, 800 - (i+1)*30);
        rect->show();
        towers[0][i] = rect;
    }
}

void MainWindow::hanoi(int n, Rect**& from, Rect**& to, Rect**& aux, int& sizeFrom, int& sizeTo, int& sizeAux, int x1, int x2, int x3) {

    if (n == 1) {
        count++;
        ui->count->setText(QString::number(count));

        Rect* rect = from[sizeFrom-1];
        Rect** newFrom = new Rect*[sizeFrom - 1]; // выделяем память для нового массива
        for(int i = 0; i < sizeFrom - 1; i++) {
            newFrom[i] = from[i]; // копируем старые элементы
        }
        delete[] from; // удаляем старый массив
        from = newFrom; // обновляем указатель
        sizeFrom--;
        moveRect(rect, x2, 800 - (sizeTo+1)*30); // перемещаем прямоугольник на новую позицию
        Rect** newTo = new Rect*[sizeTo + 1]; // выделяем память для нового элемента
        for(int i = 0; i < sizeTo; i++) {
            newTo[i] = to[i]; // копируем старые элементы
        }
        newTo[sizeTo] = rect; // добавляем новый элемент
        to = newTo; // обновляем указатель
        sizeTo++;
        return;
    }
    hanoi(n - 1, from, aux, to, sizeFrom, sizeAux, sizeTo, x1, x3, x2);
    hanoi(1, from, to, aux, sizeFrom, sizeTo, sizeAux, x1, x2, x3);
    hanoi(n - 1, aux, to, from, sizeAux, sizeTo, sizeFrom, x3, x2, x1);
}



void MainWindow::on_pushButton_clicked()
{
    if (ui->spinBox->value() != 0) {
        count = 0;
        ui->count->setText("0");
        ui->pushButton->setEnabled(false);
        ui->spinBox->setEnabled(false);
        hanoi(towerSizes[0], towers[0], towers[2], towers[1], towerSizes[0], towerSizes[2], towerSizes[1], 310, 1570, 940);
    } else {
        QMessageBox::critical(0, "Ошибка", "Количество колец должно быть больше нуля, чтобы запустить анимацию");
    }
}



void MainWindow::on_end_button_clicked()
{
    ui->count->setText("");
    count = 0;

    if (!animation1.isNull() && animation1->state() == QAbstractAnimation::Running) {
        animation1->stop();
        animation1->deleteLater();
    }
    if (!animation2.isNull() && animation2->state() == QAbstractAnimation::Running) {
        animation2->stop();
        animation2->deleteLater();
    }
    if (!animation3.isNull() && animation3->state() == QAbstractAnimation::Running) {
        animation3->stop();
        animation3->deleteLater();
    }

    QCoreApplication::processEvents(); // Обрабатываем все ожидающие события удаления

    int n = ui->spinBox->value();

    // Удаляем все прямоугольники на экране
    QList<Rect*> rects = findChildren<Rect*>();
    for (Rect* rect : rects) {
        rect->hide();
        rect->deleteLater();
    }

    QCoreApplication::processEvents(); // Обрабатываем все ожидающие события удаления



    delete[] towers[0];
    delete[] towers[1];
    delete[] towers[2];
    towers[0] = nullptr;
    towers[1] = nullptr;
    towers[2] = nullptr;
    towerSizes[0] = 0;
    towerSizes[1] = 0;
    towerSizes[2] = 0;

    double temp = ui->doubleSpinBox->value();
    ui->doubleSpinBox->setValue(1);
    ui->doubleSpinBox->setValue(temp);

    ui->spinBox->setValue(n+1);
    ui->spinBox->setValue(n);

}


void MainWindow::on_doubleSpinBox_valueChanged(double n)
{
    speed = n;
}

