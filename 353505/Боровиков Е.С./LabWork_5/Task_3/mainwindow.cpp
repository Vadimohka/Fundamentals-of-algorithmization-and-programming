#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyValidator* val = new MyValidator;
    ui->lineEdit->setValidator(val);
    bitset = new Bitset(16);
    ui->lineEdit->setText(bitset->to_string());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_all_clicked()
{
    ui->label->setText("ans: " + QString(bitset->all() ? "true" : "false"));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_any_clicked()
{
    ui->label->setText("ans: " + QString(bitset->any() ? "true" : "false"));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_count_clicked()
{
    ui->label->setText("ans: " + QString(QString::number(bitset->count())));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_none_clicked()
{
    ui->label->setText("ans: " + QString(bitset->none() ? "true" : "false"));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_reset_clicked()
{
    bitset->reset();
    ui->label->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_set_clicked()
{
    bitset->set();
    ui->label->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_getSize_clicked()
{
    ui->label->setText("ans: " + (QString::number(bitset->getSize())));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_ullong_clicked()
{
    ui->label->setText("ans: " + (QString::number(bitset->to_ullong())));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_ulong_clicked()
{
    ui->label->setText("ans: " + QString::number(bitset->to_ulong()));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_flip_clicked()
{
    bitset->flip();
    ui->label->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_flipArg_clicked()
{
    bitset->flip(ui->spinBox_flip->value());
    ui->label->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_setArg_clicked()
{
    bitset->set(ui->spinBox_set->value());
    ui->label->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_resetArg_clicked()
{
    bitset->reset(ui->spinBox_reset->value());
    ui->label->setText("");
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_pushButton_testArg_clicked()
{
    ui->label->setText("ans: " + QString::number(bitset->test(ui->spinBox_test->value())));
    ui->lineEdit->setText(bitset->to_string());
}


void MainWindow::on_lineEdit_textChanged(const QString &arg1)
{
    QString str = ui->lineEdit->text();
    bitset = new Bitset(str.size());
    for (int i = 0; i < str.size(); ++i){
        if (str[str.size() - 1 - i] == '1') bitset->set(i);
    }
    ui->lineEdit->setText(bitset->to_string());

}

