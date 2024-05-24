#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    button->setParent(this);
    button->setText("Calculate");
    button->setGeometry(100, 150, 100, 30);

    spinBox->setParent(this);
    spinBox->setGeometry(0, 30, 300, 30);
    spinBox->setRange(0,1000000000);

    Label->setParent(this);
    Label->setGeometry(0, 80, 300 ,30);

    QPushButton::connect(button, SIGNAL(pressed()), this, SLOT(on_button_clicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

unsigned int MainWindow::func(int n)
{
    if (n <= 9) return n;
    unsigned int base = 1;
    while (n / (base * 10)){
        base *= 10;
    }
    int revNumb = (n % 10) * base;
    return revNumb + func(n / 10);
}

void MainWindow::on_button_clicked()
{
    Label->setText("Result: " + QString::number(func(spinBox->value())));
}
