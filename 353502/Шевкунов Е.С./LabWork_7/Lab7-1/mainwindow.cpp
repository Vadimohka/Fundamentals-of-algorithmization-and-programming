#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QRandomGenerator>  // Include this header for QRandomGenerator

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setupUi();

    connect(pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);
    connect(popButton, &QPushButton::clicked, this, &MainWindow::on_popButton_clicked);
    connect(fillButton, &QPushButton::clicked, this, &MainWindow::on_fillButton_clicked);
    connect(nextButton, &QPushButton::clicked, this, &MainWindow::on_nextButton_clicked);
    connect(prevButton, &QPushButton::clicked, this, &MainWindow::on_prevButton_clicked);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateDisplay);
    timer->start(100);
}

MainWindow::~MainWindow()
{
}

void MainWindow::setupUi()
{
    QWidget *centralWidget = new QWidget(this);
    setCentralWidget(centralWidget);

    QVBoxLayout *mainLayout = new QVBoxLayout(centralWidget);

    QHBoxLayout *inputLayout = new QHBoxLayout();
    valueSpinBox = new QSpinBox();
    valueSpinBox->setRange(0, 100);
    pushButton = new QPushButton("Push");
    popButton = new QPushButton("Pop");
    fillButton = new QPushButton("Fill");
    inputLayout->addWidget(valueSpinBox);
    inputLayout->addWidget(pushButton);
    inputLayout->addWidget(popButton);
    inputLayout->addWidget(fillButton);
    mainLayout->addLayout(inputLayout);

    listWidget = new QListWidget();
    mainLayout->addWidget(listWidget);

    QHBoxLayout *navigationLayout = new QHBoxLayout();
    nextButton = new QPushButton("Next");
    prevButton = new QPushButton("Prev");
    navigationLayout->addWidget(prevButton);
    navigationLayout->addWidget(nextButton);
    mainLayout->addLayout(navigationLayout);

    QHBoxLayout *displayLayout = new QHBoxLayout();
    gauge = new QProgressBar();
    gauge->setRange(0, 100);
    label = new QLabel("Empty");
    displayLayout->addWidget(gauge);
    displayLayout->addWidget(label);
    mainLayout->addLayout(displayLayout);
}

void MainWindow::on_pushButton_clicked()
{
    int value = valueSpinBox->value();
    deque.push(value);
    updateDisplay();
}

void MainWindow::on_popButton_clicked()
{
    deque.pop();
    updateDisplay();
}

void MainWindow::on_fillButton_clicked()
{
    deque.clear();
    for (int i = 0; i < 20; ++i) {
        deque.push(QRandomGenerator::global()->bounded(100));
    }
    updateDisplay();
}

void MainWindow::on_nextButton_clicked()
{
    deque.moveNext();
    updateDisplay();
}

void MainWindow::on_prevButton_clicked()
{
    deque.movePrev();
    updateDisplay();
}

void MainWindow::updateDisplay()
{
    listWidget->clear();
    for (int val : deque.toVector()) {
        listWidget->addItem(QString::number(val));
    }

    int dequeSize = deque.size();
    if (dequeSize > 0) {
        int currentIndex = deque.currentIndex();
        int currentValue = deque.currentValue();
        gauge->setRange(0, dequeSize - 1);
        gauge->setValue(currentIndex);
        label->setText(QString::number(currentValue));
    } else {
        gauge->setRange(0, 1);
        gauge->setValue(0);
        label->setText("Empty");
    }
}


