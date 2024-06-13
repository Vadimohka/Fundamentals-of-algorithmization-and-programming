#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    myVector<int> vec = myVector<int>();
    int a = 5;
    vec.push_back(a);
    vec.push_back(a+1);
    qDebug() << vec[0] << " " << vec[1];

    vec.resize(10);
    for (int i = 0; i < 10; ++i)
    {
        vec[i] = i+1;
    }
    for (int i = 0; i < 10; ++i)
    {
        qDebug() << vec[i];
    }

    vec.erase(3, 5);
    for (int i = 0; i < vec.size(); ++i)
    {
        qDebug() << vec[i];
    }

    myVector<int> v(std::move(vec));
    qDebug() << vec[1] << vec[2];
    qDebug() << v[1] << v[2];

}

MainWindow::~MainWindow()
{
    delete ui;
}
