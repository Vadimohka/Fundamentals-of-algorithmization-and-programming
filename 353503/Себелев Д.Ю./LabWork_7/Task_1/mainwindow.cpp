#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Queue");

    connect(ui->pushBack_btn, &QPushButton::clicked, this, &MainWindow::pushBack);
    connect(ui->pushFront_btn, &QPushButton::clicked, this, &MainWindow::pushFront);
    connect(ui->popBack_btn, &QPushButton::clicked, this, &MainWindow::popBack);
    connect(ui->popFront_btn, &QPushButton::clicked, this, &MainWindow::popFront);
    connect(ui->print_btn, &QPushButton::clicked, this, &MainWindow::print);
    connect(ui->clear_btn, &QPushButton::clicked, this, &MainWindow::clear);
    connect(ui->front_btn, &QPushButton::clicked, this, &MainWindow::front);
    connect(ui->back_btn, &QPushButton::clicked, this, &MainWindow::back);
    connect(ui->executeTask_btn, &QPushButton::clicked, this, &MainWindow::executeTask);


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushBack()
{
    int data = QRandomGenerator::global()->bounded(50);
    queue.push_back(data);

    print();
}

void MainWindow::pushFront()
{
    int data = QRandomGenerator::global()->bounded(50);
    queue.push_front(data);

    print();
}

void MainWindow::popBack()
{
    if (!queue.empty())
    {
        queue.pop_back();
    }

    print();
}

void MainWindow::popFront()
{
    if (!queue.empty())
    {
        queue.pop_front();
    }

    print();
}

void MainWindow::print()
{
    QString str = queue.print();
    ui->output_widget->addItem("Queue: ");
    ui->output_widget->addItem(str + "\n");
}

void MainWindow::clear()
{
    queue.clear();
}

void MainWindow::front()
{
    int data = queue.front();
    ui->output_widget->addItem("Front: ");
    ui->output_widget->addItem(QString::number(data) + "\n");
}

void MainWindow::back()
{
    int data = queue.back();
    ui->output_widget->addItem("Back: ");
    ui->output_widget->addItem(QString::number(data) + "\n");
}

void MainWindow::executeTask()
{
    mainQueue.clear();
    negativeQueue.clear();
    positiveQueue.clear();


    for (int i = 0; i < 20; i++) {
        mainQueue.push_back(QRandomGenerator::global()->bounded(-20, 20));
    }

    QString mainQueueStr = mainQueue.print();
    ui->output_widget->addItem("Main queue: ");
    ui->output_widget->addItem(mainQueueStr);

    while (!mainQueue.empty()) {
        int data = mainQueue.front();
        mainQueue.pop_front();

        if (data < 0) {
            negativeQueue.push_back(data);
        } else {
            positiveQueue.push_back(data);
        }
    }

    QString negativeQueueStr = negativeQueue.print();
    ui->output_widget->addItem("Negative queue: ");
    ui->output_widget->addItem(negativeQueueStr);

    QString positiveQueueStr = positiveQueue.print();
    ui->output_widget->addItem("Positive queue: ");
    ui->output_widget->addItem(positiveQueueStr + "\n");
}
