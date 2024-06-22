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

void MainWindow::on_pushButton_clicked()
{
    amountFold = 0;
    amountFiles = 0;
    ui->textBrowser->clear();
    ui->textBrowser_2->clear();
    QString sFilePath;
    sFilePath = QFileDialog::getExistingDirectory(this, "Выбрать файл", "/home/senya/qt/Laba3/lab3_tsk5/examples");
    checkFile(sFilePath);
    ui->lineEdit -> setText(QString::number(amountFold));
    ui->lineEdit_2 -> setText(QString::number(amountFiles));
}

void MainWindow::checkFile(QString path)
{
    QDir root(path);
    QFileInfoList list = root.entryInfoList(QDir::Filter::NoDotAndDotDot | QDir::Filter::AllEntries | QDir::Filter::Hidden);

    foreach(QFileInfo fileInf, list){
        QString type = (fileInf.isDir() ? "Dir" : "File");
        if(type == "Dir"){
            ui->textBrowser->append(fileInf.fileName());
            amountFold++;
        }
        else{
            ui->textBrowser_2->append(fileInf.fileName());
            amountFiles++;
        }

        checkFile(fileInf.absoluteFilePath());
    }
}


