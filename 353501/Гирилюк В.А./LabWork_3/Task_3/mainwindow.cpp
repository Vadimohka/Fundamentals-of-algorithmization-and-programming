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

void MainWindow::on_lineEdit_editingFinished()
{
    if(ui->lineEdit->text().length() > 0){
        std::string str = ui->lineEdit->text().toStdString();
        bool dot = false, correct = true, negative = false;
        char c = '.';
        for(int i = 0; i < str.length(); i++){
            if(str.at(0) == '-'){
                str.erase(0, 1);
                negative = true;
            }
            if((str.at(i) < '0' || str.at(i) > '9') && str.at(i) != '.'){
                correct = false;
                break;
            }
            else if(str.at(i) == c && dot){
                correct = false;
                break;
            }
            else if(str.at(i) == c && !dot){
                dot = true;
            }
        }
        if(!correct){
            QMessageBox::critical(this, "Error", "Incorrect input!\nRetry input.");
        }
        else{
            ui->outPutResult->setText((negative ? "-" : "") + reverseNumber(QString::fromStdString(str)));
        }
    }
}

QString MainWindow::reverseNumber(QString str)
{
    if(str != ""){
        QChar c = str.at(str.length() - 1);
        str.chop(1);
        return c + reverseNumber(str);
    }
    else{
        return "";
    }
}

