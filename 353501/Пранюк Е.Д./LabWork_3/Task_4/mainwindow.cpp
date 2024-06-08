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

void MainWindow::Hanoi(int n , char from ,char To , char middle)
{
    char From_name = from , To_name = To , Middle_name = middle;
    QString str;
    if (n == 0)
    {
        return;
    }
    Hanoi(n - 1,From_name,Middle_name,To_name);
    str += "Move disk " + QString::number(n) + " from rod " + From_name + " to rod " + To_name + "\n";
    ui->listWidget->addItem(str);
    Hanoi(n - 1,Middle_name,To_name,From_name);
}
void MainWindow::on_lineEdit_numberOfDiscs_returnPressed()
{
    bool ConvertionIsGood = true;
    long long n = ui->lineEdit_numberOfDiscs->text().toLongLong(&ConvertionIsGood);
    if(!ConvertionIsGood)
    {
        QMessageBox::warning(this, "Error!!!", "Please enter number!");
        return;
    }
    str_info.clear();
    Hanoi(n , 'A', 'C', 'B');
}



