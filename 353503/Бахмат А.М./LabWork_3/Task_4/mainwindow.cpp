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

/*Чтобы переместить n дисков с левого стержня на правый, сначала необходимо переместить
 n - 1 дисков на стержень посередине. Затем, когда диск под номером n, самый большой,
 оказывается на правом стержне, нужно переместить на него оставшиеся диски со стержня посередине.
 Чтобы переместить n - 1 дисков со стержня посередине направо, нужно сначала переместить n - 2
 дисков на стержень слева, затем переместить (n-1)-й диск вправо, потом переместить
 n - 2 дисков с левого стержня на правый и так далее.*/
QString& MainWindow::hanoi(int n, char fromTower, char additionalTower, char toTower, QString& solution)
{
    _steps++;

    if (n == 1)
    {
        solution += "1 disk from " + QString(fromTower) + " rod to " + QString(toTower) + " rod\n";
        return solution;
    }

    hanoi(n - 1, fromTower, toTower, additionalTower, solution);
    solution += QString::number(n) + " disk from " + QString(fromTower) + " rod to " + QString(toTower) + " rod\n";
    hanoi(n - 1, additionalTower, fromTower, toTower, solution);

    return solution;
}

void MainWindow::on_solveButton_clicked()
{
    _steps = 0;

    hanoi(ui -> spinBox -> value(), 'A', 'B', 'C', _solution);

    QString steps = QString::number(_steps) + " step(s):\n\n";
    _solution = steps + _solution;

    ui -> textEdit -> setText(_solution);

    _solution.clear();
}

