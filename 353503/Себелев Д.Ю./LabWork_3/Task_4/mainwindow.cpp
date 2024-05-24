#include "mainwindow.h"
#include "ui_mainwindow.h"

constexpr short maxCountOfRings = 15;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Hanoi Tower");

    connect(ui->solve_button, SIGNAL(clicked()), this, SLOT(GetNumOfRings()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Hanoi(int n, char from, char to, char aux)
{
    if (n == 0) {
        return;
    }
    Hanoi(n - 1, from, aux, to);

    ui->output_listEdit->addItem("Move ring " + QString::number(n) + " from rod " + from + " to rod " + to);

    Hanoi(n - 1, aux, to, from);
}

void MainWindow::GetNumOfRings()
{
    ui->output_listEdit->clear();
    if (ui->numOfRings_edit->text().isEmpty())
    {
        ui->output_listEdit->addItem("Please enter the number of rings");
        return;
    }

    if (ui->numOfRings_edit->text().toInt() < 0)
    {
        ui->output_listEdit->addItem("Please enter a positive number");
        return;
    }

    bool check = false;
    int num = ui->numOfRings_edit->text().toInt(&check);
    if (!check)
    {
        ui->output_listEdit->addItem("Please enter a valid number");
        return;
    }

    if (num <= maxCountOfRings)
    {
        Hanoi(num, 'A', 'C', 'B');
    } else {
        ui->output_listEdit->addItem("Enter the num of riings less then 16");
    }
}
