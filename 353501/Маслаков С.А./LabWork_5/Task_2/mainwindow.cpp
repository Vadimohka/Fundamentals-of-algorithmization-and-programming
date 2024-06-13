#include "mainwindow.h"
#include <QtWidgets>
#include "mystring.h"
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

void MainWindow::on_strlen_clicked()
{
    QString str1 = ui->stringEdit1->toPlainText();
    MyString myStr1(str1.toStdString().c_str());
    int len1 = myStr1.strlen(myStr1.getData());
    QMessageBox::information(this,
                             "Length",
                             "Length of the first string is: " + QString::number(len1));

    QString str2 = ui->stringEdit2->toPlainText();
    MyString myStr2(str2.toStdString().c_str());
    int len2 = myStr2.strlen(myStr2.getData());
    QMessageBox::information(this,
                             "Length",
                             "Length of the second string is: " + QString::number(len2));
}

void MainWindow::on_strcmp_clicked()
{
    QString str1 = ui->stringEdit1->toPlainText();
    QString str2 = ui->stringEdit2->toPlainText();
    MyString myStr1(str1.toStdString().c_str());
    MyString myStr2(str2.toStdString().c_str());
    int cmp = myStr1.strcmp(myStr1.getData(), myStr2.getData());
    QMessageBox::information(this, "Compare", "Result of comparison is: " + QString::number(cmp));
}

void MainWindow::on_strcat_clicked()
{
    QString str1 = ui->stringEdit1->toPlainText();
    QString str2 = ui->stringEdit2->toPlainText();
    MyString myStr1(str1.toStdString().c_str());
    MyString myStr2(str2.toStdString().c_str());
    myStr1.strcat(myStr1.getData(), myStr2.getData());
    ui->stringEdit1->setPlainText(QString::fromStdString(myStr1.getData()));
}
