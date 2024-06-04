#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MyValidator* v = new MyValidator;
    ui->NameEdit->setValidator(v);
    ui->lineEdit->setEnabled(false);
    ui->spinBox->setValue(4);
    ui->spinBox->setRange(3, 6);
    ui->doubleSpinBox->setValue(7.5);
    ui->doubleSpinBox->setRange(5,8);
    ui->ProtectionClassspinBox_2->setRange(1, 5);
    ui->ProtectionClassspinBox_2->setValue(1);
    ui->PricespinBox_2->setRange(1,100);
    ui->PricespinBox_2->setValue(1);
    ui->NumbspinBox_2->setValue(1);
    ui->NumbspinBox_2->setRange(1, 5);
    setInformation();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setInformation()
{
    QString ans = (w.HasBattery?"true":"false");
    ans = ans + "|" + QString(w.ProtectionClass) + "|" + QString::number(w.ArrowsQuantity) + "|" + QString::number(w.Radius) + "|" + w.NameOfFirm + "|";
    ans += "{" + QString::number(w.Price[0]) + "," + QString::number(w.Price[1]) + "," + QString::number(w.Price[2]) + "," + QString::number(w.Price[3]) + "," + QString::number(w.Price[4]) + "}";
    ui->lineEdit->setText(ans);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    w.HasBattery = ui->checkBox->isChecked();
    setInformation();
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    w.ArrowsQuantity = ui->spinBox->value();
    setInformation();
}


void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    w.Radius = ui->doubleSpinBox->value();
    setInformation();
}


void MainWindow::on_ProtectionClassspinBox_2_textChanged(const QString &arg1)
{
    w.ProtectionClass = ui->ProtectionClassspinBox_2->value() + 48;
    setInformation();
}


void MainWindow::on_NameEdit_textChanged(const QString &arg1)
{
   for (int i = 0; i < 15; ++i){
        w.NameOfFirm[i] = NULL;

    }
    for (int i = 0; i < ui->NameEdit->text().size(); ++i){
        w.NameOfFirm[i] = ui->NameEdit->text()[i].toLatin1();
        qDebug() << i;
    }
    setInformation();
}


void MainWindow::on_PricespinBox_2_valueChanged(int arg1)
{
    w.Price[ui->NumbspinBox_2->value() - 1] = ui->PricespinBox_2->value();
    setInformation();
}


void MainWindow::on_NumbspinBox_2_valueChanged(int arg1)
{
    ui->PricespinBox_2->setValue(w.Price[ui->NumbspinBox_2->value() - 1]);
}

