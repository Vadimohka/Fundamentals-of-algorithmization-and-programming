#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent): QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::insertInHash16);

    int temp = 0;
    srand(time(nullptr));
    for (int i = 0; i < 10; ++i)
    {
        temp = 1 + rand() % MAX_KEY_SIZE;
        hash16.insertItem(temp, temp);
    }

    demonstrateHash16();
}


MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::insertInHash16()
{
    int key = ui->keySpinBox->value();
    int value = ui->valueSpinBox->value();
    hash16.insertItem(key, value);

    demonstrateHash16();
}


void MainWindow::demonstrateHash16()
{
    answer = "";
    QVector<QPair<int, int>> vec = hash16.displayHash();
    for (int i = 0; i < vec.size(); ++i)
    {
        answer += QString::number(i+1) + ": ";
        answer += QString::number(vec[i].first) + " ";
        answer += QString::number(vec[i].second) + "\n";
    }

    ui->demonstratingBrowser->setText(answer);
}
