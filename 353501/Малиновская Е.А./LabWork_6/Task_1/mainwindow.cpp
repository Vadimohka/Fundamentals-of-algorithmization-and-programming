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
    ui->spinBox->setRange(1, 4000);
    ui->doubleSpinBox->setValue(7.5);
    ui->doubleSpinBox->setRange(500,8000);
    ui->RatingspinBox_2->setRange(1, 5);
    ui->RatingspinBox_2->setValue(1);
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
    QString ans = (Firm.IsAbroad?"true":"false");
    ans = ans + "|" + QString(Firm.Rating) + "|" + QString::number(Firm.WorkersQuantity) + "|" + QString::number(Firm.AverageSalary) + "|" + Firm.NameOfFirm + "|";
    ans += "{" + QString::number(Firm.Price[0]) + "," + QString::number(Firm.Price[1]) + "," + QString::number(Firm.Price[2]) + "," + QString::number(Firm.Price[3]) + "," + QString::number(Firm.Price[4]) + "}";
    ui->lineEdit->setText(ans);
}

void MainWindow::on_checkBox_stateChanged(int arg1)
{
    Firm.IsAbroad = ui->checkBox->isChecked();
    setInformation();
}


void MainWindow::on_spinBox_valueChanged(int arg1)
{
    Firm.WorkersQuantity = ui->spinBox->value();
    setInformation();
}


void MainWindow::on_doubleSpinBox_valueChanged(double arg1)
{
    Firm.AverageSalary = ui->doubleSpinBox->value();
    setInformation();
}


void MainWindow::on_RatingspinBox_2_textChanged(const QString &arg1)
{
    Firm.Rating = ui->RatingspinBox_2->value() + 48;
    setInformation();
}


void MainWindow::on_NameEdit_textChanged(const QString &arg1)
{
    for (int i = 0; i < 15; ++i){
        Firm.NameOfFirm[i] = NULL;

    }
    for (int i = 0; i < ui->NameEdit->text().size(); ++i){
        Firm.NameOfFirm[i] = ui->NameEdit->text()[i].toLatin1();
        qDebug() << i;
    }
    setInformation();
}


void MainWindow::on_PricespinBox_2_valueChanged(int arg1)
{
    Firm.Price[ui->NumbspinBox_2->value() - 1] = ui->PricespinBox_2->value();
    setInformation();
}


void MainWindow::on_NumbspinBox_2_valueChanged(int arg1)
{
    ui->PricespinBox_2->setValue(Firm.Price[ui->NumbspinBox_2->value() - 1]);
}
