#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "visual.h"
#include <QThread>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    scene = new Visual();
    scene->setSceneRect(0, 0, 650, 300);
    QGraphicsView *view = new QGraphicsView(scene, this);
    view->setGeometry(50, 150, 700, 450);
    ui->textEdit->setReadOnly(true);

    view->show();
}

void MainWindow::hanoi(int n, char from_rod, char to_rod, char aux_rod)
{
    if(n < 1){return;}

    if (n == 1) {
        ui->textEdit->append(QString("Переместить диск 1 с стержня %1 на стержень %2").arg(from_rod).arg(to_rod));
        return;
    }
    hanoi(n - 1, from_rod, aux_rod, to_rod);
    ui->textEdit->append(QString("Переместить диск %1 с стержня %2 на стержень %3").arg(n).arg(from_rod).arg(to_rod));
    hanoi(n - 1, aux_rod, to_rod, from_rod);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->textEdit->clear();
    QString input = ui->lineEdit->text();
    int n = input.toInt();
    if (n > 10){
        QMessageBox::critical(nullptr, "Ошибка", "Переполнение стека!");
        ui->lineEdit->clear();
        return;
    }
    hanoi(n, 'A', 'C', 'B');
    showItems(n);
}

void MainWindow::showItems(int amount)
{
    scene->clear();
    hanoibricks.clear();
    rod_a = scene->intializeItems();
    rod_a->setParams(50, 0, 10, 300);
    scene->addItem(rod_a);
    rod_b = scene->intializeItems();
    rod_b->setParams(300, 0, 10, 300);
    scene->addItem(rod_b);
    rod_c = scene->intializeItems();
    rod_c->setParams(550, 0, 10, 300);
    scene->addItem(rod_c);
    for(int i = 0; i < amount; ++i){
        HanoiBrick* brick = scene->intializeItems();
        brick->setParams(i);
        scene->addItem(brick);
        hanoibricks.push_back(brick);
    }
    scene->update();
}

/*void MainWindow::moveItems(int amount)
{
    /*if(amount < 1){return;}

    if (amount == 1) {
        hanoibricks.front()->setPos(500, 0);
        scene->update();
        return;
    }
    moveItems(amount - 1);
    hanoibricks.at(amount-1)->moveBy(500, 0);
    moveItems(amount - 1);
    if(amount < 1){return;}

    for (int i = 0; i < amount; ++i) {
        hanoibricks.at(i)->setPos(500, 0);
        QThread timer;
        scene->update();
        timer.sleep(1);
    }
    scene->update();
}*/



