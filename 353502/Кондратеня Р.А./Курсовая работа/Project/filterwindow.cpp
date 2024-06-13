#include "filterwindow.h"
#include "ui_filterwindow.h"

FilterWindow::FilterWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FilterWindow)
{
    ui->setupUi(this);
}

FilterWindow::~FilterWindow()
{
    delete ui;
}

void FilterWindow::on_pushButton_clicked()
{
    if(isInputCorrect())
    {
        emit filterSignal(ui->lineEdit->text().toDouble(), ui->lineEdit_2->text().toDouble());
    }
    else
        QMessageBox::information(nullptr, "Ошибка", "Введите корректное значение");
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    this->close();
}

bool FilterWindow::isInputCorrect()
{
    bool ok;
    double value =  ui->lineEdit->text().toDouble(&ok);
    if(!ok)
        return false;
    double value1 = ui->lineEdit_2->text().toDouble(&ok);
    if(!ok)
        return false;
    if(value <= value1)
        return true;
    return false;
}

