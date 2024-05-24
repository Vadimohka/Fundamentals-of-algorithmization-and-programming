#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    bitset = new BitSet(15);
    ui->lineEdit->setText(bitset->to_string());
    QPalette p(ui->centralwidget->palette());
    p.setColor(QPalette::Window, QColor(151, 107, 171));
    ui->centralwidget->setAutoFillBackground(true);
    ui->centralwidget->setPalette(p);
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
        QPixmap pix("/home/oblachko/Projects/LabWork_5/Task_3/cat.jpeg");
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

void MainWindow::on_pushButton_all_clicked()
{
    ui->label_ans->setText("ans: " + QString(bitset->all() ? "true" : "false"));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_any_clicked()
{
    ui->label_ans->setText("ans: " + QString(bitset->any() ? "true" : "false"));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_count_clicked()
{
    ui->label_ans->setText("ans: " + QString(QString::number(bitset->count())));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_none_clicked()
{
    ui->label_ans->setText("ans: " + QString(bitset->none() ? "true" : "false"));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_reset_clicked()
{
    bitset->reset();
    ui->label_ans->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_set_clicked()
{
    bitset->set();
    ui->label_ans->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_getSize_clicked()
{
    ui->label_ans->setText("ans: " + (QString::number(bitset->getSize())));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_ullong_clicked()
{
    ui->label_ans->setText("ans: " + (QString::number(bitset->to_ullong())));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_ulong_clicked()
{
    ui->label_ans->setText("ans: " + QString::number(bitset->to_ulong()));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_flip_clicked()
{
    bitset->flip();
    ui->label_ans->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_flipArg_clicked()
{
    bitset->flip(ui->spinBox_flip->value());
    ui->label_ans->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_setArg_clicked()
{
    bitset->set(ui->spinBox_set->value());
    ui->label_ans->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_resetArg_clicked()
{
    bitset->reset(ui->spinBox_reset->value());
    ui->label_ans->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_testArg_clicked()
{
    ui->label_ans->setText("ans: " + QString::number(bitset->test(ui->spinBox_test->value())));
    ui->lineEdit->setText(bitset->to_string());
}

