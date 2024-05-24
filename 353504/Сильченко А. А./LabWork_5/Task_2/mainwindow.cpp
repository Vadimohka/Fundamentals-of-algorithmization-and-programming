#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    string = *(new myString(""));
    ui->lineEdit_str->setText(string.c_str());
    ui->label_size->setText(QString::number(string.size()));
    ui->pushAlarm->setStyleSheet("background-color:red");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushAlarm_clicked()
{
    if(!bimage)
    {
        ui->pushAlarm->setStyleSheet("background-color:green");
        QPixmap pix("/home/oblachko/Projects/LabWork_5/Task_2/cat.jpeg");
        ui->label_2->setPixmap(pix);
        ui->pushAlarm->setText("Всё хорошо");
    }
    else
    {
        ui->pushAlarm->setStyleSheet("background-color:red");
        ui->label_2->setText(" ");
        ui->pushAlarm->setText("Нажать, когда всё плохо");
    }

    bimage=!bimage;
}

void MainWindow::on_pushButton_pe_clicked()
{
    string += *new myString(ui->lineEdit_pe->text().toStdString().c_str());
    ui->lineEdit_str->setText(string.c_str());
    ui->label_size->setText(QString::number(string.size()));
}

void MainWindow::on_pushButton_equal_clicked()
{
    string = *new myString(ui->lineEdit_equal->text().toStdString().c_str());
    ui->lineEdit_str->setText(string.c_str());
    ui->label_size->setText(QString::number(string.size()));
}

void MainWindow::on_pushButton_memcpy_clicked()
{
    ui->lineEdit_ans->setText((char *)myString::myMemcpy(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}


void MainWindow::on_pushButton_memmove_clicked()
{
    ui->lineEdit_ans->setText((char *)myString::myMemmove(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}




void MainWindow::on_pushButton_strcpy_clicked()
{
    ui->lineEdit_ans->setText((char *)myString::myStrcpy(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()));
}


void MainWindow::on_pushButton_strncpy_clicked()
{
    ui->lineEdit_ans->setText((char *)myString::myStrncpy(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}


void MainWindow::on_pushButton_strcat_clicked()
{
    ui->lineEdit_ans->setText((char *)myString::myStrcat(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()));
}


void MainWindow::on_pushButton_strncat_clicked()
{
    ui->lineEdit_ans->setText((char *)myString::myStrncat(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()));
}




void MainWindow::on_pushButton_memcmp_clicked()
{
    ui->lineEdit_ans->setText(QString::number((myString::myMemcmp(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()))));
}


void MainWindow::on_pushButton_strcmp_clicked()
{
    ui->lineEdit_ans->setText(QString::number((myString::myStrcmp(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()))));
}


void MainWindow::on_pushButton_strcoll_clicked()
{
    ui->lineEdit_ans->setText(QString::number((myString::myStrcoll(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()))));
}


void MainWindow::on_pushButton_strncmp_clicked()
{
    ui->lineEdit_ans->setText(QString::number((myString::myStrncmp(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()))));
}


void MainWindow::on_strxfrm_clicked()
{
    ui->lineEdit_ans->setText(QString::number((myString::myStrxfrm(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data(), (size_t)ui->spinBox->value()))));
}


void MainWindow::on_pushButton_strtok_clicked()
{
    ui->lineEdit_ans->setText((char*)((myString::myStrtok(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().toUtf8().data()))));
}


void MainWindow::on_pushButton_strmemset_clicked()
{
    ui->lineEdit_ans->setText((char*)myString::myMemset(ui->lineEdit_str1->text().toUtf8().data(),  ui->lineEdit_str2->text().front().toLatin1(), (size_t)ui->spinBox->value()));
}


void MainWindow::on_pushButton_strlen_clicked()
{
    ui->lineEdit_ans->setText(QString::number((myString::myStrlen(ui->lineEdit_str1->text().toUtf8().data()))));
}

