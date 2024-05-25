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

int MainWindow::Akerman(int num_m, int num_n)
{
    if(num_m == 0){
        return num_n+1;
    }
    else if(num_m>0 && num_n == 0)
        return Akerman(num_m-1,1);
    else if (num_m>0 && num_n>0)
            return Akerman(num_m-1, Akerman(num_m,num_n-1));
}

void MainWindow::CorrectInpur(int m, int n)
{
    if (m<0 || n<0 || m > 4 || (m == 3 && n >= 11) || (m == 4 && n >= 1)){
    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Предупреждение");
    msgBox.setText("Слишком большое число");
    msgBox.setIcon(QMessageBox::Information);
    msgBox.exec();

    }
}

void MainWindow::on_pushButton_clicked()
{

    int m= ui->m_lineEdit->text().toInt();
    int n= ui->n_lineEdit->text().toInt();
    if (m<0 || n<0 || m > 4 || (m == 3 && n >= 11) || (m == 4 && n >= 1)){
    CorrectInpur(m, n);
    }
    else{
    long long int sum = Akerman(m,n);
    ui->textEdit->setText(QString::number(sum));
    }
}

