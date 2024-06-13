#include "mainwindow.h"
#include <QDebug>
#include <QString>
#include <QVBoxLayout>
#include <QHBoxLayout>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle("Hanoi Tower");
    setFixedSize(600, 500);

    numDiscsSpinBox = new QSpinBox(this);
    numDiscsSpinBox->setMinimum(1);
    numDiscsSpinBox->setMaximum(10);

    startButton = new QPushButton("Start", this);

    movesTextEdit = new QTextEdit(this);
    movesTextEdit->setReadOnly(true);
    movesTextEdit->setFrameStyle(QFrame::NoFrame);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(numDiscsSpinBox);
    layout->addWidget(startButton);
    layout->addWidget(movesTextEdit);

    QWidget *widget = new QWidget(this);
    widget->setLayout(layout);
    setCentralWidget(widget);

    connect(startButton, &QPushButton::clicked, this, &MainWindow::startHanoi);
}

MainWindow::~MainWindow(){}

void MainWindow::startHanoi()
{
    int numDiscs = numDiscsSpinBox->value();

    hanoi(numDiscs, 1, 2, 3, moves);

    movesTextEdit->append(moves);
}

void MainWindow::hanoi(int n, int source, int auxiliary, int destination, QString &moves)
{
    if (n > 0) {
        if (n == 1) {
            moves += QString::number(source) + " -> " + QString::number(destination) + "\n";
        } else {
            hanoi(n - 1, source, destination, auxiliary, moves);
            moves += QString::number(source) + " -> " + QString::number(destination) + "\n";
            hanoi(n - 1, auxiliary, source, destination, moves);
        }
    }
}

