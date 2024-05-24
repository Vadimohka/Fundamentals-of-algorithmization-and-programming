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

void MainWindow::Hanoi(int r, int b, int e){
    int c;
    if (((b==1) && (e==2))||
        ((b==2) && (e==1)))
        c = 3;
    else
        if (((b==1) && (e==3))||
            ((b==3) && (e==1)))
            c = 2;
        else
            if (((b==2) && (e==3))||
                ((b==3) && (e==2)))
                c = 1;
    if (r >1){
        Hanoi(r-1,b,c);

                ui->listWidget->addItem(QString::number(b) + "->" + QString::number(e));
        //std::cout<< b << "->"<< e<<std::endl;

        Hanoi(r-1, c, e);
    }
     else
        ui->listWidget->addItem(QString::number(b) + "->" + QString::number(e));
    //std::cout<< b << "->" << e<<std::endl;
}


void MainWindow::on_pushButton_clicked()
{
    ui->listWidget->clear();
    int r = ui->lineEdit->text().toInt();
    if (r < 21){
    Hanoi(r,1,3);
    }
    else
    showPopup();
}

void MainWindow::showPopup()
{
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Предупреждение");
    msgBox.setText("Большое число");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();
}

