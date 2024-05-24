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

void MainWindow::displayDeque(){
    ui->listWidget->clear();

    if(!d.empty()){
        auto it = d.begin();
        do {
            ui->listWidget->addItem(QString::number(*it));
            ++it;
        } while (it != d.end());
    }
    ui->label->setText(QString::number(d.size()));
}
void MainWindow::on_pushButton_pushb_clicked()
{
    d.push_back(ui->spinBox->value());
    displayDeque();
}


void MainWindow::on_pushButton_pushf_clicked()
{
    d.push_front(ui->spinBox->value());
    displayDeque();
}


void MainWindow::on_pushButton_popf_clicked()
{
    d.pop_front();
    displayDeque();
}


void MainWindow::on_pushButton_popb_clicked()
{
    d.pop_back();
    displayDeque();
}

