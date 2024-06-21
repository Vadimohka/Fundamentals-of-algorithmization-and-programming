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

void MainWindow::on_createArray_clicked()
{
    ui->output->clear();
    QStringList strList = ui->input->text().split(u' ');
    std::vector<int> vector;
    for (const auto &el : strList)
    {
        vector.push_back(el.toInt());
    }
    int n = vector.size();
    for (int i = 1; n > 0; i += 3, n -= 3)
    {
        if (n >= 3)
        {
            if (vector[i - 1] > vector[i]) std::swap(vector[i - 1], vector[i]);
            if (vector[i] > vector[i + 1]) std::swap(vector[i], vector[i + 1]);
            if (vector[i - 1] > vector[i]) std::swap(vector[i - 1], vector[i]);
            ui->output->setText(ui->output->text() + QString::number(vector[i]) + " ");
        }
        else if (n == 2)
        {
            double avg = (vector[i] + vector[i - 1]) / 2;
            ui->output->setText(ui->output->text() + QString::number(avg) + " ");
        }
        else
        {
            ui->output->setText(ui->output->text() + QString::number(vector[i - 1]) + " ");
        }
    }
}

