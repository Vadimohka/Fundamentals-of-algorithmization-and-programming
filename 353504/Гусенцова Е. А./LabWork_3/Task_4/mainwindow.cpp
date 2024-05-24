#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringList>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::startSolvingTowerOfHanoi);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startSolvingTowerOfHanoi()
{   ui->textBrowser->clear();
    int value = ui->spinBox->value();
    solveTowerOfHanoi(value, "A", "B", "C");
}

void MainWindow::solveTowerOfHanoi(int n, QString source, QString auxiliary, QString destination)
{
    if (n == 1) {
        displayMove("Move disk 1 from " + source + " to " + destination);
        return;
    }

    solveTowerOfHanoi(n - 1, source, destination, auxiliary);
    displayMove("Move disk " + QString::number(n) + " from " + source + " to " + destination);
    solveTowerOfHanoi(n - 1, auxiliary, source, destination);
}

void MainWindow::displayMove(QString move)
{
    ui->textBrowser->append(move);
}
