#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->input->setValidator(new QRegularExpressionValidator(QRegularExpression("[1-9]*"),this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

long long MainWindow::reverse(int num, int c)
{
    if (c != 0)
    {
        reversed += (num - num / (long long)pow(10, c) * (long long)(pow(10, c))) / (long long)pow(10, c - 1) * (long long)pow(10, count(num) - c);
        reverse(num, c - 1);
    }
    return reversed;
}

int MainWindow::count(int num)
{
    int c = 0;
    while (num)
    {
        ++c;
        num /= 10;
    }
    return c;
}

void MainWindow::on_reverse_clicked()
{
    ui->output->clear();
    std::string inp = ui->input->text().toStdString();
    try
    {
        int num = stoi(inp);
        ui->output->setText(QString::number(reverse(num, count(num))));
    }
    catch(std::exception &err)
    {
        ui->output->setText("Неправельный ввод");
    }
    reversed = 0;
}
