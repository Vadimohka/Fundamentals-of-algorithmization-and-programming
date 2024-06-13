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

void MainWindow::update()
{
    ui->showWidget->clear();
    for (auto el : test.toVector())
        ui->showWidget->addItem(QString::number(el));
}

void MainWindow::on_append_button_clicked()
{
    test.append(ui->value->text().toInt());
    update();
}


void MainWindow::on_pop_back_button_clicked()
{
    test.pop_back();
    update();
}


void MainWindow::on_pop_front_button_clicked()
{
    test.pop_front();
    update();
}


void MainWindow::on_push_front_button_clicked()
{
    test.push_front(ui->value->text().toInt());
    update();
}


void MainWindow::on_filling_clicked()
{
    test.clear();
    test2.clear();

    for (int i = 0; i < 20; ++i) {
        test.append(QRandomGenerator64::global()->bounded(100));
    }
    for (int i = 0; i < 20; ++i) {
        test2.append(QRandomGenerator64::global()->bounded(100));
    }

    update();

    for (auto el : test2.toVector())
        ui->showWidget_2->addItem(QString::number(el));
}


void MainWindow::on_pushButton_clicked()
{
    QVector<int> a = test.toVector(), b = test2.toVector();
    int maxind = 0;
    for (int i = 0; i < a.size(); ++i){
        if (a[maxind] < a[i]) maxind = i;
    }

    for (int i = 0; i < b.size(); ++i) {
        a.insert(maxind + i + 1, b[i]);
    }

    test.clear();

    for (int i = 0; i < a.size(); ++i) {
        test.append(a[i]);
    }

    update();

}

