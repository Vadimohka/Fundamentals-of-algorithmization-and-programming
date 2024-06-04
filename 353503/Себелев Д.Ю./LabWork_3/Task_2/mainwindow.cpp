#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setWindowTitle("Ackermann Function");
    ui->result_edit->setReadOnly(true);

    connect(ui->calculate_button, SIGNAL(clicked()), this, SLOT(ShowResult()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::AckermannFunction(int m, int n)
{
    if (m == 0)
    {
        return n + 1;
    }
    else if (n == 0)
    {
        return AckermannFunction(m - 1, 1);
    }
    else
    {
        return AckermannFunction(m - 1, AckermannFunction(m, n - 1));
    }
}

void MainWindow::ShowResult()
{
    if (ui->firstNum_edit->text().isEmpty() || ui->secondNum_edit->text().isEmpty())
    {
        ui->result_edit->setText("Please enter two numbers");
        return;
    }

    if (ui->firstNum_edit->text().toInt() < 0 || ui->secondNum_edit->text().toInt() < 0)
    {
        ui->result_edit->setText("Please enter positive numbers");
        return;
    }

    if (ui->firstNum_edit->text().toInt() > 4 || ui->secondNum_edit->text().toInt() > 4 ||
        (ui->firstNum_edit->text().toInt() == 4 && ui->secondNum_edit->text().toInt() > 1))
    {
        QMessageBox::warning(this, "Warning", "The Ackermann function grows very quickly. Please enter smaller numbers.");
        return;
    }

    bool check1 = false;
    bool check2 = false;
    int m = ui->firstNum_edit->text().toInt(&check1);
    int n = ui->secondNum_edit->text().toInt(&check2);

    if (!check1 || !check2)
    {
        ui->result_edit->setText("Please enter numbers only");
        return;
    }
    int result = AckermannFunction(m, n);

    ui->result_edit->setText(QString::number(result));
}

