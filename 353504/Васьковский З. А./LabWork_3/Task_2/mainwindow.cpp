
#include "mainwindow.h"
#include "./ui_mainwindow.h"

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
void MainWindow::create(){
    long long m = ui->spinBox->value(), n = ui->spinBox_2->value();
    if (m > 4 || (m == 3 && n >= 11) || (m == 4 && n >= 1)) {
        QPixmap pixmap("/home/paul/Downloads/sizif-mem.jpg");
        ui->label_3->setPixmap(pixmap);
        return;
    }
    ui->label_2->setText(QString::number(a->ack(m, n)));
    ui->label_3->clear();
    return;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    create();
}


void MainWindow::on_spinBox_2_valueChanged(int arg1)
{
    create();
}
