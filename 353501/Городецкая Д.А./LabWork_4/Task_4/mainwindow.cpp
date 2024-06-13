#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->SizeSpinBox->setRange(1, 20);
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, [&](){
        showVector();
    });
    timer->start(30);
}

MainWindow::~MainWindow()
{
    delete ui;

}

void MainWindow::showVector()
{
    QString str = "";
    for (int i = 0; i < vec.size(); ++i){
        str += QString::number(vec[i]) + " ";
    }
    ui->anslabel_3->setText(str);
}

void MainWindow::createVector()
{
    vec.clear();
    vec.resize(ui->SizeSpinBox->value());
    for (int i = 0; i < vec.size(); ++i){
        vec[i] = i + 1;
    }
    showVector();
}

void MainWindow::on_ErasepushButton_clicked()
{
    vec.erase(iterator<int>(vec.begin() + ui->ElementSpinBox->value()));
}


void MainWindow::on_max_sizepushButton_5_clicked()
{
    QMessageBox::information(this, "", "Максималбный размер: " +QString::number(vec.max_size()));
}


void MainWindow::on_pop_backpushButton_9_clicked()
{
    vec.pop_back();
}


void MainWindow::on_push_backpushButton_13_clicked()
{
    vec.push_back(ui->ElementSpinBox->value());
}


void MainWindow::on_capacitypushButton_14_clicked()
{
    QMessageBox::information(this, "", "зарезервироанный размер: " +QString::number(vec.capacity()));

}


void MainWindow::on_emptypushButton_15_clicked()
{
    if (vec.empty())QMessageBox::information(this, "", "Ветор пуст");
    else QMessageBox::information(this, "", "Ветор не пуст");

}


void MainWindow::on_datapushButton_12_clicked()
{
    QString ptrStr = QString("0x%1").arg(reinterpret_cast<quintptr>(vec.data()), QT_POINTER_SIZE * 2, 16, QChar('0'));
    QMessageBox::information(this, "", ptrStr);

}


void MainWindow::on_sizepushButton_10_clicked()
{
    QMessageBox::information(this, "", QString::number(vec.size()));

}


void MainWindow::on_ResizepushButton_6_clicked()
{
    vec.resize(ui->ElementSpinBox->value());
}


void MainWindow::on_AtpushButton_3_clicked()
{
    QMessageBox::information(this, "", QString::number(vec.at(ui->ElementSpinBox->value())));

}


void MainWindow::on_RevercepushButton_2_clicked()
{
    vec.reserve(10);
}


void MainWindow::on_pushButton_clicked()
{
    createVector();
}


void MainWindow::on_ClearpushButton_7_clicked()
{
    vec.clear();
}
