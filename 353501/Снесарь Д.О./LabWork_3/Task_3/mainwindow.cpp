#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->in->setValidator(new QIntValidator());
}

MainWindow::~MainWindow()
{
    delete ui;
}

long long MainWindow::reverse(long long n, long long a)
{
    if (n == 0)
        return a;
    else
        return reverse(n / 10, 10 * a + n % 10);
}


void MainWindow::on_pushButton_clicked()
{
    ui->out->setText(QString::number(reverse(ui->in->text().toLongLong())));
}

