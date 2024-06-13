#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    task1_Button.setText("Задание №1");
    task2_Button.setText("Задание №2");
    task3_Button.setText("Задание №3");
    task4_Button.setText("Задание №4");
    task5_Button.setText("Задание №5");

    task1_Button.setFixedSize(BUTTON_W_SIZE, BUTTON_H_SIZE);
    task2_Button.setFixedSize(BUTTON_W_SIZE, BUTTON_H_SIZE);
    task3_Button.setFixedSize(BUTTON_W_SIZE, BUTTON_H_SIZE);
    task4_Button.setFixedSize(BUTTON_W_SIZE, BUTTON_H_SIZE);
    task5_Button.setFixedSize(BUTTON_W_SIZE, BUTTON_H_SIZE);

    QVBoxLayout *layout = new QVBoxLayout(ui->centralwidget);
    connect(&task1_Button, &QPushButton::clicked, &task1, &Task1::startDialog);
    layout->addWidget(&task1_Button);
    connect(&task2_Button, &QPushButton::clicked, &task2, &Task2::startDialog);
    layout->addWidget(&task2_Button);
    connect(&task3_Button, &QPushButton::clicked, &task3, &Task3::startDialog);
    layout->addWidget(&task3_Button);
    connect(&task4_Button, &QPushButton::clicked, &task4, &Task4::startDialog);
    layout->addWidget(&task4_Button);
    connect(&task5_Button, &QPushButton::clicked, &task5, &Task5::startDialog);
    layout->addWidget(&task5_Button);

    layout->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

