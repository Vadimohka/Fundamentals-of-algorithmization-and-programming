#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->centralwidget->setStyleSheet("background-color: black");
    ui->pushButton->setStyleSheet("background-color: gray");
}

MainWindow::~MainWindow()
{
    delete ui;
}

int MainWindow::AckermannFunc(int m, int n)
{
    if(m == 0)
    {
        return n + 1;
    }
    else if(m > 0 && n == 0)
    {
        return AckermannFunc(m - 1,1);
    }
    else if(m > 0 && n > 0)
    {
        return AckermannFunc(m - 1,AckermannFunc(m, n - 1));
    }
}

void MainWindow::on_lineEdit_m_returnPressed()
{
    bool ConvertionIsGood = true;
    _m = ui->lineEdit_m->text().toInt(&ConvertionIsGood);
    if(!ConvertionIsGood)
    {
        QMessageBox::warning(this, "Error!!!", "Please enter number!");
        return;
    }
    isM = true;
}

void MainWindow::on_lineEdit_n_returnPressed()
{
    bool ConvertionIsGood = true;
    _n = ui->lineEdit_n->text().toInt(&ConvertionIsGood);
    if(!ConvertionIsGood)
    {
        QMessageBox::warning(this, "Error!!!", "Please enter number!");
        return;
    }
    isN = true;
}

void MainWindow::on_pushButton_clicked()
{
    if(isN && isM)
    {
        if((_m >= 4 && _n >= 2))
        {
            QMessageBox::warning(this, "Error!!!", "I can not represent answer!");
            return;
        }

        ui->lineEdit_Result->setText(QString::number(AckermannFunc(_m,_n)));
        return;
    }
    QMessageBox::warning(this, "Error!!!", "Please enter m and n befor clicking the button!");
}

