#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix("/home/senya/qt/Laba3/lab3_tsk4/hanoi_tow.png");
    ui->label_image -> setPixmap(pix.scaled(570, 280));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::hanoi(int amount, int beg, int end)
{
    if(amount == 1){
        vStr.push_back("Move  " + QString::number(amount) + "  ring  from  " + (beg - 1 + 'A') +  "  to  " + (end - 1 + 'A'));
        return;
    }
    hanoi(amount - 1, beg, 6 - beg - end);
    vStr.push_back("Move  " + QString::number(amount) + "  ring  from  " + (beg - 1 + 'A') +  "  to  " + (end - 1 + 'A'));
    hanoi(amount - 1, 6 - beg - end, end);
}

void MainWindow::on_spinBox_editingFinished()
{
    ui->textBrowser->clear();
    vStr.clear();
    hanoi(ui->spinBox->value(), 1, 3);
    for(QString str: vStr){
        ui->textBrowser->append(str);
    }
}

