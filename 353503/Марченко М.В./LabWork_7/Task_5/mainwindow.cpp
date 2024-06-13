#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton_pushb, &QPushButton::clicked, this, &MainWindow::pushBackClicked);
    connect(ui->pushButton_pushf, &QPushButton::clicked, this, &MainWindow::pushFrontClicked);
    connect(ui->pushButton_popf, &QPushButton::clicked, this, &MainWindow::popFrontClicked);
    connect(ui->pushButton_popb, &QPushButton::clicked, this, &MainWindow::popBackClicked);
    connect(ui->pushButton_clear, &QPushButton::clicked, this, &MainWindow::clearClicked);
    connect(ui->pushButton_empty, &QPushButton::clicked, this, &MainWindow::emptyClicked);
    connect(ui->pushButton_size, &QPushButton::clicked, this, &MainWindow::sizeClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::pushBackClicked()
{
    deque.push_back(ui->spinBox1->value());
    displayDeque();
}

void MainWindow::pushFrontClicked()
{
    deque.push_front(ui->spinBox2->value());
    displayDeque();
}

void MainWindow::popFrontClicked()
{
    deque.pop_front();
    displayDeque();
}

void MainWindow::popBackClicked()
{
    deque.pop_back();
    displayDeque();
}

void MainWindow::displayDeque()
{
    ui->listWidget->clear();

    if(!deque.empty()){
        auto it = deque.begin();
        do {
            ui->listWidget->addItem(QString::number(*it));
            ++it;
        } while (it != deque.end());
    }
   // ui->label->setText(QString::number(deque.size()));
}

void MainWindow::emptyClicked()
{
    if (deque.empty()) {
        QMessageBox::information(this, "Empty", "Deque is empty");
    } else {
        QMessageBox::information(this, "Not Empty", "Deque is not empty");
    }
}

void MainWindow::sizeClicked()
{
    int size = deque.size();
    QMessageBox::information(this, "Size", "Deque size is " + QString::number(size));
}

void MainWindow::clearClicked()
{
    deque.clear();
    ui->listWidget->clear();
}
