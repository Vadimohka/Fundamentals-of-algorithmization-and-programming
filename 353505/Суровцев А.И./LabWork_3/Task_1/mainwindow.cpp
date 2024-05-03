#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(700, 150);
    setFixedSize(700,150);
    timer = new QTimer;
    QObject::connect(timer, &QTimer::timeout, [=](){
        update();
        if (ui->doubleSpinBox->value() == lastNumber) {
            ui->pushButton->setEnabled(false);
            ui->pushButton->setStyleSheet("background-color: gray;");
        }
        else {
            ui->pushButton->setEnabled(true);
            ui->pushButton->setStyleSheet("background-color: white;");
        }
    });
    timer->start(25);
    ui->doubleSpinBox->setMaximum(1e308);
    ui->doubleSpinBox->setMinimum(-1e308);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    long double number = ui->doubleSpinBox->value();
    ui->doubleSpinBox->setValue(1e308);
    lastNumber = number;
    Converter_to_binary c;
    QString str = c.solve(number);
    ui->label_2->setText("Результат: " + str);
}

