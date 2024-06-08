#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "converter.h"
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

bool MainWindow::checkInput(QString string)
{
    try {
        (void)std::stold(string.toStdString());
    }catch (...){
        return false;
    }
    bool isDot = false;
    bool isE = false;
    for(QChar c : string) {
        if(c == '.'){
            if(isDot) return false;
            isDot = true;
        }
        if(c == 'e'){
            if(isE) return false;
            isE = true;
        }
    }
    return true;
}
void MainWindow::on_convertbut_clicked()
{
    QString a = ui->inputlineedit->text();
    if(!checkInput(a)){
        QMessageBox::critical(0,tr("Ошибка"),tr("Неверный формат данных файла"),QMessageBox::Ok|QMessageBox::NoButton);
        return;
    }
    ui->outputlabel->setText(Converter::toBinaryIEE754(a));
}

